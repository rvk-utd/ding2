<?php

/**
 * @file
 * Panel page title
 */


$plugin = array(
  'single' => TRUE,
  'title' => t('BBS Text Block'),
  'description' => t('BBS Text Block'),
  'category' => t('BBS'),
  'edit form' => 'bbs_text_block_textblock_edit_form',
  'render callback' => 'bbs_text_block_pane_textblock_render',
  'defaults' => array(
    'text' => '',
  ),
  'all contexts' => TRUE,
);


/**
 * Return the pane text.
 */
function bbs_text_block_textblock_content_type_admin_title($subtype, $conf, $context) {
    return t('BBS Text Block');
}

/**
 * Panel pane configuration form.
 */
function bbs_text_block_textblock_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];


    $form['text'] = array(
        '#type' => 'textfield',
        '#title' => t('text'),
        '#default_value' => $conf['text'],
        '#required' => TRUE,
    );

    $form['class'] = array(
        '#type' => 'textfield',
        '#title' => t('CSS Class'),
        '#default_value' => $conf['class'],
        '#required' => TRUE,
    );

    return $form;
}

/**
 * Panel pane configuration form submit handler.
 */
function bbs_text_block_texteblock_edit_form_submit(&$form, &$form_state) {
    $form_state['conf']['text'] = $form_state['values']['text'];
    $form_state['conf']['class'] = $form_state['values']['class'];
}


/**
 * Run-time rendering of the body of the block (content type)
 */
function bbs_text_block_pane_textblock_render($subtype, $conf, $args, $contexts) {


  $text = t($conf['text']);
  $block = new stdClass();
  $block->content = '<div class="' . $conf['class'] . '">' .   $text . '</div>'; 
  return $block;
}
