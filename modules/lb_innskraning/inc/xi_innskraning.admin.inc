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

  $form['xi_innskraning_x509_cert'] = array(
    '#type' => 'textarea',
    '#title' => t('x.509 Certificate'),
    '#description' => t('Enter the application certificate provided by the IdP.'),
    '#default_value' => variable_get('xi_innskraning_x509_cert', ''),
    '#required' => TRUE,
    '#max_length' => 1024,
  );

  $form['xi_innskraning_cert_location'] = array(
    '#type'   => 'textfield',
    '#title'  => t('Certificate Location'),
    '#description'  => t('The location of the x.509 certificate file on the server. This must be a location that PHP can read.'),
    '#default_value' => variable_get('xi_innskraning_cert_location', 'sites/all/libraries/php-saml/sp.pem'),
  );

  $form['xi_innskraning_key_location'] = array(
    '#type'   => 'textfield',
    '#title'  => t('Key Location'),
    '#description'  => t('The location of the x.509 key file on the server. This must be a location that PHP can read.'),
    '#default_value' => variable_get('xi_innskraning_key_location', 'sites/all/libraries/php-saml/sp.key'),
  );

  return system_settings_form($form);
}
