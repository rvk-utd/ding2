<?php

/**
 * @file
 * Handles user loans.
 */

use Drupal\aleph\Aleph\Handler\AlephPatronHandler;

/**
 * Implements provider loan, list.
 *
 * @return array
 *   Loan information.
 */
function aleph_loan_list() {
  // Get creds is outside cache function as it may throw exception if the user
  // is not longer logged in.
  $patron = aleph_get_patron_by_account();
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron($patron);
  $loans = $patron_handler->getLoans();

  $results = array();

  foreach ($loans as $loan) {
    $loan_data = array(
      'ding_entity_id' => ding_provider_build_entity_id($loan->getId()),
      'display_name' => $loan->getTitle(),
      'loan_date' => $loan->getLoanDate(),
      'expiry' => $loan->getDueDate(),
      'materials_number' => $loan->getId(),
      'renewable' => $loan->isRenewable(),
    );

    $results[] = new DingProviderLoan($loan->getId(), $loan_data);
  }

  return $results;
}

/**
 * Implements provider loan, renew.
 *
 * @param object $account
 *    Drupal user object to renew loan for.
 * @param array $loan_ids
 *    The loan IDs.
 *
 * @return array Result of renewals.
 *    Result of renewals.
 */
function aleph_loan_renew($account, array $loan_ids) {
  $patron = aleph_get_patron_by_account($account);
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron($patron);
  $returned_loans = $patron_handler->renewLoans($loan_ids);
  $result = array();

  foreach ($returned_loans as $id => $returned_loan) {
    if ($returned_loan->isRenewed()) {
      $result[$id] = DingProviderLoan::STATUS_RENEWED;
    }
    else {
      $result[$id] = DingProviderLoan::STATUS_NOT_RENEWED;
    }
  }

  return $result;
}
