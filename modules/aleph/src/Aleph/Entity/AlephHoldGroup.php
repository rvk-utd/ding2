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
  protected $url;

  /**
   * Get the hold group URL.
   *
   * @return string
   *   The hold group URL.
   */
  public function getUrl() {
    return $this->url;
  }

  /**
   * Set the hold group URL.
   *
   * @param string $url
   *   The hold group URL.
   */
  public function setUrl($url) {
    $this->url = $url;
  }

  /**
   * Get name of the holding group sub library.
   *
   * @return string
   *   The full name of the sub library.
   */
  public function getSubLibrary() {
    return $this->subLibrary;
  }

  /**
   * Set the sub library name.
   *
   * @param string $sub_library
   *   Set the name of the sub library.
   */
  protected function setSubLibrary($sub_library) {
    $this->subLibrary = $sub_library;
  }

  /**
   * Get the sub library code.
   *
   * @return string
   *   The sub library code.
   */
  public function getSubLibraryCode() {
    return $this->subLibraryCode;
  }

  /**
   * Set the sub library code.
   *
   * @param string $sub_library_code
   *   Set the sub library code, like: 'BBAAA'.
   */
  protected function setSubLibraryCode($sub_library_code) {
    $this->subLibraryCode = $sub_library_code;
  }

  /**
   * Get the pickup locations.
   *
   * @return array
   *   Array with available pickup locations.
   */
  public function getPickupLocations() {
    return $this->pickupLocations;
  }

  /**
   * Set the available pickup locations.
   *
   * @param array $pickup_locations
   *   Array with pickup locations.
   */
  protected function setPickupLocations($pickup_locations) {
    $this->pickupLocations = $pickup_locations;
  }

  /**
   * Create hold group object from XML.
   *
   * @param \SimpleXMLElement $xml
   *   The XML response as a SimpleXMLElement from Aleph.
   *
   * @return AlephHoldGroup
   *   The AlephHoldGroup object.
   */
  public static function createHoldGroupFromXML(\SimpleXMLElement $xml) {
    $hold_group = new self();
    $pickup_locations = [];

    foreach ($xml->xpath('pickup-locations/pickup-location') as $pickup_location) {
      if (!empty($pickup_location['code'])) {
        $pickup_locations[(string) $pickup_location['code']] = (string) $pickup_location;
      }
    }

    $hold_group->setSubLibraryCode((string) $xml->xpath('sublibrary-code')[0]);
    $hold_group->setSubLibrary((string) $xml->xpath('sublibrary')[0]);
    $hold_group->setPickupLocations($pickup_locations);
    $hold_group->setUrl((string) $xml['href']);

    return $hold_group;
  }
}
