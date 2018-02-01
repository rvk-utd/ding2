<?php
/**
 * @file
 * Handles availability information from the library system.
 */

use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Handler\AlephMaterialHandler;

/**
 * Implements provider availability, items.
 *
 * @param array $provider_ids
 *   Array of ting object ids.
 *
 * @return array
 *   Availability info.
 */
function aleph_availability_items(array $provider_ids) {
  $items = array();
  $material_handler = new AlephMaterialHandler(aleph_client());

  foreach ($provider_ids as $provider_id) {
    $material = new AlephMaterial();
    $material->setId($provider_id);
    $items[] = $material_handler->getHoldings($material);
  }

  $result = array();
  foreach ($items as $item) {
    $result[$item->getId()] = array(
      'available' => $item->isAvailable(),
      'reservable' => $item->isReservable(),
    );
  }

  return $result;
}

/**
 * Implements provider availability, holdings.
 *
 * @param array $provider_ids
 *   Array of ting object ids.
 *
 * @return array
 *   Holdings info.
 */
function aleph_availability_holdings(array $provider_ids) {
  $results = array();
  $sub_libraries = array();

  try {
    $material_handler = new AlephMaterialHandler(aleph_client());
  }
  catch (Exception $e) {
    watchdog_exception('aleph', $e);
    return [];
  }

  foreach ($provider_ids as $provider_id) {
    $material = new AlephMaterial();
    $material->setId($provider_id);
    $items = $material_handler->getHoldings($material);

    $reserved_count = 0;
    $available_count = 0;

    foreach ($items as $item) {
      // Count the total amount on sub-libraries and see if it's available or
      // reservable.
      if (array_key_exists($item->getSubLibraryCode(), $sub_libraries) &&
          $item->getSubLibraryCode() !== NULL) {
        $sub_libraries[$item->getSubLibraryCode()]['total_count']++;
        if ($item->isAvailable()) {
          $sub_libraries[$item->getSubLibraryCode()]['available_count']++;
        }
        $sub_libraries[$item->getSubLibraryCode()]['available'] = $item->isAvailable();
        $sub_libraries[$item->getSubLibraryCode()]['reservable'] = $item->isReservable();
      }
      else {
        // In the case of additional shelving location of the item from the
        // Z30-CALL-NO-2 field.
        $placements = implode(' > ', array_filter($item->getPlacements()));
        $sub_libraries[$item->getSubLibraryCode()] = array(
          'placement' => array($item->getSubLibrary(), $placements),
          // Reference count not available in Aleph.
          'reference_count' => 0,
          'available' => $item->isAvailable(),
          'reservable' => $item->isReservable(),
          'total_count' => 1,
          'available_count' => $item->isAvailable() ? 1 : 0,
        );
      }

      // Count how many of the materials are on shelf / available and how
      // many are reservable.
      $item->isAvailable() ? $available_count++ : $reserved_count++;

      // Provide data for each material from the provider ID.
      $data = array(
        'local_id' => $item->getId(),
        'available' => $available_count > 0,
        'reservable' => count($items) > 0,
        'total_count' => count($items),
        'reserved_count' => $reserved_count,
        'is_internet' => $item->getIsInternet(),
        'holdings' => $sub_libraries,
        // Deferred_period, issues and is_periodical is not available in Aleph.
        'deferred_period' => FALSE,
        'issues' => array(),
        'is_periodical' => FALSE,
      );

      $results[$item->getId()] = $data;
    }
  }

  return $results;
}
