(function (scope, $) {
    'use strict';
    /**
     * Menu functionality.
     */
    Drupal.behaviors.sidebar = {
        attach: function (context) {
            var sidebar = $('.sidebar', context);
            if (sidebar.length > 0) {
                if (sidebar.find('li').length === 0) {
                    sidebar.css('display', 'none');
                }
            }
        }
    };
})(this, jQuery);