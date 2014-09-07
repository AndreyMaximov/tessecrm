<?php
/**
 * @file
 * field.field_collection_item.field_fs_size.field_financial_supply.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'active' => '1',
    'cardinality' => '1',
    'columns' => array(
      'value' => array(
        'not null' => FALSE,
        'type' => 'int',
      ),
    ),
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_fs_size',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'field_encrypt' => array(
        'encrypt' => 0,
      ),
    ),
    'storage' => array(
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_fs_size' => array(
              'value' => 'field_fs_size_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_fs_size' => array(
              'value' => 'field_fs_size_value',
            ),
          ),
        ),
      ),
      'module' => 'field_sql_storage',
      'settings' => array(),
      'type' => 'field_sql_storage',
    ),
    'translatable' => '0',
    'type' => 'number_integer',
  ),
  'field_instance' => array(
    'bundle' => 'field_financial_supply',
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fs_size',
    'label' => 'Размер фин. обеспечения',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0',
      'prefix' => '',
      'suffix' => ' руб.',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => '3',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'number',
);
