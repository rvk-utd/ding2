<?php
$plugin['bbs_page_layout'] = array(
    'title' => t('BBS page layout'),
    'icon' => 'bbs_page_layout.png',
    'theme' => 'bbs_page_layout',
    'admin_css' => 'bbs_page_layout.css',
    'category' => 'Ding2, theme',
    'regions' => array(
        'node-content' => t('Node Content'),
        'sidebar' => t('Sidebar'),
        'secondary-content' => t('Secondary Content'),
        'tertiary-content' => t('Tertiary Content'),
        'quaternary-content' => t('Quaternary Content'),
    ),
);
