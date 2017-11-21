<?php
/**
 * @file
 * The Result class.
 */

namespace Primo\Ting;

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
  public function __construct($result, TingSearchRequest $ting_search_request) {
    $this->result = $result;
    $this->tingSearchRequest = $ting_search_request;

    // Construct a Ting collection pr. document.
    foreach ($this->result->getDocuments() as $document) {
      $this->collections[] = new TingCollection($document->getRecordId(), new Collection([$document]));
    }
  }

  /**
   * Total number of elements in the search-result (regardless of limit).
   *
   * @return int
   *   The number of objects.
   */
  public function getNumTotalObjects() {
    return count($this->result->getDocuments());
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
    // Will in effect be one collection pr object as we don't support
    // collections.
    return count($this->collections);
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
    return [];
  }
}
