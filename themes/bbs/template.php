<?php

/**
 * Implements theme_menu_link().
 *
 * Add specific markup for top-bar menu exposed as menu_block_4.
 */

function bbs_menu_link__menu_tabs_menu($vars) {
    global $user;

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
            // Special placeholder for mobile user menu. Fall through to next case.
            $element['#localized_options']['attributes']['class'][] = 'default-override';

        case 'user':
            $title_prefix = '<i class="icon-user"></i>';
            $title_suffix = '<i class="icon-arrow-down"></i>';
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
            $title_prefix = '<i class="icon-signout"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-signout';
            $element['#attributes']['class'][] = 'topbar-link-signout';

            break;

        case 'libraries':
            $title_prefix = '<i class="icon-clock"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-opening-hours';
            $element['#attributes']['class'][] = 'topbar-link-opening-hours';
            break;

        default:
            $title_prefix = '<i class="icon-align-justify"></i>';
            $element['#localized_options']['attributes']['class'][] = 'topbar-link-menu';
            $element['#attributes']['class'][] = 'topbar-link-menu';
            break;
    }

    $output = l($title_prefix . '<span class="details">' . $element['#title'] . '</span>' . $title_suffix, $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function bbs_form_search_block_form_alter(&$form, &$form_state, $form_id) {
    $form['actions']['submit'] = array('#type' => 'image_button', '#src' => base_path() . path_to_theme() . '/images/search.svg');
}