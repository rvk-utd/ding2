<?php

namespace Drupal\aleph\Aleph\Entity;

/**
 * @file
 * Provides the AlephRequestResponse.
 */

/**
 * Class AlephRequestResponse
 *
 * This entity describes the response from Aleph.
 *
 * @package Drupal\aleph\Aleph\Entity
 */
class AlephRequestResponse {

  /**
   * @var string $replyCode
   *  The reply code is 0000 on success.
   */
  protected $replyCode;

  /**
   * @var string $replyText
   *  The reply text.
   *  For example: "Failed to create request"
   */
  protected $replyText;

  /**
   * @var string $note
   *  The note for the response.
   *  For example: "Patron has already requested this item."
   */
  protected $note;

  /**
   * @return string
   */
  public function getReplyCode() {
    return $this->replyCode;
  }

  /**
   * @param string $replyCode
   */
  public function setReplyCode($replyCode) {
    $this->replyCode = $replyCode;
  }

  /**
   * @return string
   */
  public function getReplyText() {
    return $this->replyText;
  }

  /**
   * @param string $replyText
   */
  public function setReplyText($replyText) {
    $this->replyText = $replyText;
  }

  /**
   * @return string
   */
  public function getNote() {
    return $this->note;
  }

  /**
   * @param string $note
   */
  public function setNote($note) {
    $this->note = $note;
  }

  /**
   * @return bool
   */
  public function success() {
    return $this->getReplyCode() === '0000';
  }

  /**
   * Create a request response from provided SimpleXMLElement.
   *
   * @param \SimpleXMLElement
   * @return \Drupal\aleph\Aleph\Entity\AlephRequestResponse
   */
  public static function createRequestResponseFromXML(\SimpleXMLElement $xml) {
    $response = new self();

    $response->setReplyCode((string) $xml->xpath('reply-code')[0]);
    $response->setReplyText((string) $xml->xpath('reply-text')[0]);
    $response->setNote((string) $xml->xpath('note')[0]);

    return $response;
  }

}
