<?php

namespace Drupal\aleph\Aleph;

/**
 * @file
 * Provides a client for the Aleph library information webservice.
 */

use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Entity\AlephPatron;
use Drupal\aleph\Aleph\Entity\AlephRequest;
use Drupal\aleph\Aleph\Entity\AlephRequestResponse;
use Drupal\aleph\Aleph\Exception\AlephClientException;
use Drupal\aleph\Aleph\Exception\AlephPatronInvalidPin;
use GuzzleHttp\Client;

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
   * @var string
   */
  protected $baseUrlRest;

  /**
   * The primary library, ICE01 for example.
   * @var string
   */
  protected $mainLibrary;

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
   * @param $base_url_rest
   *    The base url for the Aleph REST end-point.
   *
   * @param $main_library
   *    The main library. For example ICE01.
   *
   * @param $filter_institution
   *    The institution filter to set. ICE53 for example.
   */
  public function __construct($base_url, $base_url_rest, $main_library, $filter_institution) {
    $this->baseUrl = $base_url;
    $this->baseUrlRest = $base_url_rest;
    $this->mainLibrary = $main_library;
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
        'library' => 'ICE53',
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
   *    The method to use, like post, get, put, etc.
   * @param string $url
   *    The URL the send the request to.
   * @param array $options
   *    The options to send via GuzzleHttp.
   *
   * @return \SimpleXMLElement
   *    The returned XML from Aleph.
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
   *
   * @return \SimpleXMLElement
   *   The authentication response from Aleph or error message.
   *
   * @throws AlephClientException
   */
  public function authenticate($bor_id, $verification) {
    $response = $this->request('GET', 'bor-auth', array(
      'bor_id' => $bor_id,
      'verification' => $verification,
    ));

    return $response;
  }

  /**
   * Get information about the patron.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *    The Aleph Patron.
   *
   * @return \SimpleXMLElement
   *    The response from Aleph.
   *
   * @throws AlephClientException
   */
  public function borInfo(AlephPatron $patron) {
    $response = $this->request('GET', 'bor-info', array(
      'bor_id' => $patron->getId(),
      'verification' => $patron->getVerification(),
    ));

    return $response;
  }

  /**
   * Change the patrons pin code.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *    The Aleph patron.
   * @param string $new_pin
   *    The new pin code.
   *
   * @return bool
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
   *    The Aleph patron to get debts from.
   *
   * @return \SimpleXMLElement
   *    The SimpleXMLElement response from Aleph.
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
   * @param \Drupal\aleph\Aleph\Entity\AlephMaterial $material
   *    The Aleph material to get items from.
   *
   * @return \SimpleXMLElement The SimpleXMLElement response from Aleph.
   *    The SimpleXMLElement response from Aleph.
   *
   * @throws AlephClientException
   */
  public function getItems(AlephMaterial $material) {
    return $this->requestRest(
      'GET',
      'record/' . $this->mainLibrary . $material->getId() . '/items?view=full'
    );
  }

  /**
   * Get patron's loans.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The patron to get loans from.
   *
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
   *
   * @return \SimpleXMLElement
   *    The response from Aleph.
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
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *   The Aleph patron.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephRequest $request
   *   The request information.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephHoldGroup[] $holding_groups
   *   The holding groups.
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

    $rid = $this->mainLibrary . $request->getDocNumber();

    // Try to make the reservation against each holding group.
    // If the reservation is OK, the reply code is '0000' and we stop.
    foreach ($holding_groups as $holding_group) {
      $response = $this->requestRest(
        'PUT',
        'patron/' . $patron->getId() . '/record/' . $rid . '/holds/' .
        basename($holding_group->getUrl()),
        $options
      );

      if ((string) $response->xpath('reply-code')[0] === '0000') {
        return $response;
      }
    }

    return $response;
  }

  /**
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   * @param array $ids
   *
   * @return \SimpleXMLElement
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
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron  $patron
   * @param \Drupal\aleph\Aleph\Entity\AlephRequest $request
   *
   * @return \SimpleXMLElement
   * @throws AlephClientException
   */
  public function deleteReservation(AlephPatron $patron, AlephRequest
  $request) {
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
   *    The Aleph patron ID.
   *
   * @return \SimpleXMLElement
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
      'patron/' . $patron->getId() . '/record/' . $this->mainLibrary .
      $material->getId() . '/holds?view=full'
    )->xpath('hold/institution/group');
  }

}
