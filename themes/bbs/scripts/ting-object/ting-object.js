/*jshint forin:false, jquery:true, browser:true, indent:2, trailing:true, unused:false */
/*globals ddbasic*/
(function($) {
  'use strict';

  // Shorten ting object teaser titles
  Drupal.behaviors.ding_ting_teaser_short_title = {
    attach: function(context, settings) {
      $('.book-teaser > .inner .field-name-ting-title h2').each(function(){
        this.innerText = ellipse(this.innerText, 45);
      });
    }
  };

  function ellipse(str, max){
    return str.length > (max - 3) ? str.substring(0,max-3) + '...' : str;
  }

  // Ting teaser image proportions.
  function adapt_images(images){
    $(images).each(function() {
      var image = new Image();
      image.src = $(this).attr("src");
      var that = $(this);
      image.onload = function() {
        var img_height = this.height;
        var img_width = this.width;
        var img_format = img_width/img_height;
        // Format of our container.
        var standart_form = 0.7692;

        if(img_format >= standart_form) {
          that.addClass('scale-height');
        } else if (img_width < img_height) {
          that.addClass('scale-width');
        }
      };
    });
  }
  Drupal.behaviors.ding_ting_teaser_image_width = {
    attach: function(context, settings) {
      adapt_images($('.book-teaser img'));
    }
  };

  // Ting teaser mobile
  Drupal.behaviors.ding_ting_object_list_mobile = {
    attach: function(context, settings) {
      $('.js-toggle-info-container', context).click(function(){
        if(ddbasic.breakpoint.is('mobile')) {
          $(this)
            .toggleClass('is-open')
            .closest('.ting-object-right').find('.info-container')
              .slideToggle('fast');
        }
      });
    }
  };
})(jQuery);
