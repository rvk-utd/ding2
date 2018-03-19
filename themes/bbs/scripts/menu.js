(function (scope, $) {
    'use strict';
    /**
     * Menu functionality.
     */
    Drupal.behaviors.menu = {
        attach: function (context) {
            var topbar_menu_btn = $('li.topbar-link-menu', context),
                topbar_link_user = $('a.topbar-link-user', context),
                close_user_login = $('.close-user-login', context),
                body = $('body'),
                topbar_menu = $('.topbar-link-menu-inner'),
                main_menu_button = $('a.menu-button'),
                sub_menu = $('.sub-menu'),
                ddbasic;

            topbar_menu_btn.on('click', function (evt) {
                evt.preventDefault();
                body.toggleClass('menu-is-open');
                topbar_menu.toggleClass('active');
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

            main_menu_button.on('click', function(evt) {
                evt.preventDefault();

                // remove previously expanded
                main_menu_button.removeClass('expanded');
                sub_menu.addClass('hidden');

                $(this).addClass('expanded');
                $(this).parent().find('.sub-menu').removeClass('hidden');

            });
        }
    };
})(this, jQuery);
