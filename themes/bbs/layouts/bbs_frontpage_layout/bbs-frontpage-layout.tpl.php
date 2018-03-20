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
<div class="frontpage-content">
    <div class="border-wrapper">
        <div class="border-element">
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
            <img class="border-image" src="profiles/ding2/themes/bbs/images/icons/logo-black-grey@2x.png"/>
        </div>
    </div>
    <div class="secondary-content">
        <?php if (!empty($content['secondary-content'])): ?>
            <?php print $content['secondary-content']; ?>
        <?php endif ?>
    </div>
    <div class="tertiary-content">
        <?php if (!empty($content['tertiary-content'])): ?>
            <?php print $content['tertiary-content']; ?>
        <?php endif ?>
    </div>
</div>
