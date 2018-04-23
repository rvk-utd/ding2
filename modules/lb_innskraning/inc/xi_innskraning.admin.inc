<?php

/**
 * @file
 * Administrative functions for xi_innskraning.
 */

/**
 * Settings form.
 */
function xi_innskraning_settings() {
  $form = array();

  $form['xi_innskraning_id'] = array(
    '#type' => 'textfield',
    '#title' => t('ID'),
    '#default_value' => variable_get('xi_innskraning_id', ''),
    '#size' => 60,
    '#maxlength' => 60,
    '#description' => t("The id sent to https://innskraning.island.is as get parameter 'id'."),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
