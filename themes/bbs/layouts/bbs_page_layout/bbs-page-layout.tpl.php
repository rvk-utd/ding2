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
<div class="bbs-page bbs-layout-content">
    <div class="content-block main-content">
        <?php if (!empty($content['node-content'])): ?>
            <?php print $content['node-content']; ?>
        <?php endif ?>
    </div>
    <div class="sidebar">
        <?php if (!empty($content['sidebar'])): ?>
            <?php print $content['sidebar']; ?>
        <?php endif ?>
    </div>
    <div class="content-block secondary-content">
        <div class="content-wrapper">
            <?php if (!empty($content['secondary-content'])): ?>
                <?php print $content['secondary-content']; ?>
            <?php endif ?>
        </div>
    </div>
    <div class="logo-wrapper bbs-color-background">
    <div class="content-block tertiary-content ">
        <div class="content-wrapper ">
            <?php if (!empty($content['tertiary-content'])): ?>
                <?php print $content['tertiary-content']; ?>
            <?php endif ?>
        </div>
    </div>
    <?php if (!empty($content['quaternary-content'])): ?>
        <div class="content-block quaternary-content">
            <div class="content-wrapper ">
                <?php print $content['quaternary-content']; ?>
            </div>
        </div>
    <?php endif ?>
    </div>
</div>
