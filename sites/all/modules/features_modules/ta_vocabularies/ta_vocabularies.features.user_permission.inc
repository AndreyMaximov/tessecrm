<?php
/**
 * @file
 * ta_vocabularies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ta_vocabularies_user_default_permissions() {
  $permissions = array();

  // Exported permission: add terms in 1.
  $permissions['add terms in 1'] = array(
    'name' => 'add terms in 1',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: add terms in 2.
  $permissions['add terms in 2'] = array(
    'name' => 'add terms in 2',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: compile printable contract.
  $permissions['compile printable contract'] = array(
    'name' => 'compile printable contract',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'contract_print',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
