<?php

namespace Drupal\aleph\Aleph\Entity;

use DateTime;

/**
 * Class AlephMaterial.
 *
 * This entity describes a material from Aleph which can be anything from a
 * book, an e-book, a CD, etc.
 *
 * @package Drupal\aleph\Aleph
 */
class AlephMaterial {

  protected $available = FALSE;
  protected $collection;
  protected $dueDate;
  protected $id;
  protected $isInternet;
  protected $loanDate;
  protected $loans;
  protected $placements = [];
  protected $reservable = FALSE;
  protected $subLibrary;
  protected $subLibraryCode;
  protected $title;
  protected $type;

  /**
   * Set the material title.
   *
   * @param string $title
   *    The title of the material.
   */
  public function setTitle($title) {
    $this->title = $title;
  }

  /**
   * Returns the material title.
   *
   * @return string
   *    The material title.
   */
  public function getTitle() {
    return $this->title;
  }

  /**
   * Return the date for the loan of the material.
   *
   * @return string
   *   The formatted date.
   */
  public function getLoanDate() {
    return DateTime::createFromFormat('Ymd', $this->loanDate)->format('Y-m-d');
  }

  /**
   * Set material loan date.
   *
   * @param string $date
   *    The loan date.
   */
  public function setLoanDate($date) {
    $this->loanDate = $date;
  }

  /**
   * Get the material ID.
   *
   * @return string
   *    The material ID.
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Set the material ID.
   *
   * @param string $id
   *    The material ID.
   */
  public function setId($id) {
    $this->id = $id;
  }

  /**
   * Get the due date for the material.
   *
   * @return string
   *    The due date.
   */
  public function getDueDate() {
    return DateTime::createFromFormat('Ymd', $this->dueDate)->format('Y-m-d');
  }

  /**
   * Set the due date.
   *
   * @param string $date
   *   The due date.
   */
  public function setDueDate($date) {
    $this->dueDate = $date;
  }

  /**
   * If the material is renewable.
   *
   * @return bool
   *    TRUE if the material is renewable.
   */
  public function isRenewable() {
    // The patron is only allowed to renew an item two times.
    if ($this->loans <= 2) {
      return TRUE;
    }
  }

  /**
   * Checks if the material is available.
   *
   * @return bool
   *    If the material is available.
   */
  public function isAvailable() {
    return $this->available;
  }

  /**
   * Checks if the material is reservable.
   *
   * @return bool
   *    If the material is reservable.
   */
  public function isReservable() {
    return $this->reservable;
  }

  /**
   * Set the type of material.
   *
   * @param string $type
   *    The type of material (z30-material).
   */
  public function setType($type) {
    $this->type = $type;
  }

  /**
   * Get the type of material.
   *
   * @return string
   *    The type of material (z30-material).
   *    For example: 'MP3-Audio book', 'CD-Spoken', 'Book', etc.
   */
  public function getType() {
    return $this->type;
  }

  /**
   * Set if the material is available.
   *
   * @param bool $available
   *    If the material is available (status = on shelf).
   */
  public function setAvailable($available) {
    $this->available = $available;
  }

  /**
   * Get if the material is available.
   *
   * @return bool
   *    If the material is available (status = on shelf).
   */
  public function getAvailable() {
    return $this->available;
  }

  /**
   * Set the material's sub-library/branch.
   *
   * @param string $sub_library
   */
  public function setSubLibrary($sub_library) {
    $this->subLibrary = $sub_library;
  }

  /**
   * Get the material sub-library/branch.
   *
   * @return string
   *    The sub-library/branch.
   */
  public function getSubLibrary() {
    return $this->subLibrary;
  }

  /**
   * Set the material collection.
   *
   * @param string $collection
   *    The collection the material belongs to.
   */
  public function setCollection($collection) {
    $this->collection = $collection;
  }

  /**
   * Returns the material collection.
   *
   * @return string
   *    The collection the material belongs to.
   */
  public function getCollection() {
    return $this->collection;
  }

  /**
   * Set if the material is internet-only (no z30).
   *
   * @param bool $is_internet
   *    If the material is internet-only.
   */
  public function setIsInternet($is_internet) {
    $this->isInternet = $is_internet;
  }

  /**
   * If the material is internet-only (no z30).
   *
   * @return bool
   *    If the material is internet-only (no z30).
   */
  public function getIsInternet() {
    return $this->isInternet;
  }

  /**
   * Set the sub-library/branch code.
   *
   * @param string $sub_library
   *    The sub-library/branch code.
   */
  public function setSubLibraryCode($sub_library) {
    $this->subLibraryCode = $sub_library;
  }

  /**
   * Get the sub-library/branch code.
   *
   * @return string
   *    The sub-library/branch code.
   *    For example 'BBAAA', 'BBKAA', etc.
   */
  public function getSubLibraryCode() {
    return $this->subLibraryCode;
  }

  /**
   * Set the physical location(s) of the material.
   *
   * @param array $placements
   *    Array of locations.
   */
  public function setPlacements($placements) {
    $this->placements = $placements;
  }

  /**
   * Return the physical location(s) of the material in the order:
   * z30-call-no (shelving location of the item), z30-call-no2 (additional
   * shelving location of the item).
   *
   * @return array
   *    For example ['Row Har B', ''].
   *    The second one, z30-call-no2 is empty most of the time.
   */
  public function getPlacements() {
    return $this->placements;
  }

  /**
   * Returns the patron's loans from SimpleXMLElement.
   *
   * @param \SimpleXMLElement $xml
   *    The SimpleXMLElement from bor_info.
   *
   * @return array
   *    Array with AlephMaterials.
   */
  public static function loansFromBorInfo(\SimpleXMLElement $xml) {
    $items = $xml->xpath('item-l');
    $loans = array();
    foreach ($items as $item) {
      $material = new self();
      $material->setTitle((string) $item->xpath('z13/z13-title')[0]);
      $material->setId((string) $item->xpath('z30/z30-doc-number')[0]);
      $material->setDueDate((string) $item->xpath('z36/z36-due-date')[0]);
      $material->setLoanDate((string) $item->xpath('z36/z36-loan-date')[0]);
      $loans[] = $material;
    }
    return $loans;
  }

  /**
   * Create material from item.
   *
   * @param $item
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephMaterial
   */
  public static function materialFromItem(\SimpleXMLElement $item) {
    $material = new self();
    $material->setId((string) $item->xpath('z13/z13-doc-number')[0]);
    $material->setType((string) $item->xpath('z30/z30-material')[0]);
    $material->setTitle((string) $item->xpath('z13/z13-title')[0]);
    $material->setSubLibrary((string) $item->xpath('z30/z30-sub-library')[0]);
    $material->setCollection((string) $item->xpath('z30/z30-collection')[0]);
    if ($item->xpath('z36-sub-library-code')) {
      $material->setSubLibraryCode((string) $item->xpath('z36-sub-library-code')[0]);
    }
    if ($item->xpath('z30-sub-library-code')) {
      $material->setSubLibraryCode((string) $item->xpath('z30-sub-library-code')[0]);
    }
    $material->setDueDate((string) $item->xpath('z36/z36-due-date')[0]);
    $material->setLoanDate((string) $item->xpath('z36/z36-loan-date')[0]);

    // Note placements of the material.
    $placements = array_map(function ($path) use ($item) {
      return empty($item->xpath($path)[0]) ? NULL : (string) $item->xpath($path)[0];
    }, ['z30/z30-call-no', 'z30/z30-call-no2']);

    if (!empty($placements)) {
      $material->setPlacements($placements);
    }

    if ((string) $item->xpath('status')[0] === 'On Shelf') {
      $material->setAvailable(TRUE);
      $material->reservable = TRUE;
    }

    if ($item->xpath('z30') === FALSE) {
      $material->setIsInternet(TRUE);
    }

    return $material;
  }

}
