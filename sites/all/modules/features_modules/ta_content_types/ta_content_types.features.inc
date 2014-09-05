<?php
/**
 * @file
 * ta_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ta_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ta_content_types_node_info() {
  $items = array(
    'contract' => array(
      'name' => t('Договор'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Номер договора'),
      'help' => '',
    ),
    'tourist' => array(
      'name' => t('Турист'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('ФИО'),
      'help' => '',
    ),
  );
  return $items;
}
