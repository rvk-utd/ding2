<?php

/**
 * @file
 * Administrative functions for Ding Borgun Checkout.
 */

/**
 * Settings form.
 */
function ding_borgun_checkout_settings($form, $form_state) {
  $form['env'] = array(
    '#type' => 'fieldset',
    '#title' => t('Environment settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['env']['ding_borgun_checkout_host'] = array(
    '#type' => 'radios',
    '#title' => t('Use evironment'),
    '#description' => t('Whether to use the test or live environment at Borgun.'),
    '#options' => array(
      'https://test.borgun.is' => t('Test'),
      'https://ecommerce.borgun.is' => t('Live'),
    ),
    '#default_value' => variable_get('ding_borgun_checkout_host', 'https://test.borgun.is'),
    '#required' => TRUE,
  );

  $form['env']['ding_borgun_checkout_private_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Private token'),
    '#description' => t('Private token provided by Borgun.'),
    '#default_value' => variable_get('ding_borgun_checkout_private_token', ''),
    '#required' => TRUE,
  );

  $form['env']['ding_borgun_checkout_public_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Public token'),
    '#description' => t('Public token provided by Borgun.'),
    '#default_value' => variable_get('ding_borgun_checkout_public_token', ''),
    '#required' => TRUE,
  );

  $form['env']['ding_borgun_checkout_company_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name shown in payment window.'),
    '#default_value' => variable_get('ding_borgun_checkout_company_name', ''),
  );

  $form['env']['ding_borgun_checkout_company_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('Slogan'),
    '#description' => t('Slogan shown in payment window.'),
    '#default_value' => variable_get('ding_borgun_checkout_company_slogan', ''),
  );

  $form['env']['ding_borgun_checkout_order_id_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Order ID prefix'),
    '#description' => t('Prefix added to order ids. Use to avoid order ids clashing on different sites. A-Z only.'),
    '#default_value' => variable_get('ding_borgun_checkout_order_id_prefix', ''),
    '#max_length' => 8,
  );

  $form['env']['ding_borgun_checkout_order_id_next'] = array(
    '#type' => 'textfield',
    '#title' => t('Next order ID'),
    '#description' => t('Order id used for the next order.'),
    '#default_value' => variable_get('ding_borgun_checkout_order_id_next', '1'),
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['env']['#validate'] = array('ding_borgun_checkout_settings_validate');

  $form['buy_membership_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Buy membership page'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['buy_membership_page']['ding_borgun_checkout_buy_membership_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page title'),
    '#description' => t('The title shown on the top of the page'),
    '#default_value' => variable_get('ding_borgun_checkout_buy_membership_page_title'),
  );

  $form['buy_membership_page']['ding_borgun_checkout_buy_membership_page_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Intro text'),
    '#description' => t('Text shown on the buy membership page'),
    '#default_value' => variable_get('ding_borgun_checkout_buy_membership_page_text')['value'],
    '#format' => 'ding_wysiwyg',
  );

  $form['buy_membership_page']['ding_borgun_checkout_buy_membership_page_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price'),
    '#description' => t('Price in ISK'),
    '#default_value' => variable_get('ding_borgun_checkout_buy_membership_page_price'),
  );

  $form['buy_membership_page']['ding_borgun_checkout_buy_membership_page_button'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#description' => t('The text on the payment button'),
    '#default_value' => variable_get('ding_borgun_checkout_buy_membership_page_button'),
  );

  $form['renew_membership_page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Renew membership page'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['renew_membership_page']['ding_borgun_checkout_renew_membership_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Page title'),
    '#description' => t('The title shown on the top of the page'),
    '#default_value' => variable_get('ding_borgun_checkout_renew_membership_page_title'),
  );

  $form['renew_membership_page']['ding_borgun_checkout_renew_membership_page_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Intro text'),
    '#description' => t('Text shown on the renew membership page'),
    '#default_value' => variable_get('ding_borgun_checkout_renew_membership_page_text')['value'],
    '#format' => 'ding_wysiwyg',
  );

  $form['renew_membership_page']['ding_borgun_checkout_renew_membership_page_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Price'),
    '#description' => t('Price in ISK'),
    '#default_value' => variable_get('ding_borgun_checkout_renew_membership_page_price'),
  );

  $form['renew_membership_page']['ding_borgun_checkout_renew_membership_page_button'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#description' => t('The text on the payment button'),
    '#default_value' => variable_get('ding_borgun_checkout_renew_membership_page_button'),
  );

  return system_settings_form($form);
}

/**
 * Validate settings form.
 */
function ding_borgun_checkout_settings_validate($form, &$form_state) {
  // Uppercase prefix and remove all but A-Z.
  $prefix = $form_state['values']['env']['ding_borgun_checkout_order_id_prefix'];
  $prefix = preg_replace('/[^A-Z]+/', '', drupal_strtoupper($prefix));
  form_set_value($form['env']['ding_borgun_checkout_order_id_prefix'], $prefix, $form_state);
}
