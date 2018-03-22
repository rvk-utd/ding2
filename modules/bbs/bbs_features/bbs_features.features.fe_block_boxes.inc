<?php
/**
 * @file
 * bbs_features.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function bbs_features_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'BBS Frontpage Block 1';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_frontpage_new_1';
  $fe_block_boxes->body = '<div class="block-item skyblue"><div class="text">Nýr á safninu?</div><a class="underline" href="#">Lesa meira</a></div>';

  $export['bbs_frontpage_new_1'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'BBS Frontpage Block 2';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_frontpage_new_2';
  $fe_block_boxes->body = '<div class="block-item yellow"><div class="text">New at the library?</div><a class="underline" href="#">Learn more</a></div>';

  $export['bbs_frontpage_new_2'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'See all Events';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'see_all_events';
  $fe_block_boxes->body = '<a href="/events" class="see-all">See all Events</a>';

  $export['see_all_events'] = $fe_block_boxes;

  return $export;
}
