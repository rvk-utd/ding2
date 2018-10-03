(function (scope, $) {
    'use strict';
    Drupal.behaviors.eventcarousel = {
        attach: function () {
            var quicktabs_lists = $('.quicktabs-wrapper .item-list ul'),
                tabs = $('.quicktabs-wrapper .quicktabs-tab');

            quicktabs_lists.each(function () {
                $(this).not('.slick-initialized').slick({
                    'slidesToScroll': 1,
                    'slidesToShow': 3,
                    'infinite': false,
                    'variableWidth': true,
                    'responsive' : [
                        {
                            breakpoint: 1020,
                            settings: {
                                'slidesToShow': 1,
                            },
                        },
                        {
                            breakpoint: 1220,
                            settings: {
                                'slidesToShow': 2,
                            },
                        },
                    ]
                });
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
                    slides = 3;
                }
                else if ($(this).hasClass('view-recommended-content')) {
                    slides = 2;
                }
                var list = $(this).find('.item-list ul');
                $(list).not('.slick-initialized').slick({
                    'slidesToShow': slides,
                    'infinite': false,
                    'variableWidth': true,
                    responsive: [
                      {
                        breakpoint: 1020,
                        settings: {
                            'slidesToShow': 1,
                        },
                      },
                      {
                          breakpoint: 1220,
                          settings: {
                              'slidesToShow': 2,
                          },
                      },
                    ]
                });
            });

        }
    };
})(this, jQuery);
