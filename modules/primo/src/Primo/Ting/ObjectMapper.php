<?php
/**
 * @file
 * The ObjectMapper class.
 */

namespace Primo\Ting;

use Matriphe\ISO639\ISO639;
use Primo\BriefSearch\Document;
use Ting\TingObject;
use Ting\TingObjectInterface;

/**
 * Maps from Primo Documents onto a TingObjectInterface implementation.
 */
class ObjectMapper {

  /**
   * The Primo document to be mapped.
   *
   * @var \Primo\BriefSearch\Document
   */
  protected $document;

  /**
   * Object constructor.
   *
   * @param \Primo\BriefSearch\Document $document
   *   The Primo document to map.
   */
  public function __construct(Document $document) {
    $this->document = $document;
  }

  /**
   * Maps the loaded Primo Document onto a TingObjectInterface.
   *
   * @param \Ting\TingObjectInterface|NULL $object
   *   An existing object to map the data onto. If none is provided a new
   *   TingObject instance is used.
   *
   * @return \Ting\TingObject|\Ting\TingObjectInterface
   *   The mapped object.
   */
  public function map(TingObjectInterface $object = NULL) {
    // Construct the object if it does not exist.
    if (NULL === $object) {
      $object = new TingObject();
    }

    // Populate the object. Simple Object properties we have a 1:1 counterpart
    // to in the Primo object is mapped directly. Properties that requires more
    // processing before they can be mapped are handled by instance map*()
    // functions.
    $object->setId($this->document->getRecordId());
    $object->setSourceId($this->document->getSourceRecordId());
    // TODO BBS-SAL: Implement isLocal() method.
    $object->setOwnerId($this->document->getSourceId());
    $object->setTitle($this->document->getTitle());
    // Primo does not distinguish between short and default title lengths.
    $object->setShortTitle($this->document->getTitle());
    $object->setAbstract($this->document->getLocalDisplayField(7));
    // TODO BBS-SAL: Implement getAge() method.
    // TODO BBS-SAL: Implement getAudience() method.
    $object->setContributors($this->document->getContributors());
    $object->setCreatorsFormatDefault($this->mapCreators(TingObjectInterface::NAME_FORMAT_DEFAULT));
    $object->setCreatorsFormatSurnameFirst($this->mapCreators(TingObjectInterface::NAME_FORMAT_SURNAME_FIRST));
    $object->setDescription($this->document->getDescription());
    $object->setExtent($this->document->getDisplayFormat());
    // TODO BBS-SAL: Implement getGenere() method.
    $object->setIsbn($this->mapIsbn());
    $object->setLanguage($this->mapLanguage());
    $object->setMaterialSource($this->document->getSource());
    $object->setOnlineUrl($this->document->getOnlineUrl());
    $object->setOnline(!empty($this->document->getOnlineUrl()));
    $object->setPublisher($this->document->getPublisher());
    $object->setSeriesDescription($this->mapSeriesDescription());
    $object->setSource($this->mapSource());
    $object->setSubjects($this->mapSubjects());
    // TODO BBS-SAL: Implement getTracks() method.
    // TODO BBS-SAL: Implement getURI() method.
    $object->setType($this->document->getType());
    $object->setYear($this->document->getYear());


    // Below are parts of the TingObjectInterface which the Primo modules
    // currently do not support.
    // Note that this does not necessarily mean that the information is not
    // available from Primo. It is just not implemented at the moment. Please
    // check each setter-invocation for any additional information.
    // We do not support classification.
    $object->setClassifications(FALSE);
    // The contents of this field is partly duplicated by getExtent().
    $object->setFormat(FALSE);
    $object->setIsPartOf([]);
    $object->setMusician([]);
    $object->setPegi(FALSE);
    $object->setReferenced([]);
    $object->setRelations([]);
    $object->setReplacedBy(FALSE);
    $object->setReplaces(FALSE);
    $object->setRights(FALSE);
    $object->setSeriesTitles(FALSE);
    $object->setSpatial(FALSE);
    $object->setSpoken(FALSE);
    $object->setSubTitles([]);
    // Primo does not distinguish between difference versions of the same
    // object.
    $object->setVersion(FALSE);

    return $object;
  }

  /**
   * Maps creator information.
   *
   * @param string $format
   *   TingObjectInterface::NAME_FORMAT_* formats to specify how the authors
   *   names should be formatted.
   *
   * @return string[].
   *   The list of formatted author-names, empty if none was found.
   */
  public function mapCreators($format) {
    // Create a mapper for each name format. A mapper should take an array of
    // elements for a name and combine them into a single string.
    $defaultMapper = function(array $nameElements) {
      return implode(' ', $nameElements);
    };
    $surnameFirstMapper = function(array $nameElements) {
      return implode(', ', array_reverse($nameElements));
    };
    $mapper = ($format === TingObjectInterface::NAME_FORMAT_SURNAME_FIRST) ? $surnameFirstMapper : $defaultMapper;

    return array_map($mapper, $this->document->getCreators());
  }

  /**
   * The ISBN of the material.
   *
   * Eg. "9780615384238"
   *
   * @return string[]
   *   Zero or more ISBNs.
   */
  public function mapIsbn() {
    // A Primo record may contain multiple ISBNs - ISBN-10 and ISBN-13.
    // Ding2 only works with a single ISBN value for an object and we prefer
    // ISBN-13 so sort values by length and return the longest.
    $isbns = $this->document->getIsbns();
    usort($isbns, function($a, $b) {
      return strlen($b) - strlen($a);
    });
    return reset($isbns);
  }

  /**
   * The language of the material.
   *
   * @return string|FALSE
   *   The language, FALSE if it could not be found.
   */
  public function mapLanguage() {
    $lang = $this->document->getLanguage();
    if (!empty($lang)) {
      // Languages returned by Primo is in ISO-639 format. To return something
      // understandable by users we convert it to English and let Drupal try to
      // translate it to the user language.
      $lang = (new ISO639())->languageByCode2b($lang);
      $lang = t($lang);
    }
    return (!empty($lang)) ? $lang : FALSE;
  }

  /**
   * Description of the series which the material is a part of.
   *
   * @return string|FALSE
   *   The series description, or FALSE if it could not be determined.
   */
  public function mapSeriesDescription() {
    // Series data contain both title of series and number for current document.
    // We only want the series title so split and return first element.
    $seriesData = explode(' ; ', $this->document->getSeriesData());
    return array_shift($seriesData);
  }

  /**
   * Title of the material from which this material stems.
   *
   * Eg. "Harry Potter and the philosopher's stone" is the source for
   *  "Harry Potter und der Stein der Weisen"
   *
   * @return string|FALSE
   *   The title of the source, or FALSE if it could not be determined.
   */
  public function mapSource() {
    $source = $this->document->getLocalDisplayField(6);
    // Source texts may contain the text 'Á frummáli: ' meaning 'In the original
    // language'. However such a prefix will be added by the calling code so
    // we remove it here.
    // Note that this is strictly tied to how Primo is used by Icelandic
    // libraries.
    return str_replace('Á frummáli: ', '', $source);
  }

  /**
   * Returns list of subjects/keywords for the material.
   *
   * @return string[]
   *   List of subjects, empty if none could be found.
   */
  public function mapSubjects() {
    $subjects = $this->document->getSubjects();
    // Primo returns subjects as a single string but Ding2 expects an array of
    // subject name strings. Explode by Primos delimiter.
    return explode(' ; ', $subjects);
  }
}
