<?php
/**
 * @file
 * bbs_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bbs_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = '_education_page_main_content';
  $view->description = 'Display a list of all nodes in queue \'Education page main content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = '\'Education page main content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'education_page_main_content' => 'education_page_main_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/13';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Education page main content\'';
  $translatables['_education_page_main_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Education page main content\''),
  );
  $export['_education_page_main_content'] = $view;

  $view = new view();
  $view->name = '_inspiration_subcontent_lower_right';
  $view->description = 'Display a list of all nodes in queue \'Inspiration subcontent lower right\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = ' Inspiration subcontent lower right';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'inspiration_subcontent_lower_rig' => 'inspiration_subcontent_lower_rig',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/12';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Inspiration subcontent lower right\'';
  $translatables['_inspiration_subcontent_lower_right'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Inspiration subcontent lower right\''),
  );
  $export['_inspiration_subcontent_lower_right'] = $view;

  $view = new view();
  $view->name = 'bbs_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BBS Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Viðburðir framundan';
  $handler->display->display_options['css_class'] = 'view-carousel';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'Sjá alla viðburði';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="see-all" href="/vidburdir">See all events</a>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_ding_event_date) */
  $handler->display->display_options['sorts']['field_ding_event_date_value']['id'] = 'field_ding_event_date_value';
  $handler->display->display_options['sorts']['field_ding_event_date_value']['table'] = 'field_data_field_ding_event_date';
  $handler->display->display_options['sorts']['field_ding_event_date_value']['field'] = 'field_ding_event_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_ding_event_date.field_ding_event_date_value' => 'field_data_field_ding_event_date.field_ding_event_date_value',
    'field_data_field_ding_event_date.field_ding_event_date_value2' => 'field_data_field_ding_event_date.field_ding_event_date_value2',
  );

  /* Display: Frontpage events */
  $handler = $view->new_display('block', 'Frontpage events', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_ding_event_date.field_ding_event_date_value' => 'field_data_field_ding_event_date.field_ding_event_date_value',
    'field_data_field_ding_event_date.field_ding_event_date_value2' => 'field_data_field_ding_event_date.field_ding_event_date_value2',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Education page events */
  $handler = $view->new_display('block', 'Education page events', 'block_1');

  /* Display: Literature page events */
  $handler = $view->new_display('block', 'Literature page events', 'block_2');

  /* Display: Family page events */
  $handler = $view->new_display('block', 'Family page events', 'block_3');
  $translatables['bbs_events'] = array(
    t('Master'),
    t('Viðburðir framundan'),
    t('Sjá alla viðburði'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a class="see-all" href="/vidburdir">Sjá alla viðburði</a>'),
    t('Frontpage events'),
    t('more'),
    t('Education page events'),
    t('Literature page events'),
    t('Family page events'),
  );
  $export['bbs_events'] = $view;

  $view = new view();
  $view->name = 'bbs_library_projocts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BBS Library Projocts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Starfið á safninu';
  $handler->display->display_options['css_class'] = 'view-carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ding_news' => 'ding_news',
  );

  /* Display: Frontpage news */
  $handler = $view->new_display('block', 'Frontpage news', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ding_news' => 'ding_news',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Education page news */
  $handler = $view->new_display('block', 'Education page news', 'block_1');

  /* Display: Literature page news */
  $handler = $view->new_display('block', 'Literature page news', 'block_2');

  /* Display: Family page news */
  $handler = $view->new_display('block', 'Family page news', 'block_3');
  $translatables['bbs_library_projocts'] = array(
    t('Master'),
    t('Starfið á safninu'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Frontpage news'),
    t('Education page news'),
    t('Literature page news'),
    t('Family page news'),
  );
  $export['bbs_library_projocts'] = $view;

  $view = new view();
  $view->name = 'education_page_sub_content';
  $view->description = 'Display a list of all nodes in queue \'Education page sub content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Education page sub content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'education_page_sub_content' => 'education_page_sub_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/14';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Education page sub content\'';
  $translatables['education_page_sub_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Education page sub content\''),
  );
  $export['education_page_sub_content'] = $view;

  $view = new view();
  $view->name = 'family_page_lower_left';
  $view->description = 'Display a list of all nodes in queue \'Family page lower left\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Family page lower left';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'family_page_lower_left' => 'family_page_lower_left',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/17';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Family page lower left\'';
  $translatables['family_page_lower_left'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Family page lower left\''),
  );
  $export['family_page_lower_left'] = $view;

  $view = new view();
  $view->name = 'family_page_lower_right';
  $view->description = 'Display a list of all nodes in queue \'Family page lower right\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Family page lower right';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'family_page_lower_right' => 'family_page_lower_right',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/18';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Family page lower right\'';
  $translatables['family_page_lower_right'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Family page lower right\''),
  );
  $export['family_page_lower_right'] = $view;

  $view = new view();
  $view->name = 'family_page_upper_left';
  $view->description = 'Display a list of all nodes in queue \'Family page upper left\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Family page upper left';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'family_page_upper_left' => 'family_page_upper_left',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/15';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Family page upper left\'';
  $translatables['family_page_upper_left'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Family page upper left\''),
  );
  $export['family_page_upper_left'] = $view;

  $view = new view();
  $view->name = 'family_page_upper_right';
  $view->description = 'Display a list of all nodes in queue \'Family page upper right\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Family page upper right';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'family_page_upper_right' => 'family_page_upper_right',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/16';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Family page upper right\'';
  $translatables['family_page_upper_right'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Family page upper right\''),
  );
  $export['family_page_upper_right'] = $view;

  $view = new view();
  $view->name = 'frontpage_main_content';
  $view->description = 'Display a list of all nodes in queue \'Frontpage main event\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Frontpage main content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'frontpage_main_event' => 'frontpage_main_event',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/5';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Queue \'Frontpage main event\'';
  $translatables['frontpage_main_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Frontpage main event\''),
  );
  $export['frontpage_main_content'] = $view;

  $view = new view();
  $view->name = 'frontpage_sub_content';
  $view->description = 'Display a list of all nodes in queue \'Frontpage sub pages\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Frontpage sub content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'frontpage_sub_pages' => 'frontpage_sub_pages',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/6';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['frontpage_sub_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
  );
  $export['frontpage_sub_content'] = $view;

  $view = new view();
  $view->name = 'inspiration_main_content';
  $view->description = 'Display a list of all nodes in queue \'Inspiration Main Content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Inspiration Main Content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'inspiration_main_content' => 'inspiration_main_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/9';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Queue \'Inspiration Main Content\'';
  $translatables['inspiration_main_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Inspiration Main Content\''),
  );
  $export['inspiration_main_content'] = $view;

  $view = new view();
  $view->name = 'inspiration_subcontent_lower_left';
  $view->description = 'Display a list of all nodes in queue \'Inspiration subcontent lower left\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Inspiration subcontent lower left';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'inspiration_subcontent_lower_lef' => 'inspiration_subcontent_lower_lef',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/11';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Queue \'Inspiration subcontent lower left\'';
  $translatables['inspiration_subcontent_lower_left'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Inspiration subcontent lower left\''),
  );
  $export['inspiration_subcontent_lower_left'] = $view;

  $view = new view();
  $view->name = 'inspiration_subcontent_upper';
  $view->description = 'Display a list of all nodes in queue \'Inspiration Subcontent upper\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Inspiration Subcontent upper';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'inspiration_subcontent_upper' => 'inspiration_subcontent_upper',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/10';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Inspiration Subcontent upper\'';
  $translatables['inspiration_subcontent_upper'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Inspiration Subcontent upper\''),
  );
  $export['inspiration_subcontent_upper'] = $view;

  $view = new view();
  $view->name = 'library_content_roll';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'library content roll';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Starfið á safninu';
  $handler->display->display_options['css_class'] = 'view-carousel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ding_event' => 'ding_event',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['library_content_roll'] = array(
    t('Master'),
    t('Starfið á safninu'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['library_content_roll'] = $view;

  $view = new view();
  $view->name = 'literature_main_content';
  $view->description = 'Display a list of all nodes in queue \'Literature main content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Literature main content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'literature_main_content' => 'literature_main_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/7';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Literature main content\'';
  $translatables['literature_main_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Literature main content\''),
  );
  $export['literature_main_content'] = $view;

  $view = new view();
  $view->name = 'literature_sub_content';
  $view->description = 'Display a list of all nodes in queue \'Literature sub content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Literature sub content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'responsive_grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'literature_sub_content' => 'literature_sub_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/8';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Literature sub content\'';
  $translatables['literature_sub_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Literature sub content\''),
  );
  $export['literature_sub_content'] = $view;

  $view = new view();
  $view->name = 'literature_third_content';
  $view->description = 'Display a list of all nodes in queue \'Literature third content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Literature third content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'literature_third_content' => 'literature_third_content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/20';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'Queue \'Literature third content\'';
  $translatables['literature_third_content'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Literature third content\''),
  );
  $export['literature_third_content'] = $view;

  $view = new view();
  $view->name = 'recommended_content';
  $view->description = 'Display a list of all nodes in queue \'Recommended content\'';
  $view->tag = 'nodequeue';
  $view->base_table = 'node';
  $view->human_name = 'Recommended content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Við mælum með';
  $handler->display->display_options['css_class'] = 'view-carousel';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'we_recommend' => 'we_recommend',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nodequeue/19';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Queue \'Recommended content\'';
  $translatables['recommended_content'] = array(
    t('Defaults'),
    t('Við mælum með'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('queue'),
    t('Page'),
    t('Block'),
    t('Queue \'Recommended content\''),
  );
  $export['recommended_content'] = $view;

    $view = new view();
    $view->name = 'bbs_news';
    $view->description = '';
    $view->tag = 'ding_news';
    $view->base_table = 'node';
    $view->human_name = 'BBS News';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Library news';
    $handler->display->display_options['css_class'] = 'view-carousel';
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all news';
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
    $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
    $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
    $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
    $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '5';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'list';
    $handler->display->display_options['style_options']['default_row_class'] = FALSE;
    $handler->display->display_options['style_options']['row_class_special'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    $handler->display->display_options['empty']['area']['label'] = 'Empty text';
    $handler->display->display_options['empty']['area']['empty'] = TRUE;
    $handler->display->display_options['empty']['area']['content'] = 'No news where found.';
    $handler->display->display_options['empty']['area']['format'] = 'ding_wysiwyg';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    /* Field: Category (excluded) */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category (excluded)';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['exclude'] = TRUE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date (excluded) */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date (excluded)';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['exclude'] = TRUE;
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author (excluded) */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author (excluded)';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['exclude'] = TRUE;
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: News title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'News title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category, date and author */
    $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['table'] = 'views';
    $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
    $handler->display->display_options['fields']['nothing']['ui_name'] = 'Category, date and author';
    $handler->display->display_options['fields']['nothing']['label'] = '';
    $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="news-label">[field_ding_news_category]</span> <span class="news-date">[created]</span>  |  <span class="news-author">af [name]</span>';
    $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
    $handler->display->display_options['fields']['nothing']['element_class'] = 'news-sub-heading';
    $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'relationship' => 'none',
        'ui_name' => 'Image (list image)',
        'custom_label' => 0,
        'label' => '',
        'element_label_colon' => 0,
        'exclude' => 0,
        'element_type_enable' => 1,
        'element_type' => 'div',
        'element_class_enable' => 1,
        'element_class' => 'image-container',
        'element_label_type_enable' => 0,
        'element_label_type' => '',
        'element_label_class_enable' => 0,
        'element_label_class' => '',
        'element_wrapper_type_enable' => 0,
        'element_wrapper_type' => '',
        'element_wrapper_class_enable' => 0,
        'element_wrapper_class' => '',
        'element_default_classes' => 0,
        'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'absolute' => 0,
            'replace_spaces' => 0,
            'external' => 0,
            'path_case' => 'none',
            'link_class' => '',
            'alt' => '',
            'rel' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'more_link' => 0,
            'more_link_text' => '',
            'more_link_path' => '',
            'html' => 0,
            'strip_tags' => 0,
            'preserve_tags' => '',
            'trim_whitespace' => 0,
            'nl2br' => 0,
        ),
        'empty' => '',
        'empty_zero' => 0,
        'hide_empty' => 0,
        'hide_alter_empty' => 1,
        'click_sort_column' => 'fid',
        'type' => 'cs_adaptive_image',
        'field_api_classes' => 0,
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Lead (content) */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead (content)';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    /* Contextual filter: Content: Has taxonomy term ID */
    $handler->display->display_options['arguments']['tid']['id'] = 'tid';
    $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
    $handler->display->display_options['arguments']['tid']['field'] = 'tid';
    $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
    $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
        'news_category' => 'news_category',
    );
    $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
    $handler->display->display_options['filter_groups']['groups'] = array(
        1 => 'AND',
        2 => 'OR',
    );
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 1;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'ding_news' => 'ding_news',
    );
    $handler->display->display_options['filters']['type']['group'] = 1;

    /* Display: News list (frontpage) */
    $handler = $view->new_display('panel_pane', 'News list (frontpage)', 'ding_news_frontpage_list');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'grid-medium';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = TRUE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all news';
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '5';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Content: Sticky */
    $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['table'] = 'node';
    $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['defaults']['filter_groups'] = FALSE;
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter criterion: Content: Published */
    $handler->display->display_options['filters']['status']['id'] = 'status';
    $handler->display->display_options['filters']['status']['table'] = 'node';
    $handler->display->display_options['filters']['status']['field'] = 'status';
    $handler->display->display_options['filters']['status']['value'] = 1;
    $handler->display->display_options['filters']['status']['group'] = 0;
    $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
    /* Filter criterion: Content: Type */
    $handler->display->display_options['filters']['type']['id'] = 'type';
    $handler->display->display_options['filters']['type']['table'] = 'node';
    $handler->display->display_options['filters']['type']['field'] = 'type';
    $handler->display->display_options['filters']['type']['value'] = array(
        'ding_news' => 'ding_news',
    );
    /* Filter criterion: Content: Promoted to front page */
    $handler->display->display_options['filters']['promote']['id'] = 'promote';
    $handler->display->display_options['filters']['promote']['table'] = 'node';
    $handler->display->display_options['filters']['promote']['field'] = 'promote';
    $handler->display->display_options['filters']['promote']['value'] = '1';
    $handler->display->display_options['pane_category']['name'] = 'News panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 0;
    $handler->display->display_options['allow']['fields_override'] = 0;

    /* Display: Library news list */
    $handler = $view->new_display('panel_pane', 'Library news list', 'ding_news_library_list');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = TRUE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all news';
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '6';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['empty'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: OG membership: OG membership from Node */
    $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
    $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
    /* Relationship: OG membership: Group Node from OG membership */
    $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'OG node group';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Content: Sticky */
    $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['table'] = 'node';
    $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
    $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
    /* Sort criterion: Content: Post date */
    $handler->display->display_options['sorts']['created']['id'] = 'created';
    $handler->display->display_options['sorts']['created']['table'] = 'node';
    $handler->display->display_options['sorts']['created']['field'] = 'created';
    $handler->display->display_options['sorts']['created']['order'] = 'DESC';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: OG membership: Group ID */
    $handler->display->display_options['arguments']['gid']['id'] = 'gid';
    $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
    $handler->display->display_options['arguments']['gid']['field'] = 'gid';
    $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['pane_category']['name'] = 'Library panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'gid' => array(
            'type' => 'context',
            'context' => 'entity:node.nid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'OG membership: Group ID',
        ),
    );

    /* Display: News list */
    $handler = $view->new_display('panel_pane', 'News list', 'ding_news_list');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'relationship' => 'none',
        'ui_name' => 'Image (list image)',
        'custom_label' => 0,
        'label' => '',
        'element_label_colon' => 0,
        'exclude' => 0,
        'element_type_enable' => 1,
        'element_type' => 'div',
        'element_class_enable' => 1,
        'element_class' => 'news-image-wrapper',
        'element_label_type_enable' => 0,
        'element_label_type' => '',
        'element_label_class_enable' => 0,
        'element_label_class' => '',
        'element_wrapper_type_enable' => 0,
        'element_wrapper_type' => '',
        'element_wrapper_class_enable' => 0,
        'element_wrapper_class' => '',
        'element_default_classes' => 0,
        'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'absolute' => 0,
            'replace_spaces' => 0,
            'external' => 0,
            'path_case' => 'none',
            'link_class' => '',
            'alt' => '',
            'rel' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'more_link' => 0,
            'more_link_text' => '',
            'more_link_path' => '',
            'html' => 0,
            'strip_tags' => 0,
            'preserve_tags' => '',
            'trim_whitespace' => 0,
            'nl2br' => 0,
        ),
        'empty' => '',
        'empty_zero' => 0,
        'hide_empty' => 0,
        'hide_alter_empty' => 1,
        'click_sort_column' => 'fid',
        'type' => 'cs_adaptive_image',
        'field_api_classes' => 0,
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: Content: Has taxonomy term ID */
    $handler->display->display_options['arguments']['tid']['id'] = 'tid';
    $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
    $handler->display->display_options['arguments']['tid']['field'] = 'tid';
    $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
    $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
    $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
        'news_category' => 'news_category',
    );
    $handler->display->display_options['pane_category']['name'] = 'News panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 0;
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'tid' => array(
            'type' => 'panel',
            'context' => 'entity:user.uid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'Indhold: Har taksonomiterm ID',
        ),
    );

    /* Display: Library Feed */
    $handler = $view->new_display('feed', 'Library Feed', 'ding_news_library_feed');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '20';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'rss';
    $handler->display->display_options['row_plugin'] = 'node_rss';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['path'] = 'node/%/news/feed';
    $handler->display->display_options['displays'] = array(
        'default' => 0,
        'ding_news_frontpage_list' => 0,
        'ding_news_library_list' => 0,
        'ding_news_list' => 0,
        'ding_news_list_library' => 0,
        'panel_pane_2' => 0,
    );
    $handler->display->display_options['sitename_title'] = 1;

    /* Display: Feed */
    $handler = $view->new_display('feed', 'Feed', 'ding_news_feed');
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '20';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['style_plugin'] = 'rss';
    $handler->display->display_options['row_plugin'] = 'node_rss';
    $handler->display->display_options['path'] = 'news/feed';
    $handler->display->display_options['displays'] = array(
        'default' => 0,
        'ding_news_frontpage_list' => 0,
        'ding_news_library_list' => 0,
        'ding_news_list' => 0,
        'ding_news_list_library' => 0,
        'panel_pane_2' => 0,
    );
    $handler->display->display_options['sitename_title'] = 1;

    /* Display: Simple news list */
    $handler = $view->new_display('panel_pane', 'Simple news list', 'panel_pane_2');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'news-list';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Date (excluded) */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date (excluded)';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'custom';
    $handler->display->display_options['fields']['created']['custom_date_format'] = 'j. M';
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    $handler->display->display_options['pane_category']['name'] = 'News panes';
    $handler->display->display_options['pane_category']['weight'] = '0';

    /* Display: News list (library) */
    $handler = $view->new_display('panel_pane', 'News list (library)', 'ding_news_list_library');
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: OG membership: OG membership from Node */
    $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
    $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
    /* Relationship: OG membership: Group Node from OG membership */
    $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'OG node group';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'relationship' => 'none',
        'ui_name' => 'Image (list image)',
        'custom_label' => 0,
        'label' => '',
        'element_label_colon' => 0,
        'exclude' => 0,
        'element_type_enable' => 1,
        'element_type' => 'div',
        'element_class_enable' => 1,
        'element_class' => 'news-image-wrapper',
        'element_label_type_enable' => 0,
        'element_label_type' => '',
        'element_label_class_enable' => 0,
        'element_label_class' => '',
        'element_wrapper_type_enable' => 0,
        'element_wrapper_type' => '',
        'element_wrapper_class_enable' => 0,
        'element_wrapper_class' => '',
        'element_default_classes' => 0,
        'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'absolute' => 0,
            'replace_spaces' => 0,
            'external' => 0,
            'path_case' => 'none',
            'link_class' => '',
            'alt' => '',
            'rel' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'more_link' => 0,
            'more_link_text' => '',
            'more_link_path' => '',
            'html' => 0,
            'strip_tags' => 0,
            'preserve_tags' => '',
            'trim_whitespace' => 0,
            'nl2br' => 0,
        ),
        'empty' => '',
        'empty_zero' => 0,
        'hide_empty' => 0,
        'hide_alter_empty' => 1,
        'click_sort_column' => 'fid',
        'type' => 'cs_adaptive_image',
        'field_api_classes' => 0,
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: OG membership: Group ID */
    $handler->display->display_options['arguments']['gid']['id'] = 'gid';
    $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
    $handler->display->display_options['arguments']['gid']['field'] = 'gid';
    $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
    /* Contextual filter: Content: Has taxonomy term ID */
    $handler->display->display_options['arguments']['tid']['id'] = 'tid';
    $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
    $handler->display->display_options['arguments']['tid']['field'] = 'tid';
    $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
    $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
    $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
        'news_category' => 'news_category',
    );
    $handler->display->display_options['pane_category']['name'] = 'Library panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 0;
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'gid' => array(
            'type' => 'context',
            'context' => 'entity:node.nid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'OG membership: Group ID',
        ),
        'tid' => array(
            'type' => 'context',
            'context' => 'entity:taxonomy_term.tid',
            'context_optional' => 0,
            'panel' => '1',
            'fixed' => '',
            'label' => 'Indhold: Har taksonomiterm ID',
        ),
    );

    /* Display: User news simple list */
    $handler = $view->new_display('panel_pane', 'User news simple list', 'ding_news_simple_list_user');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Latest news posts';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'news-list';
    $handler->display->display_options['display_description'] = 'simple news list by user';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'mini';
    $handler->display->display_options['pager']['options']['items_per_page'] = '8';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['style_options']['row_class'] = 'simple-list-item';
    $handler->display->display_options['style_options']['default_row_class'] = FALSE;
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'fields';
    $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = '0';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: User: Uid */
    $handler->display->display_options['arguments']['uid']['id'] = 'uid';
    $handler->display->display_options['arguments']['uid']['table'] = 'users';
    $handler->display->display_options['arguments']['uid']['field'] = 'uid';
    $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
    $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['pane_category']['name'] = 'News panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['argument_input'] = array(
        'uid' => array(
            'type' => 'context',
            'context' => 'entity:user.uid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'Bruger: Uid',
        ),
    );

    /* Display: User news list */
    $handler = $view->new_display('panel_pane', 'User news list', 'ding_news_list_user');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Latest news posts';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['display_description'] = 'news list by user';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all news';
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'mini';
    $handler->display->display_options['pager']['options']['items_per_page'] = '8';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: User: Uid */
    $handler->display->display_options['arguments']['uid']['id'] = 'uid';
    $handler->display->display_options['arguments']['uid']['table'] = 'users';
    $handler->display->display_options['arguments']['uid']['field'] = 'uid';
    $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
    $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
    $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
    $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['pane_category']['name'] = 'News panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 0;
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'uid' => array(
            'type' => 'context',
            'context' => 'entity:user.uid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'Bruger: Uid',
        ),
    );

    /* Display: Groups news list */
    $handler = $view->new_display('panel_pane', 'Groups news list', 'ding_news_groups_list');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Group news';
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['use_more'] = TRUE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['defaults']['use_more_always'] = FALSE;
    $handler->display->display_options['use_more_always'] = TRUE;
    $handler->display->display_options['defaults']['use_more_text'] = FALSE;
    $handler->display->display_options['use_more_text'] = 'See all news';
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'temaer/!1/nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['pager']['options']['items_per_page'] = '6';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['defaults']['empty'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: OG membership: OG membership from Node */
    $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
    $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
    /* Relationship: OG membership: Group Node from OG membership */
    $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'OG node group';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    /* Field: OG membership: Group ID */
    $handler->display->display_options['fields']['gid']['id'] = 'gid';
    $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
    $handler->display->display_options['fields']['gid']['field'] = 'gid';
    $handler->display->display_options['fields']['gid']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['fields']['gid']['label'] = '';
    $handler->display->display_options['fields']['gid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['gid']['separator'] = '';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: OG membership: Group ID */
    $handler->display->display_options['arguments']['gid']['id'] = 'gid';
    $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
    $handler->display->display_options['arguments']['gid']['field'] = 'gid';
    $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['pane_category']['name'] = 'Groups panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'gid' => array(
            'type' => 'context',
            'context' => 'entity:node.nid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'OG membership: Group ID',
        ),
    );

    /* Display: News list (groups) */
    $handler = $view->new_display('panel_pane', 'News list (groups)', 'panel_pane_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'Group news';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['defaults']['use_more'] = FALSE;
    $handler->display->display_options['defaults']['link_display'] = FALSE;
    $handler->display->display_options['link_display'] = 'custom_url';
    $handler->display->display_options['link_url'] = 'nyheder';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['pager']['options']['offset'] = '';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
    $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
    $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
    $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
    $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
    $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
    $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'default';
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['row_plugin'] = 'node';
    $handler->display->display_options['row_options']['links'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['relationships'] = FALSE;
    /* Relationship: OG membership: OG membership from Node */
    $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
    $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
    /* Relationship: OG membership: Group Node from OG membership */
    $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'OG node group';
    /* Relationship: Content: Author */
    $handler->display->display_options['relationships']['uid']['id'] = 'uid';
    $handler->display->display_options['relationships']['uid']['table'] = 'node';
    $handler->display->display_options['relationships']['uid']['field'] = 'uid';
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Image (list image) */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['ui_name'] = 'Image (list image)';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_type'] = 'div';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_class'] = 'news-image-wrapper';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['type'] = 'cs_adaptive_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'relationship' => 'none',
        'ui_name' => 'Image (list image)',
        'custom_label' => 0,
        'label' => '',
        'element_label_colon' => 0,
        'exclude' => 0,
        'element_type_enable' => 1,
        'element_type' => 'div',
        'element_class_enable' => 1,
        'element_class' => 'news-image-wrapper',
        'element_label_type_enable' => 0,
        'element_label_type' => '',
        'element_label_class_enable' => 0,
        'element_label_class' => '',
        'element_wrapper_type_enable' => 0,
        'element_wrapper_type' => '',
        'element_wrapper_class_enable' => 0,
        'element_wrapper_class' => '',
        'element_default_classes' => 0,
        'alter' => array(
            'alter_text' => 0,
            'text' => '',
            'make_link' => 0,
            'path' => '',
            'absolute' => 0,
            'replace_spaces' => 0,
            'external' => 0,
            'path_case' => 'none',
            'link_class' => '',
            'alt' => '',
            'rel' => '',
            'prefix' => '',
            'suffix' => '',
            'target' => '',
            'trim' => 0,
            'max_length' => '',
            'word_boundary' => 1,
            'ellipsis' => 1,
            'more_link' => 0,
            'more_link_text' => '',
            'more_link_path' => '',
            'html' => 0,
            'strip_tags' => 0,
            'preserve_tags' => '',
            'trim_whitespace' => 0,
            'nl2br' => 0,
        ),
        'empty' => '',
        'empty_zero' => 0,
        'hide_empty' => 0,
        'hide_alter_empty' => 1,
        'click_sort_column' => 'fid',
        'type' => 'cs_adaptive_image',
        'field_api_classes' => 0,
        'image_link' => 'content',
        'styles' => array(
            'breakpoint_1' => '768',
            'style_1' => 'ding_list_medium',
            'breakpoint_2' => '500',
            'style_2' => 'ding_list_small',
            'max_style' => 'ding_list_large',
            'fallback_style' => 'ding_list_large',
        ),
    );
    /* Field: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'Title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Category */
    $handler->display->display_options['fields']['field_ding_news_category']['id'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['table'] = 'field_data_field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['field'] = 'field_ding_news_category';
    $handler->display->display_options['fields']['field_ding_news_category']['ui_name'] = 'Category';
    $handler->display->display_options['fields']['field_ding_news_category']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_category']['element_type'] = 'span';
    $handler->display->display_options['fields']['field_ding_news_category']['element_class'] = 'news-label';
    $handler->display->display_options['fields']['field_ding_news_category']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_category']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_category']['element_default_classes'] = FALSE;
    /* Field: Date */
    $handler->display->display_options['fields']['created']['id'] = 'created';
    $handler->display->display_options['fields']['created']['table'] = 'node';
    $handler->display->display_options['fields']['created']['field'] = 'created';
    $handler->display->display_options['fields']['created']['ui_name'] = 'Date';
    $handler->display->display_options['fields']['created']['label'] = '';
    $handler->display->display_options['fields']['created']['element_type'] = 'span';
    $handler->display->display_options['fields']['created']['element_class'] = 'news-date';
    $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['created']['date_format'] = 'ding_long_date_only';
    /* Field: Author */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'uid';
    $handler->display->display_options['fields']['name']['ui_name'] = 'Author';
    $handler->display->display_options['fields']['name']['label'] = '';
    $handler->display->display_options['fields']['name']['element_type'] = 'span';
    $handler->display->display_options['fields']['name']['element_class'] = 'news-author';
    $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
    /* Field: Lead */
    $handler->display->display_options['fields']['field_ding_news_lead']['id'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['table'] = 'field_data_field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['field'] = 'field_ding_news_lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['ui_name'] = 'Lead';
    $handler->display->display_options['fields']['field_ding_news_lead']['label'] = '';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_type'] = 'p';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_class'] = 'news-list-content';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_lead']['element_wrapper_type'] = '0';
    $handler->display->display_options['fields']['field_ding_news_lead']['element_default_classes'] = FALSE;
    /* Field: Link (read more) */
    $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node']['ui_name'] = 'Link (read more)';
    $handler->display->display_options['fields']['view_node']['label'] = '';
    $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'span';
    $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'news-link';
    $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
    $handler->display->display_options['fields']['view_node']['text'] = 'Læs mere';
    /* Field: Content: Link */
    $handler->display->display_options['fields']['view_node_1']['id'] = 'view_node_1';
    $handler->display->display_options['fields']['view_node_1']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['view_node_1']['field'] = 'view_node';
    $handler->display->display_options['fields']['view_node_1']['label'] = '';
    $handler->display->display_options['fields']['view_node_1']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['view_node_1']['alter']['text'] = '<i class="icon-chevron-right"></i>';
    $handler->display->display_options['fields']['view_node_1']['element_type'] = 'div';
    $handler->display->display_options['fields']['view_node_1']['element_class'] = 'news-arrow-link';
    $handler->display->display_options['fields']['view_node_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['view_node_1']['element_default_classes'] = FALSE;
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: OG membership: Group ID */
    $handler->display->display_options['arguments']['gid']['id'] = 'gid';
    $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
    $handler->display->display_options['arguments']['gid']['field'] = 'gid';
    $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
    $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
    $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
    /* Contextual filter: Content: Has taxonomy term ID */
    $handler->display->display_options['arguments']['tid']['id'] = 'tid';
    $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
    $handler->display->display_options['arguments']['tid']['field'] = 'tid';
    $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
    $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['pane_category']['name'] = 'Groups panes';
    $handler->display->display_options['pane_category']['weight'] = '0';
    $handler->display->display_options['allow']['use_pager'] = 0;
    $handler->display->display_options['allow']['items_per_page'] = 0;
    $handler->display->display_options['allow']['offset'] = 0;
    $handler->display->display_options['allow']['link_to_view'] = 0;
    $handler->display->display_options['allow']['more_link'] = 0;
    $handler->display->display_options['allow']['path_override'] = 0;
    $handler->display->display_options['allow']['title_override'] = 'title_override';
    $handler->display->display_options['allow']['exposed_form'] = 0;
    $handler->display->display_options['allow']['fields_override'] = 0;
    $handler->display->display_options['argument_input'] = array(
        'gid' => array(
            'type' => 'context',
            'context' => 'entity:node.nid',
            'context_optional' => 0,
            'panel' => '0',
            'fixed' => '',
            'label' => 'OG membership: Group ID',
        ),
        'tid' => array(
            'type' => 'context',
            'context' => 'entity:taxonomy_term.tid',
            'context_optional' => 0,
            'panel' => '1',
            'fixed' => '',
            'label' => 'Indhold: Har taksonomiterm ID',
        ),
    );

    /* Display: News Image Crop list */
    $handler = $view->new_display('page', 'News Image Crop list', 'ding_news_imagecrop_list');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'News Image Crop Overview';
    $handler->display->display_options['defaults']['css_class'] = FALSE;
    $handler->display->display_options['css_class'] = 'news-list imagecrop-list';
    $handler->display->display_options['defaults']['access'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'edit any ding_news content';
    $handler->display->display_options['defaults']['pager'] = FALSE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '30';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'field_ding_news_category' => 'field_ding_news_category',
        'created' => 'created',
        'name' => 'name',
        'title' => 'title',
        'nothing' => 'nothing',
        'field_ding_news_list_image' => 'field_ding_news_list_image',
        'field_ding_news_lead' => 'field_ding_news_lead',
        'view_node' => 'view_node',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
        'field_ding_news_category' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'created' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'name' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'title' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'nothing' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'field_ding_news_list_image' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'field_ding_news_lead' => array(
            'sortable' => 0,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'view_node' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: News title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['ui_name'] = 'News title';
    $handler->display->display_options['fields']['title']['label'] = '';
    $handler->display->display_options['fields']['title']['element_type'] = 'h3';
    $handler->display->display_options['fields']['title']['element_class'] = 'news-heading';
    $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
    /* Field: Content: Edit link */
    $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
    $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
    $handler->display->display_options['fields']['edit_node']['label'] = 'Rediger';
    $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
    /* Field: Content: List image */
    $handler->display->display_options['fields']['field_ding_news_list_image']['id'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['label'] = 'Original Image';
    $handler->display->display_options['fields']['field_ding_news_list_image']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image']['settings'] = array(
        'image_style' => '',
        'image_link' => '',
    );
    /* Field: Content: List image */
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['id'] = 'field_ding_news_list_image_1';
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['table'] = 'field_data_field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['field'] = 'field_ding_news_list_image';
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['label'] = 'Cropped image';
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['element_label_colon'] = FALSE;
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['click_sort_column'] = 'fid';
    $handler->display->display_options['fields']['field_ding_news_list_image_1']['settings'] = array(
        'image_style' => 'ding_panorama_list_large',
        'image_link' => '',
    );
    $handler->display->display_options['path'] = 'news-imagecrop';
    $translatables['bbs_news'] = array(
        t('Master'),
        t('Library news'),
        t('See all news'),
        t('Udfør'),
        t('Gendan'),
        t('Sortér efter'),
        t('Stigende'),
        t('Faldende'),
        t('Empty text'),
        t('No news where found.'),
        t('author'),
        t('<span class="news-label">[field_ding_news_category]</span> <span class="news-date">[created]</span>  |  <span class="news-author">af [name]</span>'),
        t('Læs mere'),
        t('Alle'),
        t('News list (frontpage)'),
        t('<i class="icon-chevron-right"></i>'),
        t('News panes'),
        t('Library news list'),
        t('OG membership from node'),
        t('OG node group'),
        t('All'),
        t('Library panes'),
        t('News list'),
        t('more'),
        t('Antal elementer'),
        t('- Alle -'),
        t('Forskydning'),
        t('« første'),
        t('‹ forrige'),
        t('næste ›'),
        t('sidste »'),
        t('Library Feed'),
        t('Feed'),
        t('Simple news list'),
        t('News list (library)'),
        t('User news simple list'),
        t('Latest news posts'),
        t('simple news list by user'),
        t('User news list'),
        t('news list by user'),
        t('« first'),
        t('last »'),
        t('Groups news list'),
        t('Group news'),
        t('.'),
        t('Groups panes'),
        t('News list (groups)'),
        t('News Image Crop list'),
        t('News Image Crop Overview'),
        t('Items per page'),
        t('- All -'),
        t('Offset'),
        t('‹ previous'),
        t('next ›'),
        t('Rediger'),
        t('Original Image'),
        t('Cropped image'),
    );

    $export[bbs_news] = $view;

    return $export;
}
