<?php


// deal with context placement of the content rather than default block manager
$vars['page']['content_zone']['#regions']['content']['#theme_wrappers'] = array('region');
$vars['page']['content_zone']['#regions']['content']['#region'] = 'content';

// we have two cache for the utility menu one if logged in one if logged out.
// also we change the name of the login if we are already logged in.
global $user;
$menu_utility_cache = $user->uid ? cache_get("menu_utility") : cache_get("menu_utility_anon") ;
if($menu_utility_cache) {
  $menu_utility = $menu_utility_cache->data;
}
else {
  $menu_utility = menu_navigation_links('menu-utility');
  if ($user->uid) {
    foreach($menu_utility as $key => $item) {
      if ($item['href'] == 'user') {
      $menu_utility[$key]['title'] ='My Account';
      }
    }
  }
  $menu_utility = theme(
    'links', 
    array(
      'links' => $menu_utility,
      'attributes' => array(
        'id' => 'user-menu',
        'class' => array('links', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('User menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    )
  );
  cache_set( $user->uid ? "menu_utility" : "menu_utility_anon" , $menu_utility);
}
$vars['menu_utility'] = $menu_utility;

$footer_utility_cache = cache_get("footer_utility") ;
if($footer_utility_cache) {
  $footer_utility = $footer_utility_cache->data;
}
else {
  $footer_utility = menu_navigation_links('menu-footer-utility');
  $footer_utility = theme(
    'links', 
    array(
      'links' => $footer_utility,
      'attributes' => array(
        'id' => 'footer-utility',
        'class' => array('links', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Utility Links'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    )
  );
  cache_set("footer_utility", $footer_utility);
}
$vars['footer_utility'] = $footer_utility;

// We are caching the footer_menu render array for performance 
$footer_menu_cache = cache_get("footer_menu_data") ;
if ($footer_menu_cache) {
  $footer_menu = $footer_menu_cache->data;
}
else {
  $footer_menu = menu_tree_output(menu_build_tree('main-menu', array('max_depth'=>2)));
  cache_set("footer_menu_data", $footer_menu);
}
//set the active trail
$active_trail = menu_get_active_trail();
foreach($active_trail as $trail) {
  if (isset($trail['mlid']) && isset($footer_menu[$trail['mlid'] ] )) {
    $footer_menu[$trail['mlid']]['#attributes']['class'][] = 'active-trail';
  }
}
$vars['footer_menu'] = $footer_menu;
$vars['main_menu'] = $footer_menu;
$vars['secondary_menu'] = FALSE;

$frontpage = variable_get('site_frontpage', 'node');

$logo = $vars['logo'];
$site_name = $vars['site_name'];
if (preg_match("|^.*/files/(.*)|", $logo, $m)) {
  $file = "public://" . $m[1];
  $header_logo = l(theme('image_style', array('style_name'=>'logo', 'path'=>$file, 'alt'=>"$site_name logo")), $frontpage, array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
  $footer_logo = l(theme('image_style', array('style_name'=>'logo-small', 'path'=>$file, 'alt'=>"$site_name logo")), $frontpage, array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
}
elseif ($logo == url(drupal_get_path('theme', 'openpublic_theme') . "/logo.png", array('absolute'=>TRUE))) {
  $header_logo = l(theme('image', array('path'=>$logo, 'alt'=>"$site_name logo")), '', array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
  $footer_logo = l(theme('image', array('path'=>drupal_get_path('theme', 'openpublic_theme') . "/logo-sm.png", 'alt'=>"$site_name logo")), '', array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
}
else {
  $header_logo = l(theme('image', array('path'=>$logo, 'alt'=>"$site_name logo")), '', array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
  $footer_logo = l(theme('image', array('path'=>$logo, 'alt'=>"$site_name logo")), '', array("html"=>TRUE, 'attributes'=>array('class'=>'logo')));
}

$vars['footer_logo'] = $footer_logo;
$vars['header_logo'] = $header_logo;
$vars['front_page'] = $frontpage;
if(function_exists('defaultcontent_get_node') &&
   ($node = defaultcontent_get_node("email_update")) ) {
  $node = node_view($node);
  $vars['subscribe_form'] = $node['webform'];
}

//krumo($vars);