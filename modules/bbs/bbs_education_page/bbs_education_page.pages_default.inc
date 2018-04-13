<?php
/**
 * @file
 * bbs_education_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bbs_education_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'education_page';
  $page->task = 'page';
  $page->admin_title = 'Education page';
  $page->admin_description = '';
  $page->path = 'fraedsla';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_education_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'education_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'bbs_frontpage_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'menu' => NULL,
      'new-user' => NULL,
      'main-info' => NULL,
      'sec-info' => NULL,
      'secondary-content' => NULL,
      'tertiary-content' => NULL,
      'quaternary-content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '186a26fb-65cc-4aad-8d84-b2f1c7dc2053';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-06e91faf-ea31-4edb-a24c-1f5a0f4ca801';
    $pane->panel = 'main-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_13';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '06e91faf-ea31-4edb-a24c-1f5a0f4ca801';
    $display->content['new-06e91faf-ea31-4edb-a24c-1f5a0f4ca801'] = $pane;
    $display->panels['main-info'][0] = 'new-06e91faf-ea31-4edb-a24c-1f5a0f4ca801';
    $pane = new stdClass();
    $pane->pid = 'new-6f37aacb-ba59-4782-8ccf-a20629849e96';
    $pane->panel = 'menu';
    $pane->type = 'block';
    $pane->subtype = 'block-10';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6f37aacb-ba59-4782-8ccf-a20629849e96';
    $display->content['new-6f37aacb-ba59-4782-8ccf-a20629849e96'] = $pane;
    $display->panels['menu'][0] = 'new-6f37aacb-ba59-4782-8ccf-a20629849e96';
    $pane = new stdClass();
    $pane->pid = 'new-83c31366-6323-4754-b86b-255a8aff858d';
    $pane->panel = 'new-user';
    $pane->type = 'block';
    $pane->subtype = 'block-11';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '83c31366-6323-4754-b86b-255a8aff858d';
    $display->content['new-83c31366-6323-4754-b86b-255a8aff858d'] = $pane;
    $display->panels['new-user'][0] = 'new-83c31366-6323-4754-b86b-255a8aff858d';
    $pane = new stdClass();
    $pane->pid = 'new-896ca6f6-eba6-4a00-848b-a6da5bce4b11';
    $pane->panel = 'quaternary-content';
    $pane->type = 'views';
    $pane->subtype = 'library_content_roll';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '896ca6f6-eba6-4a00-848b-a6da5bce4b11';
    $display->content['new-896ca6f6-eba6-4a00-848b-a6da5bce4b11'] = $pane;
    $display->panels['quaternary-content'][0] = 'new-896ca6f6-eba6-4a00-848b-a6da5bce4b11';
    $pane = new stdClass();
    $pane->pid = 'new-8a621beb-907e-4d73-825d-ee5ee6431d18';
    $pane->panel = 'sec-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_14';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8a621beb-907e-4d73-825d-ee5ee6431d18';
    $display->content['new-8a621beb-907e-4d73-825d-ee5ee6431d18'] = $pane;
    $display->panels['sec-info'][0] = 'new-8a621beb-907e-4d73-825d-ee5ee6431d18';
    $pane = new stdClass();
    $pane->pid = 'new-19a64a0d-bf08-4bbe-94ea-01aa42464a97';
    $pane->panel = 'secondary-content';
    $pane->type = 'carousel';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '19a64a0d-bf08-4bbe-94ea-01aa42464a97';
    $display->content['new-19a64a0d-bf08-4bbe-94ea-01aa42464a97'] = $pane;
    $display->panels['secondary-content'][0] = 'new-19a64a0d-bf08-4bbe-94ea-01aa42464a97';
    $pane = new stdClass();
    $pane->pid = 'new-ce20f3d6-a366-443d-9abc-759c28296ce2';
    $pane->panel = 'secondary-content';
    $pane->type = 'carousel';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ce20f3d6-a366-443d-9abc-759c28296ce2';
    $display->content['new-ce20f3d6-a366-443d-9abc-759c28296ce2'] = $pane;
    $display->panels['secondary-content'][1] = 'new-ce20f3d6-a366-443d-9abc-759c28296ce2';
    $pane = new stdClass();
    $pane->pid = 'new-630ec12c-103a-46a8-ac6c-a6f869fbd8f4';
    $pane->panel = 'secondary-content';
    $pane->type = 'views';
    $pane->subtype = 'frontpage_events_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '6',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '630ec12c-103a-46a8-ac6c-a6f869fbd8f4';
    $display->content['new-630ec12c-103a-46a8-ac6c-a6f869fbd8f4'] = $pane;
    $display->panels['secondary-content'][2] = 'new-630ec12c-103a-46a8-ac6c-a6f869fbd8f4';
    $pane = new stdClass();
    $pane->pid = 'new-8b81f2e5-0aef-4747-b4e4-10a98f08ffa0';
    $pane->panel = 'tertiary-content';
    $pane->type = 'carousel';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8b81f2e5-0aef-4747-b4e4-10a98f08ffa0';
    $display->content['new-8b81f2e5-0aef-4747-b4e4-10a98f08ffa0'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-8b81f2e5-0aef-4747-b4e4-10a98f08ffa0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-06e91faf-ea31-4edb-a24c-1f5a0f4ca801';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages[''] = $page;

  return $pages;

}
