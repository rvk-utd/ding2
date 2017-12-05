<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * Class AlephDebtMaterial.
 *
 * Material information related to debt.
 *
 * @package Drupal\aleph\Aleph
 */
class AlephDebtMaterial {
  protected $title;
  protected $id;

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
   * Set the material ID.
   *
   * @param $id
   *    The material ID.
   */
  public function setId($id) {
    $this->id = $id;
  }

  /**
   * Get the material ID.
   */
  public function getId() {
    return $this->id;
  }

  /**
   * Create debt material.
   *
   * @param \SimpleXMLElement $xml
   *    The XML from Aleph.
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephDebtMaterial The Aleph debt material.
   * The Aleph debt material.
   */
  public static function createDebtMaterial(\SimpleXMLElement $xml) {
    $debt_material = new self();
    $debt_material->setTitle((string) $xml->xpath('z13/z13-title')[0]);
    $debt_material->setId((string) $xml->xpath('z13/z13-doc-number')[0]);
    return $debt_material;
  }

}
