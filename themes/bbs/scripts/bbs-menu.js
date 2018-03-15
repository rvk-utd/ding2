$(document).ready(function() {
  'use strict';

  $('.topbar-link-menu').click(function( ) {
    $('topbar-link-menu-inner').toggleClass('active');
    if ($('topbar-link-menu-inner').hasClass('active')) {
      $('body').addClass('overlay-is-active');
    } else {
      $('body').removeClass('overlay-is-active');
    }
  });

});
