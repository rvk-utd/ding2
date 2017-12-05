<?php

namespace Primo\BriefSearch;

/**
 * A result from accessing the Primo brief search service.
 */
class Result {
  use DocumentTrait;

  /**
   * Result constructor.
   *
   * @param string $data
   *   The data returned from Primo.
   */
  public function __construct($data) {
    $this->document = new \DOMDocument();
    $this->document->loadXML($data);
  }

  /**
   * Extracts the documents returned within the search result.
   *
   * @return \Primo\BriefSearch\Document[]
   *   The resulting documents.
   */
  public function getDocuments() {
    $recordIdNodes = $this->xpath('//search:DOC//primo:control/primo:recordid');
    $recordIds = $this->nodeValues($recordIdNodes);

    $documents = array_map(function($recordId) {
      return new Document($this->document, $recordId);
    }, array_combine($recordIds, $recordIds));

    return $documents;
  }

  /**
   * Returns the number of items in the result.
   *
   * @return int
   *   The number of results.
   */
  public function getNumResults() {
    $docset = $this->xpath('//sear:DOCSET');
    // Empty list or false if we hit an error or can't find the element.
    if (empty($docset)) {
      return 0;
    }
    $docset = $docset->item(0);

    // Cast the string return-value from getAttributes. getAttributes returns an
    // empty string if the attribute cannot be found which will be cast to 0.
    // which will be cast to 0.
    return (int) $docset->getAttribute('TOTALHITS');
  }
}
