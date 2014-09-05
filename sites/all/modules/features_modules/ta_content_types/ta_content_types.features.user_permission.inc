<?php
/**
 * @file
 * ta_content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ta_content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: compile cash order.
  $permissions['compile cash order'] = array(
    'name' => 'compile cash order',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'contract_print',
  );

  // Exported permission: create contract content.
  $permissions['create contract content'] = array(
    'name' => 'create contract content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: create tourist content.
  $permissions['create tourist content'] = array(
    'name' => 'create tourist content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any contract content.
  $permissions['delete any contract content'] = array(
    'name' => 'delete any contract content',
    'roles' => array(
      'Старший менеджер' => 'Старший менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any tourist content.
  $permissions['delete any tourist content'] = array(
    'name' => 'delete any tourist content',
    'roles' => array(
      'Старший менеджер' => 'Старший менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own contract content.
  $permissions['delete own contract content'] = array(
    'name' => 'delete own contract content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own tourist content.
  $permissions['delete own tourist content'] = array(
    'name' => 'delete own tourist content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: edit any contract content.
  $permissions['edit any contract content'] = array(
    'name' => 'edit any contract content',
    'roles' => array(
      'Старший менеджер' => 'Старший менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any tourist content.
  $permissions['edit any tourist content'] = array(
    'name' => 'edit any tourist content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own contract content.
  $permissions['edit own contract content'] = array(
    'name' => 'edit own contract content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own tourist content.
  $permissions['edit own tourist content'] = array(
    'name' => 'edit own tourist content',
    'roles' => array(
      'Менеджер' => 'Менеджер',
    ),
    'module' => 'node',
  );

  return $permissions;
}
