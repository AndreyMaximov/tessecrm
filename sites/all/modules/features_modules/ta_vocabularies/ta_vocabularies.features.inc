<?php
/**
 * @file
 * ta_vocabularies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ta_vocabularies_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
