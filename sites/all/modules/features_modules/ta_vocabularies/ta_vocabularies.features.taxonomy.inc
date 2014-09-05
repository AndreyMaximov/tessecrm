<?php
/**
 * @file
 * ta_vocabularies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ta_vocabularies_taxonomy_default_vocabularies() {
  return array(
    'countries' => array(
      'name' => 'Направление (страна)',
      'machine_name' => 'countries',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tour_operators' => array(
      'name' => 'Туроператоры',
      'machine_name' => 'tour_operators',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
