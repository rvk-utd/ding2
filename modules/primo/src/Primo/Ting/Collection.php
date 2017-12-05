<?php
/**
 * @file
 * The Collection class.
 */

namespace Primo\Ting;

use Primo\BriefSearch\Document;
use Ting\TingObjectCollectionInterface;

/**
 * A collection of materials.
 */
class Collection implements TingObjectCollectionInterface {

  /**
   * List of the Ting objects that makes up the collection.
   *
   * @var \Ting\TingObjectInterface[]
   */
  protected $objects;

  /**
   * Collection constructor.
   *
   * @param \Ting\TingObjectInterface[] $objects
   *   Documents from a Primo search.
   */
  public function __construct($objects) {
    $this->objects = $objects;
  }

  /**
   * Returns the objects in the collection.
   *
   * @return \Ting\TingObjectInterface[]
   *   Returns the objects that makes up the collection.
   */
  public function getObjects() {
    return $this->objects;
  }

  /**
   * Get the primary Object in this collection.
   *
   * @return \Ting\TingObjectInterface
   *   The object.
   */
  public function getPrimaryObject() {
    return empty($this->objects) ? NULL : reset($this->objects);
  }
}
