<?php

/**
 * @file
 * Implements searching in Primo.
 */

use Primo\BriefSearch\Document;
use Primo\Exception\TransferException;
use Primo\Ting\Collection;
use Primo\Ting\ObjectMapper;
use Primo\Ting\Result;
use Ting\Search\SearchProviderException;
use Ting\Search\TingSearchRequest;

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
  return opensearch_search_material_types();
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
  return variable_get('primo_source_systems', []);
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
  $query = '';
  $client = primo_client();

  // Add a general quoted free text search.
  if (!empty($free_text_query = $ting_query->getFullTextQuery())) {

    // Querying against the "any" field will:
    // "search against most of the (red: available) fields at once." as pre the
    // documentation.
    // We always use fuzzy searches, so no need for setFuzzy/isFuzzy.
    $query .= 'any,contains,' . urlencode($free_text_query);
  }

  // We use a free text search instead of the raw query.
  if (!empty($raw_query = $ting_query->getRawQuery())) {
    $query .= 'any,contains,' . urlencode($raw_query);
  }

  $page = $ting_query->getPage();
  $count = $ting_query->getCount();

  // Execute the search, return the result.
  try {
    $primo_result = $client->search($query, $page, $count);
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
 * Mapping between common fields and their provider-specific name.
 *
 * @return array
 *   Mapping between TingSearchCommonFields::* fields and their provider-
 *   specific counterpart.
 */
function primo_search_map_common_condition_fields() {
  return opensearch_search_map_common_condition_fields();
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
  return opensearch_search_prepare_reference_query($query_string);
}

/**
 * Provide additional sort options.
 *
 * @return array
 *   List of sort options represented by their labels and a TingSearchSort
 *   instance. Keyed by a machine-name.
 */
function primo_search_sort_options() {
  return opensearch_search_sort_options();
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
  // TODO: Only search on titles, and do something to speed up the query.
  $results = ting_start_query()->setCount(10)->setFullTextQuery($query)->execute();

  $suggestions = [];
  foreach ($results->getTingEntityCollections() as $collection) {
    $suggestions[$collection->getTitle()] = $collection->getTitle();
  }

  return $suggestions;
}
