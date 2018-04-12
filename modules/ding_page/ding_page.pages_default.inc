<?php
/**
 * @file
 * ding_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ding_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Library',
        'keyword' => 'library_group',
        'name' => 'og_group_from_node',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Library node',
        'keyword' => 'library_node',
        'name' => 'og_node_from_group',
        'context' => 'relationship_og_group_from_node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Multiple terms from node',
        'keyword' => 'terms',
        'name' => 'terms_from_node',
        'context' => 'argument_entity_id:node_1',
        'vid' => array(
          3 => '3',
          4 => '4',
          1 => '1',
          2 => '2',
        ),
        'concatenator' => ',',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_page' => 'ding_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = '25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'left_sidebar' => NULL,
      'main_content' => NULL,
      'right_sidebar' => NULL,
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e4576eaa-237b-4dbb-917b-aba5bff3d8a3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cc5c609c-5ad8-4a91-abf2-3b9befd8f376';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'campaign';
    $pane->subtype = 'campaign';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ding_campaign_count' => 3,
      'ding_campaign_offset' => 0,
      'ding_campaign_style' => 'ding_campaign_full_width',
      'context' => array(
        0 => 'argument_entity_id:node_1',
        1 => 'argument_entity_id:node_1',
        2 => 'empty',
        3 => 'relationship_terms_from_node_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cc5c609c-5ad8-4a91-abf2-3b9befd8f376';
    $display->content['new-cc5c609c-5ad8-4a91-abf2-3b9befd8f376'] = $pane;
    $display->panels['attachment_1_1'][0] = 'new-cc5c609c-5ad8-4a91-abf2-3b9befd8f376';
    $pane = new stdClass();
    $pane->pid = 'new-7d600a9c-d723-45a7-bd21-59af1a691ca4';
    $pane->panel = 'attachment_1_1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ding_page_materials';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'ding_carousel',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
      ),
      'context' => 'argument_entity_id:node_1',
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
      'css_class' => 'grid-small no-gradient',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7d600a9c-d723-45a7-bd21-59af1a691ca4';
    $display->content['new-7d600a9c-d723-45a7-bd21-59af1a691ca4'] = $pane;
    $display->panels['attachment_1_1'][1] = 'new-7d600a9c-d723-45a7-bd21-59af1a691ca4';
    $pane = new stdClass();
    $pane->pid = 'new-c857a1ef-6bb2-4f95-94ae-d176d79a7265';
    $pane->panel = 'left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-3';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c857a1ef-6bb2-4f95-94ae-d176d79a7265';
    $display->content['new-c857a1ef-6bb2-4f95-94ae-d176d79a7265'] = $pane;
    $display->panels['left_sidebar'][0] = 'new-c857a1ef-6bb2-4f95-94ae-d176d79a7265';
    $pane = new stdClass();
    $pane->pid = 'new-a5810ddf-717b-4560-a63a-1ec30c14060a';
    $pane->panel = 'left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = 'a5810ddf-717b-4560-a63a-1ec30c14060a';
    $display->content['new-a5810ddf-717b-4560-a63a-1ec30c14060a'] = $pane;
    $display->panels['left_sidebar'][1] = 'new-a5810ddf-717b-4560-a63a-1ec30c14060a';
    $pane = new stdClass();
    $pane->pid = 'new-b2afcfd3-6561-4a08-9b5d-f493ac9c3938';
    $pane->panel = 'left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'og_menu-og_single_menu_block';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b2afcfd3-6561-4a08-9b5d-f493ac9c3938';
    $display->content['new-b2afcfd3-6561-4a08-9b5d-f493ac9c3938'] = $pane;
    $display->panels['left_sidebar'][2] = 'new-b2afcfd3-6561-4a08-9b5d-f493ac9c3938';
    $pane = new stdClass();
    $pane->pid = 'new-0c1b010b-aad2-4a5e-badd-f2fe5334a80c';
    $pane->panel = 'left_sidebar';
    $pane->type = 'campaign';
    $pane->subtype = 'campaign';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ding_campaign_count' => 3,
      'ding_campaign_offset' => 0,
      'context' => array(
        0 => 'argument_entity_id:node_1',
        1 => 'relationship_og_node_from_group_1',
        2 => 'empty',
        3 => 'relationship_terms_from_node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '600',
        'granularity' => 'context',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = '';
    $pane->uuid = '0c1b010b-aad2-4a5e-badd-f2fe5334a80c';
    $display->content['new-0c1b010b-aad2-4a5e-badd-f2fe5334a80c'] = $pane;
    $display->panels['left_sidebar'][3] = 'new-0c1b010b-aad2-4a5e-badd-f2fe5334a80c';
    $pane = new stdClass();
    $pane->pid = 'new-0d732c8e-6a2e-4993-ba6f-7cb2025bada6';
    $pane->panel = 'left_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'similarterms-ding_content_tags';
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
    $pane->position = 4;
    $pane->locks = '';
    $pane->uuid = '0d732c8e-6a2e-4993-ba6f-7cb2025bada6';
    $display->content['new-0d732c8e-6a2e-4993-ba6f-7cb2025bada6'] = $pane;
    $display->panels['left_sidebar'][4] = 'new-0d732c8e-6a2e-4993-ba6f-7cb2025bada6';
    $pane = new stdClass();
    $pane->pid = 'new-33f78b6a-3147-455f-b437-70261fe3426c';
    $pane->panel = 'main_content';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
      'style' => 'naked',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '33f78b6a-3147-455f-b437-70261fe3426c';
    $display->content['new-33f78b6a-3147-455f-b437-70261fe3426c'] = $pane;
    $display->panels['main_content'][0] = 'new-33f78b6a-3147-455f-b437-70261fe3426c';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-33f78b6a-3147-455f-b437-70261fe3426c';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

    $handler = new stdClass();
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'node_view__panel_context_5';
    $handler->task = 'node_view';
    $handler->subtask = '';
    $handler->handler = 'panel_context';
    $handler->weight = -20;
    $handler->conf = array(
        'title' => 'BBS Side',
        'no_blocks' => 0,
        'pipeline' => 'standard',
        'body_classes_to_remove' => '',
        'body_classes_to_add' => '',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'name' => '',
        'access' => array(
            'plugins' => array(
                0 => array(
                    'name' => 'node_type',
                    'settings' => array(
                        'type' => array(
                            'ding_page' => 'ding_page',
                        ),
                    ),
                    'context' => 'argument_entity_id:node_1',
                    'not' => FALSE,
                ),
            ),
            'logic' => 'and',
        ),
    );
    $display = new panels_display();
    $display->layout = 'bbs_page_layout';
    $display->layout_settings = array();
    $display->panel_settings = array(
        'style_settings' => array(
            'default' => NULL,
            'node-content' => NULL,
            'sidebar' => NULL,
            'secondary-content' => NULL,
            'tertiary-content' => NULL,
            'quaternary-content' => NULL,
        ),
    );
    $display->cache = array();
    $display->title = '';
    $display->uuid = '816b6c66-5559-4f7c-8d12-4457f7a9c5f7';
    $display->content = array();
    $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0687b1bf-15d2-4ec6-a250-5c7081d81078';
    $pane->panel = 'node-content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'view_mode' => 'full',
        'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '0687b1bf-15d2-4ec6-a250-5c7081d81078';
    $display->content['new-0687b1bf-15d2-4ec6-a250-5c7081d81078'] = $pane;
    $display->panels['node-content'][0] = 'new-0687b1bf-15d2-4ec6-a250-5c7081d81078';
    $pane = new stdClass();
    $pane->pid = 'new-eab72e20-d854-43dc-9499-f268178fe452';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'og_menu-og_single_menu_block';
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
    $pane->uuid = 'eab72e20-d854-43dc-9499-f268178fe452';
    $display->content['new-eab72e20-d854-43dc-9499-f268178fe452'] = $pane;
    $display->panels['sidebar'][0] = 'new-eab72e20-d854-43dc-9499-f268178fe452';
    $pane = new stdClass();
    $pane->pid = 'new-41305c72-c4a5-4e4b-90cd-11384cbf7771';
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
    $pane->uuid = '41305c72-c4a5-4e4b-90cd-11384cbf7771';
    $display->content['new-41305c72-c4a5-4e4b-90cd-11384cbf7771'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-41305c72-c4a5-4e4b-90cd-11384cbf7771';
    $display->hide_title = PANELS_TITLE_FIXED;
    $display->title_pane = 'new-0687b1bf-15d2-4ec6-a250-5c7081d81078';
    $handler->conf['display'] = $display;

    $export['node_view__panel_context_5'] = $handler;

    $handler = new stdClass();
    $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
    $handler->api_version = 1;
    $handler->name = 'node_view__panel_context_6';
    $handler->task = 'node_view';
    $handler->subtask = '';
    $handler->handler = 'panel_context';
    $handler->weight = -19;
    $handler->conf = array(
        'title' => 'BBS Groups',
        'no_blocks' => 0,
        'pipeline' => 'standard',
        'body_classes_to_remove' => '',
        'body_classes_to_add' => '',
        'css_id' => '',
        'css' => '',
        'contexts' => array(),
        'relationships' => array(),
        'name' => '',
        'access' => array(
            'logic' => 'and',
            'plugins' => array(
                0 => array(
                    'name' => 'node_type',
                    'settings' => array(
                        'type' => array(
                            'ding_group' => 'ding_group',
                        ),
                    ),
                    'context' => 'argument_entity_id:node_1',
                    'not' => FALSE,
                ),
            ),
        ),
    );
    $display = new panels_display();
    $display->layout = 'bbs_page_layout';
    $display->layout_settings = array();
    $display->panel_settings = array(
        'style_settings' => array(
            'default' => NULL,
            'node-content' => NULL,
            'sidebar' => NULL,
            'secondary-content' => NULL,
            'tertiary-content' => NULL,
            'quaternary-content' => NULL,
        ),
    );
    $display->cache = array();
    $display->title = '';
    $display->uuid = 'fde716f7-7b26-4d39-8f55-8d320921026b';
    $display->content = array();
    $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3f21488-6e0d-4ead-bfc1-69c1af6ab1c3';
    $pane->panel = 'node-content';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'view_mode' => 'full',
        'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'd3f21488-6e0d-4ead-bfc1-69c1af6ab1c3';
    $display->content['new-d3f21488-6e0d-4ead-bfc1-69c1af6ab1c3'] = $pane;
    $display->panels['node-content'][0] = 'new-d3f21488-6e0d-4ead-bfc1-69c1af6ab1c3';
    $pane = new stdClass();
    $pane->pid = 'new-2c7f32f5-b8bb-4072-b4fa-8fde14ef263a';
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
    $pane->css = array(
        'css_id' => '',
        'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2c7f32f5-b8bb-4072-b4fa-8fde14ef263a';
    $display->content['new-2c7f32f5-b8bb-4072-b4fa-8fde14ef263a'] = $pane;
    $display->panels['quaternary-content'][0] = 'new-2c7f32f5-b8bb-4072-b4fa-8fde14ef263a';
    $pane = new stdClass();
    $pane->pid = 'new-d2079d72-5d09-4d06-a9bf-f2d6e026822a';
    $pane->panel = 'secondary-content';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_news-ding_news_groups_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'context' => array(
            0 => 'argument_entity_id:node_1',
        ),
        'override_title' => 1,
        'override_title_text' => 'Tengar fréttir',
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
    $pane->uuid = 'd2079d72-5d09-4d06-a9bf-f2d6e026822a';
    $display->content['new-d2079d72-5d09-4d06-a9bf-f2d6e026822a'] = $pane;
    $display->panels['secondary-content'][0] = 'new-d2079d72-5d09-4d06-a9bf-f2d6e026822a';
    $pane = new stdClass();
    $pane->pid = 'new-79778e71-4159-4b31-8327-b9ff68642862';
    $pane->panel = 'secondary-content';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_event-ding_event_groups_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
        'context' => array(
            0 => 'argument_entity_id:node_1',
        ),
        'override_title' => 1,
        'override_title_text' => 'Viðburðir framundan',
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
    $pane->uuid = '79778e71-4159-4b31-8327-b9ff68642862';
    $display->content['new-79778e71-4159-4b31-8327-b9ff68642862'] = $pane;
    $display->panels['secondary-content'][1] = 'new-79778e71-4159-4b31-8327-b9ff68642862';
    $pane = new stdClass();
    $pane->pid = 'new-85ad4a2e-7b74-457d-b402-4f71156657e9';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'og_menu-og_single_menu_block';
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
    $pane->uuid = '85ad4a2e-7b74-457d-b402-4f71156657e9';
    $display->content['new-85ad4a2e-7b74-457d-b402-4f71156657e9'] = $pane;
    $display->panels['sidebar'][0] = 'new-85ad4a2e-7b74-457d-b402-4f71156657e9';
    $pane = new stdClass();
    $pane->pid = 'new-8fcd45a3-c1a1-49a0-898b-5072ed7390bb';
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
    $pane->css = array(
        'css_id' => '',
        'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8fcd45a3-c1a1-49a0-898b-5072ed7390bb';
    $display->content['new-8fcd45a3-c1a1-49a0-898b-5072ed7390bb'] = $pane;
    $display->panels['tertiary-content'][0] = 'new-8fcd45a3-c1a1-49a0-898b-5072ed7390bb';
    $display->hide_title = PANELS_TITLE_FIXED;
    $display->title_pane = 'new-d3f21488-6e0d-4ead-bfc1-69c1af6ab1c3';
    $handler->conf['display'] = $display;

    $export['node_view__panel_context_6'] = $handler;

    return $export;
}
