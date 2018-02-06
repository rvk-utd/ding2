<?php
/**
 * @file
 * Handles reservation with Aleph.
 */

use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Entity\AlephRequest;
use Drupal\aleph\Aleph\Entity\AlephReservation;
use Drupal\aleph\Aleph\Exception\AlephClientException;
use Drupal\aleph\Aleph\Handler\AlephPatronHandler;

/**
 * @file
 * Handles reservation with Aleph.
 */

/**
 * Creates form which can be used during reservation.
 *
 * It's used to select preferred branch and interest period.
 *
 * @param object $account
 *   Drupal user account object.
 * @param string $default_value
 *   The name of the branch that should be selected as default value.
 *
 * @return array
 *   Form element with the provider reservation options (branch and interest
 *   period).
 */
function aleph_reservation_options($account, $default_value = '') {
  $branches = aleph_get_branches();
  $periods = aleph_get_interest_periods();

  $preferred_branch = NULL;
  $interest_period = NULL;
  if (ding_user_is_provider_user($account)) {
    // Load profile2 profile.
    $profile = ding_user_provider_profile($account);

    // Use a metadata wrapper to access the data.
    $wrapper = entity_metadata_wrapper('profile2', $profile);

    // Get values.
    $preferred_branch = $wrapper->field_aleph_preferred_branch->value();
    $interest_period = aleph_reservation_default_interest_period($profile);
  }

  // Set default value in the selection box if given else use preferred_branch.
  $default = $preferred_branch;
  if (!empty($default_value)) {
    $default = $default_value;
  }

  $form = array();
  $form += ding_reservation_default_options_branch('aleph_preferred_branch',
    $default, $branches);
  if (variable_get('ding_reservation_disable_interest_date') !== 1) {
    $form += ding_reservation_interest_period_selector('interest_period', $interest_period, $periods);
  }

  return $form;
}

/**
 * Implements provider reservation, options_submit.
 *
 * @param object $account
 *   The user to get update preferred branch for.
 * @param array $values
 *   Form values.
 */
function aleph_reservation_options_submit($account, array $values) {
  // Load profile2 profile.
  $profile = ding_user_provider_profile($account);

  // Use a metadata wrapper to access the data.
  $wrapper = entity_metadata_wrapper('profile2', $profile);

  // Get values.
  $preferred_branch = $wrapper->field_aleph_preferred_branch->value();

  // If default branch was not found in the profile, update the profile with the
  // one selected.
  if (!$preferred_branch) {
    $wrapper->field_aleph_preferred_branch->set($values['aleph_preferred_branch']);
    $profile->save();
  }
}

/**
 * Implements provider reservation, default_options.
 *
 * @param object $account
 *   Drupal user account object.
 *
 * @return array
 *   The interest period and default pick-up branch from the provider profile.
 */
function aleph_reservation_default_options($account) {
  // Load profile2 profile.
  $profile = ding_user_provider_profile($account);

  // Use a metadata wrapper to access the data.
  $wrapper = entity_metadata_wrapper('profile2', $profile);

  $result = array(
    'aleph_preferred_branch' => $wrapper->field_aleph_preferred_branch->value(),
    'interest_period' => $wrapper->field_aleph_interest_period->value(),
  );

  return $result;
}

/**
 * Implements provider reservation, default_interest_period.
 *
 * Tries to find the users default interest period based on the users profile2
 * provider profile.
 *
 * @param object $profile
 *   The users profile2 provider profile.
 *
 * @return string
 *   The default interest period selected by the user in his/her profile or the
 *   default value selected by the site.
 */
function aleph_reservation_default_interest_period($profile = NULL) {
  // If profile is not given, try loading it for the user.
  if (NULL === $profile) {
    global $user;
    $profile = ding_user_provider_profile($user);
  }

  // Get interest period from the profile.
  $wrapper = entity_metadata_wrapper('profile2', $profile);
  $value = $wrapper->field_aleph_interest_period->value();

  // If no period is selected, try getting default value.
  if (is_null($value) || empty($value)) {
    $value = variable_get('aleph_default_interest_period', 360);
  }

  return $value;
}

/**
 * Provider list callback.
 *
 * @param object $account
 *   User to list reservations for.
 * @param string|null $requested_type
 *   Type of reservations to list. NULL for all.
 *
 * @return \DingProviderReservation[]
 *   Array of DingProviderReservations.
 */
function aleph_reservation_list($account, $requested_type = NULL) {
  // Throw exception if we're not logged in.
  ding_user_get_creds();

  $result = array(
    DING_RESERVATION_READY => array(),
    DING_RESERVATION_NOT_READY => array(),
    DING_RESERVATION_INTERLIBRARY_LOANS => array(),
  );

  try {
    $patron_handler = new AlephPatronHandler(aleph_client());
    $patron_handler->setPatron(aleph_get_patron_by_account());
    $res = $patron_handler->getReservations();
  }
  catch (Exception $e) {
    watchdog_exception('aleph', $e);
    return $result;
  }

  $ids = [];
  foreach ($res as $reservation) {
    $id = $reservation->getItem()->getId();
    $ids[$id] = $id;
  }
  $ids = ding_provider_build_entity_id($ids);

  foreach ($res as $reservation) {
    $request = $reservation->getRequest();
    $material = $reservation->getItem();

    // Filter the list; only show materials for the branches in
    // aleph_get_branches().
    if (!array_key_exists($material->getSubLibraryCode(), aleph_get_branches())) {
      continue;
    }

    $type = $request->getStatus() === 'S' ? DING_RESERVATION_READY : DING_RESERVATION_NOT_READY;

    $ding_reservation = array(
      'ding_entity_id' => $ids[$material->getId()],
      'id' => $material->getId(),
      'order_id' => $request->getRequestNumber(),
      'pickup_branch_id' => $request->getPickupLocation(),
      'created' => $request->getOpenDate(),
      'expiry' => $request->getEndRequestDate(),
      'display_name' => $material->getTitle(),
      'reservation_type' => $type,
      'queue_number' => FALSE,
      'ill_status' => FALSE,
    );

    if ($type === DING_RESERVATION_READY) {
      $ding_reservation['pickup_date'] = $request->getHoldDate();
      $ding_reservation['pickup_order_id'] = $request->getRequestNumber();
      $ding_reservation['order_arrived'] = TRUE;
    }

    $result[$type][$ding_reservation['id']] = new DingProviderReservation($ding_reservation['id'], $ding_reservation);
  }

  // Filter the result based on the requested type of reservations.
  if ($requested_type !== NULL && isset($result[$requested_type])) {
    return $result[$requested_type];
  }
  watchdog('aleph', 'Unknown reservation type (%type) requested', array('%type' => $requested_type), WATCHDOG_ERROR);

  return $result;
}

/**
 * Create a new reservation in the library system.
 *
 * @param object $account
 *   Drupal user account object.
 * @param string $id
 *   ID of reservation.
 *
 * @return array
 *   Reservation information.
 *
 * @throws DingProviderAuthException
 *   If the users is not logged in.
 * @throws DingProviderReservationExists
 *   If reservation exists.
 * @throws DingProviderUserException
 *   Error messages shown to the user.
 * @throws Exception
 *    New DateInterval throws a generic exception.
 */
function aleph_reservation_create($account, $id) {
  $client = aleph_client();
  $patron_handler = new AlephPatronHandler($client);
  $patron_handler->setPatron(aleph_get_patron_by_account());
  $patron = $patron_handler->getPatron();

  // Check if the users has this reservation and throw exception.
  try {
    $reservations = $patron_handler->getReservations();
  }
  catch (AlephClientException $e) {
    throw new DingProviderUserException(t('Unable to get existing reservations.'));
  }

  foreach ($reservations as $reservation) {
    if ($id === $reservation->getItem()->getId()) {
      throw new DingProviderReservationExists();
    }
  }

  // Add the interest period for the 'to' date.
  $interest_period = aleph_reservation_default_interest_period();

  $end_request_date = new DateTime();
  $end_request_date->add(new DateInterval('P' . $interest_period . 'D'));

  // Build the reservation object.
  $defaults = aleph_reservation_default_options($account);
  $reservation = new AlephReservation();
  $request = new AlephRequest();
  $material = new AlephMaterial();
  $material->setId($id);
  $request->setRequestDate(new DateTime());
  $request->setEndRequestDate($end_request_date);
  $request->setPickupLocation($defaults['aleph_preferred_branch']);
  $request->setDocNumber($id);
  $reservation->setRequest($request);

  try {
    $holding_groups = $patron_handler->getHoldingGroups($patron, $material);
  }
  catch (AlephClientException $e) {
    throw new DingProviderUserException(t('Unable to get holding groups from the library system. Contact the library'));
  }

  // Try to make the reservation.
  $response = NULL;
  try {
    $response = $patron_handler->createReservation($patron, $reservation, $holding_groups);
    if ($response->success()) {
      return array(
        'branch' => $request->getPickupLocation(),
        // Queue number not supported by Aleph.
        'queue_number' => NULL,
      );
    }
    throw new DingProviderUserException(t($response->getReplyText()));
  }
  catch (AlephClientException $e) {
    watchdog_exception('aleph', $e);
    throw new DingProviderUserException(t(
      'We are unable to create a reservation in the library system. Please contact the library.'
    ));
  }
}

/**
 * Delete a reservation for a given account.
 *
 * @param object $account
 *   Drupal user account object.
 * @param string $id
 *   ID of a reservation.
 *
 * @return bool
 *   If the deletion succeeded or not.
 *
 * @throws DingProviderAuthException
 * @throws DingProviderReservationUserError
 * @throws AlephClientException
 */
function aleph_reservation_delete($account, $id) {
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron(aleph_get_patron_by_account());
  $reservations = $patron_handler->getReservations();

  if (isset($reservations[(string) $id])) {
    $cid = md5(serialize(array($reservations[$id]->getItem()->getId())));
    cache_clear_all($cid, 'cache');
  }

  $response = $patron_handler->deleteReservation($patron_handler->getPatron(),
    $reservations[$id]);

  if ($response->getNote() === 'Action Succeeded') {
    return $response->success();
  }

  throw new DingProviderReservationUserError($response->getNote());
}

/**
 * Implements provider reservation, reservation_deletion_enabled.
 *
 * Check whether reservation deletion have been enabled in the provider
 * settings.
 *
 * @return bool
 *   Whether deletion is enabled.
 */
function aleph_reservation_reservation_deletion_enabled() {
  return variable_get('aleph_enable_reservation_deletion', FALSE);
}

/**
 * Return a branch name for a given branch id.
 *
 * @param string $branch_id
 *   The identifier for a given pick-up branch (e.g. BBAAA).
 *
 * @return string
 *   The human name for the id or NULL if one do not exist.
 */
function aleph_reservation_branch_name($branch_id) {
  // $branch_id _CAN_ be the human readable name of the branch.
  // Branch ID's are 5 characters, so if it's more, return it.
  if (strlen($branch_id) > 5) {
    return $branch_id;
  }

  $branches = aleph_get_branches();

  if (isset($branches[$branch_id])) {
    return $branches[$branch_id];
  }

  return NULL;
}

/**
 * Provider pickup_branches callback.
 *
 * @param object $account
 *   The Drupal account object.
 *
 * @return array
 *   The branches as key and name.
 *
 * @throws DingProviderAuthException
 *    If the patron is not logged in.
 */
function aleph_reservation_pickup_branches($account) {
  // Throw exception if we're not logged in.
  ding_user_get_creds();
  return aleph_get_branches();
}
