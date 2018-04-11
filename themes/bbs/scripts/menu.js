(function (scope, $) {
    'use strict';
    /**
     * Menu functionality.
     */
     var ddbasic;

    Drupal.behaviors.menu = {
        attach: function (context) {
            var topbar_menu_btn = $('li.topbar-link-menu', context),
                topbar_link_user = $('a.topbar-link-user', context),
                close_user_login = $('.close-user-login', context),
                body = $('body'),
                topbar_menu = $('.topbar-link-menu-inner'),
                topbar = $('.topbar'),
                main_menu_button = $('a.menu-button'),
                sub_menu = $('.sub-menu'),
                top = 80,
                admin_menu_offset = $('#admin-menu').outerHeight() || 0,
                redBackgroundOffset = $('.red-background').offset();

            topbar_menu_btn.on('click', function (evt) {
                evt.preventDefault();
                body.toggleClass('menu-is-open');
                topbar_menu.toggleClass('active');
            });

            topbar_link_user.on('click', function (evt) {
                if (!body.hasClass('logged-in')) {
                    evt.preventDefault();
                    body.removeClass('menu-is-open');
                    topbar_menu.removeClass('active');
                    ddbasic.openLogin();
                }
            });

            close_user_login.on('click', function (evt) {
                evt.preventDefault();
                body.removeClass('pane-login-is-open');
                body.removeClass('overlay-is-active');
            });


            // Show first menu item as expanded
            sub_menu.first().removeClass('hidden');

            main_menu_button.on('click', function (evt) {
                evt.preventDefault();

                // remove previously expanded
                main_menu_button.removeClass('expanded');
                sub_menu.addClass('hidden');

                $(this).addClass('expanded');
                $(this).parent().find('.sub-menu').removeClass('hidden');

            });

            if (body.hasClass('front')) {
                if ($(window).scrollTop() >= top) {
                    topbar.css('top', admin_menu_offset);
                }

                window.onscroll = function () {
                    var yOffset = $(window).scrollTop();
                    if (yOffset >= top) {
                        topbar.css('top', admin_menu_offset);
                    }
                    else {
                        topbar.css('top', top - yOffset + admin_menu_offset);
                    }

                    if (yOffset >= redBackgroundOffset.top) {
                        topbar.addClass('opaque');
                    }
                    else {
                        topbar.removeClass('opaque');
                    }
                };
            }
            else {
                topbar.css('top', admin_menu_offset);
            }

        }
    };
})(this, jQuery);
