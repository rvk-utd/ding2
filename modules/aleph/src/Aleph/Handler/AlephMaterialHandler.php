<?php

namespace Drupal\aleph\Aleph\Handler;

use Drupal\aleph\Aleph\AlephClient;
use Drupal\aleph\Aleph\Entity\AlephMaterial;

/**
 * Class AlephMaterialHandler.
 *
 * @package Drupal\aleph\Aleph\Handler
 */
class AlephMaterialHandler extends AlephHandlerBase {

  /**
   * AlephMaterialHandler constructor.
   *
   * @param \Drupal\aleph\Aleph\AlephClient $client
   *    Instance of the Aleph Client.
   */
  public function __construct(AlephClient $client) {
    parent::__construct($client);
  }

  /**
   * Get holdings from Aleph Material.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephMaterial $material
   *    The Aleph Material.
   *
   * @return \Drupal\aleph\Aleph\Entity\AlephMaterial[]
   *    Array with Aleph Materials.
   *
   * @throws \RuntimeException
   */
  public function getHoldings(AlephMaterial $material) {
    $items = array();
    $aleph_items = $this->client->getItems($material)->xpath('items/item');
    foreach ($aleph_items as $aleph_item) {
      $material = new AlephMaterial();
      $items[] = $material::materialFromItem($aleph_item);
    }
    return $items;
  }

  /**
   * {@inheritdoc}
   */
  protected function getIdentity() {
    return 'AlephMaterialHandler';
  }

}
