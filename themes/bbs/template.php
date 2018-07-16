<?php

/**
 * Returns a bbs color value name given a path
 */
function bbs_color_name($path) {
    if (module_exists('bbs_color_picker')) {
        return bbs_color_picker_path_name($path);
    }
}

/**
 * Returns a bbs color value in hex given a color name
 */
function bbs_color_value($name) {
    if (module_exists('bbs_color_picker')) {
        return bbs_color_picker_path_value($name);
    }
}

/**
 * Implements theme_menu_link().
 *
 * Add specific markup for main menu.
 */
function bbs_menu_link__main_menu($vars) {

    $element = $vars['element'];
    $color_name = bbs_color_name($element['#href']);
    $color = bbs_color_value($color_name);
    $element['#localized_options']['attributes']['data-color'] = $color;
    $element['#localized_options']['attributes']['class'][] = 'menu-button';


    if ($element['#below']) {
        $element['#localized_options']['attributes']['class'][] = 'menu-button-submenu';
        $element['#below']['#localized_options']['attributes']['class'][] = 'submenu-button';
        $sub_menu = '<div class="sub-menu hidden"> <div class="back-button">' . t('Go Back') . '</div> <div class="header-element">' . l($element['#title'], $element['#href']) . '</div>' . drupal_render($element['#below']) . '</div>';
        $output = l($element['#title'], $element['#href'],  $element['#localized_options']);

    }
    else {
        $sub_menu = '';
        $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    }
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

}

/**
 * Implements theme_menu_link().
 *
 * Add specific markup for top-bar menu.
 */
function bbs_menu_link__menu_bbs_topbar_menu($vars) {
    global $user;
    global $language;

    // Check if the class array is empty.
    if (empty($vars['element']['#attributes']['class'])) {
        unset($vars['element']['#attributes']['class']);
    }

    $element = $vars['element'];

    // Add default class to a tag.
    $element['#localized_options']['attributes']['class'] = array(
        'menu-item',
    );

    // Make sure text string is treated as html by l function.
    $element['#localized_options']['html'] = TRUE;

    $element['#localized_options']['attributes']['class'][] = 'js-topbar-link';

    // Some links are not translated properly, this makes sure these links are
    // run through the t function.
    if ($element['#original_link']['title'] == $element['#original_link']['link_title']) {
        $element['#title'] = t($element['#title']);
    }

    $title_suffix = '';

    // Add some icons to our top-bar menu. We use system paths to check against.
    switch ($element['#href']) {
        case 'search':
            $element['#attributes']['class'][] = 'topbar-link-search';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-search';
            $output =  drupal_render(drupal_get_form('search_block_form'));
            return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";

        case 'node':
            // Special placeholder for language switcher.
            /* In the future we would like to have an actual switcher
            $element['#attributes']['class'][] = 'topbar-language';
            $element['#localized_options']['attributes']['class'][] = 'topbar-language';
            $block =  module_invoke('locale', 'block_view', 'language');
            $lang_name = $language->language ;
            return '<li' . drupal_attributes($element['#attributes']) . '><span class="current-language">' .
                $lang_name . '</span>' . $block['content'] . $sub_menu . "</li>\n";
            */
            return '<li class="topbar-language"><a href="#"><span class="long-name">English</span><span class="short-name">EN</span></a></li>';

        case 'user':
            $title_prefix = '<i class="icon icon-user"></i>';
            $title_suffix = '<i class="icon icon-arrow-down"></i>';
            // If a user is logged in we change the menu item title.
            if (user_is_logged_in()) {
                $user_name = (!empty($user->data['display_name'])) ? $user->data['display_name'] : $user->name;
                $element['#href'] = 'user/me/view';
                $element['#title'] = $user_name;
                $element['#attributes']['class'][] = 'topbar-link-user';
                $element['#localized_options']['attributes']['class'][] = 'topbar-link-user';

                if (ding_user_is_provider_user($user)) {
                    // Fill the notification icon, in following priority.
                    // Debts, overdue, ready reservations, notifications.
                    $notification = array();
                    $debts = ddbasic_account_count_debts();
                    if (!empty($debts)) {
                        $notification = array(
                            'count' => $debts,
                            'type' => 'debts',
                        );
                    }

                    if (empty($notification)) {
                        $overdues = ddbasic_account_count_overdue_loans();
                        if (!empty($overdues)) {
                            $notification = array(
                                'count' => $overdues,
                                'type' => 'overdue',
                            );
                        }
                    }

                    if (empty($notification)) {
                        $ready = ddbasic_account_count_reservation_ready();
                        if (!empty($ready)) {
                            $notification = array(
                                'count' => $ready,
                                'type' => 'ready',
                            );
                        }
                    }

                    if (!empty($notification)) {
                        $element['#title'] .= '<div class="notification-count notification-count-type-' . $notification['type'] . '">' . $notification['count'] . '</div>';
                    }
                }
                // Add dropdown menu
                $user_menu = '<div class="user-menu"></div>';
                $output = l($title_prefix . '<span class="details">' . $element['#title'] . '</span>' . $title_suffix, $element['#href'], $element['#localized_options']);
                return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $user_menu . "</li>\n";
            }
            else {
                $element['#title'] = t('My Account');
                $element['#attributes']['class'][] = 'topbar-link-user';
                $element['#localized_options']['attributes']['class'][] = 'topbar-link-user';
            }
            break;

        case 'libraries':
            $title_prefix = '<i class="icon icon-clock"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-opening-hours';
            $element['#attributes']['class'][] = 'topbar-link-opening-hours';
            break;

        default:
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-menu';
            $element['#attributes']['class'][] = 'topbar-link-menu';
            $output = '<div class="topbar-link-menu-inner">' . '<span></span><span></span><span></span><span></span>' . '</div>';
            return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
    }

    $output = l($title_prefix . '<span class="details">' . $element['#title'] . '</span>' . $title_suffix, $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}

function bbs_form_search_block_form_alter(&$form, &$form_state, $form_id) {
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search.svg');
}

function bbs_menu_link__menu_frontpage_menu($vars) {
    $element = $vars['element'];

    // Make sure text string is treated as html by l function.
    $element['#localized_options']['html'] = TRUE;

    // Add some icons to our top-bar menu. We use system paths to check against.
    switch ($element['#href']) {
        case 'search':
            $element['#attributes']['class'][] = 'menu-item menu-item-search';
            $element['#localized_options']['attributes']['class'][] = 'menu-item menu-item-search';
            $form = drupal_get_form('search_block_form');
            $output =  drupal_render($form);
            return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";

        case 'libraries':
            $title_prefix = '<i class="icon icon-clock"></i>';
            $element['#attributes']['class'][] = 'menu-item menu-item-hours';
            break;

        case 'contact':
            $title_prefix = '<div class="bbs-icon" style="background-image: url(/profiles/ding2/themes/bbs/images/icons/mail.svg);"></div>';
            $element['#localized_options']['attributes']['class'][] = 'menu-item menu-item-contact';
            $element['#attributes']['class'][] = 'menu-item menu-item-contact';

    }
    $output = l($title_prefix . '<span class="details">' . $element['#title'] . '</span>', $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";

}

/**
 * Implements hook_preprocess_html().
 */
function bbs_preprocess_html(&$vars)
{
    global $language;

    // Setup iOS logo if it's set.
    $vars['ios_logo'] = theme_get_setting('iosicon_upload');

    // Set variable for the base path.
    $vars['base_path'] = base_path();

    // Clean up the lang attributes.
    $vars['html_attributes'] = 'lang="' . $language->language . '" dir="' . $language->dir . '"';

    // Add additional body classes.
    $vars['classes_array'] = array_merge($vars['classes_array'], ddbasic_body_class());

    $color_name = bbs_color_name(current_path());
    $color = bbs_color_value($color_name);
    $vars['attributes_array']['id'][] = $color_name;
    $vars['attributes_array']['data-color'][] = $color;


    // Search form style.
    switch (variable_get('ting_search_form_style', TING_SEARCH_FORM_STYLE_NORMAL)) {
        case TING_SEARCH_FORM_STYLE_EXTENDED:
            $vars['classes_array'][] = 'search-form-extended';
            $vars['classes_array'][] = 'show-secondary-menu';

            if (menu_get_item()['path'] === 'search/ting/%') {
                $vars['classes_array'][] = 'extended-search-is-open';
            }
            break;
    }

    switch (variable_get('ting_field_search_search_style')) {
        case 'extended_with_profiles':
            $vars['classes_array'][] = 'search-form-extended-with-profiles';
            break;
    }

    // If dynamic background.
    $image_conf = dynamic_background_load_image_configuration($vars);

    if (!empty($image_conf)) {
        $vars['classes_array'][] = 'has-dynamic-background';
    }

    // Detect if current page is a panel page and set class accordingly
    $panel_page = page_manager_get_current_page();

    if (!empty($panel_page)) {
        $vars['classes_array'][] = 'page-panels';
    } else {
        $vars['classes_array'][] = 'page-no-panels';
    }

    // Include the libraries.
    libraries_load('jquery.imagesloaded');
    libraries_load('html5shiv');
    libraries_load('masonry');
    libraries_load('slick');
}

/**
 * Implements hook_process_ting_object().
 *
 * Adds wrapper classes to the different groups on the ting object.
 */
/*function bbs_process_ting_object(&$vars) {
    //
    // Add tpl suggestions for node view modes.
    if (isset($vars['elements']['#view_mode'])) {
        $vars['theme_hook_suggestions'][] = $vars['elements']['#bundle'] . '__view_mode__' . $vars['elements']['#view_mode'];
    }

    switch ($vars['elements']['#entity_type']) {
        case 'ting_collection':
            // Add a reference to the ting_object if it's included in a
            // ting_collection.
            foreach ($vars['object']->getEntities() as &$ting_entity) {
                $ting_entity->in_collection = $vars['object'];
            }
            break;

        case 'ting_object':

            $uri_collection = entity_uri('ting_collection', $vars['object']);
            $vars['ting_object_url_collection'] = url($uri_collection['path']);

            $uri_object = entity_uri('ting_object', $vars['object']);
            $vars['ting_object_url_object'] = url($uri_object['path']);

            switch ($vars['elements']['#view_mode']) {

                // Teaser.
                case 'teaser':
                    $vars['content']['group_text']['read_more_button'] = array(
                        array(
                            '#theme' => 'link',
                            '#text' => t('Read more'),
                            '#path' => $uri_object['path'],
                            '#options' => array(
                                'attributes' => array(
                                    'class' => array(
                                        'action-button',
                                        'read-more-button',
                                        'underline',
                                    ),
                                ),
                                'html' => FALSE,
                            ),
                        ),
                        '#weight' => 9998,
                    );

                    if ($vars['object']->is('reservable')) {
                        $vars['content']['group_text']['reserve_button'] = ding_reservation_ding_entity_buttons(
                            'ding_entity',
                            $vars['object'],
                            'ajax'
                        );
                        $vars['content']['group_text']['reserve_button']['#weight'] = 9998;
                    }

                    if ($vars['object']->online_url) {
                        // Slice the output, so it only usese the online link button.
                        $vars['content']['group_text']['online_link'] = array_slice(ting_ding_entity_buttons(
                            'ding_entity',
                            $vars['object']
                        ), 0, 1);
                    }

                    // Check if teaser has rating function and remove abstract.
                    if (!empty($vars['content']['group_text']['group_rating']['ding_entity_rating_action'])) {
                        unset($vars['content']['group_text']['ting_abstract']);
                    }

                    break;

                // Reference teaser.
                case 'reference_teaser':
                    $vars['content']['buttons'] = array(
                        '#prefix' => '<div class="buttons">',
                        '#suffix' => '</div>',
                        '#weight' => 9999,
                    );
                    $vars['content']['buttons']['read_more_button'] = array(
                        array(
                            '#theme' => 'link',
                            '#text' => t('Read more'),
                            '#path' => $uri_object['path'],
                            '#options' => array(
                                'attributes' => array(
                                    'class' => array(
                                        'action-button',
                                        'read-more-button',
                                    ),
                                ),
                                'html' => FALSE,
                            ),
                        ),
                    );

                    if ($vars['object']->is('reservable')) {
                        $vars['content']['buttons']['reserve_button'] = ding_reservation_ding_entity_buttons(
                            'ding_entity',
                            $vars['object'],
                            'ajax'
                        );
                    }
                    if ($vars['object']->online_url) {
                        // Slice the output, so it only usese the online link button.
                        $vars['content']['buttons']['online_link'] = array_slice(ting_ding_entity_buttons(
                            'ding_entity',
                            $vars['object']
                        ), 0, 1);
                    }

                    break;

            }
            break;
    }

    // Inject the availability from the collection into the actual ting object.
    // Notice it's only done on the "search_result" view mode.
    if ($vars['elements']['#entity_type'] == 'ting_object' && isset($vars['object']->in_collection)
        && isset($vars['elements']['#view_mode'])
        && in_array($vars['elements']['#view_mode'], array('search_result'))) {
        $availability = field_view_field(
            'ting_collection',
            $vars['object']->in_collection,
            'ting_collection_types',
            array(
                'type' => 'ding_availability_with_labels',
                'weight' => 9999,
            )
        );
        $availability['#title'] = t('Borrowing options');

        if (isset($vars['content']['group_ting_right_col_search'])) {
            if (isset($vars['content']['group_ting_right_col_search']['group_info']['group_rating']['#weight'])) {
                $availability['#weight'] = $vars['content']['group_ting_right_col_search']['group_info']['group_rating']['#weight'] - 0.5;
            }
            $vars['content']['group_ting_right_col_search']['group_info']['availability'] = $availability;
        }
        else {
            $vars['content']['group_ting_right_col_collection']['availability'] = $availability;
        }
    }

    if (isset($vars['elements']['#view_mode']) && $vars['elements']['#view_mode'] == 'full') {
        switch ($vars['elements']['#entity_type']) {
            case 'ting_object':
                $content = $vars['content'];
                $vars['content'] = array();

                if (isset($content['group_ting_object_left_column']) && $content['group_ting_object_left_column']) {
                    $vars['content']['ting-object'] = array(
                        '#prefix' => '<div class="ting-object-wrapper">',
                        '#suffix' => '</div>',
                        'content' => array(
                            '#prefix' => '<div class="ting-object-inner-wrapper">',
                            '#suffix' => '</div>',
                            'left_column' => $content['group_ting_object_left_column'],
                            'right_column' => $content['group_ting_object_right_column'],
                        ),
                    );

                    unset($content['group_ting_object_left_column']);
                    unset($content['group_ting_object_right_column']);
                }

                if (isset($content['group_material_details']) && $content['group_material_details']) {
                    $vars['content']['material-details'] = array(
                        '#prefix' => '<div class="ting-object-wrapper">',
                        '#suffix' => '</div>',
                        'content' => array(
                            '#prefix' => '<div class="ting-object-inner-wrapper">',
                            '#suffix' => '</div>',
                            'details' => $content['group_material_details'],
                        ),
                    );
                    unset($content['group_material_details']);
                }

                if (isset($content['content']['ding_availability_holdings'])) {

                    $vars['content']['holdings-available'] = array(
                        '#prefix' => '<div class="ting-object-wrapper">',
                        '#suffix' => '</div>',
                        'content' => array(
                            '#prefix' => '<div class="ting-object-inner-wrapper">',
                            '#suffix' => '</div>',
                            'details' => $content['group_holdings_available'],
                        ),
                    );
                    unset($content['content']['ding_availability_holdings']);
                }

                if (isset($content['group_periodical_issues']) && $content['group_periodical_issues']) {
                    $vars['content']['periodical-issues'] = array(
                        '#prefix' => '<div class="ting-object-wrapper">',
                        '#suffix' => '</div>',
                        'content' => array(
                            '#prefix' => '<div class="ting-object-inner-wrapper">',
                            '#suffix' => '</div>',
                            'details' => $content['group_periodical_issues'],
                        ),
                    );
                    unset($content['group_periodical_issues']);
                }

                if (isset($content['group_on_this_site']) && $content['group_on_this_site']) {
                    $vars['content']['on_this_site'] = array(
                        '#prefix' => '<div class="ting-object-wrapper">',
                        '#suffix' => '</div>',
                        'content' => array(
                            '#prefix' => '<div id="ting_reference" class="ting-object-inner-wrapper">',
                            '#suffix' => '</div>',
                            'details' => $content['group_on_this_site'],
                        ),
                    );
                    unset($content['group_on_this_site']);
                }

                if (isset($content['ting_relations']) && $content['ting_relations']) {
                    $vars['content']['ting-relations'] = array(
                        'content' => array(
                            'details' => $content['ting_relations'],
                        ),
                    );
                    unset($content['ting_relations']);
                }

                // Move the rest over if any have been defined in the UI.
                if (!empty($content)) {
                    // Move the remaining content one level down in the array structure.
                }

                break;
        }
    }
}*/
