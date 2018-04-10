<?php
if ($content['field_ding_library_phone_number']) {
    $content['field_ding_library_phone_number']['#label_display'] = 'hidden';
}
if ($content['field_ding_library_mail']) {
    $content['field_ding_library_mail']['#label_display'] = 'hidden';
}
?>
<?php if ($node->field_ding_library_title_image): ?>
<div class="library-image" style="background-image: url('<?php print file_create_url($node->field_ding_library_title_image['und'][0]['uri']);  ?>')"></div>
<?php endif;?>
<div class="title">
    <?php print $title; ?>
</div>

<div class="info-wrapper">
    <div class="info">
        <div class="address">
            <?php print render($content['field_ding_library_addresse']) ?>
        </div>
        <div class="opening-hours-title">
            <?php print t('Opening hours') ?>
        </div>
        <div class="contact">
            <div class="telephone">
                <?php print render($content['field_ding_library_phone_number']) ?>
            </div>
            <div class="email">
                <?php print render($content['field_ding_library_mail']) ?>
            </div>
        </div>
    </div>
</div>