<?php

/**
 * @file
 * Panel page title
 */


$plugin = array(
  'single' => TRUE,
  'title' => t('BBS Title Block'),
  'description' => t('BBS Title Block'),
  'category' => t('BBS'),
  'edit form' => 'bbs_title_block_titleblock_edit_form',
  'render callback' => 'bbs_title_block_pane_titleblock_render',
  'defaults' => array(
    'text' => '',
  ),
  'all contexts' => TRUE,
);


/**
 * Return the pane title.
 */
function bbs_title_block_titleblock_content_type_admin_title($subtype, $conf, $context) {
    return t('BBS Title Block');
}

/**
 * Panel pane configuration form.
 */
function bbs_title_block_titleblock_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];

    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#default_value' => $conf['title'],
        '#required' => TRUE,
    );

    return $form;
}

/**
 * Panel pane configuration form submit handler.
 */
function bbs_title_block_titleblock_edit_form_submit(&$form, &$form_state) {
    $form_state['conf']['title'] = $form_state['values']['title'];
}


/**
 * Run-time rendering of the body of the block (content type)
 */
function bbs_title_block_pane_titleblock_render($subtype, $conf, $args, $contexts) {


  $title = t($conf['title']);
  $block = new stdClass();
  $block->content = '<h1>' . $title . '</h1>'; 
  return $block;
}
