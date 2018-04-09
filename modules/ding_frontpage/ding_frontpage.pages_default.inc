<?php
/**
 * @file
 * ding_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ding_frontpage_default_page_manager_pages()
{
    $pages = array();
    $page = new stdClass();
    $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
    $page->api_version = 1;
    $page->name = 'ding_frontpage';
    $page->task = 'page';
    $page->admin_title = 'Ding frontpage';
    $page->admin_description = 'Front page.';
    $page->path = 'ding_frontpage';
    $page->access = array(
        'type' => 'none',
        'settings' => NULL,
    );
    $page->menu = array();
    $page->arguments = array();
    $page->conf = array(
        'admin_paths' => FALSE,
    );
    $page->default_handlers = array();
    $handler = new stdClass();
    $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'page_ding_frontpage_panel_context';
    $handler->task = 'page';
    $handler->subtask = 'ding_frontpage';
    $handler->handler = 'panel_context';
    $handler->weight = 0;
    $handler->conf = array(
        'title' => 'Ding frontpage',
        'no_blocks' => 0,
        'pipeline' => 'ipe',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
    );
    $display = new panels_display();
    $display->layout = 'ding_layout_1';
    $display->layout_settings = array();
    $display->panel_settings = array(
        'style_settings' => array(
            'default' => NULL,
            'top' => NULL,
            'left' => NULL,
            'right' => NULL,
            'bottom' => NULL,
            'top_secondary' => NULL,
            'main_content' => NULL,
            'main_left_right' => NULL,
            'main_right_right' => NULL,
            'attachment_4_1' => NULL,
            'attachment_4_2' => NULL,
            'attachment_4_3' => NULL,
            'attachment_4_4' => NULL,
            'attachment_3_1' => NULL,
            'attachment_3_2' => NULL,
            'attachment_3_3' => NULL,
            'attachment_2_1' => NULL,
            'attachment_2_2' => NULL,
            'attachment_1_1' => NULL,
            'primary' => NULL,
            'secondary' => NULL,
            'tertiary' => NULL,
        ),
    );
    $display->cache = array();
    $display->title = '';
    $display->uuid = '6795d6ae-3c57-4fb4-b339-3d6373acce88';
    $display->content = array();
    $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74a49488-f11d-40b6-8211-52e84c8b296a';
    $pane->panel = 'primary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_tabroll-ding_frontpage_tabroll';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '74a49488-f11d-40b6-8211-52e84c8b296a';
    $display->content['new-74a49488-f11d-40b6-8211-52e84c8b296a'] = $pane;
    $display->panels['primary'][0] = 'new-74a49488-f11d-40b6-8211-52e84c8b296a';
    $pane = new stdClass();
    $pane->pid = 'new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $pane->panel = 'primary';
    $pane->type = 'carousel';
    $pane->subtype = 'carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_title' => 1,
        'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $display->content['new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0'] = $pane;
    $display->panels['primary'][1] = 'new-18cfc092-1d0f-42e4-bde8-8a6e314c9bd0';
    $pane = new stdClass();
    $pane->pid = 'new-3f5761b9-1db4-4dc9-87cb-13e33008a1fc';
    $pane->panel = 'primary';
    $pane->type = 'interaction_pane';
    $pane->subtype = 'interaction_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'count' => '5',
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
    $pane->uuid = '3f5761b9-1db4-4dc9-87cb-13e33008a1fc';
    $display->content['new-3f5761b9-1db4-4dc9-87cb-13e33008a1fc'] = $pane;
    $display->panels['primary'][2] = 'new-3f5761b9-1db4-4dc9-87cb-13e33008a1fc';
    $pane = new stdClass();
    $pane->pid = 'new-5e2a0d2d-7b27-498e-a368-d4e9a2888769';
    $pane->panel = 'primary';
    $pane->type = 'campaign';
    $pane->subtype = 'campaign';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'ding_campaign_count' => 3,
        'ding_campaign_offset' => 0,
        'ding_campaign_style' => 'ding_campaign_full_width',
        'context' => array(
            0 => 'empty',
            1 => 'empty',
            2 => 'empty',
            3 => 'empty',
        ),
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5e2a0d2d-7b27-498e-a368-d4e9a2888769';
    $display->content['new-5e2a0d2d-7b27-498e-a368-d4e9a2888769'] = $pane;
    $display->panels['primary'][3] = 'new-5e2a0d2d-7b27-498e-a368-d4e9a2888769';
    $pane = new stdClass();
    $pane->pid = 'new-6fbe82af-b670-4746-90bf-a44ac1007db4';
    $pane->panel = 'primary';
    $pane->type = 'serendipity_ting_object';
    $pane->subtype = 'serendipity_ting_object';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'view_mode' => 'teaser',
        'sort_weight' => FALSE,
        'max' => '20',
        'min' => '10',
        'random' => 1,
        'selected_keys' => array(
            'ting_object' => 'ting_object',
            'frontpage' => 'frontpage',
        ),
        'context' => array(
            0 => 'empty',
            1 => 'empty',
            2 => 'empty',
            3 => 'empty',
        ),
        'override_title' => 0,
        'override_title_text' => '',
        'override_title_heading' => 'h2',
    );
    $pane->cache = array(
        'method' => 'lazy',
        'settings' => array(
            'load_strategy' => 'pane-visible',
            'show_spinner' => 1,
            'load_text' => '',
        ),
    );
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array(
        'css_id' => '',
        'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6fbe82af-b670-4746-90bf-a44ac1007db4';
    $display->content['new-6fbe82af-b670-4746-90bf-a44ac1007db4'] = $pane;
    $display->panels['primary'][4] = 'new-6fbe82af-b670-4746-90bf-a44ac1007db4';
    $pane = new stdClass();
    $pane->pid = 'new-ca2f62ff-8c78-44c0-9259-6cf568418012';
    $pane->panel = 'secondary';
    $pane->type = 'popular';
    $pane->subtype = 'popular';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'month' => '',
        'libcode' => 0,
        'override_title' => 1,
        'override_title_text' => 'Månedens populæreste titler',
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
    $pane->uuid = 'ca2f62ff-8c78-44c0-9259-6cf568418012';
    $display->content['new-ca2f62ff-8c78-44c0-9259-6cf568418012'] = $pane;
    $display->panels['secondary'][0] = 'new-ca2f62ff-8c78-44c0-9259-6cf568418012';
    $pane = new stdClass();
    $pane->pid = 'new-20a8af4e-90a0-42a4-be60-89cb72e44127';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_news-ding_news_frontpage_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_title' => 1,
        'override_title_text' => 'Library news',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array(
        'css_id' => '',
        'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '20a8af4e-90a0-42a4-be60-89cb72e44127';
    $display->content['new-20a8af4e-90a0-42a4-be60-89cb72e44127'] = $pane;
    $display->panels['secondary'][1] = 'new-20a8af4e-90a0-42a4-be60-89cb72e44127';
    $pane = new stdClass();
    $pane->pid = 'new-6af18880-acd3-436c-a1e3-39581aa3b62a';
    $pane->panel = 'secondary';
    $pane->type = 'all_opening_hours';
    $pane->subtype = 'all_opening_hours';
    $pane->shown = TRUE;
    $pane->access = array(
        'plugins' => array(
            0 => array(
                'name' => 'opening_hours_frontpage',
                'settings' => NULL,
                'not' => FALSE,
            ),
        ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6af18880-acd3-436c-a1e3-39581aa3b62a';
    $display->content['new-6af18880-acd3-436c-a1e3-39581aa3b62a'] = $pane;
    $display->panels['secondary'][2] = 'new-6af18880-acd3-436c-a1e3-39581aa3b62a';
    $pane = new stdClass();
    $pane->pid = 'new-1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $pane->panel = 'secondary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_event-ding_event_list_frontpage';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_title' => 0,
        'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array(
        'css_id' => '',
        'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $display->content['new-1235d134-3c15-4d11-86e4-a48f9c8737b3'] = $pane;
    $display->panels['secondary'][3] = 'new-1235d134-3c15-4d11-86e4-a48f9c8737b3';
    $pane = new stdClass();
    $pane->pid = 'new-21e4a892-88bb-4aa3-9fc4-fa91c0333938';
    $pane->panel = 'tertiary';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_groups-panel_pane_frontpage';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'override_title' => 1,
        'override_title_text' => 'Udvalgte temaer',
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
    $pane->uuid = '21e4a892-88bb-4aa3-9fc4-fa91c0333938';
    $display->content['new-21e4a892-88bb-4aa3-9fc4-fa91c0333938'] = $pane;
    $display->panels['tertiary'][0] = 'new-21e4a892-88bb-4aa3-9fc4-fa91c0333938';
    $display->hide_title = PANELS_TITLE_NONE;
    $display->title_pane = '0';
    $handler->conf['display'] = $display;
    $page->default_handlers[$handler->name] = $handler;
    $pages['Ding Frontpage'] = $page;

    $handler = new stdClass();
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'page_ding_frontpage__bbs-frontpage';
    $handler->task = 'page';
    $handler->subtask = 'ding_frontpage';
    $handler->handler = 'panel_context';
    $handler->weight = 1;
    $handler->conf = array(
        'title' => 'BBS Frontpage',
        'no_blocks' => 0,
        'pipeline' => 'ipe',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'name' => 'bbs-frontpage',
    );
    $display = new panels_display();
    $display->layout = 'bbs_frontpage_layout';
    $display->layout_settings = array();
    $display->panel_settings = array(
        'style_settings' => array(
            'default' => NULL,
            'top' => NULL,
            'left' => NULL,
            'right' => NULL,
            'bottom' => NULL,
            'top_secondary' => NULL,
            'main_content' => NULL,
            'main_left_right' => NULL,
            'main_right_right' => NULL,
            'attachment_4_1' => NULL,
            'attachment_4_2' => NULL,
            'attachment_4_3' => NULL,
            'attachment_4_4' => NULL,
            'attachment_3_1' => NULL,
            'attachment_3_2' => NULL,
            'attachment_3_3' => NULL,
            'attachment_2_1' => NULL,
            'attachment_2_2' => NULL,
            'attachment_1_1' => NULL,
            'primary' => NULL,
            'secondary' => NULL,
            'tertiary' => NULL,
            'menu' => NULL,
            'new-user' => NULL,
            'new-user2' => NULL,
            'main-info' => NULL,
            'sec-info' => NULL,
            'sec-info2' => NULL,
            'secondary-content' => NULL,
            'tertiary-content' => NULL,
            'quaternary-content' => NULL,
        ),
        'style' => 'default',
    );
    $display->cache = array();
    $display->title = '';
    $display->uuid = '6795d6ae-3c57-4fb4-b339-3d6373acce88';
    $display->content = array();
    $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-41a7473c-dff3-4009-9691-680fd76d2f80';
    $pane->panel = 'main-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_5';
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
        'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
        'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '41a7473c-dff3-4009-9691-680fd76d2f80';
    $display->content['new-41a7473c-dff3-4009-9691-680fd76d2f80'] = $pane;
    $display->panels['main-info'][0] = 'new-41a7473c-dff3-4009-9691-680fd76d2f80';
    $pane = new stdClass();
    $pane->pid = 'new-9bfff131-d8d9-4a78-a792-563777923dff';
    $pane->panel = 'menu';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-frontpage-menu';
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
    $pane->css = array(
        'css_id' => '',
        'css_class' => 'column-item',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9bfff131-d8d9-4a78-a792-563777923dff';
    $display->content['new-9bfff131-d8d9-4a78-a792-563777923dff'] = $pane;
    $display->panels['menu'][0] = 'new-9bfff131-d8d9-4a78-a792-563777923dff';
    $pane = new stdClass();
    $pane->pid = 'new-b7111054-db08-4b1f-8898-cefb96ae9c21';
    $pane->panel = 'new-user';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
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
    $pane->css = array(
        'css_id' => '',
        'css_class' => 'column-item',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b7111054-db08-4b1f-8898-cefb96ae9c21';
    $display->content['new-b7111054-db08-4b1f-8898-cefb96ae9c21'] = $pane;
    $display->panels['new-user'][0] = 'new-b7111054-db08-4b1f-8898-cefb96ae9c21';
    $pane = new stdClass();
    $pane->pid = 'new-b2beaeaa-380c-4439-b605-3d5540bf71a8';
    $pane->panel = 'new-user';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
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
    $pane->uuid = 'b2beaeaa-380c-4439-b605-3d5540bf71a8';
    $display->content['new-b2beaeaa-380c-4439-b605-3d5540bf71a8'] = $pane;
    $display->panels['new-user'][1] = 'new-b2beaeaa-380c-4439-b605-3d5540bf71a8';
    $pane = new stdClass();
    $pane->pid = 'new-6dd6ceed-7ae6-4ec3-8710-33760e8fdd57';
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
    $pane->uuid = '6dd6ceed-7ae6-4ec3-8710-33760e8fdd57';
    $display->content['new-6dd6ceed-7ae6-4ec3-8710-33760e8fdd57'] = $pane;
    $display->panels['quaternary-content'][0] = 'new-6dd6ceed-7ae6-4ec3-8710-33760e8fdd57';
    $pane = new stdClass();
    $pane->pid = 'new-a9acb13d-e4de-4c6d-b44a-a09f5abf33e1';
    $pane->panel = 'sec-info';
    $pane->type = 'views';
    $pane->subtype = 'nodequeue_6';
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
    $pane->uuid = 'a9acb13d-e4de-4c6d-b44a-a09f5abf33e1';
    $display->content['new-a9acb13d-e4de-4c6d-b44a-a09f5abf33e1'] = $pane;
    $display->panels['sec-info'][0] = 'new-a9acb13d-e4de-4c6d-b44a-a09f5abf33e1';
    $pane = new stdClass();
    $pane->pid = 'new-ceb25e6d-c6f0-4b2b-952e-74560f6597a0';
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
    $pane->uuid = 'ceb25e6d-c6f0-4b2b-952e-74560f6597a0';
    $display->content['new-ceb25e6d-c6f0-4b2b-952e-74560f6597a0'] = $pane;
    $display->panels['secondary-content'][0] = 'new-ceb25e6d-c6f0-4b2b-952e-74560f6597a0';
    $pane = new stdClass();
    $pane->pid = 'new-59deef14-25e3-40a1-b1a2-4c25d5bdbf9d';
    $pane->panel = 'secondary-content';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-events';
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
    $pane->uuid = '59deef14-25e3-40a1-b1a2-4c25d5bdbf9d';
    $display->content['new-59deef14-25e3-40a1-b1a2-4c25d5bdbf9d'] = $pane;
    $display->panels['secondary-content'][1] = 'new-59deef14-25e3-40a1-b1a2-4c25d5bdbf9d';
    $pane = new stdClass();
    $pane->pid = 'new-885d390a-895f-4fec-b90e-f32ef910e03f';
    $pane->panel = 'secondary-content';
    $pane->type = 'block';
    $pane->subtype = 'block-7';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '885d390a-895f-4fec-b90e-f32ef910e03f';
    $display->content['new-885d390a-895f-4fec-b90e-f32ef910e03f'] = $pane;
    $display->panels['secondary-content'][2] = 'new-885d390a-895f-4fec-b90e-f32ef910e03f';
    $pane = new stdClass();
    $pane->pid = 'new-3a6726be-35ae-433a-840b-35316c61513b';
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
        'more_link' => 1,
        'feed_icons' => 0,
        'panel_args' => 0,
        'link_to_view' => 0,
        'args' => '',
        'url' => '',
        'display' => 'block',
        'override_title' => 1,
        'override_title_text' => 'Við mælum með',
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
    $pane->uuid = '3a6726be-35ae-433a-840b-35316c61513b';
    $display->content['new-3a6726be-35ae-433a-840b-35316c61513b'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-3a6726be-35ae-433a-840b-35316c61513b';
    $display->hide_title = PANELS_TITLE_NONE;
    $display->title_pane = '0';
    $handler->conf['display'] = $display;
    $page->default_handlers[$handler->name] = $handler;

    $pages['BBS Frontpage'] = $page;
    return $pages;
}
