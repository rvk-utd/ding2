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
                    'responsive' : [
                        {
                            breakpoint: 750,
                            settings: {
                                'slidesToShow': 1,
                            },
                        },
                        {
                            breakpoint: 1024,
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
                    slides = 4;
                }
                else if ($(this).hasClass('view-recommended-content')) {
                    slides = 2;
                }
                var list = $(this).find('.item-list ul');
                $(list).not('.slick-initialized').slick({ 
                    'slidesToShow': slides, 
                    'infinite': false,
                    responsive: [
                        {
                            breakpoint: 800,
                            settings: {
                                'slidesToShow': 1,
                            },
                        },
                        {
                            breakpoint: 1024,
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

(function (scope, $) {
    'use strict';
    Drupal.behaviors.bbstingcarousel = {
        attach: function () {
            var reserve_button = $('.inner .reserve-button');
            reserve_button.each(function () {
                $(this).addClass('underline');
            });
        }
    };
})(this, jQuery);