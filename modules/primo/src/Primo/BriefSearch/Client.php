<?php


namespace Primo\BriefSearch;

use GuzzleHttp\ClientInterface;
use GuzzleHttp\Exception\RequestException;
use Primo\Exception\TransferException;

/**
 * Client for the Primo Brief Search webservice
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
   *   the institution)
   */
  public function __construct(ClientInterface $httpClient, $institution, $ipAddress) {
    $this->httpClient = $httpClient;
    $this->defaultParameters = [
      'institution' => $institution,
      'ip' => $ipAddress
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
  public function documents($recordIds) {
    $result = $this->search('rid,contains,' . implode($recordIds, ' OR '), 1, count($recordIds));
    return $result->getDocuments();
  }

  /**
   * Execute a search
   *
   * @param string $query
   *   The raw query string
   * @param int $offset
   *   The offset of the search results to return. Use 1 for the first result.
   * @param int $numResults
   *   The number of results to return.
   * @param array $parameters
   *   Addition query parameters to use for the query. See documentation for what
   *   options are available.
   *
   * @return \Primo\BriefSearch\Result
   *   The search result.
   *
   * @throws \Primo\Exception\TransferException
   *   If an error occurs during the execution of the search.
   */
  public function search($query, $offset, $numResults, $parameters = []) {
    $parameters += [
      'query' => $query,
      'indx' => $offset,
      'bulkSize' => $numResults,
    ] + $this->defaultParameters;
    try {
      $response = $this->httpClient->get('PrimoWebServices/xservice/search/brief', [
        'query' => $parameters
      ]);
      return new Result($response->getBody()->getContents());
    } catch (RequestException $e) {
      // Wrap the exception and rethrow.
      throw new TransferException($e->getMessage(), $e->getCode(), $e);
    }
  }

}
