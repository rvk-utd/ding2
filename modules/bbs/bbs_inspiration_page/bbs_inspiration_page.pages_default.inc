<?php
/**
 * @file
 * bbs_inspiration_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bbs_inspiration_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'inspiration';
  $page->task = 'page';
  $page->admin_title = 'inspiration';
  $page->admin_description = '';
  $page->path = 'innblastur';
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
  $handler->name = 'page_inspiration__panel';
  $handler->task = 'page';
  $handler->subtask = 'inspiration';
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
  $display->uuid = 'dc911f3b-6d2c-47fc-9bda-a284ce6d5c5b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-91536b41-d0f7-487f-9770-f4e107819515';
    $pane->panel = 'main-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_9';
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
    $pane->uuid = '91536b41-d0f7-487f-9770-f4e107819515';
    $display->content['new-91536b41-d0f7-487f-9770-f4e107819515'] = $pane;
    $display->panels['main-info'][0] = 'new-91536b41-d0f7-487f-9770-f4e107819515';
    $pane = new stdClass();
    $pane->pid = 'new-850b24fb-11df-4113-a1c7-dc8a77798d98';
    $pane->panel = 'menu';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_10';
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
    $pane->uuid = '850b24fb-11df-4113-a1c7-dc8a77798d98';
    $display->content['new-850b24fb-11df-4113-a1c7-dc8a77798d98'] = $pane;
    $display->panels['menu'][0] = 'new-850b24fb-11df-4113-a1c7-dc8a77798d98';
    $pane = new stdClass();
    $pane->pid = 'new-ff578c13-fbda-4ac4-b868-9248a84d7e1f';
    $pane->panel = 'new-user';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_12';
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
    $pane->uuid = 'ff578c13-fbda-4ac4-b868-9248a84d7e1f';
    $display->content['new-ff578c13-fbda-4ac4-b868-9248a84d7e1f'] = $pane;
    $display->panels['new-user'][0] = 'new-ff578c13-fbda-4ac4-b868-9248a84d7e1f';
    $pane = new stdClass();
    $pane->pid = 'new-b830cb91-f97f-44fd-8547-11ffa85918ee';
    $pane->panel = 'quaternary-content';
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
    $pane->uuid = 'b830cb91-f97f-44fd-8547-11ffa85918ee';
    $display->content['new-b830cb91-f97f-44fd-8547-11ffa85918ee'] = $pane;
    $display->panels['quaternary-content'][0] = 'new-b830cb91-f97f-44fd-8547-11ffa85918ee';
    $pane = new stdClass();
    $pane->pid = 'new-3b63e5b0-d225-4523-9284-c8cdca7553ed';
    $pane->panel = 'sec-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_11';
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
    $pane->uuid = '3b63e5b0-d225-4523-9284-c8cdca7553ed';
    $display->content['new-3b63e5b0-d225-4523-9284-c8cdca7553ed'] = $pane;
    $display->panels['sec-info'][0] = 'new-3b63e5b0-d225-4523-9284-c8cdca7553ed';
    $pane = new stdClass();
    $pane->pid = 'new-305073a3-1e0e-490e-90d5-740f592d1bd9';
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
    $pane->uuid = '305073a3-1e0e-490e-90d5-740f592d1bd9';
    $display->content['new-305073a3-1e0e-490e-90d5-740f592d1bd9'] = $pane;
    $display->panels['secondary-content'][0] = 'new-305073a3-1e0e-490e-90d5-740f592d1bd9';
    $pane = new stdClass();
    $pane->pid = 'new-db9e6a43-b23a-4452-88f5-bb50c1bd296d';
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
    $pane->uuid = 'db9e6a43-b23a-4452-88f5-bb50c1bd296d';
    $display->content['new-db9e6a43-b23a-4452-88f5-bb50c1bd296d'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-db9e6a43-b23a-4452-88f5-bb50c1bd296d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-91536b41-d0f7-487f-9770-f4e107819515';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages[''] = $page;

  return $pages;

}
