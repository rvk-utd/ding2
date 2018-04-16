<?php

function bbs_color_map($element) {
    $path = $element['#href'];
    switch ($path) {
        case '':
            return 'bbs-red';
        case 'fraedsla':
            return 'bbs-limegreen';
        case 'arrangementer':
            return 'bbs-yellow';
        case 'nyheder':
            return 'bbs-skyblue';
        case 'libraries':
            return 'bbs-seagreen';
    }
}
/**
 * Implements theme_menu_link().
 *
 * Add specific markup for main menu.
 */

function bbs_menu_link__main_menu($vars) {

    $element = $vars['element'];
    $color_class = bbs_color_map($element);

    $element['#localized_options']['attributes']['id'][] = $color_class;
    $element['#localized_options']['attributes']['class'][] = 'menu-button';


    if ($element['#below']) {
        $element['#below']['#localized_options']['attributes']['class'][] = 'submenu-button';
        $sub_menu = '<div class="sub-menu hidden">' . drupal_render($element['#below']) . '</div>';
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
function bbs_menu_link__menu_tabs_menu($vars) {
    global $user;
    global $language ;

    // Check if the class array is empty.
    if (empty($vars['element']['#attributes']['class'])) {
        unset($vars['element']['#attributes']['class']);
    }

    $element = $vars['element'];

    $sub_menu = '';

    if ($element['#below']) {
        $sub_menu = drupal_render($element['#below']);
    }

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

    // Add some icons to our top-bar menu. We use system paths to check against.
    switch ($element['#href']) {
        case 'search':
            $element['#attributes']['class'][] = 'topbar-link-search';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-search';
            $output =  drupal_render(drupal_get_form('search_block_form'));
            return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

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
                $element['#href'] = 'user/me/view';
                $element['#title'] = $user->name;
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
            }
            else {
                $element['#title'] = t('My Account');
                $element['#attributes']['class'][] = 'topbar-link-user';
                $element['#localized_options']['attributes']['class'][] = 'topbar-link-user';
            }
            break;

        case 'user/logout':
            $title_prefix = '<i class="icon icon-signout"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-signout';
            $element['#attributes']['class'][] = 'topbar-link-signout';

            break;

        case 'libraries':
            $title_prefix = '<i class="icon icon-clock"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-opening-hours';
            $element['#attributes']['class'][] = 'topbar-link-opening-hours';
            break;

        default:
            $title_prefix = '<i class="icon icon-align-justify"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-menu';
            $element['#attributes']['class'][] = 'topbar-link-menu';
            $output = '<div class="topbar-link-menu-inner">' . '<span></span><span></span><span></span><span></span>' . '</div>';
            return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
    }

    $output = l($title_prefix . '<span class="details">' . $element['#title'] . '</span>' . $title_suffix, $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
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
