(function ($, Drupal) {
  "use strict";

  Drupal.behaviors.tingOnlineLink = {
    attach:function (context) {

      // Find all the containers with the class borrow-online-container.
      $(context).find(".borrow-online-container").each(function () {
        // Get material id.
        const id = $(this).data('id');
        if (id) {
          const container = $(this);
          // See if we can get an online link for this material.
          $.get(`/primo-ve-api/online-url/${id}`, function( data ) {
            const { url } = data;
            if (url) {
              const linkText = Drupal.t('Borrow online', {}, {context: 'tingOnlineLink'});
              $(container).html(
                `<a class="button-see-online action-button" href="${url}">${linkText}</a>`
              );
              return;
            }

            // If we don't have an url, remove the container.
            $(container).remove();

          });
          return;
        }
        // If we don't have an id, remove the container.
        $(container).remove();
      });
    }
  };
}(jQuery, Drupal));
