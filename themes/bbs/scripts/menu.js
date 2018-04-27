(function (scope, $) {
    'use strict';
    /**
     * Menu functionality.
     */
    Drupal.behaviors.menu = {
        attach: function (context) {
            var topbar_menu_btn = $('li.topbar-link-menu', context),
                topbar_link_user = $('.topbar-link-user .details', context),
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

                if (body.hasClass('menu-is-open')) {
                    // store page color
                    body.attr('data-color', body.attr('id'));
                }
                else {
                    // set color back to page color
                    body.attr('id', body.attr('data-color'));
                }
            });

            topbar_link_user.on('click', function (evt) {
                evt.preventDefault();
                if (!body.hasClass('logged-in')) {
                    body.removeClass('menu-is-open');
                    topbar_menu.removeClass('active');
                    ddbasic.openLogin();
                }
                else {
                    $('ul.links').toggleClass('open');
                }
            });

            close_user_login.on('click', function (evt) {
                evt.preventDefault();
                body.removeClass('pane-login-is-open');
                body.removeClass('overlay-is-active');
            });

            main_menu_button.each(function () {
                if ($(this).hasClass('active')) {
                    $(this).parent().addClass('expanded');
                    $(this).parent().find('.sub-menu').removeClass('hidden');

                    var color = $(this).attr('id');
                    if (color) {
                        body.attr('id', color);
                    }
                    else {
                        body.attr('id', '');
                    }
                }
            });

            main_menu_button.hover(function () {
                if ($(this).parent().parent().parent().hasClass('sub-menu')) {
                    return;
                }
                main_menu_button.parent().removeClass('expanded');
                sub_menu.addClass('hidden');

                $(this).parent().addClass('expanded');
                $(this).parent().find('.sub-menu').removeClass('hidden');

                var color = $(this).attr('id');
                if (color) {
                    body.attr('id', color);
                }
                else {
                    body.attr('id', '');
                }
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
