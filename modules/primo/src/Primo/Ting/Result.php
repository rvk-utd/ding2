<?php
/**
 * @file
 * The Result class.
 */

namespace Primo\Ting;

use Primo\BriefSearch\Document;
use Ting\Search\TingSearchRequest;
use Ting\Search\TingSearchResultInterface;
use TingCollection;

/**
 * A Ting compatible search result from the Primo search provider.
 */
class Result implements TingSearchResultInterface {

  /**
   * The original search request that was executed to produce this result.
   *
   * @var \Ting\Search\TingSearchRequest
   */
  protected $tingSearchRequest;

  /**
   * The primo-specific search result object.
   *
   * @var \Primo\BriefSearch\Result
   */
  protected $result;

  /**
   * List of Ting collections in the search result.
   *
   * As Primo does not support the concept of a collection we have a 1-1
   * relation between materials and collections.
   *
   * @var \TingCollection[]
   */
  protected $collections;

  /**
   * Result constructor.
   *
   * @param \Primo\BriefSearch\Result $result
   *   Primo search result.
   *
   * @param \Ting\Search\TingSearchRequest $ting_search_request
   *   Ting search query request that was executed to produce the result.
   */
  public function __construct(\Primo\BriefSearch\Result $result, TingSearchRequest $ting_search_request) {
    $this->result = $result;
    $this->tingSearchRequest = $ting_search_request;
  }

  /**
   * Total number of elements in the search-result (regardless of limit).
   *
   * @return int
   *   The number of objects.
   */
  public function getNumTotalObjects() {
    return $this->result->getNumResults();
  }

  /**
   * Total number of collections in the search-result.
   *
   * Primo does not support collections so the number of collections will be
   * equal to the number of objects.
   *
   * @return int
   *   The number of collections.
   */
  public function getNumTotalCollections() {
    // We don't support collections so the count of collections is == count of
    // objects.
    return $this->getNumTotalObjects();
  }

  /**
   * Returns a list of loaded TingCollections.
   *
   * Notice that TingCollection is actually a collection of Ting Entities.
   *
   * @return \TingCollection[]
   *   Collections contained in the search result.
   */
  public function getTingEntityCollections() {
    // Load if not loaded yet.
    if ($this->collections === NULL) {
      // Extract the document ids and load a collection pr. document.
      $ids = array_map(function(Document $document) {
        return $document->getRecordId();
      }, $this->result->getDocuments());

      $this->collections = entity_load('ting_collection', array(),
        array('ding_entity_id' => $ids));
    }

    return $this->collections;
  }

  /**
   * Indicates whether the the search could yield more results.
   *
   * Eg. by increasing the count or page-number.
   *
   * @return bool
   *   TRUE if the search-provider could provide more results.
   */
  public function hasMoreResults() {
    return $this->result->getNumResults() > ($this->tingSearchRequest->getPage() * $this->tingSearchRequest->getCount());
  }

  /**
   * The search request that produced the resulted.
   *
   * @return \Ting\Search\TingSearchRequest
   *   The search request.
   */
  public function getSearchRequest() {
    return $this->tingSearchRequest;
  }

  /**
   * Facet matched in the result with term matches.
   *
   * The list is keyed by facet name.
   *
   * @return \Ting\Search\TingSearchFacet[]
   *   List of facets, empty if none where found.
   */
  public function getFacets() {
    // TODO: Implement.
    return [];
  }

  /**
   * Returns the primo-specific search result.
   *
   * @return \Primo\BriefSearch\Result
   *   The search result.
   */
  public function getPrimoSearchresult() {
    return $this->result;
  }
}
