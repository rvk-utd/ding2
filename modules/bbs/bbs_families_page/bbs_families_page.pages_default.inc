<?php
/**
 * @file
 * bbs_families_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bbs_families_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'families_page';
  $page->task = 'page';
  $page->admin_title = 'Families page';
  $page->admin_description = '';
  $page->path = 'born-og-fjolskyldur';
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
  $handler->name = 'page_families_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'families_page';
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
      'node-content' => NULL,
      'sidebar' => NULL,
      'secondary-content' => NULL,
      'tertiary-content' => NULL,
      'quaternary-content' => NULL,
      'menu' => NULL,
      'new-user' => NULL,
      'main-info' => NULL,
      'sec-info' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4a5100b1-3eb2-4bc8-9817-d02a4b8927f1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-358efa3b-107b-4475-b523-b68ce8177321';
    $pane->panel = 'main-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_16';
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
    $pane->uuid = '358efa3b-107b-4475-b523-b68ce8177321';
    $display->content['new-358efa3b-107b-4475-b523-b68ce8177321'] = $pane;
    $display->panels['main-info'][0] = 'new-358efa3b-107b-4475-b523-b68ce8177321';
    $pane = new stdClass();
    $pane->pid = 'new-c63442fe-935f-4002-a768-5ca2909801a3';
    $pane->panel = 'menu';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_16';
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
    $pane->uuid = 'c63442fe-935f-4002-a768-5ca2909801a3';
    $display->content['new-c63442fe-935f-4002-a768-5ca2909801a3'] = $pane;
    $display->panels['menu'][0] = 'new-c63442fe-935f-4002-a768-5ca2909801a3';
    $pane = new stdClass();
    $pane->pid = 'new-f05f35d7-8607-4b73-b303-003357b5696a';
    $pane->panel = 'new-user';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_18';
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
    $pane->uuid = 'f05f35d7-8607-4b73-b303-003357b5696a';
    $display->content['new-f05f35d7-8607-4b73-b303-003357b5696a'] = $pane;
    $display->panels['new-user'][0] = 'new-f05f35d7-8607-4b73-b303-003357b5696a';
    $pane = new stdClass();
    $pane->pid = 'new-e8060c3c-c7ef-4131-81a2-fca4859a9d98';
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
    $pane->uuid = 'e8060c3c-c7ef-4131-81a2-fca4859a9d98';
    $display->content['new-e8060c3c-c7ef-4131-81a2-fca4859a9d98'] = $pane;
    $display->panels['quaternary-content'][0] = 'new-e8060c3c-c7ef-4131-81a2-fca4859a9d98';
    $pane = new stdClass();
    $pane->pid = 'new-fcc12696-f17f-4fbd-ae77-e086776134f2';
    $pane->panel = 'sec-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_17';
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
    $pane->uuid = 'fcc12696-f17f-4fbd-ae77-e086776134f2';
    $display->content['new-fcc12696-f17f-4fbd-ae77-e086776134f2'] = $pane;
    $display->panels['sec-info'][0] = 'new-fcc12696-f17f-4fbd-ae77-e086776134f2';
    $pane = new stdClass();
    $pane->pid = 'new-e191fae6-26ed-4403-bc8b-512f708904ab';
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
    $pane->uuid = 'e191fae6-26ed-4403-bc8b-512f708904ab';
    $display->content['new-e191fae6-26ed-4403-bc8b-512f708904ab'] = $pane;
    $display->panels['secondary-content'][0] = 'new-e191fae6-26ed-4403-bc8b-512f708904ab';
    $pane = new stdClass();
    $pane->pid = 'new-654fe401-55bc-499c-b1b3-efb2aac8ca5e';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '654fe401-55bc-499c-b1b3-efb2aac8ca5e';
    $display->content['new-654fe401-55bc-499c-b1b3-efb2aac8ca5e'] = $pane;
    $display->panels['secondary-content'][1] = 'new-654fe401-55bc-499c-b1b3-efb2aac8ca5e';
    $pane = new stdClass();
    $pane->pid = 'new-343e5385-ce27-4e9f-9a1d-8e6c6b138449';
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
    $pane->uuid = '343e5385-ce27-4e9f-9a1d-8e6c6b138449';
    $display->content['new-343e5385-ce27-4e9f-9a1d-8e6c6b138449'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-343e5385-ce27-4e9f-9a1d-8e6c6b138449';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e191fae6-26ed-4403-bc8b-512f708904ab';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages[''] = $page;

  return $pages;

}
