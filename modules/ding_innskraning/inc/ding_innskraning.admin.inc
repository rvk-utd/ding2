<?php

/**
 * @file
 * Administrative functions for ding_innskraning.
 */

/**
 * Settings form.
 */
function ding_innskraning_settings() {
  $form = array();

  $form['ding_innskraning_id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#default_value' => variable_get('ding_innskraning_id', ''),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t("The https://innskraning.island.is id to use."),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
