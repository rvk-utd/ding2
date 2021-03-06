<?php

/**
 * @file
 * Theme and preprocess files.
 */

/**
 * Ding list message theme.
 */
function theme_ding_list_message($variables) {
  return '<div class="ding-list-message">' . $variables['message'] . '</div>';
}

/**
 * Info displayed, when a list is created.
 */
function theme_ding_list_create_info($variables) {
  $list = $variables['list'];

  $out = '<div class="ding-list-test-button"></div>';

  $items = array();
  $items[] = t("You've create the list !list.", array(
    '!list' => l($list->title, 'list/' . $list->id),
  ));
  $items[] = t('Use the "More" button on materials, to add them to the list.');
  $items[] = t('You can search after materials !search, that you can add to the list.', array(
    '!search' => l(t('Here'), 'search'),
  ));
  $items[] = t('Read more about how you use the lists !help', array(
    '!help' => l(t('Here'), 'help/lists'),
  ));

  $list = array(
    '#theme' => 'item_list',
    '#items' => $items,
  );
  $out .= drupal_render($list);;

  return '<div class="ding-list-create-info">' . $out . '</div>';
}

/**
 * Ding list permission description theme.
 */
function theme_ding_list_permission_description($variables) {
  return '<div id="status-description">' . $variables['message'] . '</div>';
}

/**
 * Default preprocess.
 */
function template_preprocess_ding_list_list(&$variables) {
  if ($variables['sortable'] !== FALSE) {
    $variables['classes_array'][] = 'sort-enabled';
  }
}

/**
 * Add button.
 */
function template_preprocess_ding_list_add_button(&$variables) {
  if (empty($variables['title'])) {
    $variables['title'] = t('Add to list');
  }

  $variables['buttons'] = array(
    '#theme' => 'links',
    '#links' => array(),
    '#attributes' => array(
      'class' => array('buttons'),
    ),
    '#attached' => array(
      'library' => array(array('system', 'drupal.ajax')),
    ),
  );

  $variables['single_link'] = FALSE;

  if ($variables['options'] === FALSE) {
    $options = ding_list_get_add_to_list_data($variables['type'], $variables['value'], $variables['value_title']);
  }
  else {
    $options = $variables['options'];
  }

  if ($variables['type'] == 'ting_object') {
    $new_list = array(
      'custom' => array(
        'title' => '<div class="list-title">' . t('New list') . '</div><div class="add-to-list-button button">' . t('Add to new list') . '</div>',
        'href' => 'list/create',
        'attributes' => array(
          'class' => array(),
        ),
        'query' => array('at' => $variables['type'], 'av' => $variables['value']),
        'html' => TRUE,
      ),
    );

    if (!user_is_logged_in()) {
      $new_list['custom']['attributes']['class'][] = 'use-ajax';
      $new_list['custom']['href'] = 'ding-list/login-create';
    }

    $options[] = $new_list;
  }
  foreach ($options as $option) {
    if ($option['type'] == 'search_query') {
      $option['title'] = t('Add to searches I follow');
    }

    if (!isset($option['custom'])) {
      $l = array(
        'title' => $option['title'],
        'href' => 'dinglist/attach/' . $option['type'] . '/' . $option['list_id'] . '/' . $option['value'],
        'attributes' => array(
          'class' => array('use-ajax', drupal_html_class($option['type'])),
        ),
        'html' => TRUE,
      );

      if (!empty($option['value_title'])) {
        $l['query'] = array('title' => $option['value_title']);
      }
    }
    else {
      $l = $option['custom'];
    }

    $variables['buttons']['#links'][] = $l;
    if (isset($option['#single_link'])) {
      $variables['single_link'] = TRUE;
    }
  }
}

/**
 * Ding list followers preprocessor.
 */
function template_preprocess_ding_list_followers(&$variables) {
  $list = $variables['list'];
  $variables['count'] = ding_list_get_list_followers_count($list);

  $variables['note'] = ding_base_get_value('ding_type', $list, 'field_notes');
  if ($variables['note'] === FALSE) {
    $list_information = ding_list_list_operations();
    $list_type = ding_base_get_value('ding_type', $list, 'field_list_type');
    if (isset($list_information[$list_type])) {
      $list_information = $list_information[$list_type];
      if (isset($list_information['_data']['description'])) {
        $variables['note'] = $list_information['_data']['description'];
      }
    }
  }

  $variables['no_objects'] = empty($list->field_list_objects);
}

/**
 * Ding list followers theme.
 */
function theme_ding_list_followers($variables) {
  $out = format_plural($variables['count'], '1 user following this list', '@count users following this list');

  return $out;
}

/**
 * Ding list info theme.
 */
function theme_ding_list_info($variables) {
  $out = '';

  if ($variables['note'] !== FALSE) {
    $out .= '<div class="ding-list-note">' . $variables['note'] . '</div>';
  }

  if ($variables['no_objects']) {
    $out .= '<div class="ding-list-no-elements">' . t('No elements in this list.') . '</div>';
  }

  return $out;
}

/**
 * Ding list lists theme.
 */
function theme_ding_list_lists($variables) {
  global $user;
  $out = '';

  foreach ($variables['groups'] as $group_name => $group) {
    $out .= "<a name='" . $group_name . "'></a>";
    $rows = array();
    $group_name_class = drupal_html_class($group_name);

    foreach ($group['lists'] as $lists) {
      foreach ($lists as $list) {
        // Remove the #list reference, so the item_list theme doesn't confuse
        // it with an attribute.
        unset($list['#list']);
        $rows[] = $list;
      }
    }

    if (!empty($rows)) {
      $render = array(
        '#theme' => 'item_list',
        '#title' => $group['title'],
        '#items' => $rows,
        '#type' => 'ul',
        '#attributes' => array('class' => array('list-links', $group_name_class)),
      );
      $out .= drupal_render($render);
    }
  }

  // Footer links.
  if ($variables['uid'] == $user->uid) {
    $render = array(
      '#theme' => 'item_list',
      '#items' => array(),
      '#title' => "",
      '#type' => 'ul',
      '#attributes' => array('class' => array('bottom-links')),
    );

    if (ding_message_get_message_count()) {
      $render['#items'][] = l(t("Mark all notifications as read"), "ding_message/clear_user_messages", array('attributes' => array('class' => array('button'))));
    }

    $render['#items'][] = l(t("Create new list"), "list/create", array('attributes' => array('class' => array('button'))));
    $render['#items'][] = l(t('View all public lists'), 'public-lists', array('attributes' => array('class' => array('button'))));

    $out .= drupal_render($render);
  }

  return '<div class="ding-user-lists">' . $out . '</div>';
}
