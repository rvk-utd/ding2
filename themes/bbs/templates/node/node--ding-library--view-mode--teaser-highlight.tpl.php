<?php
if ($content['field_ding_library_phone_number']) {
    $content['field_ding_library_phone_number']['#label_display'] = 'hidden';
}
if ($content['field_ding_library_mail']) {
    $content['field_ding_library_mail']['#label_display'] = 'hidden';
}
?>
<div class="library-items">
    <?php if ($node->field_ding_library_title_image): ?>
        <div class="library-image" style="background-image: url('<?php print file_create_url($node->field_ding_library_title_image['und'][0]['uri']); ?>')"></div>
    <?php endif; ?>
    <div class="text-wrapper">
        <div class="title">
            <?php print $title; ?>
        </div>
        <div class="info-wrapper">
            <div class="info">
                <div class="address">
                    <?php print render($content['field_ding_library_addresse']) ?>
                </div>
                <div class="opening-hours">
                    <span class="icon icon-clock"></span>
                    <?php if (!empty($opening_hours)) : ?>
                        <div class="libraries-opening-hours js-opening-hours-toggle-element"<?php if (variable_get('ding_ddbasic_opening_hours_extended_title', FALSE)): print ' data-extended-title="1"';
                        endif; ?>>
                            <?php print $opening_hours; ?>
                        </div>
                    <?php endif; ?>
                </div>
            </div>
        </div>
    </div>
    <div class="contact-wrapper">
        <div class="telephone">
            <?php print render($content['field_ding_library_phone_number']) ?>
        </div>
        <div class="email">
            <?php print render($content['field_ding_library_mail']) ?>
        </div>
    </div>
</div>
