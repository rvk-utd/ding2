<?php
/**
 * @file
 * bbs implementation to present a Panels layout.
 *
 * Available variables:
 * - $content: An array of content, each item in the array is keyed to one
 * - $panel of the layout.
 * - $css_id: unique id if present.
 */
?>
<div class="frontpage">
    <div class="main-content">
        <div class="row">
            <div class="left-side">
                <?php if (!empty($content['menu'])): ?>
                    <div class="menu-wrapper">
                        <?php print $content['menu']; ?>
                    </div>
                <?php endif ?>
            </div>
            <div class="right-side">
                <?php if (!empty($content['main-info'])): ?>
                    <div class="main-info">
                        <?php print $content['main-info']; ?>
                    </div>
                <?php endif ?>
            </div>
        </div>
        <div class="row">
            <div class="left-side">
                <?php if (!empty($content['new-user'])): ?>
                    <div class="new-user">
                        <?php print $content['new-user']; ?>
                    </div>
                <?php endif ?>
            </div>
            <div class="right-side">
                <div class="secondary-info">
                    <?php if (!empty($content['sec-info'])): ?>
                        <div class="secondary-info-item">
                            <?php print $content['sec-info']; ?>
                        </div>
                    <?php endif ?>
                </div>
            </div>
        </div>
    </div>
</div>