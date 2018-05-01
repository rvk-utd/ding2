/**
 * @file
 * Pay debts with Borgun.Checkout.
 */

(function ($) {

  /**
   * Define a $.BorgunCheckout function.
   *
   * The jQuery function in Borgun.Checkout is buggy, it assumes that
   * jQuery is $ (which it's not when the Borgun script is included,
   * due to $.noConflict), and can't find the form element. So we
   * define our own working version here.
   */
  $.fn.BorgunCheckout = function (t, e) {
    var n = new Checkout(t, this[0], e, this[0].form);
    return n.variables.Jquery = !0,
    n.Init(),
    this
  };

  /**
   * Behaviour to Borgunify .borgun-checkout elements.
   */
  Drupal.behaviors.dingBorgunCheckout = {
    attach: function (context, settings) {
      $('.borgun-checkout').once('borgun-checkout', function () {
        $(this).BorgunCheckout(settings.dingBorgunCheckout);
      });
    }
  }
})(jQuery);
