<?php

/**
 * @file
 * Implements searching in Primo.
 */

use Primo\Exception\TransferException;
use Primo\Ting\Collection;
use Primo\Ting\PrimoStatementRenderer;
use Primo\Ting\Result;
use Ting\Search\SearchProviderException;
use Ting\Search\TingSearchCommonFields;
use Ting\Search\TingSearchRequest;
use Ting\Search\TingSearchSort;

// TODO Remove this once Primo search provider is fully implemented.
// Ding does not support mixing multiple partial implementations of a provider
// so we fall back to OpenSearch while we implement Primo. Thus we need to
// load the OpenSearch search provider manually to have the functions available
// here.
module_load_include('inc', 'opensearch',
  'includes/opensearch.search');

/**
 * Get a list of material types from Primo.
 */
function primo_search_material_types() {
  // We cannot retrieve patron-friendly list of material types directy from
  // Primo. Instead we rely on an managed map from Primo material type ids to
  // material type names. Returning the values means returning the names as
  // expected by this hook implementation.
  $material_types = array_values(variable_get('primo_material_type_map', []));
  // Calling code requires material types to be in lower case.
  // @see ding_availability_field_formatter_view()
  return array_map('drupal_strtolower', $material_types);
}

/**
 * Get a list of Primo sources.
 *
 * @return string[]
 *   Primo source names.
 */
function primo_search_sources() {
  // We are not able to extract sources from Primo programmatically so instead
  // we maintain a list of them in the administration interface.
  $sources = variable_get('primo_source_systems', []);
  // Calling code requires sources to be in lower case.
  // @see ding_availability_field_formatter_view()
  return array_map('drupal_strtolower', $sources);
}

/**
 * Load objects from Primo.
 *
 * @param string[] $ids
 *   Array of ids to load from Primo.
 *
 * @return Ting\TingObjectInterface[]
 *   An array of loaded objects.
 *
 * @throws \Ting\Search\SearchProviderException
 *   Thrown if an error occurs.
 */
function primo_search_object_load(array $ids) {
  // First set up a list of id's we wish to load and a list of actual loads.
  $to_load = array_combine($ids, $ids);
  $loaded = [];

  // Keep track of loading for later logging.
  $misses = $failed = [];

  // Load existing objects from cache: Go through the argument list and attempt
  // a lookup, if we have a hit, remove the entry from the to_load list.
  array_walk($ids,
    function ($record_id) use (&$to_load, &$loaded) {
      if (($object = _primo_cache_get($record_id)) !== FALSE) {
        unset($to_load[$record_id]);
        $loaded[$record_id] = $object;
      }
    }
  );
  // Prepare any hits for logging.
  $hits = array_intersect($ids, array_keys($loaded));

  // Load any objects we don't have in the cache from primo.
  if (!empty($to_load)) {
    $client = primo_client();
    try {
      $documents = $client->documents($to_load);
      if (!empty($documents)) {
        // Warm the cache and map the documents into objects.
        $mapped = _primo_search_map_and_warm_cache_documents($documents);
        $loaded = array_merge($mapped, $loaded);

        // Any successfully mapped object counts as a cache miss.
        $misses = array_intersect($ids, array_keys($mapped));
      }
    }
    catch (TransferException $e) {
      throw new SearchProviderException('Exception occured while searching against primo', 0, $e);
    }
  }

  // Any id we have left now was not present in the cache and could not be
  // loaded from primo and should be counted as a failed load.
  $failed = array_diff(array_values($ids), array_keys($loaded));

  // Write statistics to the log.
  if (variable_get('primo_enable_logging', FALSE)) {
    $log_level = !empty($failed) ? WATCHDOG_WARNING : WATCHDOG_DEBUG;
    watchdog('primo',
      'Primo object load cache: @hit_count hits: @hit_ids @miss_count misses: @miss_ids @fail_count failures: @fail_ids',
      [
        '@hit_count' => count($hits),
        '@hit_ids' => implode(', ', $hits),
        '@miss_count' => count($misses),
        '@miss_ids' => implode(', ', $misses),
        '@fail_count' => count($failed),
        '@fail_ids' => implode(', ', $failed),
      ], $log_level
    );
  }



  return $loaded;
}

/**
 * Load a collection from Primo.
 *
 * @param string $id
 *   Id of material to load as a collection.
 *
 * @return Ting\TingObjectCollectionInterface
 *   The collection.
 *
 * @throws \Ting\Search\SearchProviderException
 *   Thrown if an error occurs.
 */
function primo_search_collection_load($id) {
  // We don't support collections, so load a single document whos id will be the
  // same as the "collections".
  return new Collection(primo_search_object_load([$id]));
}

/**
 * Perform a search.
 *
 * @param \Ting\Search\TingSearchRequest $ting_query
 *   The query to execute.
 *
 * @return \Ting\Search\TingSearchResultInterface
 *   The search result.
 *
 * @throws \Ting\Search\SearchProviderException
 *   Thrown if an error occurs.
 */
function primo_search_search(TingSearchRequest $ting_query) {
  $queries = [];
  $client = primo_client();

  // Add a general quoted free text search.
  if (!empty($free_text_query = $ting_query->getFullTextQuery())) {

    // Querying against the "any" field will:
    // "search against most of the (red: available) fields at once." as pre the
    // documentation.
    // We always use fuzzy searches, so no need for setFuzzy/isFuzzy.
    $queries['query'][] = 'any,contains,' . htmlspecialchars($free_text_query);
  }

  // Handle filters.
  if (!empty($field_filters = $ting_query->getFilters())) {
    $renderer = new PrimoStatementRenderer(_primo_common_field_mapping());
    $queries = array_merge_recursive($queries, $renderer->renderStatements($field_filters));
  }

  // Handle material filters.
  if (!empty($material_filters = $ting_query->getMaterialFilter())) {
    // Material filters is a list of material ids.
    $queries['query'][] = 'rid,contains,' . implode(' OR ', $material_filters);
  }

  // Handle raw query.
  if (!empty($raw_query = $ting_query->getRawQuery())) {
    // The query starts with "[", so we query for comma separated ID's.
    if (strpos($raw_query, '[') !== FALSE) {
      $ids = explode(',', trim($raw_query, '[]'));
      $ids = array_map('trim', $ids);
      $queries['query'][] = 'rid,contains,' . implode(' OR ', $ids);
    }
    // The query starts with '"', so we search for the title.
    elseif (strpos($raw_query, '"') !== FALSE) {
      $queries['query'][] = 'swtitle,begins_with,' . trim($raw_query, '"');
    }
    // If not, do a raw query.
    else {
      $queries['query'][] = $raw_query;
    }
  }

  $page = $ting_query->getPage();
  $count = $ting_query->getCount();

  // Empty sort string means default relevance sort is used.
  $sort_string = NULL;
  $sorts = $ting_query->getSorts();
  if (!empty($sorts)) {
    // Primo only supports a single sort order. The field name includes the
    // sort direction so extract and use the first one. Ignore the rest.
    $sort = array_shift($sorts);
    $sort_string = $sort->getField();
  }

  // Execute the search, return the result.
  try {
    $primo_result = $client->search($queries, $page, $count, $sort_string);
    $result = new Result($primo_result, $ting_query);

    // Pre-warm the cache so that subsequent loads of objects for the documents
    // in the result will be ready and won't require a new search.
    _primo_search_map_and_warm_cache_result($result);

    return $result;
  }
  catch (TransferException $e) {
    throw new SearchProviderException('Exception occurred while searching against primo', 0, $e);
  }
}

/**
 * Provide standard object ID's for Primo provider.
 *
 * @param array|string $ids
 *    Array with id's.
 *
 * @return array
 *    Array with multiple ID's.
 *    ID as key and Primo sourceid as value.
 */
function primo_search_object_ids($ids) {
  $translated_ids = array();

  if (is_array($ids)) {
    foreach ($ids as $id) {
      $translated_ids[$id] = variable_get('primo_sourceid') . $id;
    }
  }
  else {
    $translated_ids[$ids] = variable_get('primo_sourceid') . $ids;
  }

  return $translated_ids;
}

/**
 * Allows the provider to programmatically filter relations.
 *
 * @return array
 *   Filtered list.
 */
function primo_search_filter_relations($relations) {
  return opensearch_search_filter_relations($relations);
}

/**
 * Produce a list of relations we can handle.
 *
 * @return string[]
 *   Array of supported type-titles keyed by type name.
 */
function primo_search_supported_relations() {
  return opensearch_search_supported_relations();
}

/**
 * Returns a ting_relation render-array given a TingRelation.
 *
 * @param \TingRelation $relation
 *   The relation to render.
 *
 * @return array
 *   The render array.
 */
function primo_search_render_inline_relation(TingRelation $relation) {
  return opensearch_search_render_inline_relation($relation);
}

/**
 * Constructs a TingSearchRequest based on a "reference" search query.
 *
 * The implementation should assume that the user has entered a string with the
 * express purpose of finding a specific material. That is, if the string seems
 * to match the pattern of a unique material ID, the query should be constructed
 * to look up by id.
 *
 * The provider can also choose to support advanced provider-specific querying.
 *
 * @param string $query_string
 *   The user-provided search query.
 *
 * @return \Ting\Search\TingSearchRequest
 *   The prepared query object.
 */
function primo_search_prepare_reference_query($query_string) {
  $query = ting_start_query();

  // Search for rid if the query starts with the institution code.
  $source_id = variable_get('primo_sourceid');
  if (strpos($query_string, $source_id) !== FALSE) {
    // The wildcard "*" is not mentioned in the Primo documentation, however
    // it is necessary in order to get all ID's.
    $query = $query->withRawQuery('rid,contains,' . $query_string . '*');
  }
  // Do a fuzzy search.
  else {
    $query = $query->withRawQuery('swtitle,begins_with,' . $query_string);
  }

  return $query;
}

/**
 * Provide additional sort options.
 *
 * @return array
 *   List of sort options represented by their labels and a TingSearchSort
 *   instance. Keyed by a machine-name.
 */
function primo_search_sort_options() {
  // For Primo the direction is a part of the field name so we do not need to
  // set it. Default direction NONE is fine.
  return [
    'title' => [
      'label' => t('Title'),
      'sort' => new TingSearchSort('stitle'),
    ],
    'creator' => [
      'label' => t('Creator'),
      'sort' => new TingSearchSort('screator'),
    ],
    'date_descending' => [
      'label' => t('Date (Descending)'),
      'sort' => new TingSearchSort('scdate'),
    ],
    'date_ascending' => [
      'label' => t('Date (Ascending)'),
      'sort' => new TingSearchSort('scdate2'),
    ],
    'popularity' => [
      'label' => t('Popularity'),
      'sort' => new TingSearchSort('popularity'),
    ]
  ];
}

/**
 * Auto-complete callback for the ting search block.
 *
 * @param string $query
 *   The string to search suggestion with.
 *
 * @return array $items
 *   Items similar to the query.
 */
function primo_search_autocomplete($query) {
  $suggestions = [];

  try {
    $results = primo_client()
      ->search(['query' => ['swtitle,begins_with,' . urlencode($query)]], 1, 10)
      ->getDocuments();
  }
  catch (TransferException $e) {
    watchdog('primo', '@error_code: @message',
      ['@error_code' => $e->getCode(), '@message' => $e->getMessage()],
      WATCHDOG_ERROR
    );
    return $suggestions;
  }

  foreach ($results as $result) {
    $title = $result->getTitle();
    $suggestions[$title] = $title;
  }

  return $suggestions;
}

/**
 * Quotes a search string to make it compatible with the provider.
 *
 * @param string $search_string
 *   The search string.
 */
function primo_search_search_quote($search_string) {
  // We don't do escaping right now.
}
