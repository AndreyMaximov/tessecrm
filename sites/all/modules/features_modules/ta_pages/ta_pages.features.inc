<?php
/**
 * @file
 * ta_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ta_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ta_pages_views_api() {
  return array("api" => "3.0");
}
