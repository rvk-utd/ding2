<?php

namespace Primo\BriefSearch;

use GuzzleHttp\ClientInterface;
use GuzzleHttp\Exception\RequestException;
use Primo\Exception\TransferException;

/**
 * Client for the Primo Brief Search webservice.
 *
 * @see https://developers.exlibrisgroup.com/primo/apis/webservices/xservices/search/briefsearch
 */
class Client {

  /**
   * The HTTP client used to access the service.
   *
   * @var \GuzzleHttp\ClientInterface
   */
  protected $httpClient;

  /**
   * Default parameters to send when accessing the service.
   *
   * @var array
   */
  protected $defaultParameters;

  /**
   * Commaseperated list of of scopes the search should be done within.
   *
   * @var string
   */
  protected $locationScopes;

  /**
   * Client constructor.
   *
   * @param \GuzzleHttp\ClientInterface $httpClient
   *   The HTTP client used to access the service. It should already have a
   *   base url with the Primo protocol, hostname and port.
   * @param string $institution
   *   The institution code. Relevant for restricted scopes or for when
   *   searching against Primo Central.
   * @param string $ipAddress
   *   The client IP. This will help to identify the institution in cases the
   *   institution was not identified (according to the IP range associated with
   *   the institution).
   * @param string $scopes
   *   Comma-seperated list of location scopes the search should be done within.
   */
  public function __construct(ClientInterface $httpClient, $institution, $ipAddress, $scopes = NULL) {
    $this->httpClient = $httpClient;
    $this->locationScopes = $scopes;
    $this->defaultParameters = [
      'institution' => [$institution],
      'ip' => [$ipAddress],
    ];
  }

  /**
   * Retrieve a single document.
   *
   * @param string $recordId
   *   Record id for the document to retrive.
   *
   * @return \Primo\BriefSearch\Document
   *   The corresponding document.
   *
   * @throws \Primo\Exception\TransferException
   *   Thrown if an error occurs during retrieval.
   */
  public function document($recordId) {
    $docs = $this->documents([$recordId]);
    return reset($docs);
  }

  /**
   * Retrieve multiple documents.
   *
   * @param string[] $recordIds
   *   Record ids for the documents to retrive.
   *
   * @return \Primo\BriefSearch\Document[]
   *   An array of the corresponding documents keyed by record id.
   *
   * @throws \Primo\Exception\TransferException
   *   Thrown if an error occurs during retrieval.
   */
  public function documents(array $recordIds) {
    $result = $this->search(['query' => 'rid,contains,' . implode($recordIds, ' OR ')], 1, count($recordIds));
    return $result->getDocuments();
  }

  /**
   * Validate a Primo thumbnail url.
   *
   * Primo may return thumbnail urls to resources which are in fact not
   * images. This method will check verify that a url is a valid thumbnail.
   *
   * @param string $url
   *   A potential thumbnail url.
   *
   * @return bool
   *   Whether the url is a valid thumbnail url.
   */
  public function validateThumbnail($url) {
    // Use HEAD as we only care about status code and content type here.
    try {
      $response = $this->httpClient->head($url);
      // According to docs content type should be a string but is really a array
      // with a single string entry.
      /* @var string[] $contentType */
      $contentType = $response->getHeader('Content-Type');
      return stripos(implode('', $contentType), 'image') === 0;
    }
    catch (RequestException $e) {
      if ($e->getResponse()->getStatusCode() != 404) {
        watchdog_exception('primo', $e);
      }
      return FALSE;
    }
  }

  /**
   * Execute a search.
   *
   * @param array $queryParameters
   *   List of query-parameters on the form [key => [val1, val2...]].
   *   what options are available.
   * @param int $offset
   *   The offset of the search results to return. Use 1 for the first result.
   * @param int $numResults
   *   The number of results to return.
   * @param string $sort
   *   Specifies the type of sort to perform. If this parameter is not specified
   *   or left empty, the system uses the relevance sort.
   *
   * @return \Primo\BriefSearch\Result
   *   The search result.
   *
   * @throws \Primo\Exception\TransferException
   *   If an error occurs during the execution of the search.
   */
  public function search(array $queryParameters, $offset, $numResults, $sort = NULL) {
    // Set user-specified "runtime" values.
    $queryParameters['indx'] = [$offset];
    $queryParameters['bulkSize'] = [$numResults];
    if (NULL !== $sort) {
      $queryParameters['sortField'] = [$sort];
    }

    // Add in "static" defaults.
    $queryParameters = array_merge_recursive($queryParameters, $this->defaultParameters);

    // If we're configured to search in a scope, add it.
    if (!empty($this->locationScopes)) {
      $queryParameters['loc'][] = 'local,scope:(' . $this->locationScopes . ')';
    }
    try {
      $response = $this->httpClient->get('PrimoWebServices/xservice/search/brief', [
        'query' => \GuzzleHttp\Psr7\build_query($queryParameters),
      ]);
      return new Result($response->getBody()->getContents());
    }
    catch (RequestException $e) {
      // Wrap the exception and rethrow.
      throw new TransferException($e->getMessage(), $e->getCode(), $e);
    }
  }

}
