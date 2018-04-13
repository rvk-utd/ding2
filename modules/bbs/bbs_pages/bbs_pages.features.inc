<?php
/**
 * @file
 * bbs_inspiration_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bbs_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function bbs_pages_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: ding_tabroll_frontpage
  $nodequeues['ding_tabroll_frontpage'] = array(
    'name' => 'ding_tabroll_frontpage',
    'title' => 'Front page tabroll',
    'subqueue_title' => '',
    'size' => 5,
    'link' => 'Add to front page',
    'link_remove' => 'Remove from front page',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => NULL,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_rolltab',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: inspiration_main_content
  $nodequeues['inspiration_main_content'] = array(
    'name' => 'inspiration_main_content',
    'title' => 'Inspiration Main Content',
    'subqueue_title' => '',
    'size' => 1,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_news',
      3 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: inspiration_subcontent_lower_lef
  $nodequeues['inspiration_subcontent_lower_lef'] = array(
    'name' => 'inspiration_subcontent_lower_lef',
    'title' => 'Inspiration subcontent lower left',
    'subqueue_title' => '',
    'size' => 2,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: inspiration_subcontent_lower_rig
  $nodequeues['inspiration_subcontent_lower_rig'] = array(
    'name' => 'inspiration_subcontent_lower_rig',
    'title' => 'Inspiration subcontent lower right',
    'subqueue_title' => '',
    'size' => 1,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_news',
      3 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: inspiration_subcontent_upper
  $nodequeues['inspiration_subcontent_upper'] = array(
    'name' => 'inspiration_subcontent_upper',
    'title' => 'Inspiration Subcontent upper',
    'subqueue_title' => '',
    'size' => 1,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
      2 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
