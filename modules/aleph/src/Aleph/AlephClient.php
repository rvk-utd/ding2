<?php

namespace Drupal\aleph\Aleph;

/**
 * @file
 * Provides a client for the Aleph library information webservice.
 */

use DateTime;
use SimpleXMLElement;
use GuzzleHttp\Client;
use Drupal\aleph\Aleph\Entity\AlephPatron;
use Drupal\aleph\Aleph\Entity\AlephRequest;
use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Entity\AlephRequestResponse;
use Drupal\aleph\Aleph\Exception\AlephClientException;
use Drupal\aleph\Aleph\Exception\AlephPatronInvalidPin;

/**
 * Implements the AlephClient class.
 */
class AlephClient {
  /**
   * The base URL for the X service.
   *
   * @var string
   */
  protected $baseUrl;

  /**
   * The base URL for the REST service.
   *
   * @var string
   */
  protected $baseUrlRest;

  /**
   * The catalog library, ICE01 for example.
   *
   * @var string
   */
  protected $catalogLibrary;

  /**
   * The item library, ICE53 for example.
   *
   * @var string
   */
  protected $itemLibrary;

  /**
   * The GuzzleHttp Client.
   *
   * @var \GuzzleHttp\Client
   */
  protected $client;

  /**
   * Constructor, checking if we have a sensible value for $base_url.
   *
   * @param string $base_url
   *   The base url for the Aleph end-point.
   * @param string $base_url_rest
   *   The base url for the Aleph REST end-point.
   * @param string $catalog_library
   *   The catalog library. For example ICE01.
   * @param string $item_library
   *   The item library. ICE53 for example.
   */
  public function __construct($base_url, $base_url_rest, $catalog_library, $item_library) {
    $this->baseUrl = $base_url;
    $this->baseUrlRest = $base_url_rest;
    $this->catalogLibrary = $catalog_library;
    $this->itemLibrary = $item_library;
    $this->client = new Client();
  }

  /**
   * Perform request to the Aleph server.
   *
   * @param string $method
   *   The query method (GET, POST, etc.).
   * @param string $operation
   *   The operation to run in Aleph.
   * @param array $params
   *   The extra query parameters to send.
   *
   * @return \SimpleXMLElement
   *   A SimpleXMLElement object.
   *
   * @throws AlephClientException
   */
  public function request($method, $operation, array $params = array()) {
    $options = array(
      'query' => array(
        'op' => $operation,
        'library' => $this->itemLibrary,
      ) + $params,
      'allow_redirects' => FALSE,
    );

    // Send the request.
    $response = $this->client->request($method, $this->baseUrl, $options);

    // Status from Aleph is OK.
    if ($response->getStatusCode() === 200) {
      return new \SimpleXMLElement($response->getBody());
    }

    // Throw exception if the status from Aleph is not OK.
    throw new AlephClientException($response->error, $response->code);
  }

  /**
   * Send a request via the REST service.
   *
   * @param string $method
   *   The method to use, like post, get, put, etc.
   * @param string $url
   *   The URL the send the request to.
   * @param array $options
   *   The options to send via GuzzleHttp.
   *
   * @return \SimpleXMLElement
   *   The returned XML from Aleph.
   *
   * @throws AlephClientException
   */
  public function requestRest($method, $url, array $options = array()) {
    $response = $this->client->request(
      $method, $this->baseUrlRest . '/' . $url,
      $options
    );
    // Status from Aleph is OK.
    if ($response->getStatusCode() === 200) {
      return new \SimpleXMLElement($response->getBody());
    }

    // Throw exception if the status from Aleph is not OK.
    throw new AlephClientException($response->error, $response->code);
  }

  /**
   * Authenticate the patron.
   *
   * @param string $bor_id
   *   Patron ID.
   * @param string $verification
   *   Patron PIN.
   * @param string $sub_library
   *   The branch/sublibrary to authenticate against.
   *
   * @return \SimpleXMLElement
   *   The authentication response from Aleph or error message.
   *
   * @throws AlephClientException
   */
  public function authenticate($bor_id, $verification, $sub_library = '') {
    if (!empty($sub_library)) {
      return $this->request('GET', 'bor-auth', array(
        'bor_id' => $bor_id,
        'verification' => $verification,
        'sub_library' => $sub_library,
      ));
    }

    return $this->request('GET', 'bor-auth', array(
      'bor_id' => $bor_id,
      'verification' => $verification,
    ));
  }

  /**
   * Get information about the patron.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph Patron.
   * @param bool $extended
   *   Return Z304 and Z308 records too.
   *
   * @return \SimpleXMLElement
   *   The response from Aleph.
   *
   * @throws AlephClientException
   */
  public function borInfo(AlephPatron $patron, $extended = FALSE) {
    $args = array(
      'bor_id' => $patron->getId(),
    );
    if ($extended) {
      $args['format'] = 1;
    }
    $response = $this->request('GET', 'bor-info', $args);

    return $response;
  }

  /**
   * Change the patrons pin code.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron.
   * @param string $new_pin
   *   The new pin code.
   *
   * @return bool
   *   True if pin code was changed.
   *
   * @throws AlephClientException
   * @throws AlephPatronInvalidPin
   */
  public function changePin(AlephPatron $patron, $new_pin) {
    $options = array();

    $xml = new \SimpleXMLElement('<get-pat-pswd></get-pat-pswd>');
    $password_parameters = $xml->addChild('password_parameters');
    $password_parameters->addChild('old-password', $patron->getVerification());
    $password_parameters->addChild('new-password', $new_pin);

    $options['body'] = 'post_xml=' . $xml->asXML();

    $response = AlephRequestResponse::createRequestResponseFromXML($this->requestRest(
      'POST',
      'patron/' . $patron->getId() . '/patronInformation/password',
      $options
    ));

    if ($response->success()) {
      return TRUE;
    }

    throw new AlephPatronInvalidPin($response->getReplyText() . ': ' . $response->getNote());
  }

  /**
   * Get patrons debts.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron to get debts from.
   *
   * @return \SimpleXMLElement
   *   The SimpleXMLElement response from Aleph.
   *
   * @throws AlephClientException
   */
  public function getDebts(AlephPatron $patron) {
    return $this->requestRest(
      'GET',
      'patron/' . $patron->getId() . '/circulationActions/cash?view=full'
    );
  }

  /**
   * Get the items for a Material.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephMaterial $material
   *   The Aleph material to get items from.
   *
   * @return \SimpleXMLElement
   *   The SimpleXMLElement response from Aleph.
   *
   * @throws AlephClientException
   */
  public function getItems(AlephMaterial $material) {
    return $this->requestRest(
      'GET',
      'record/' . $this->catalogLibrary . $material->getId() . '/items?view=full'
    );
  }

  /**
   * Create payment.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron.
   * @param int $sum
   *   Amount paid.
   * @param string $reference
   *   Identification of the payment.
   *
   * @return \SimpleXMLElement
   *   The SimpleXMLElement from the raw XML response.
   *
   * @throws AlephClientException
   */
  public function addPayment(AlephPatron $patron, $sum, $reference) {
    $options = array(
      'query' => array('institution' => $this->itemLibrary),
    );

    $xml = new \SimpleXMLElement('<pay-cash-parameters></pay-cash-parameters>');
    $xml->addChild('sum', $sum);
    $xml->addChild('pay-reference', $reference);
    $options['body'] = 'post_xml=' . $xml->asXML();

    return $this->requestRest(
      'PUT',
      'patron/' . $patron->getId() . '/circulationActions/cash',
      $options
    );
  }

  /**
   * Get patron's loans.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The patron to get loans from.
   * @param string|false $loan_id
   *   The loan ID to get specific loan.
   *
   * @return \SimpleXMLElement
   *   The response from Aleph.
   *
   * @throws AlephClientException
   */
  public function getLoans(AlephPatron $patron, $loan_id = FALSE) {
    if ($loan_id) {
      return $this->requestRest(
        'GET',
        'patron/' . $patron->getId() . '/circulationActions/loans/' . $loan_id
      );
    }

    return $this->requestRest(
      'GET',
      'patron/' . $patron->getId() . '/circulationActions/loans?view=full'
    );
  }

  /**
   * Get a patron's reservations.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   Patron to get reservations for.
   *
   * @return \SimpleXMLElement
   *   The response from Aleph.
   *
   * @throws AlephClientException
   */
  public function getReservations(AlephPatron $patron) {
    return $this->requestRest(
      'GET',
      'patron/' . $patron->getId() . '/circulationActions/requests/holds?view=full'
    );
  }

  /**
   * Create a reservation.
   *
   * As Aleph reservations aren't on the material level, but on the item level,
   * this tries to reserve individual items until it succeeds. It gives
   * preference to items located at the pickup branch.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The patron to reserve for.
   * @param \Drupal\aleph\Aleph\Entity\AlephRequest $request
   *   The reserve request information.
   * @param \Drupal\aleph\Aleph\Entity\AlephHoldGroup[] $holding_groups
   *   The holding groups for the material.
   *
   * @return \SimpleXMLElement|false
   *   The SimpleXMLElement from the raw XML response.
   *
   * @throws AlephClientException
   */
  public function createReservation(AlephPatron $patron, AlephRequest $request, array $holding_groups) {
    $options = array();
    $response = FALSE;

    $xml = new \SimpleXMLElement('<hold-request-parameters></hold-request-parameters>');
    $xml->addChild('pickup-location', $request->getPickupLocation());
    $xml->addChild('start-interest-date', $request->getRequestDate());
    $xml->addChild('last-interest-date', $request->getEndRequestDate());

    $options['body'] = 'post_xml=' . $xml->asXML();

    $rid = $this->catalogLibrary . $request->getDocNumber();

    // Sort holdings into "preferred" (same sub-library as pickup library) and
    // the rest.
    $groups = array(array(), array());
    foreach ($holding_groups as $holding_group) {
      $is_preferred = (int) $holding_group->getSubLibraryCode() == $request->getSubLibraryCode();
      $groups[$is_preferred][] = $holding_group;
    }
    // Flatten the array. This moves the items in the pickup library to the
    // start of of the list, so we can just iterate over it and return when one
    // succeeds.
    $groups = array_merge($groups[1], $groups[0]);

    // Try to make the reservation against the selected group.
    foreach ($groups as $holding_group) {
      $response = $this->requestRest(
        'PUT',
        'patron/' . $patron->getId() . '/record/' . $rid . '/holds/' .
        basename($holding_group->getUrl()),
        $options
      );

      // If the reservation is OK, the reply code is '0000' and we stop.
      if ((string) $response->xpath('reply-code')[0] === '0000') {
        return $response;
      }
    }

    return FALSE;
  }

  /**
   * Renew patron loans.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The patron.
   * @param array $ids
   *   Loan ids to renew.
   *
   * @return \SimpleXMLElement
   *   The response.
   *
   * @throws AlephClientException
   */
  public function renewLoans(AlephPatron $patron, array $ids) {
    $options = array();

    $xml = new \SimpleXMLElement('<get-pat-loan></get-pat-loan>');

    foreach ($ids as $id) {
      $loan = $xml->addChild('loan');
      $loan->addAttribute('renew', 'Y');
      $z36 = $loan->addChild('z36');
      $z36->addChild('z36-doc-number', $id);
    }

    $options['body'] = 'post_xml=' . $xml->asXML();

    return $this->requestRest(
      'POST',
      'patron/' . $patron->getId() . '/circulationActions/loans',
      $options
    );
  }

  /**
   * Delete reservations.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The patron.
   * @param \Drupal\aleph\Aleph\Entity\AlephRequest $request
   *   The reservation to delete.
   *
   * @return \SimpleXMLElement
   *   The response.
   *
   * @throws AlephClientException
   */
  public function deleteReservation(AlephPatron $patron, AlephRequest $request) {
    // ADM library code + the item record key.
    // For example, USM50000238843000320.
    $iid = $request->getInstitutionCode() . $request->getDocNumber() .
      $request->getItemSequence() . $request->getSequence();

    return $this->requestRest(
      'DELETE',
      'patron/' . $patron->getId() . "/circulationActions/requests/holds/$iid"
    );
  }

  /**
   * Get information about the institutions and branches from the patron ID.
   *
   * @param string $bor_id
   *   The Aleph patron ID.
   *
   * @return \SimpleXMLElement
   *   The response.
   *
   * @throws AlephClientException
   */
  public function getPatronBlocks($bor_id) {
    return $this->requestRest('GET', 'patron/' . $bor_id . '/patronStatus/blocks');
  }

  /**
   * Get holding groups.
   *
   * Holding groups are used to make reservations from the material ID.
   * There's one for each library and it contains information about items
   * from the library.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron.
   * @param \Drupal\aleph\Aleph\Entity\AlephMaterial $material
   *   The Aleph material.
   *
   * @return \SimpleXMLElement[]
   *   XML response from Aleph with holding groups.
   *
   * @throws AlephClientException
   */
  public function getHoldingGroups(AlephPatron $patron, AlephMaterial $material) {
    return $this->requestRest(
      'GET',
      'patron/' . $patron->getId() . '/record/' . $this->catalogLibrary .
      $material->getId() . '/holds?view=full'
    )->xpath('hold/institution/group');
  }

  /**
   * Get patron ID from library card ID.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph Patron.
   *
   * @return \SimpleXMLElement
   *   The response from Aleph.
   *
   * @throws AlephClientException
   */
  public function borByKey(AlephPatron $patron) {
    $response = $this->request('GET', 'bor-by-key', array(
      'bor_id' => $patron->getLibraryCardID(),
    ));

    return $response;
  }

  /**
   * Set the patron expiry date.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Patron.
   * @param \DateTime $expiryDate
   *   The expiry date.
   *
   * @return \SimpleXMLElement
   *   A SimpleXMLElement object.
   */
  public function setExpiryDate(AlephPatron $patron, DateTime $expiryDate) {
    $aleph_path = drupal_get_path('module', 'aleph');
    $xml = simplexml_load_file($aleph_path . '/xml/update-bor.xml');
    $patronRecord = $xml->xpath('patron-record')[0];

    $z303 = $patronRecord->xpath('z303')[0];
    $z303->addChild('match-id', $patron->getId());
    $z303->addChild('z303-id', $patron->getId());

    $z305 = $patronRecord->addChild('z305');
    // Tell Aleph that we want to update the record.
    $z305->addChild('record-action', $expiryDate->format('U'));
    $z305->addChild('z305-id', $patron->getId());
    // The sub library where memberships are actually registered.
    $z305->addChild('z305-sub-library', 'BBAAA');
    $z305->addChild('z305-expiry-date', $expiryDate->format('Ymd'));
    $parameters = array(
      'library' => $this->itemLibrary,
      'update_flag' => 'Y',
      'xml_full_req' => $xml->asXML(),
    );
    return $this->request('GET', 'update-bor', $parameters);
  }

  /**
   * Register patron as a new member.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Patron.
   * @param \DateTime $expiryDate
   *   The expiry date.
   *
   * @return \SimpleXMLElement
   *   A SimpleXMLElement object.
   */
  public function setMember(AlephPatron $patron, DateTime $expiryDate) {
    $current_date = new DateTime('now');

    $aleph_path = drupal_get_path('module', 'aleph');
    $xml = simplexml_load_file($aleph_path . '/xml/update-bor.xml');
    $patronRecord = $xml->xpath('patron-record')[0];

    $z303 = $patronRecord->xpath('z303')[0];
    $z303->addChild('match-id', $patron->getId());
    $z303->addChild('z303-id', $patron->getId());

    $z305 = $patronRecord->addChild('z305');
    // Tell Aleph that we want to insert a new record.
    $z305->addChild('record-action', $expiryDate->format('A'));
    $z305->addChild('z305-id', $patron->getId());
    // The sub library where memberships are actually registered.
    $z305->addChild('z305-sub-library', 'BBAAA');
    // Data needed for creation.
    $z305->addChild('z305-open-date', $current_date->format('Ymd'));
    $z305->addChild('z305-update-date', $current_date->format('Ymd'));
    $z305->addChild('z305-bor-status', '01');
    $z305->addChild('z305-registration-date', '00000000');
    $z305->addChild('z305-expiry-date', $expiryDate->format('Ymd'));
    $z305->addChild('z305-note', '');
    $z305->addChild('z305-loan-permission', 'Y');
    $z305->addChild('z305-photo-permission', 'Y');
    $z305->addChild('z305-over-permission', 'Y');
    $z305->addChild('z305-loan-check', 'Y');
    $z305->addChild('z305-hold-permission', 'Y');
    $z305->addChild('z305-renew-permission', 'Y');
    $z305->addChild('z305-rr-permission', 'Y');
    $z305->addChild('z305-cash-limit', '2000.00');
    $z305->addChild('z305-sum', '0.00');
    $z305->addChild('z305-delinq-1', '00');
    $z305->addChild('z305-delinq-n-1', '');
    $z305->addChild('z305-delinq-1-update-date', $current_date->format('Ymd'));
    $z305->addChild('z305-delinq-1-cat-name', 'BBSUTLOF1');
    $z305->addChild('z305-delinq-2', '00');
    $z305->addChild('z305-delinq-n-2', '');
    $z305->addChild('z305-delinq-2-update-date', $current_date->format('Ymd'));
    $z305->addChild('z305-delinq-2-cat-name', 'BBSUTLOF1');
    $z305->addChild('z305-delinq-3', '00');
    $z305->addChild('z305-delinq-n-3', '');
    $z305->addChild('z305-delinq-3-update-date', $current_date->format('Ymd'));
    $z305->addChild('z305-delinq-3-cat-name', 'BBSUTLOF1');
    $z305->addChild('z305-hold-on-shelf', 'Y');
    $z305->addChild('z305-upd-time-stamp', $current_date->format('Ymd'));

    $parameters = array(
      'library' => $this->itemLibrary,
      'update_flag' => 'Y',
      'xml_full_req' => $xml->asXML(),
    );
    return $this->request('GET', 'update-bor', $parameters);

  }

}
