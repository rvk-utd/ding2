<?php

/**
 * @file
 * Handles user authentication with the aleph provider.
 */

use Drupal\aleph\Aleph\Handler\AlephPatronHandler;

/**
 * Implements hook_user_authenticate().
 *
 * {@inheritdoc}
 */
function aleph_user_authenticate($name, $pass) {
  $return['success'] = FALSE;

  // Setup client and patron handler.
  $client = aleph_client();
  $patron_handler = new AlephPatronHandler($client);

  // Authenticate user against Aleph.
  $auth_result = $patron_handler->authenticate($name, $pass, aleph_get_allowed_login_branches());

  // Check if the user is authenticated.
  if ($auth_result->isAuthenticated()) {
    $return['success'] = TRUE;

    // Get patron.
    $patron = $auth_result->getPatron();

    // Set user information.
    $return['user'] = array(
      'data' => array(
        'display_name' => $patron->getName(),
      ),
    );
  }

  // Set credentials.
  $return['creds'] = array(
    // The user might have logged in using library card number, but we're saving
    // their real id here, which authenticate did extra work to dig out.
    'name' => $auth_result->getPatron()->getId(),
    'pass' => $pass,
  );

  return $return;
}

/**
 * Update pin code at Aleph.
 *
 * @param object $user
 *    The Drupal global user object.
 * @param string $new_pincode
 *   The users new pin-code.
 *
 * @return array
 *    Updated credential.
 *
 * @throws \DingProviderAuthException
 *   Given operation cannot be completed until the user authenticates.
 */
function aleph_user_update_pincode($user, $new_pincode) {
  $creds = ding_user_get_creds();
  $result = array();

  // Setup client and patron handler.
  $client = aleph_client();
  $patron_handler = new AlephPatronHandler($client);
  $patron_handler->authenticate($creds['name'], $creds['pass']);

  // Change the users pin code.
  if ($patron_handler->setPin($new_pincode)) {
    $creds['pass'] = $new_pincode;
    $result['creds'] = $creds;
    $patron_handler->authenticate($creds['name'], $new_pincode);
  }

  return $result;
}
