<?php

/**
 * @file
 * Link to node with a background color
 */


$plugin = array(
  'single' => TRUE,
  'title' => t('BBS Color Block'), 
  'description' => t('BBS Color Block'),
  'category' => t('BBS'),
  'edit form' => 'bbs_color_block_colorblock_edit_form', 
  'render callback' => 'bbs_color_block_pane_colorblock_render',
  'defaults' => array(
    'text' => '',
  ),
  'all contexts' => TRUE,
);


/**
 * Return the pane title.
 */
function bbs_color_block_colorblock_content_type_admin_title($subtype, $conf, $context) {
    return t('BBS Color Block');
}

/**
 * Panel pane configuration form.
 */
function bbs_color_block_colorblock_edit_form($form, &$form_state) {
    $conf = $form_state['conf'];

    $text = empty($conf['text']) ? 'Lesa meira' : $conf['text'];


    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#default_value' => $conf['title'],
        '#required' => TRUE,
    );

    $form['path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to node'),
        '#default_value' => $conf['path'],
        '#required' => TRUE,
    );

    $form['color'] = array(
        '#type' => 'textfield',
        '#title' => t('Color - Hex'),
        '#default_value' => $conf['color'],
        '#required' => TRUE,
    );

    $form['text'] = array(
        '#type' => 'textfield',
        '#title' => t('Read more text'),
        '#description' => t('Default value is "Lesa meira"'),
        '#default_value' => $text,
    );

    return $form;
}

/**
 * Panel pane configuration form submit handler.
 */
function bbs_color_block_colorblock_edit_form_submit(&$form, &$form_state) {
    $form_state['conf']['title'] = $form_state['values']['title'];
    $form_state['conf']['path'] = $form_state['values']['path'];
    $form_state['conf']['text'] = $form_state['values']['text'];
    $form_state['conf']['color'] = $form_state['values']['color'];
}


/**
 * Run-time rendering of the body of the block (content type)
 */
function bbs_color_block_pane_colorblock_render($subtype, $conf, $args, $contexts) {


  $link = l($conf['text'], $conf['path'], array('attributes' => array('class' => array('underline'))));
  $block = new stdClass();
  $block->content = '<div style="background-color:' . $conf['color'] . ';"><div class="text">' . $conf['title'] . '</div><div class="underline">' . $link . '</div></div>';
  return $block;
}
 