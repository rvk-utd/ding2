<?php

function bbs_frontpage_quicktabs_default_quicktabs() {
    $quicktabs = new stdClass();
    $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
    $quicktabs->api_version = 1;
    $quicktabs->machine_name = 'events';
    $quicktabs->ajax = 0;
    $quicktabs->hide_empty_tabs = FALSE;
    $quicktabs->default_tab = 0;
    $quicktabs->title = 'Events';
    $quicktabs->tabs = array(
        0 => array(
            'vid' => 'frontpage_events_1',
            'display' => 'default',
            'args' => '',
            'use_title' => 0,
            'title' => 'Shows',
            'weight' => '-100',
            'type' => 'view',
        ),
        1 => array(
            'vid' => 'frontpage_events_2',
            'display' => 'default',
            'args' => '',
            'use_title' => 0,
            'title' => 'Family',
            'weight' => '-99',
            'type' => 'view',
        ),
    );
    $quicktabs->renderer = 'quicktabs';
    $quicktabs->style = 'nostyle';
    $quicktabs->options = array();
    return array('events' => $quicktabs);
}