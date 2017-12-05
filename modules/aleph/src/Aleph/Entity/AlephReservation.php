<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * Class AlephReservation.
 *
 * @package Drupal\aleph\Aleph
 */
class AlephReservation {
  protected $item;
  protected $request;

  /**
   * @param \Drupal\aleph\Aleph\Entity\AlephMaterial $item
   */
  public function setItem(AlephMaterial $item) {
    $this->item = $item;
  }

  /**
   * @return \Drupal\aleph\Aleph\Entity\AlephMaterial
   */
  public function getItem() {
    return $this->item;
  }

  /**
   * @param \Drupal\aleph\Aleph\Entity\AlephRequest $request
   */
  public function setRequest(AlephRequest $request) {
    $this->request = $request;
  }

  /**
   * @return \Drupal\aleph\Aleph\Entity\AlephRequest
   */
  public function getRequest() {
    return $this->request;
  }
}
