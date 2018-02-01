<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * Class AlephHoldGroup.
 *
 * Entity for hold groups.
 *
 * @package Drupal\aleph\Aleph
 */

class AlephHoldGroup {
  protected $subLibrary;
  protected $subLibraryCode;
  protected $pickupLocations = [];

  /**
   * @return mixed
   */
  public function getSubLibrary() {
    return $this->subLibrary;
  }

  /**
   * @param mixed $subLibrary
   */
  public function setSubLibrary($subLibrary) {
    $this->subLibrary = $subLibrary;
  }

  /**
   * @return mixed
   */
  public function getSubLibraryCode() {
    return $this->subLibraryCode;
  }

  /**
   * @param mixed $subLibraryCode
   */
  public function setSubLibraryCode($subLibraryCode) {
    $this->subLibraryCode = $subLibraryCode;
  }

  /**
   * @return array
   */
  public function getPickupLocations() {
    return $this->pickupLocations;
  }

  /**
   * @param array $pickupLocations
   */
  public function setPickupLocations($pickupLocations) {
    $this->pickupLocations = $pickupLocations;
  }

  /**
   * @param \SimpleXMLElement $xml
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephHoldGroup
   */
  public static function createHoldGroupFromXML(\SimpleXMLElement $xml) {
    $hold_group = new self();
    $pickup_locations = [];

    foreach ($xml->xpath('pickup-locations/pickup-location') as $pickup_location) {
      $pickup_locations[(string) $pickup_location['code']] = (string) $pickup_location;
    }

    $hold_group->setSubLibraryCode((string) $xml->xpath('sublibrary-code')[0]);
    $hold_group->setSubLibrary((string) $xml->xpath('sublibrary')[0]);

    $hold_group->setPickupLocations($pickup_locations);

    return $hold_group;
  }
}
