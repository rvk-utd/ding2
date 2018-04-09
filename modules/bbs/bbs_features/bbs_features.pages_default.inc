<?php
/**
 * @file
 * bbs_features.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bbs_features_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bokmenntir';
  $page->task = 'page';
  $page->admin_title = 'literature';
  $page->admin_description = '';
  $page->path = 'bokmenntir';
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
  $handler->name = 'page_bokmenntir__panel';
  $handler->task = 'page';
  $handler->subtask = 'bokmenntir';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'BBS Literature',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'literature',
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
  $display->title = 'Bókmenntir';
  $display->uuid = 'ff9e788f-ee82-422e-b1eb-7908807143e5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f161c17d-1fb8-4f57-86bd-914156b99b9e';
    $pane->panel = 'main-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_7';
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
    $pane->uuid = 'f161c17d-1fb8-4f57-86bd-914156b99b9e';
    $display->content['new-f161c17d-1fb8-4f57-86bd-914156b99b9e'] = $pane;
    $display->panels['main-info'][0] = 'new-f161c17d-1fb8-4f57-86bd-914156b99b9e';
    $pane = new stdClass();
    $pane->pid = 'new-01508884-c06f-4c06-97e5-b531238f421b';
    $pane->panel = 'new-user';
    $pane->type = 'block';
    $pane->subtype = 'block-8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => 'BBS Literature Block 1',
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
    $pane->uuid = '01508884-c06f-4c06-97e5-b531238f421b';
    $display->content['new-01508884-c06f-4c06-97e5-b531238f421b'] = $pane;
    $display->panels['new-user'][0] = 'new-01508884-c06f-4c06-97e5-b531238f421b';
    $pane = new stdClass();
    $pane->pid = 'new-1b822b47-0ce4-466d-ab27-68a9e18efc20';
    $pane->panel = 'new-user';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
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
    $pane->uuid = '1b822b47-0ce4-466d-ab27-68a9e18efc20';
    $display->content['new-1b822b47-0ce4-466d-ab27-68a9e18efc20'] = $pane;
    $display->panels['new-user'][1] = 'new-1b822b47-0ce4-466d-ab27-68a9e18efc20';
    $pane = new stdClass();
    $pane->pid = 'new-bffd521f-4004-45a9-ac41-67bac21b145e';
    $pane->panel = 'sec-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_8';
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
    $pane->uuid = 'bffd521f-4004-45a9-ac41-67bac21b145e';
    $display->content['new-bffd521f-4004-45a9-ac41-67bac21b145e'] = $pane;
    $display->panels['sec-info'][0] = 'new-bffd521f-4004-45a9-ac41-67bac21b145e';
    $pane = new stdClass();
    $pane->pid = 'new-66273304-d149-4276-bff1-899931d53dec';
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
    $pane->uuid = '66273304-d149-4276-bff1-899931d53dec';
    $display->content['new-66273304-d149-4276-bff1-899931d53dec'] = $pane;
    $display->panels['secondary-content'][0] = 'new-66273304-d149-4276-bff1-899931d53dec';
    $pane = new stdClass();
    $pane->pid = 'new-c93bb4da-cbd9-4930-99ce-a1d101ca6a67';
    $pane->panel = 'secondary-content';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-events';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c93bb4da-cbd9-4930-99ce-a1d101ca6a67';
    $display->content['new-c93bb4da-cbd9-4930-99ce-a1d101ca6a67'] = $pane;
    $display->panels['secondary-content'][1] = 'new-c93bb4da-cbd9-4930-99ce-a1d101ca6a67';
    $pane = new stdClass();
    $pane->pid = 'new-fe5862c3-e34a-40d3-a6ad-247f6b327657';
    $pane->panel = 'tertiary-content';
    $pane->type = 'views';
    $pane->subtype = 'recommended_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '',
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
    $pane->uuid = 'fe5862c3-e34a-40d3-a6ad-247f6b327657';
    $display->content['new-fe5862c3-e34a-40d3-a6ad-247f6b327657'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-fe5862c3-e34a-40d3-a6ad-247f6b327657';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-01508884-c06f-4c06-97e5-b531238f421b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages[''] = $page;

  return $pages;

}
