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

    $form['nid'] = array(
        '#type' => 'textfield',
        '#title' => t('Node Id'),
        '#default_value' => $conf['nid'],
    );

    $form['color'] = array(
        '#type' => 'textfield',
        '#title' => t('Color - Hex'),
        '#default_value' => $conf['color'],
    );

    return $form;
}

/**
 * Panel pane configuration form submit handler.
 */
function bbs_color_block_colorblock_edit_form_submit(&$form, &$form_state) {
    $form_state['conf']['nid'] = $form_state['values']['nid'];
    $form_state['conf']['color'] = $form_state['values']['color'];
}


/**
 * Run-time rendering of the body of the block (content type)
 */
function bbs_color_block_pane_colorblock_render($subtype, $conf, $args, $contexts) {

  // Update the strings to allow contexts.
  if (!empty($contexts)) {
    $content = $conf['color'];
  }

  $node = node_load($conf['nid']);
  $title = $node -> title;
  $path = 'node/' . $node -> nid;
  $alias = drupal_get_path_alias($path);
  $link = l(t('Read More'), $alias, array('attributes' => array('class' => array('underline'))));
  $block = new stdClass();
  $block->content = '<div style="background-color:' . $conf['color'] . ';"><div class="text">' . $title . '</div><div class="underline">' . $link . '</div></div>';
  return $block;
}
 