(function (scope, $) {
    'use strict';
    Drupal.behaviors.eventcarousel = {
        attach: function () {
            var quicktabs_lists = $('.quicktabs-wrapper .item-list ul'),
                tabs = $('.quicktabs-wrapper .quicktabs-tab');

            quicktabs_lists.each(function () {
                $(this).not('.slick-initialized').slick({'slidesToShow': 3, 'slidesToScroll': 1, 'infinite': false});
            });
            tabs.on('click', function() {
                quicktabs_lists.each(function () {
                    $(this).get(0).slick.setPosition();
                });
            });
        }
    };
})(this, jQuery);

(function (scope, $) {
    'use strict';
    Drupal.behaviors.recommendedcontent = {
        attach: function () {
            var views = $('.view-carousel');
            views.each(function () {
                var slides = 3;
                if ($(this).hasClass('view-library-content-roll')) {
                    slides = 4;
                }
                else if ($(this).hasClass('view-recommended-content')) {
                    slides = 2;
                }
                var list = $(this).find('.item-list ul');
                $(list).not('.slick-initialized').slick({ 'slidesToShow': slides, 'outerEdgeLimit': true, 'infinite': false});
            });

        }
    };
})(this, jQuery);

(function (scope, $) {
    'use strict';
    Drupal.behaviors.bbstingcarousel = {
        attach: function () {
            var read_more_button = $('.inner .read-more-button');
            read_more_button.each(function () {
                $(this).addClass('underline');
            });
        }
    };
})(this, jQuery);