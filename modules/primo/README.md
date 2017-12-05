# Primo search provider
This provider integrates Ding with Ex Libris Primo for searches.

## Configuration
The provider is configured via admin/config/ding/provider/primo 

## Caching
Provider-specific search-results are represented by \Primo\BriefSearch\Result 
instances and individual documents as \PrimoBriefSearch\Document. As these 
relies on an internal DomDocument instance that is not suitable for caching, 
we instead map each document to a TingObject instance and cache this value-object
 instead.

The mapping and caching is performed via the _primo_search_map_and_warm_cache_* 
functions which in turn uses _primo_cache_set for the actual cache-write.

## Relevant implementation details
Primo does not support the concept of representing a collection of objects as
a single "Collection". The Primo provider will in effect represent each object
as a collection with a single items in it.
