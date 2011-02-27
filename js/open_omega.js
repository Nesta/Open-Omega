(function ($) {
  // function to keep sidebar heights sane
  $.fn.equalizeHeights = function(){
    return this.height( Math.max.apply(this, $(this).map(function(i,e){ 
      return $(e).height() 
    }).get() ) )
  }
  Drupal.behaviors.sidebarHeight = {
    attach: function(context, settings) {
      $('#region-sidebar_second, #region-content').equalizeHeights();
    }
  };
})(jQuery);
