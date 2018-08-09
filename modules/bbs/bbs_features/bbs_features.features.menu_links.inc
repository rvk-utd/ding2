<?php
/**
 * @file
 * bbs_features.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function bbs_features_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-bbs-topbar-menu_languages:node
  $menu_links['menu-bbs-topbar-menu_languages:node'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => 'node',
    'router_path' => 'node',
    'link_title' => 'Languages',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_languages:node',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-bbs-topbar-menu_login:user
  $menu_links['menu-bbs-topbar-menu_login:user'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Login',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_login:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-bbs-topbar-menu_logout:user/logout
  $menu_links['menu-bbs-topbar-menu_logout:user/logout'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_logout:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-bbs-topbar-menu_login:user',
  );
  // Exported menu link: menu-bbs-topbar-menu_menu:<front>
  $menu_links['menu-bbs-topbar-menu_menu:<front>'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Menu',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_menu:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-bbs-topbar-menu_opening-hours:libraries
  $menu_links['menu-bbs-topbar-menu_opening-hours:libraries'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => 'libraries',
    'router_path' => 'libraries',
    'link_title' => 'Opening hours',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_opening-hours:libraries',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-bbs-topbar-menu_search:search
  $menu_links['menu-bbs-topbar-menu_search:search'] = array(
    'menu_name' => 'menu-bbs-topbar-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bbs-topbar-menu_search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-menu_hafa-samband:contact
  $menu_links['menu-frontpage-menu_hafa-samband:contact'] = array(
    'menu_name' => 'menu-frontpage-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Hafa samband',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-frontpage-menu_hafa-samband:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-menu_opening-hours:libraries
  $menu_links['menu-frontpage-menu_opening-hours:libraries'] = array(
    'menu_name' => 'menu-frontpage-menu',
    'link_path' => 'libraries',
    'router_path' => 'libraries',
    'link_title' => 'Opening hours',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-frontpage-menu_opening-hours:libraries',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-frontpage-menu_search:search
  $menu_links['menu-frontpage-menu_search:search'] = array(
    'menu_name' => 'menu-frontpage-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-frontpage-menu_search:search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Hafa samband');
  t('Languages');
  t('Login');
  t('Logout');
  t('Menu');
  t('Opening hours');
  t('Search');


  return $menu_links;
}
