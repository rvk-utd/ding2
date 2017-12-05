<?php

namespace Drupal\aleph\Aleph\Handler;

use Drupal\aleph\Aleph\AlephClient;

/**
 * Class AlephHandlerBase.
 *
 * @package Drupal\aleph\Aleph\Handler
 */
abstract class AlephHandlerBase {

  /**
   * Instance of the AlephClient.
   *
   * @var AlephClient
   */
  protected $client;

  /**
   * AlephHandlerBase constructor.
   *
   * @param AlephClient $client
   *    The AlephClient.
   */
  protected function __construct(AlephClient $client) {
    $this->client = $client;
  }

  /**
   * Gets the identity.
   *
   * @return string
   *    The identity.
   */
  abstract protected function getIdentity();

}
