<?php
/**
 * @file
 * bbs_nodequeues.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function bbs_features_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-footer-menu-1.
  $menus['menu-footer-menu-1'] = array(
    'menu_name' => 'menu-footer-menu-1',
    'title' => 'Um Borgarbókasafnið',
    'description' => '',
  );
  // Exported menu: menu-footer-menu-2.
  $menus['menu-footer-menu-2'] = array(
    'menu_name' => 'menu-footer-menu-2',
    'title' => 'Gott að vita',
    'description' => '',
  );
  // Exported menu: menu-footer-menu-3.
  $menus['menu-footer-menu-3'] = array(
    'menu_name' => 'menu-footer-menu-3',
    'title' => 'Tengdar síður',
    'description' => '',
  );
  // Exported menu: menu-frontpage-menu.
  $menus['menu-frontpage-menu'] = array(
    'menu_name' => 'menu-frontpage-menu',
    'title' => 'Velkomin/n á vefsíðu Borgarbókasafnsins',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Gott að vita');
  t('Main menu');
  t('Tengdar síður');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Um Borgarbókasafnið');
  t('Velkomin/n á vefsíðu Borgarbókasafnsins');


  return $menus;
}
