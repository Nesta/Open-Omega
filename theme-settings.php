<?php

/**
 * @file
 * Theme settings for the Omega theme.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function open_omega_form_system_theme_settings_alter(&$form, &$form_state) {
  // Remove some sections of the theme settings that are irrelevant for Open Omega
  unset($form['omega_general']['menu']);
  unset($form['omega_general']['grid_overlay']);
  unset($form['omega_general']['breadcrumb']);
  // get rid of the option to enable Omega core CSS that will mess things up
  unset($form['omega_general']['optional_css']['text_css']);
  unset($form['omega_general']['optional_css']['table_css']);
  unset($form['omega_general']['optional_css']['menu_css']);
  unset($form['omega_general']['optional_css']['link_css']);
  unset($form['omega_general']['optional_css']['form_css']);
  unset($form['omega_general']['optional_css']['pager_css']);
  unset($form['omega_general']['optional_css']['regions_css']);
  unset($form['omega_general']['optional_css']['defaults_css']);
  unset($form['omega_general']['optional_css']['custom_css']);
}
