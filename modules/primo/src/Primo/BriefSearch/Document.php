<?php

namespace Primo\BriefSearch;

/**
 * A document returned when accessing the Primo brief search service.
 *
 * A central part of the document is the PNX record.
 *
 * @see https://knowledge.exlibrisgroup.com/Primo/Product_Documentation/Technical_Guide/010The_PNX_Record
 */
class Document {
  use DocumentTrait;

  /**
   * The id of the document.
   *
   * @var string
   */
  protected $recordId;

  /**
   * Document constructor.
   *
   * @param \DOMDocument $document
   *   The XML search response document which contains the current document.
   * @param string $recordId
   *   Document record id.
   */
  public function __construct(\DOMDocument $document, $recordId) {
    $this->document = $document;
    $this->recordId = $recordId;
  }

  /**
   * Get the record id for the document.
   *
   * @return string
   *   Document record id.
   */
  public function getRecordId() {
    return $this->recordId;
  }

  /**
   * Get the id of the source organization.
   *
   * @return string
   *   Source organization id.
   */
  public function getSourceId() {
    $nodes = $this->recordXpath($this->recordId, '//primo:control/primo:sourceid');
    return $this->nodeValue($nodes);
  }

  /**
   * This ID identifies the record in the source repository.
   *
   * A source repository could be an ALEPH system number supplied in MARC 21 tag
   * 001). The ID must be unique and persistent within the source repository.
   * It is derived from the OAI header.
   *
   * @return string
   *   Source record id.
   */
  public function getSourceRecordId() {
    $nodes = $this->recordXpath($this->recordId, '//primo:control/primo:sourcerecordid');
    return $this->nodeValue($nodes);
  }

  /**
   * Returns the full version of the document title.
   *
   * @return string
   *   Document title.
   */
  public function getTitle() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:btitle');
    return $this->nodeValue($nodes);
  }

  /**
   * Returns a extended description of the document.
   *
   * @return string
   *   Document description.
   */
  public function getDescription() {
    $nodes = $this->recordXpath($this->recordId, '//primo:display/primo:description');
    return $this->nodeValue($nodes);
  }

  /**
   * Returns the display format for the document.
   *
   * This will contain information about the physical format of the document
   * e.g.number of pages, illustrations and such.
   *
   * @return string
   *   Display format description.
   */
  public function getDisplayFormat() {
    $nodes = $this->recordXpath($this->recordId, '//primo:display/primo:format');
    return $this->nodeValue($nodes);
  }

  /**
   * Return ISBN numbers for the record.
   *
   * Note that a Primo record can contain multiple ISBN numbers - both ISBN-10
   * and ISBN-13.
   *
   * @return string[]
   */
  public function getIsbns() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:isbn');
    return $this->nodeValues($nodes);
  }

  /**
   * Get all thumbnail urls for the document.
   *
   * @return string[]
   *   Thumbnail urls.
   */
  public function getThumbnailUrls() {
    $thumbnailNodes = $this->recordXpath($this->recordId, '//search:thumbnail');
    $thumbnailUrls = $this->nodeValues($thumbnailNodes);

    // Primo results are known to include duplicates urls. Remove these.
    return array_unique($thumbnailUrls);
  }

  /**
   * Return document publisher name.
   *
   * @return string
   *   Publisher name.
   */
  public function getPublisher() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:pub');
    return $this->nodeValue($nodes);
  }

  /**
   * Returns the publishing year for the document.
   *
   * @return string
   *   Publishing year.
   */
  public function getYear() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:date');
    return $this->nodeValue($nodes);
  }

  /**
   * Gets the language of the document.
   *
   * Languages are returned in three letter ISO-639 format.
   *
   * @return string
   *   Language in ISO-639 format.
   */
  public function getLanguage() {
    $nodes = $this->recordXpath($this->recordId, '//primo:display/primo:language');
    return $this->nodeValue($nodes);
  }

  /**
   * Gets the value of a local display field.
   *
   * Primo supports local fields which are represented as XML elements named
   * lds[XX]. This allows extraction of such fields.
   *
   * @see https://knowledge.exlibrisgroup.com/Primo/Product_Documentation/Back_Office_Guide/110Additional_Primo_Features/Display_of_Local_Fields
   *
   * @return string
   *   Local display field value
   */
  public function getLocalDisplayField($number) {
    $nodes = $this->recordXpath($this->recordId,
      '//primo:display/primo:lds' .
      str_pad($number, 2, 0,  STR_PAD_LEFT));
    return $this->nodeValue($nodes);
  }

  /**
   * Get the format of the document ie. the type.
   *
   * Example: book
   *
   * @return string
   *   Document format.
   */
  public function getType() {
    $nodes = $this->recordXpath($this->recordId, '//primo:display/primo:type');
    return $this->nodeValue($nodes);
  }

  /**
   * Get the names of the person(s) who created the document.
   *
   * Examples of creators are authors or musicians.
   *
   * @return string[][]
   *   Creator names broken into elements.
   */
  public function getCreators() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:au');
    // Creator names may be in the format [lastname], [firstname]. If so we
    // split and reverse them to return an array of name elements with firstname
    // before lastname. If the name is not in this format there will be no split
    // and we simply return the name as an array with a single entry containing
    // the full name.
    return array_map(function($name) {
      return array_reverse(explode(', ', $name, 2));
    }, $this->nodeValues($nodes));
  }

  /**
   * Get the names of the person(s) who contributed to the document.
   *
   * Examples of contributors are translators.
   *
   * @return string[]
   *   Contributor names.
   */
  public function getContributors() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:addau');
    return $this->nodeValues($nodes);
  }

  /**
   * Gets all the subjects of the document as a single string.
   *
   * Each subject will be separated by a semi-colon (;).
   *
   * @return string
   *   Subject string.
   */
  public function getSubjects() {
    $nodes = $this->recordXpath($this->recordId, '//primo:display/primo:subject');
    return $this->nodeValue($nodes);
  }

  /**
   * Gets the name of the system from which the document originates.
   *
   * E.g. Aleph.
   *
   * @return string
   *   Source system name.
   */
  public function getSource() {
    $nodes = $this->recordXpath($this->recordId, '//primo:control/primo:sourcesystem');
    return $this->nodeValue($nodes);
  }

  /**
   * Gets data about whether the document is part of a series.
   *
   * Data will usually be in the format [title]; [number]
   *
   * @return string
   *   Series data.
   */
  public function getSeriesData() {
    $nodes = $this->recordXpath($this->recordId, '//primo:addata/primo:seriestitle');
    return $this->nodeValue($nodes);
  }

  /**
   * Get the url to the online representation of the document.
   *
   * @return string
   *   Url.
   */
  public function getOnlineUrl() {
    $nodes = $this->recordXpath($this->recordId, '//search:LINKS/search:linktorsrc');
    return $this->nodeValue($nodes);
  }

}
