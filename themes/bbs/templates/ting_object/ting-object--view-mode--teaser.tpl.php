<?php

/**
 * @file
 * Template to render objects from the Ting database.
 *
 * Available variables:
 * - $object: The TingClientObject instance we're rendering.
 * - $content: Render array of content.
 */
 hide($content['ding_serendipity_info']);
?>
<div class="book">
  <div class="inner">
    <a href="<?php print $ting_object_url_object; ?>">
      <?php print render($content['ting_cover']); ?>
    </a>
    <?php print render($content); ?>

  </div>
    <div class="activities">
  	<div class="read-more">
  		<a class="underline" href="<?php print $ting_object_url_object; ?>">Lesa meira</a>
  	</div>
  </div>
  <?php print render($content['ding_serendipity_info']); ?>
</div>
