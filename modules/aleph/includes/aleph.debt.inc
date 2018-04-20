<?php

/**
 * @file
 * Handles debt with Aleph.
 */

use Drupal\aleph\Aleph\Handler\AlephPatronHandler;

/**
 * Return patron debts.
 *
 * @return array
 *    Array of DingProviderDebt objects containing debts for the patron.
 */
function aleph_debt_list() {
  $result = array();

  $patron = aleph_get_patron_by_account();
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron($patron);

  try {
    $debts = $patron_handler->getDebts();
  }
  catch (Exception $e) {
    watchdog_exception('aleph', $e);
  }

  foreach ($debts as $debt) {
    $data = array(
      'date' => $debt->getDate(),
      'display_name' => $debt->getDebtMaterial()->getTitle(),
      'amount' => $debt->getSum(),
      'amount_paid' => $debt->isPaid() ? $debt->getSum() : 0,
      'invoice_number' => NULL,
      'type' => $debt->getType(),
    );
    $result[$debt->getId()] = new DingProviderDebt($debt->getId(), $data);
  }

  return $result;
}

/**
 * Mark debts as paid.
 *
 * @param float $amount
 *   The total amount paid.
 * @param array $debt_ids
 *   IDs of the paid debts.
 * @param mixed $order_id
 *   Order ID of the payment transaction, to be recorded in the backend system.
 */
function aleph_debt_payment_received($amount, array $debt_ids = array(), $order_id = NULL) {
  $patron = aleph_get_patron_by_account();
  $patron_handler = new AlephPatronHandler(aleph_client());
  $patron_handler->setPatron($patron);

  try {
    $patron_handler->addPayment($amount, $order_id);
  }
  catch (Exception $e) {
    watchdog_exception('aleph', $e);
  }
}

function aleph_debt_translate_debt_type() {
  return '';
}
