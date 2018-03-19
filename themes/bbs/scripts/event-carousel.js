(function (scope, $) {
    'use strict';
    Drupal.behaviors.eventcarousel = {
        attach: function () {
            var quicktabs_lists = $('#quicktabs-events .item-list ul'),
                tabs = $('#quicktabs-events .quicktabs-tab');

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
