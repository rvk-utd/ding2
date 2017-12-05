<?php


namespace Primo\BriefSearch;

/**
 * Trait used for accessing data with a Primo brief search result document.
 */
trait DocumentTrait {

  /**
   * The Primo brief search result document.
   *
   * @var \DOMDocument
   */
  protected $document;

  /**
   * Perform a xpath query against the document.
   *
   * The xpath will have helpful Primo related namespaces registered:
   * - search: http://www.exlibrisgroup.com/xsd/jaguar/search
   * - primo: http://www.exlibrisgroup.com/xsd/primo/primo_nm_bib
   *
   * @param string $query
   *   The XPath query
   * @return \DOMNodeList
   *   The result of the xpath query.
   */
  protected function xpath($query) {
    $xpath = new \DOMXPath($this->document);
    $xpath->registerNamespace(
      'search', 'http://www.exlibrisgroup.com/xsd/jaguar/search');
    $xpath->registerNamespace(
      'primo', 'http://www.exlibrisgroup.com/xsd/primo/primo_nm_bib');
    return $xpath->query($query);
  }

  /**
   * Perform a xpath query against a record contained with the document.
   *
   * A document may contain multiple records. This is a neat way to focus
   * solely on a single record.
   *
   * @param string $recordId
   *   The document record id.
   * @param string $query
   *
   * @return \DOMNodeList
   *   The result of thr xpath query.
   */
  protected function recordXpath($recordId, $query) {
    $query = '//search:DOC[.//primo:recordid[.="' . $recordId .  '"]]' . $query;
    return $this->xpath($query);
  }

  /**
   * Retrieves values from a node list.
   *
   * @param \DOMNodeList $list
   *   The node list.
   *
   * @return string[]
   *   The node values.
   */
  protected function nodeValues(\DOMNodeList $list) {
    $values = [];
    foreach ($list as $node) {
      $values[] = $node->nodeValue;
    }
    return $values;
  }

  /**
   * Retrieves the first value from a node list.
   *
   * All subsequent values are discarded.
   *
   * @param \DOMNodeList $list
   *   The node list.
   *
   * @return string|FALSE
   *   The value of the first node. FALSE if the list is empty.
   */
  protected function nodeValue(\DOMNodeList $list) {
    $values = $this->nodeValues($list);
    return reset($values);
  }

}
