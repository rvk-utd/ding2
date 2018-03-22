<?php
/**
 * @file
 * bbs_nodequeues.features.inc
 */

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function bbs_nodequeues_fe_nodequeue_export_fields() {
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

  return $nodequeues;
}
