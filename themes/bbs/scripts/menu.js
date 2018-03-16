(function (scope, $) {
    'use strict';
    /**
     * Menu functionality.
     */
    Drupal.behaviors.menu = {
        attach: function (context, settings) {
            var topbar_menu_btn = $('li.topbar-link-menu', context),
                topbar_link_user = $('a.topbar-link-user', context),
                close_user_login = $('.close-user-login', context),
                body = $('body'),
                menu = $('.topbar-link-menu-inner');

            topbar_menu_btn.on('click', function (evt) {
                evt.preventDefault();
                body.toggleClass('menu-is-open');
                menu.toggleClass('active');
            });

            topbar_link_user.on('click', function (evt) {
                evt.preventDefault();
                ddbasic.openLogin();
            });

            close_user_login.on('click', function (evt) {
                evt.preventDefault();
                body.removeClass('pane-login-is-open');
                body.removeClass('overlay-is-active');
            });
        }
    }
})(this, jQuery);
