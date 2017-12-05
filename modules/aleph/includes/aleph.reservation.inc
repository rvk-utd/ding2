<?php
/**
 * @file
 * Handles reservation with Aleph.
 */

use Drupal\aleph\Aleph\Entity\AlephRequest;
use Drupal\aleph\Aleph\Entity\AlephReservation;
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
  $form += ding_reservation_default_options_branch('alma_preferred_branch', $default, $branches);
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
 *    User to list reservations for.
 * @param string|null $requested_type
 *    Type of reservations to list. NULL for all.
 *
 * @return \DingProviderReservation[]
 *    Array of DingProviderReservations.
 */
function aleph_reservation_list($account, $requested_type = NULL) {
  // Throw exception if we're not logged in.
  ding_user_get_creds($account);

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

  foreach ($res as $reservation) {
    $request = $reservation->getRequest();
    $material = $reservation->getItem();

    $type = $request->getStatus() === 'S' ? DING_RESERVATION_READY : DING_RESERVATION_NOT_READY;

    $ding_reservation = array(
      'ding_entity_id' => ding_provider_build_entity_id($material->getId()),
      'id' => $material->getId(),
      'pickup_branch_id' => $request->getPickupLocation(),
      'created' => $request->getOpenDate(),
      'expiry' => $request->getEndRequestDate(),
      'display_name' => $material->getTitle(),
      // Required by ding_reservation.
      'reservation_type' => $type,
    );

    if ($type === DING_RESERVATION_READY) {
      $ding_reservation['pickup_date'] = $request->getHoldDate();
      $ding_reservation['pickup_order_id'] = $request->getDocNumber();
      $ding_reservation['order_arrived'] = TRUE;
    }
    elseif ($type === DING_RESERVATION_NOT_READY) {
      if (!empty($request->getSequence())) {
        $ding_reservation['queue_number'] = $request->getSequence();
      }
    }

    $result[$type][$ding_reservation['id']] = new DingProviderReservation($ding_reservation['id'], $ding_reservation);
  }

  // Filter the result based on the requested type of reservations.
  if ($requested_type !== NULL && isset($result[$requested_type])) {
    return $result[$requested_type];
  }
  else {
    watchdog('aleph', 'Unknown reservation type (%type) requested', array('%type' => $requested_type), WATCHDOG_ERROR);
  }

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
 * @throws \DingProviderReservationExists
 *   Reservation exists.
 * @throws \DingProviderUserException
 *    General exception.
 */
function aleph_reservation_create($account, $id) {
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron(aleph_get_patron_by_account());

  // Check if the users has this reservation and throw exception.
  $reservations = $patron_handler->getReservations();

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
  $request->setRequestDate(new DateTime());
  $request->setEndRequestDate($end_request_date);
  $request->setPickupLocation($defaults['aleph_preferred_branch']);
  $reservation->setRequest($request);

  // Try to make the reservation.
  $patron = $patron_handler->getPatron();
  $response = NULL;
  try {
    $response = $patron_handler->createReservation($patron, $reservation);
  }
  catch (Exception $e) {
    watchdog_exception('aleph', $e);
    return array();
  }

  if ($response->success()) {
    return array(
      'branch' => $request->getPickupLocation(),
      // Queue number not supported by Aleph.
      'queue_number' => NULL,
    );
  }
  throw new DingProviderUserException(t($response->getNote()));
}

function aleph_reservation_update() {
  return NULL;
}

function aleph_reservation_delete() {
  return NULL;
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
 * @param $account
 *    The Drupal account object.
 *
 * @return array
 *    The branches as key and name.
 */
function aleph_reservation_pickup_branches($account) {
  // Throw exception if we're not logged in.
  ding_user_get_creds($account);
  return aleph_get_branches();
}

function aleph_reservation_get_reservations() {
  return NULL;
}

function aleph_reservation_clear_cache() {
  return NULL;
}

function aleph_reservation_exists() {
  return FALSE;
}

function aleph_reservation_format_date() {
  return NULL;
}
