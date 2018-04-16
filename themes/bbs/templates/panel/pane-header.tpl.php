<?php

/**
 * @file
 * Theme implementation to display the header block on a Drupal page.
 *
 * This utilizes the following variables thata re normally found in
 * page.tpl.php:
 * - $logo
 * - $front_page
 * - $site_name
 * - $front_page
 * - $site_slogan
 * - $search_box.
 *
 * Additional items can be added via theme_preprocess_pane_header(). See
 * template_preprocess_pane_header() for examples.
 */
?>
<div class="logo">
  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
    <div class="site-name-container<?php if ($logo): ?> logo-container<?php
   endif; ?>">
      <?php if ($logo): ?>
        <img class="logo-icon" src="<?php print $logo; ?>" />
        <img class="logo-text" src="/profiles/ding2/themes/bbs/images/icons/logotext@2x.png"/>
      <?php endif; ?>
    </div>
  </a>
</div>
