<?php
/**
 * @file
 * bbs_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bbs_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function bbs_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function bbs_features_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: frontpage_main_event
  $nodequeues['frontpage_main_event'] = array(
    'name' => 'frontpage_main_event',
    'title' => 'Frontpage main event',
    'subqueue_title' => '',
    'size' => 1,
    'link' => 'Add a highlight',
    'link_remove' => 'Remove',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 1,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: frontpage_sub_pages
  $nodequeues['frontpage_sub_pages'] = array(
    'name' => 'frontpage_sub_pages',
    'title' => 'Frontpage sub pages',
    'subqueue_title' => '',
    'size' => 2,
    'link' => 'Add a page',
    'link_remove' => 'Remove a page',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 1,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
