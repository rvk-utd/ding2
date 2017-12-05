<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * Class AlephLoan.
 *
 * Entity with setters/getters for loans in Aleph.
 *
 * https://www.obvsg.at/uploads/media/Z36.pdf
 *
 * @package Drupal\aleph\Aleph
 */

class AlephLoan {

  /**
   * The ID of the loan.
   * @var string
   */
  protected $loanId;

  /**
   * The loan status code. "Y" or "N" (yes/no).
   * @var string
   */
  protected $statusCode;

  /**
   * System number of the administrative record associated to the loan.
   * @var string
   */
  protected $docNumber;

  /**
   * Get the ID of the loan.
   *
   * @return string
   */
  public function getLoanId() {
    return $this->loanId;
  }

  /**
   * Set the ID of the loan.
   *
   * @param string $loanId
   */
  public function setLoanId($loanId) {
    $this->loanId = $loanId;
  }

  /**
   * The status code indicating if it's renewable.
   * "Y" or "N".
   *
   * @return string
   */
  public function getStatusCode() {
    return $this->statusCode;
  }

  /**
   * The status code indicating if it's renewable.
   * "Y" or "N".
   *
   * @param string $statusCode
   */
  public function setStatusCode($statusCode) {
    $this->statusCode = $statusCode;
  }

  /**
   * Check if the loan is renewed.
   *
   * @return bool
   *    True if loan is renewed.
   */
  public function isRenewed() {
    return $this->getStatusCode() === 'Y';
  }

  /**
   * Get the system number of the administrative record associated to the loan.
   *
   * @return string
   */
  public function getDocNumber() {
    return $this->docNumber;
  }

  /**
   * Set the system number of the administrative record associated to the loan.
   *
   * @param string $docNumber
   */
  public function setDocNumber($docNumber) {
    $this->docNumber = $docNumber;
  }

}
