<?php

namespace Drupal\aleph\Aleph\Handler;

use Drupal\aleph\Aleph\AlephClient;
use Drupal\aleph\Aleph\Entity\AlephMaterial;
use Drupal\aleph\Aleph\Exception\AlephClientException;

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
   * @throws AlephClientException
   */
  public function getHoldings(AlephMaterial $material) {
    $aleph_items = $this->client->getItems($material)->xpath('items/item');

    $items = array_map(function($aleph_item) {
      return AlephMaterial::materialFromItem($aleph_item);
    }, $aleph_items);

    return array_filter($items, function(AlephMaterial $material) {
      return array_key_exists($material->getSubLibraryCode(), aleph_get_branches());
    });
  }

  /**
   * {@inheritdoc}
   */
  protected function getIdentity() {
    return 'AlephMaterialHandler';
  }

}
