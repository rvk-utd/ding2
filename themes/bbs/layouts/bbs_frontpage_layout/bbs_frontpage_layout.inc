<?php
$plugin['bbs_frontpage_layout'] = array(
    'title' => t('BBS frontpage layout'),
    'icon' => 'bbs_frontpage_layout.png',
    'theme' => 'bbs_frontpage_layout',
    'admin_css' => 'bbs_frontpage_layout.css',
    'category' => 'Ding2, theme',
    'regions' => array(
        'bbs-title' => t('Title'),
        'menu' => t('Menu'),
        'new-user' => t('New User'),
        'main-info' => t('Main Info'),
        'sec-info' => t('Secondary Info'),
        'secondary-content' => t('Secondary Content'),
        'tertiary-content' => t('Tertiary Content'),
        'quaternary-content' => t('Quaternary Content'),
    ),
);
