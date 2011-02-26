<?php

/**
 * @file
 * Starter template.php file for subthemes of Omega.
 */

/*
 * Add any conditional stylesheets you will need for this sub-theme.
 *
 * To add stylesheets that ALWAYS need to be included, you should add them to
 * your .info file instead. Only use this section if you are including
 * stylesheets based on certain conditions.
 */

/**
 * Implements hook_theme().
 */
function open_omega_theme(&$existing, $type, $theme, $path) {
  $hooks = array();
  
  return $hooks;
}

/**
 * Implements hook_css_alter().
 */
function open_omega_css_alter(&$css) {
  
}

/**
 * Implements hook_form_alter().
 */
function open_omega_form_alter(&$css) {
  
}

/**
 * Implements hook_page_alter().
 */
function open_omega_page_alter(&$css) {
  
}