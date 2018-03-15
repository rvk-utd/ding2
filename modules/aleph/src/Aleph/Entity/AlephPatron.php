<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * @file
 * Provides the AlephPatron.
 */

/**
 * Class AlephPatron.
 *
 * This entity describes the Aleph patron and provides basic information about
 * the patron.
 */
class AlephPatron {

  protected $borId;
  protected $name;
  protected $verification;
  protected $email;
  protected $phoneNumber;
  protected $expiryDate;
  protected $libraryCardID;

  /**
   * Return the patron's name.
   *
   * @return string
   *    The patron's name.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Set the patron's name.
   *
   * @param string $name
   *    The patron's name.
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * Returns the patron's ID.
   *
   * @return string
   *    The bor_id.
   */
  public function getId() {
    return $this->borId;
  }

  /**
   * Set the patron's ID.
   *
   * @param string $bor_id
   *    The patron's ID.
   */
  public function setId($bor_id) {
    $this->borId = $bor_id;
  }

  /**
   * Get the verification code.
   *
   * @return string
   *    The pin/verification code.
   */
  public function getVerification() {
    return $this->verification;
  }

  /**
   * Set verification for patron.
   *
   * @param string $verification
   *    The patron's pin code.
   */
  public function setVerification($verification) {
    $this->verification = $verification;
  }

  /**
   * Set the patrons email.
   *
   * @param string $email
   *    Patrons email address.
   */
  public function setEmail($email) {
    $this->email = $email;
  }

  /**
   * Get the patrons email.
   *
   * @return string
   */
  public function getEmail() {
    return $this->email;
  }

  /**
   * Get the patrons phone number.
   *
   * @return string
   *    The patrons phone number.
   */
  public function getPhoneNumber() {
    return $this->phoneNumber;
  }

  /**
   * Set the patron phone number.
   *
   * @param string $phoneNumber
   *    The patrons phone number.
   */
  public function setPhoneNumber($phoneNumber) {
    $this->phoneNumber = $phoneNumber;
  }

  /**
   * Get the user expiry date.
   *
   * @return string
   */
  public function getExpiryDate() {
    return $this->expiryDate;
  }

  /**
   * Set the expiry date.
   *
   * @param string $expiryDate
   *    Patron expiry date in Aleph.
   */
  public function setExpiryDate($expiryDate) {
    $this->expiryDate = $expiryDate;
  }

  /**
   * Get the library card ID.
   */
  public function getLibraryCardID() {
    return $this->libraryCardID;
  }

  /**
   * Set the library card ID.
   *
   * @param string $libraryCardID
   *   The library card ID.
   */
  public function setLibraryCardID($libraryCardID) {
    $this->libraryCardID = $libraryCardID;
  }
}
