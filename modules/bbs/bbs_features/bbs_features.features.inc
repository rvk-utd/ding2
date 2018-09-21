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

  // Exported nodequeues: education_page_main_content
  $nodequeues['education_page_main_content'] = array(
    'name' => 'education_page_main_content',
    'title' => 'Education page main content',
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
    'i18n' => 0,
    'insert_at_front' => 0,
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

  // Exported nodequeues: education_page_sub_content
  $nodequeues['education_page_sub_content'] = array(
    'name' => 'education_page_sub_content',
    'title' => 'Education page sub content',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: family_page_lower_left
  $nodequeues['family_page_lower_left'] = array(
    'name' => 'family_page_lower_left',
    'title' => 'Family page lower left',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: family_page_lower_right
  $nodequeues['family_page_lower_right'] = array(
    'name' => 'family_page_lower_right',
    'title' => 'Family page lower right',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: family_page_upper_left
  $nodequeues['family_page_upper_left'] = array(
    'name' => 'family_page_upper_left',
    'title' => 'Family page upper left',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: family_page_upper_right
  $nodequeues['family_page_upper_right'] = array(
    'name' => 'family_page_upper_right',
    'title' => 'Family page upper right',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

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
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
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
    'i18n' => 1,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
      2 => 'ding_page',
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
    'i18n' => 0,
    'insert_at_front' => 0,
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
    'i18n' => 0,
    'insert_at_front' => 0,
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
    'i18n' => 0,
    'insert_at_front' => 0,
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
      2 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: literature_main_content
  $nodequeues['literature_main_content'] = array(
    'name' => 'literature_main_content',
    'title' => 'Literature main content',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: literature_sub_content
  $nodequeues['literature_sub_content'] = array(
    'name' => 'literature_sub_content',
    'title' => 'Literature sub content',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_news',
      2 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: literature_third_content
  $nodequeues['literature_third_content'] = array(
    'name' => 'literature_third_content',
    'title' => 'Literature third content',
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
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_event',
      1 => 'ding_group',
      2 => 'ding_library',
      3 => 'ding_news',
      4 => 'ding_page',
      5 => 'panel',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: we_recommend
  $nodequeues['we_recommend'] = array(
    'name' => 'we_recommend',
    'title' => 'Recommended content',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ding_group',
      1 => 'ding_news',
      2 => 'ding_page',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
