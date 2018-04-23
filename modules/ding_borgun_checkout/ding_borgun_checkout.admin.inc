<?php

/**
 * @file
 * Administrative functions for Ding Borgun.Checkout.
 */

/**
 * Settings form.
 */
function ding_borgun_checkout_settings($form, $form_state) {
  $form['ding_borgun_checkout_host'] = array(
    '#type' => 'radios',
    '#title' => t('Use evironment'),
    '#description' => t('Whether to use the test evironment at Borgun, or the live environment.'),
    '#options' => array(
      'https://test.borgun.is' => t('Test'),
      'https://ecommerce.borgun.is' => t('Live'),
    ),
    '#default_value' => variable_get('ding_borgun_checkout_host', 'https://test.borgun.is'),
    '#required' => TRUE,
  );

  $form['ding_borgun_checkout_private_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Private token'),
    '#description' => t('Private token provided by Borgun.'),
    '#default_value' => variable_get('ding_borgun_checkout_private_token', ''),
    '#required' => TRUE,
  );

  $form['ding_borgun_checkout_public_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Public token'),
    '#description' => t('Public token provided by Borgun.'),
    '#default_value' => variable_get('ding_borgun_checkout_public_token', ''),
    '#required' => TRUE,
  );

  $form['ding_borgun_checkout_company_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name shown in payment window.'),
    '#default_value' => variable_get('ding_borgun_checkout_company_name', ''),
  );

  $form['ding_borgun_checkout_company_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('Slogan'),
    '#description' => t('Slogan shown in payment window.'),
    '#default_value' => variable_get('ding_borgun_checkout_company_slogan', ''),
  );

  $form['ding_borgun_checkout_order_id_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Order ID prefix'),
    '#description' => t('Prefix added to order ids. Use to avoid order ids clashing on different sites. A-Z only.'),
    '#default_value' => variable_get('ding_borgun_checkout_order_id_prefix', ''),
    '#max_length' => 8,
  );

  $form['ding_borgun_checkout_order_id_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next order ID'),
    '#description' => t('Order id used for the next order.'),
    '#default_value' => variable_get('ding_borgun_checkout_order_id_next', '1'),
  );

  $form['#validate'] = array('ding_borgun_checkout_settings_validate');

  return system_settings_form($form);
}

/**
 * Validate settings form.
 */
function ding_borgun_checkout_settings_validate($form, &$form_state) {
  // Uppercase prefix and remove all but A-Z.
  $prefix = $form_state['values']['ding_borgun_checkout_order_id_prefix'];
  $prefix = preg_replace('/[^A-Z]+/', '', drupal_strtoupper($prefix));
  form_set_value($form['ding_borgun_checkout_order_id_prefix'], $prefix, $form_state);

  // Ensure order id is numeric.
  $next_id = $form_state['values']['ding_borgun_checkout_order_id_next'];
  $next_id = preg_replace('/[^0-9]+/', '', $next_id);
  form_set_value($form['ding_borgun_checkout_order_id_next'], $next_id, $form_state);
}
