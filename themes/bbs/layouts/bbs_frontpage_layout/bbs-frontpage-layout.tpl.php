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
    <div class="left-side">
        <?php if (!empty($content['menu'])): ?>
        <div class="menu">
            <?php print $content['menu']; ?>
        </div>
        <?php endif ?>
        <?php if (!empty($content['new-user'])): ?>
        <div class="new-user">
            <?php print $content['new-user']; ?>
        </div>
        <?php endif ?>
        <?php if (!empty($content['new-user2'])): ?>
            <div class="new-user">
            <?php print $content['new-user2']; ?>
        </div>
        <?php endif ?>
    </div>
    <div class="right-side">
        <?php if (!empty($content['main-info'])): ?>
        <div class="main-info">
            <?php print $content['main-info']; ?>
        </div>
        <?php endif ?>
        <div class="secondary-info">
            <?php if (!empty($content['sec-info'])): ?>
            <div class="secondary-info-item">
                <?php print $content['sec-info']; ?>
            </div>
            <?php endif ?>
            <?php if (!empty($content['sec-info2'])): ?>
                <div class="secondary-info-item">
                <?php print $content['sec-info2']; ?>
            </div>
            <?php endif ?>
        </div>
    </div>
</div>