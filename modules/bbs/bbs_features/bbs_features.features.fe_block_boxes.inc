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
  $fe_block_boxes->info = 'Footer address';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_footer_address';
  $fe_block_boxes->body = '<div class="contact-information"><div class="footer-logo"><img src="/profiles/ding2/themes/bbs/images/footer-logo.png"></div><p>Borgarbókasafn Reykjavíkur<br>Tryggvagötu 15 - 101 Reykjavík<br>Sími: 411-6100<br>upplýsingar@borgarbokasafn.is</p></div>';

  $export['bbs_footer_address'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'BBS Frontpage Block 1';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_frontpage_new_1';
  $fe_block_boxes->body = '<div class="block-item bbs-skyblue"><div class="text">Nýr á safninu?</div><a class="underline" href="#">Lesa meira</a></div>
<div class="block-item bbs-yellow"><div class="text">New at the library?</div><a class="underline" href="#">Learn more</a></div>';

  $export['bbs_frontpage_new_1'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'BBS Literature Block 1';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_literature_1';
  $fe_block_boxes->body = '<div class="block-item bbs-skyblue"><div class="text">Innkaupstillaga</div><a class="underline" href="#">Lesa meira</a></div>
<div class="block-item bbs-skyblue"><div class="text">Fréttabréf</div><a class="underline" href="#">Lesa meira</a></div>';

  $export['bbs_literature_1'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'BBS Social Media Block';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'bbs_social_media_block';
  $fe_block_boxes->body = '<div class="social-media">
	<a href="#">
		<div class="bbs-icon facebook"></div>
	</a>
	<a href="#">
		<div class="bbs-icon twitter"></div>
	</a>
	<a href="#">
		<div class="bbs-icon instagram"></div>
	</a>
</div>';

  $export['bbs_social_media_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Education links lower';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'education_links_lower';
  $fe_block_boxes->body = '<div class="block-item"><div class="text">Fullorðnir</div><a class="underline" href="#">Lesa meira</a></div>
<div class="block-item"><div class="text">Sýningar</div><a class="underline" href="#">Lesa meira</a></div>';

  $export['education_links_lower'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Education links upper';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'education_links_upper';
  $fe_block_boxes->body = '<div class="block-item"><div class="text">Leikskóli</div><a class="underline" href="#">Lesa meira</a></div>
<div class="block-item"><div class="text">1. -7. bekkur</div><a class="underline" href="#">Lesa meira</a></div>
<div class="block-item"><div class="text">Unglingar</div><a class="underline" href="#">Lesa meira</a></div>';

  $export['education_links_upper'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'See all Events';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'see_all_events';
  $fe_block_boxes->body = '<a href="/events" class="see-all">See all Events</a>';

  $export['see_all_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Social media block';
  $fe_block_boxes->format = 'ding_wysiwyg';
  $fe_block_boxes->machine_name = 'social_media_block';
  $fe_block_boxes->body = '<div class="social-media"><div class="fb"><a href="//facebook.com/fb">Facebook</a></div><div class="instagram"><a href="//instagram.com/bbs">Instagram</a></div></div>';

  $export['social_media_block'] = $fe_block_boxes;

  return $export;
}
