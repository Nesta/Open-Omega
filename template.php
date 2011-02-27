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
  //unset($css['profiles/openpublic/modules/features/openpublic_services/theme/openpublic_services.css']);
  //unset($css['profiles/openpublic/modules/features/openpublic_defaults/theme/openpublic_defaults.css']);
  //unset($css['profiles/openpublic/modules/features/openpublic_most_popular/theme/openpublic_most_popular.css']);
  //unset($css['profiles/openpublic/modules/custom/combineblocks/combineblocks.css']);
  //krumo($css);
}

/**
 * Implements hook_form_alter().
 */
function open_omega_form_alter(&$form, &$form_state, $form_id) {
  
}

/**
 * Implements hook_page_alter().
 */
function open_omega_page_alter(&$page) {
  
}

/**
 * Implements theme_breadcrumb().
 * Used to overwrite omega_breadcrumb back to default breadcrumb behavior
 */
function open_omega_breadcrumb($vars) {
  $breadcrumb = $vars['breadcrumb'];

  if (!empty($breadcrumb)) {
    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    $output .= '<div class="breadcrumb">' . implode(' » ', $breadcrumb) . '</div>';
    return $output;
  }
}