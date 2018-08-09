<?php
if ($content['field_ding_library_phone_number']) {
    $content['field_ding_library_phone_number']['#label_display'] = 'hidden';
}
if ($content['field_ding_library_mail']) {
    $content['field_ding_library_mail']['#label_display'] = 'hidden';
}
if ($node->field_bbs_color) {
    $i = $node->field_bbs_color['und'][0]['value'];
    $colors = array_values(variable_get('bbs_color_options', Array()));
    $color = $colors[$i];
}
?>

<div class="library-items" <?php if ($color) {print 'style="background-color: ' . $color . ';"';}?> >
    <?php if ($node->field_ding_library_title_image): ?>
        <a href="<?php print $node_url; ?>">
            <div class="library-image" style="background-image: url('<?php print file_create_url($node->field_ding_library_title_image['und'][0]['uri']); ?>')"></div>
        </a>
    <?php endif; ?>
    <div class="text-wrapper">
        <div class="title">
            <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
        </div>
        <div class="info-wrapper">
            <div class="info">
                <div class="address">
                    <div class="library-icons" style="background-image: url(/profiles/ding2/themes/bbs/images/icons/location.svg);"></div>
                    <?php print render($content['field_ding_library_addresse']) ?>
                </div>
                <div class="opening-hours-wrapper">
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
            <div class="library-icons" style="background-image: url(/profiles/ding2/themes/bbs/images/icons/phone.svg);"></div>
            <?php print render($content['field_ding_library_phone_number']) ?>
        </div>
        <div class="email">
            <div class="library-icons" style="background-image: url(/profiles/ding2/themes/bbs/images/icons/mail.svg);"></div>
            <?php print render($content['field_ding_library_mail']) ?>
        </div>
    </div>
</div>
