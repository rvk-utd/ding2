<?php

namespace Drupal\aleph\Aleph\Handler;

use DateTime;
use Drupal\aleph\Aleph\Exception\AlephClientException;
use Drupal\aleph\Aleph\Exception\AlephPatronInvalidPin;
use Drupal\aleph\Aleph\Entity\AlephDebt;
use Drupal\aleph\Aleph\Entity\AlephHoldGroup;
use Drupal\aleph\Aleph\Entity\AlephLoan;
use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Entity\AlephPatron;
use Drupal\aleph\Aleph\AlephClient;
use Drupal\aleph\Aleph\Entity\AlephRequest;
use Drupal\aleph\Aleph\Entity\AlephRequestResponse;
use Drupal\aleph\Aleph\Entity\AlephReservation;
use Drupal\aleph\Aleph\AuthenticationResult;

/**
 * Class AlephPatronHandler.
 *
 * Handles authentication, getting loans, etc. for a patron.
 *
 * @package Drupal\aleph\Aleph\Handler
 */
class AlephPatronHandler extends AlephHandlerBase {

  protected $patron;

  /**
   * AlephPatronHandler constructor.
   *
   * @param \Drupal\aleph\Aleph\AlephClient $client
   *   The Aleph client.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron.
   */
  public function __construct(AlephClient $client, AlephPatron $patron = NULL) {
    parent::__construct($client);
    $this->client = $client;
    $this->patron = $patron;
  }

  /**
   * Get patron by ID.
   *
   * @param string $id
   *   Patron ID, mostly a social security number.
   */
  public function getPatronById($id) {
    $patron = new AlephPatron();
    $patron->setId($id);
    $response = $this->client->borInfo($patron);

    // Temporary workaround.
    // borInfo should be used, when the expiry date bug is fixed in Aleph.
    $credentials = ding_user_get_creds();

    if (!empty($credentials['pass'])) {
      // Sub library is hardcoded in order to show correct expiry date.
      // Most users are active in the BBAAA branch.
      $response_sub_library = $this->client->authenticate($id, $credentials['pass'], 'BBAAA');
    }

    $patron->setName((string) $response->xpath('z303/z303-name')[0]);
    $patron->setEmail((string) $response->xpath('z304/z304-email-address')[0]);
    $patron->setExpiryDate((string) $response->xpath('z305/z305-expiry-date')[0]);
    $patron->setPhoneNumber((string) $response->xpath('z304/z304-telephone')[0]);
    $expiry_date = new DateTime();

    // Temporary workaround.
    // borInfo should be used, when the expiry date bug is fixed in Aleph.
    if (!empty($credentials['pass'])) {
      $expiry_date = $expiry_date::createFromFormat('d/m/Y', (string) $response_sub_library->xpath('z305/z305-expiry-date')[0]);
    }
    else {
      $expiry_date = $expiry_date::createFromFormat('d/m/Y', (string) $response->xpath('z305/z305-expiry-date')[0]);
    }

    $patron->setExpiryDate($expiry_date);
    $patron->setStatus((string) $response->xpath('z305/z305-bor-status')[0]);

    return $patron;
  }

  /**
   * Authenticate user from Aleph.
   *
   * @param string $bor_id
   *   The user ID (z303-id).
   * @param string $verification
   *   The user pin-code/verification code.
   * @param string[] $allowed_login_branches
   *   Allowed login branches.
   *
   * @return \Drupal\aleph\Aleph\AuthenticationResult
   *   The authenticated Aleph patron.
   */
  public function authenticate($bor_id, $verification, array $allowed_login_branches = []) {
    $patron = new AlephPatron();

    if (0 === strpos($bor_id, 'GE')) {
      $patron->setLibraryCardID($bor_id);
      $response = $this->client->borByKey($patron);
      $bor_id = (string) $response->xpath('internal-id')[0];
    }

    $response = $this->client->authenticate($bor_id, $verification);
    // Sub library is hardcoded in order to show correct expiry date.
    // Most users are active in the BBAAA branch.
    $response_sub_library = $this->client->authenticate($bor_id, $verification, 'BBAAA');

    $result = new AuthenticationResult(
      $this->client, $bor_id, $verification, $allowed_login_branches,
      $this->getActiveBranches($bor_id)
    );

    if ($result->isAuthenticated()) {
      $patron->setId($bor_id);
      $patron->setVerification($verification);
      $patron->setName((string) $response->xpath('z303/z303-name')[0]);
      $patron->setEmail((string) $response->xpath('z304/z304-email-address')[0]);
      $expiry_date = new DateTime();
      $expiry_date = $expiry_date::createFromFormat('d/m/Y', (string) $response_sub_library->xpath('z305/z305-expiry-date')[0]);
      $patron->setExpiryDate($expiry_date);
      $patron->setPhoneNumber((string) $response->xpath('z304/z304-telephone')[0]);
      $patron->setStatus((string) $response->xpath('z305/z305-bor-status')[0]);
      $this->setPatron($patron);
      $result->setPatron($patron);
    }

    return $result;
  }

  /**
   * Get patron's loans.
   *
   * @var \SimpleXMLElement[] $loans
   *
   * @return AlephMaterial[]
   *   Array of Aleph Materials.
   */
  public function getLoans() {
    $results = array();
    $loans = $this->client->getLoans($this->getPatron())->xpath('loans/institution/loan');
    foreach ($loans as $loan) {
      $material = AlephMaterial::materialFromItem($loan);
      $results[] = $material;
    }
    return $results;
  }

  /**
   * Change patron's pin code.
   *
   * @param string $pin
   *   The new pin code.
   *
   * @return bool
   *   True if setting new pincode succeeded.
   */
  public function setPin($pin) {
    try {
      return $this->client->changePin($this->getPatron(), $pin);
    }
    catch (AlephPatronInvalidPin $e) {
      watchdog_exception('aleph', $e);
      return FALSE;
    }
  }

  /**
   * Set the Aleph patron object.
   *
   * @param AlephPatron $patron
   *   The Aleph patron.
   */
  public function setPatron(AlephPatron $patron) {
    $this->patron = $patron;
  }

  /**
   * Get the Aleph patron object.
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephPatron
   *   The Aleph patron object.
   */
  public function getPatron() {
    return $this->patron;
  }

  /**
   * Get patron debts.
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephDebt[]
   *   Array of AlephDebt objects.
   */
  public function getDebts() {
    $xml = $this->client->getDebts($this->getPatron());
    $debts = new AlephDebt();
    return $debts::debtsFromCashApi($xml);
  }

  /**
   * Create patron payment.
   *
   * @param int $amount
   *   The amount of the payment.
   * @param string $reference
   *   Transaction id or other reference to the payment.
   *
   * @return bool
   *   Whether the payments was registered.
   */
  public function addPayment($amount, $reference) {
    $response = $this->client->addPayment($this->getPatron(), $amount, $reference);

    if ((string) $response->xpath('reply-code')[0] === '0000') {
      return TRUE;
    }

    return FALSE;
  }

  /**
   * Get a patron's reservations.
   *
   * @return AlephReservation[]
   *   Array of Aleph reservation objects.
   */
  public function getReservations() {
    $reservations = array();
    $hold_requests = $this->client->getReservations($this->getPatron())->xpath('hold-requests/institution/hold-request');
    foreach ($hold_requests as $hold_request) {
      if ((string) $hold_request->xpath('z37/z37-request-type')[0] === 'Hold Request') {
        $reservation = new AlephReservation();
        $request = new AlephRequest();
        $material = new AlephMaterial();

        $end_request_date = (string) $hold_request->xpath('z37/z37-end-request-date')[0];

        $request->setStatus((string) $hold_request->xpath('z37/z37-status')[0]);
        $request->setPickupLocation((string) $hold_request->xpath('z37/z37-pickup-location')[0]);
        $request->setOpenDate((string) $hold_request->xpath('z37/z37-open-date')[0]);
        $request->setEndRequestDate(DateTime::createFromFormat(ALEPH_DATE_FORMAT,
          $end_request_date));
        $request->setDocNumber((string) $hold_request->xpath('z37/z37-doc-number')[0]);
        $request->setHoldDate((string) $hold_request->xpath('z37/z37-hold-date')[0]);
        $request->setRequestNumber((string) $hold_request->xpath('z37/z37-request-number')[0]);
        $request->setSequence((string) $hold_request->xpath('z37/z37-sequence')[0]);
        $request->setInstitutionCode((string) $hold_request->xpath('z37/translate-change-active-library')[0]);
        $request->setItemSequence((string) $hold_request->xpath('z37/z37-item-sequence')[0]);

        $material->setTitle((string) $hold_request->xpath('z13/z13-title')[0]);
        $material->setId((string) $hold_request->xpath('z13/z13-doc-number')[0]);
        $material->setSubLibraryCode((string) $hold_request->xpath('z30-sub-library-code')[0]);

        $reservation->setItem($material);
        $reservation->setRequest($request);

        $reservations[$reservation->getItem()->getId()] = $reservation;
      }
    }
    return $reservations;
  }

  /**
   * Renew a patron's loans.
   *
   * @param array $ids
   *   The ID's to renew.
   *
   * @return AlephLoan[]
   *   Array of AlephLoan objects.
   */
  public function renewLoans(array $ids) {
    $response = $this->client->renewLoans($this->getPatron(), $ids);
    $loans = $response->xpath('renewals/institution/loan');
    $renewed_loans = array();

    foreach ($loans as $loan) {
      $loan_details = $this->client->getLoans(
        $this->getPatron(), (string) $loan['id'][0]
      );

      $renewed_loan = new AlephLoan();
      $renewed_loan->setLoanId((string) $loan['id'][0]);
      $renewed_loan->setStatusCode((string) $loan->xpath('status-code')[0]);
      $renewed_loan->setDocNumber((string) $loan_details->xpath('loan/z36/z36-doc-number')[0]);

      if (in_array($renewed_loan->getDocNumber(), $ids, TRUE)) {
        $renewed_loans[$renewed_loan->getDocNumber()] = $renewed_loan;
      }
    }

    return $renewed_loans;
  }

  /**
   * Create a reservation for a patron.
   *
   * @param AlephPatron $patron
   *   The Aleph patron object.
   *
   * @param AlephReservation $reservation
   *   The Aleph reservation object.
   *
   * @param AlephHoldGroup[] $holding_groups
   *   The holding groups.
   *
   * @return AlephRequestResponse
   *   The AlephRequestResponse object.
   */
  public function createReservation($patron, $reservation, $holding_groups) {
    $response = $this->client->createReservation(
      $patron, $reservation->getRequest(), $holding_groups
    );
    return AlephRequestResponse::createRequestResponseFromXML($response);
  }

  /**
   * Delete a reservation.
   *
   * @param AlephPatron $patron
   *   The Aleph patron object.
   * @param AlephReservation $reservation
   *   The Aleph reservation object.
   *
   * @return AlephRequestResponse
   *   The AlephRequestResponse object.
   */
  public function deleteReservation($patron, $reservation) {
    $response = $this->client->deleteReservation($patron,
      $reservation->getRequest());

    return AlephRequestResponse::createRequestResponseFromXML($response);
  }

  /**
   * Get the holding groups.
   *
   * Holding groups are groups items for each sub library based on material ID.
   *
   * @param AlephPatron $patron
   *   The AlephPatron object.
   *
   * @param AlephMaterial $material
   *   The AlephMaterial object.
   *
   * @return AlephHoldGroup[]
   *   Array of Aleph hold groups.
   */
  public function getHoldingGroups($patron, $material) {
    $xml_groups = $this->client->getHoldingGroups($patron, $material);
    $groups = array_map(function(\SimpleXMLElement $group) {
      return AlephHoldGroup::createHoldGroupFromXML($group);
    }, $xml_groups);

    $allowed_branches = aleph_get_branches();
    return array_filter($groups, function(AlephHoldGroup $group) use ($allowed_branches) {
      return array_key_exists($group->getSubLibraryCode(), $allowed_branches);
    });
  }

  /**
   * Get the branches where the patron is active.
   *
   * @param string $bor_id
   *   The Aleph patron ID.
   *
   * @return string[]
   *   Array with branches the use is active in.
   */
  public function getActiveBranches($bor_id) {
    $branches = $this->client->getPatronBlocks($bor_id)->xpath('blocks_messages/institution/sublibrary/@code');
    return array_map('strval', $branches);
  }

  /**
   * {@inheritdoc}
   */
  protected function getIdentity() {
    return 'AlephPatronHandler';
  }

}
