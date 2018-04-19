<?php

namespace Drupal\aleph\Aleph\Entity;

use DateTime;

/**
 * Class AlephDebt.
 *
 * Implements a class with a patron's debt.
 *
 * @package Drupal\aleph\Aleph
 */
class AlephDebt {
  protected $id;
  protected $type;
  protected $description;
  protected $sum;
  protected $date;
  protected $debtMaterial;
  protected $paid;

  /**
   * Set the debt id.
   *
   * @param string $id
   *    The debt id.
   */
  public function setId($id) {
    $this->id = $id;
  }

  /**
   * Get the debt id.
   *
   * @return string
   *    The id of debt (example: 'Late return').
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Set the debt type.
   *
   * @param string $type
   *    The debt type.
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * Get the debt type.
   *
   * @return string
   *    The type of debt (example: 'Late return').
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Set the description of the cash transaction.
   *
   * @param string $description
   *    Description of the cash transaction.
   */
  public function setDescription($description) {
    $this->description = $description;
  }

  /**
   * Get the description of the cash transaction.
   *
   * @return string
   *    Description of the cash transaction.
   */
  public function getDescription() {
    return $this->description;
  }

  /**
   * Set the debt sum.
   *
   * @param string $sum
   *    The patron's debt sum.
   */
  public function setSum($sum) {
    $this->sum = $sum;
  }

  /**
   * Get the debt sum.
   *
   * @return string
   *    The patron's debt sum (example: 700.00).
   */
  public function getSum() {
    return $this->sum;
  }

  /**
   * Set the cash transaction date in format Y-m-d.
   *
   * @param string $date
   *    The cash transaction date.
   */
  public function setDate($date) {
    $this->date = DateTime::createFromFormat('Ymd', $date)->format('Y-m-d');
  }

  /**
   * Get the cash transaction date.
   *
   * @return string
   *    The cash transaction date (format: YYYYMMDD).
   */
  public function getDate() {
    return $this->date;
  }

  /**
   * Set the debt related material.
   *
   * @param AlephDebtMaterial $material
   *    The material which is the reason for the debt.
   */
  public function setDebtMaterial(AlephDebtMaterial $material) {
    $this->debtMaterial = $material;
  }

  /**
   * Get the debt related material.
   *
   * @return \Drupal\aleph\Aleph\AlephDebtMaterial
   *    The material which is the reason for the debt.
   */
  public function getDebtMaterial() {
    return $this->debtMaterial;
  }

  /**
   * Set if paid or not.
   *
   * @param bool $value
   *    True if paid and false otherwise.
   */
  public function setPaid($value) {
    $this->paid = $value;
  }

  /**
   * Return if debt is paid.
   *
   * @return bool
   *    True if paid and false otherwise.
   */
  public function isPaid() {
    return $this->paid;
  }

  /**
   * Returns the patron's debts from SimpleXMLElement.
   *
   * @param \SimpleXMLElement $xml
   *    The SimpleXMLElement from the Aleph Cash API.
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephDebt[]
   *    Array with debts.
   */
  public static function debtsFromCashApi(\SimpleXMLElement $xml) {
    $debts_xml = $xml->xpath('charges/institution/cash');
    $debts = array();
    foreach ($debts_xml as $debt_xml) {
      // Reply might contain credit entries, ignore everything but debit
      // entries.
      if ((string) $debt_xml['type'] !== 'debit') {
        continue;
      }
      $debt = new self();
      $debt->setId((string) $debt_xml->xpath('z31/z31-sequence')[0]);
      $debt->setType((string) $debt_xml->xpath('z31/z31-type')[0]);
      $debt->setDescription((string) $debt_xml->xpath('z31/z31-description')[0]);
      $sum = (string) $debt_xml->xpath('z31/z31-sum')[0];
      // Aleph uses the accountant convention of representing negative amounts
      // as a number in parentheses.
      $sum = str_replace(array('(', ')'), '', $sum);
      $debt->setSum($sum);
      $debt->setDate((string) $debt_xml->xpath('z31/z31-date')[0]);

      // Add the debt to the debts array.
      if ($debt->getType() !== 'Payment') {
        // Check if the debt has been paid..
        if ((string) $debt_xml['transferred'] === 'Y') {
          $debt->setPaid(TRUE);
        }
        // Set the debt material.
        $debt->setDebtMaterial(AlephDebtMaterial::createDebtMaterial($debt_xml));
        $debts[] = $debt;
      }
    }

    return $debts;
  }

}
