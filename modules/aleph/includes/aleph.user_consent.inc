<?php

/**
 * @file
 * Implements the Aleph user consent interface.
 *
 * When a user gives permission to store his or her loan history for longer
 * than 30 days the user category is changed to reflect the new status. If the
 * permission is revoked then the user category is changed back to the
 * original.
 *
 * This is implemented because Ding needs it; otherwise login becomes funky.
 * Iceland does not need the user consent.
 */

/**
 * Retrieve an array of user consent options.
 *
 * @return array
 *   An array of consent options, containing a title and a description of the
 *   option.
 */
function aleph_user_consent_info() {
  // We don't need any consent descriptions, so we just return an empty array.
  return array();
}

/**
 * Update the user consent.
 *
 * @param object $account
 *    User account.
 * @param string $consent
 *   Consent category.
 *
 * @return bool
 *   TRUE or FALSE depending on the success of the request.
 */
function aleph_user_consent_add($account, $consent) {
  // Because no request is done, we return FALSE.
  return FALSE;
}

/**
 * Delete the users consent.
 *
 * @param object $account
 *    User account.
 * @param string $consent
 *    Consent category.
 *
 * @return bool
 *   TRUE or FALSE depending on the success of the request
 */
function aleph_user_consent_remove($account, $consent) {
  // There's no user consents, so return FALSE.
  return FALSE;
}

/**
 * Retrieve any consent record which the user has saved.
 *
 * @param object $account
 *    The user account.
 *
 * @return array
 *   An array of consent arrays sorted by the date they were accepted.
 */
function aleph_user_consent_get_consent($account) {
  // There's no consent records, so return an empty array.
  return array();
}

/**
 * Get the category which matches the current when changing.
 *
 * @param string $category
 *    Category.
 *
 * @return array
 *   Category name.
 */
function aleph_user_consent_get_category_change($category) {
  // There's no consent categories, so return an empty array.
  return array();
}
