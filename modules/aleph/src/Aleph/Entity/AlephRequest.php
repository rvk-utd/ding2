<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * Class AlephRequest.
 *
 * Entity with setters/getters for requests in Aleph.
 *
 * Contains requests information.
 *
 * https://www.obvsg.at/uploads/media/Z37.pdf
 *
 * @package Drupal\aleph\Aleph
 */
class AlephRequest {

  /**
   * Hold request status.
   *
   * @var string
   */
  protected $status;

  /**
   * Item sequence number.
   * The number is within one ADM number.
   *
   * @var string
   */
  protected $itemSequence;

  /**
   * Sequence number of a request.
   * Used to distinguish between multiple requests placed on the same item.
   *
   * @var string
   */
  protected $sequence;

  /**
   * Patron’s ID.
   *
   * @var string
   */
  protected $id;

  /**
   * Patron’s pickup sub-library.
   *
   * @var string
   */
  protected $pickupLocation;

  /**
   * Sub-library code.
   *
   * @var string
   * @example BBAAA
   */
  protected $subLibraryCode;

  /**
   * The type of request.
   * For example 'Hold Request'.
   *
   * @var string
   */
  protected $requestType;

  /**
   * The starting date of the period of time during which the patron is
   * interested in receiving the material.
   *
   * @var string
   * Format YYYYMMDD.
   */
  protected $requestDate;

  /**
   * Last date of interest for the hold request.
   *
   * @var \DateTime
   */
  protected $endRequestDate;


  /**
   * Date the item was requested.
   *
   * @var string
   * Format YYYYMMDD.
   */
  protected $openDate;

  /**
   * System number of the administrative record associated to the request.
   *
   * @var string
   */
  protected $docNumber;

  /**
   * The date on which a letter was sent to the patron informing him that the
   * requested material is ready to be picked up.
   * These requests have status "S".
   *
   * @var string
   */
  protected $holdDate;

  /**
   * The request number.
   *
   * @var string
   */
  protected $requestNumber;

  /**
   * The institution code.
   *
   * @var string
   * For example 'ICE53'.
   */
  protected $institutionCode;

  /**
   * Array of URLs to hold groups.
   *
   * @var string[]
   * For example:
   * http://<server>/rest-dlf/patron/<patron_id>/record/ICE01000335901/holds/ICE53000335901001570
   */
  protected $holdGroupURLs;

  /**
   * Set the status message.
   *
   * @param string $status
   *    The status.
   */
  public function setStatus($status) {
    $this->status = $status;
  }

  /**
   * Get the status message.
   *
   * @return string
   *    The status.
   */
  public function getStatus() {
    return $this->status;
  }

  /**
   * Set the item sequence number.
   *
   * @param string $item_sequence
   *    The item sequence number.
   */
  public function setItemSequence($item_sequence) {
    $this->itemSequence = $item_sequence;
  }

  /**
   * Get the item sequence number.
   *
   * @return string
   *    The item sequence number.
   */
  public function getItemSequence() {
    return $this->itemSequence;
  }

  /**
   * Set the sequence number.
   *
   * @param string $sequence
   */
  public function setSequence($sequence) {
    $this->sequence = $sequence;
  }

  /**
   * Get the sequence number.
   *
   * @return string
   */
  public function getSequence() {
    return $this->sequence;
  }

  /**
   * Set the id.
   *
   * @param string $id
   */
  public function setId($id) {
    $this->id = $id;
  }

  /**
   * Get the id.
   *
   * @return string
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Set the pickup location.
   *
   * @param string $pickup_location
   */
  public function setPickupLocation($pickup_location) {
    $this->pickupLocation = $pickup_location;
  }

  /**
   * Get the pickup location.
   *
   * @return string
   */
  public function getPickupLocation() {
    return $this->pickupLocation;
  }

  /**
   * Set the filter sub-library.
   *
   * @param $sub_library_code
   */
  public function setSubLibraryCode($sub_library_code) {
    $this->subLibraryCode = $sub_library_code;
  }

  /**
   * Get the filter sub-library.
   *
   * @return string
   */
  public function getSubLibraryCode() {
    return $this->subLibraryCode;
  }

  /**
   * Set the request type.
   *
   * @param $request_type
   */
  public function setRequestType($request_type) {
    $this->requestType = $request_type;
  }

  /**
   * Get the request type.
   *
   * @return string
   */
  public function getRequestType() {
    return $this->requestType;
  }

  /**
   * Set the request date.
   *
   * @param \DateTimeInterface $request_date
   */
  public function setRequestDate(\DateTimeInterface $request_date) {
    $this->requestDate = $request_date->format(ALEPH_DATE_FORMAT);
  }

  /**
   * Get the request date.
   *
   * @return string
   */
  public function getRequestDate() {
    return $this->requestDate;
  }

  /**
   * Set the end request date.
   *
   * @param \DateTimeInterface $end_request_date
   */
  public function setEndRequestDate(\DateTimeInterface $end_request_date) {
    $this->endRequestDate = $end_request_date->format(ALEPH_DATE_FORMAT);
  }

  /**
   * Get the end request date.
   *
   * @return string
   */
  public function getEndRequestDate() {
    return $this->endRequestDate;
  }

  /**
   * Set the open date.
   *
   * @param string $open_date
   */
  public function setOpenDate($open_date) {
    $this->openDate = $open_date;
  }

  /**
   * Get the open date.
   *
   * @return string
   */
  public function getOpenDate() {
    return $this->openDate;
  }

  /**
   * Set the doc number.
   *
   * @param string $doc_number
   */
  public function setDocNumber($doc_number) {
    $this->docNumber = $doc_number;
  }

  /**
   * Get the doc number.
   *
   * @return string
   *    The doc number.
   */
  public function getDocNumber() {
    return $this->docNumber;
  }

  /**
   * Set the hold date.
   *
   * @param string $hold_date
   *    The hold date.
   */
  public function setHoldDate($hold_date) {
    $this->holdDate = $hold_date;
  }

  /**
   * @return string
   *    The hold date.
   */
  public function getHoldDate() {
    return $this->holdDate;
  }

  /**
   * Set the request number.
   *
   * @param string $request_number
   *    The request number.
   */
  public function setRequestNumber($request_number) {
    $this->requestNumber = $request_number;
  }

  /**
   * Get the request number.
   *
   * @return string
   *    The request number.
   */
  public function getRequestNumber() {
    return $this->requestNumber;
  }

  /**
   * Set the institution code.
   *
   * @param string $institutionCode
   */
  public function setInstitutionCode($institutionCode) {
    $this->institutionCode = $institutionCode;
  }

  /**
   * Get the institution code.
   *
   * @return string
   *    The institution code.
   */
  public function getInstitutionCode() {
    return $this->institutionCode;
  }

  /**
   * Get hold group URLs.
   *
   * @return string[]
   *  The hold group URLs.
   */
  public function getHoldGroupURLs() {
    return $this->holdGroupURLs;
  }

  /**
   * Set the hold group URLs.
   *
   * @param string[] $holdGroupURLs
   *    The hold group URLs.
   */
  public function setHoldGroupURLs(array $holdGroupURLs) {
    $this->holdGroupURLs = $holdGroupURLs;
  }

}
