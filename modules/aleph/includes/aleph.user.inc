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
function aleph_user_authenticate($uid, $pass) {
  $return['success'] = FALSE;

  // Setup client and patron handler.
  $client = aleph_client();
  $patron_handler = new AlephPatronHandler($client);

  // Authenticate user against Aleph.
  $auth_result = $patron_handler->authenticate($uid, $pass);

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
    'name' => $uid,
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
 */
function aleph_user_update_pincode($user, $new_pincode) {
  $creds = ding_user_get_creds($user);
  $result = array();

  // Change the users pin code.
  if (isset($new_pincode)) {
    // Setup client and patron handler.
    $client = aleph_client();
    $patron_handler = new AlephPatronHandler($client);

    // Authenticate user against Aleph.
    $auth_result = $patron_handler->authenticate($creds['name'], $creds['pass']);
    if ($auth_result->isAuthenticated()) {
      $patron_handler->setPin($new_pincode);
      // Set new password.
      $creds['pass'] = $new_pincode;

      // Update creds.
      $result['creds'] = $creds;
    }
  }
  return $result;
}
