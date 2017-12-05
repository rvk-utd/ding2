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

  $id = 0;
  foreach ($debts as $debt) {
    $id++;
    $data = array(
      'date' => $debt->getDate(),
      'display_name' => $debt->getDebtMaterial()->getTitle(),
      'amount' => $debt->getSum(),
      'amount_paid' => $debt->isPaid() ? $debt->getSum() : 0,
      'invoice_number' => NULL,
      'type' => $debt->getType(),
    );
    $result[$id] = new DingProviderDebt($id, $data);
  }

  return $result;
}

function aleph_debt_payment_received() {
  return array();
}

function aleph_debt_translate_debt_type() {
  return '';
}
