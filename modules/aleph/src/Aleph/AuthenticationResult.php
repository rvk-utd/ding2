<?php

namespace Drupal\aleph\Aleph;

use Drupal\aleph\Aleph\Entity\AlephPatron;

/**
 * Class AuthenticationResult.
 *
 * Provides an object with the patron and methods to check if the patron is
 * authenticated or blocked.
 *
 * @package Drupal\aleph\Aleph
 */
class AuthenticationResult {

  protected $borId;
  protected $client;
  protected $patron;
  protected $verification;
  protected $activeBranches;

  /**
   * AuthenticationResult constructor.
   *
   * @param \Drupal\aleph\Aleph\AlephClient $client
   *    The Aleph client.
   * @param string $bor_id
   *    The patron's ID.
   * @param string $verification
   *    The patron's pin.
   * @param string[] $active_branches
   *    The branches where the patron is active.
   */
  public function __construct(
    AlephClient $client,
    $bor_id,
    $verification,
    array $active_branches
  ) {
    $this->borId = $bor_id;
    $this->client = $client;
    $this->verification = $verification;
    $this->activeBranches = $active_branches;
  }

  /**
   * Check the patron is authenticated.
   */
  public function isAuthenticated() {
    return (!$this->getClientError() && !$this->isBlocked());
  }

  /**
   * Check if the user is blocked.
   */
  public function isBlocked() {
    foreach ($this->getBlockCodes() as $key => $value) {
      if ($value['code'] !== '00') {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Return users block codes and messages.
   *
   * A block-code from Aleph consists of two characters and a note.
   * They can define different reasons for denied privileges (loan, hold, etc.).
   *
   * @return array
   *    Array with an array for each identifier (z303-delinq-1).
   *    Each array contains an array with a code and a message.
   */
  public function getBlockCodes() {
    $block_codes = array();

    $codes = array('z305-delinq-1', 'z305-delinq-2', 'z305-delinq-3');

    foreach ($codes as $code) {
      $response = $this->client->authenticate($this->borId, $this->verification);
      if (!$this->getClientError()) {
        $block_codes[$code] = array(
          'code' => (string) $response->xpath('z305/' . $code)[0],
        );
      }
    }

    return $block_codes;
  }

  /**
   * Set the patron.
   *
   * @param \Drupal\aleph\Aleph\Entity\AlephPatron $patron
   *    The Patron.
   */
  public function setPatron(AlephPatron $patron) {
    $this->patron = $patron;
  }

  /**
   * Return the patron.
   *
   * @return AlephPatron
   *    The Aleph Patron.
   */
  public function getPatron() {
    return $this->patron;
  }

  /**
   * Return client error message.
   *
   * @return string|false
   *    The client error message or FALSE if no errors.
   */
  public function getClientError() {
    $response = $this->client->authenticate($this->borId, $this->verification);
    if (!empty($response->xpath('error'))) {
      return (string) $response->xpath('error')[0];
    }
    return FALSE;
  }

}
