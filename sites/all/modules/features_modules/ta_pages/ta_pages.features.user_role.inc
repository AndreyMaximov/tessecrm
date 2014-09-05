<?php
/**
 * @file
 * ta_pages.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ta_pages_user_default_roles() {
  $roles = array();

  // Exported role: Менеджер.
  $roles['Менеджер'] = array(
    'name' => 'Менеджер',
    'weight' => '2',
  );

  // Exported role: Старший менеджер.
  $roles['Старший менеджер'] = array(
    'name' => 'Старший менеджер',
    'weight' => '3',
  );

  return $roles;
}
