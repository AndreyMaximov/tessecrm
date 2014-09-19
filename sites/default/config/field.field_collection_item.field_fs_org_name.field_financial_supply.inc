<?php
/**
 * @file
 * field.field_collection_item.field_fs_org_name.field_financial_supply.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'active' => '1',
    'cardinality' => '1',
    'columns' => array(
      'format' => array(
        'length' => 255,
        'not null' => FALSE,
        'type' => 'varchar',
      ),
      'value' => array(
        'length' => '255',
        'not null' => FALSE,
        'type' => 'varchar',
      ),
    ),
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_fs_org_name',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => '0',
    'module' => 'text',
    'settings' => array(
      'field_encrypt' => array(
        'encrypt' => 0,
      ),
      'max_length' => '255',
    ),
    'storage' => array(
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_fs_org_name' => array(
              'format' => 'field_fs_org_name_format',
              'value' => 'field_fs_org_name_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_fs_org_name' => array(
              'format' => 'field_fs_org_name_format',
              'value' => 'field_fs_org_name_value',
            ),
          ),
        ),
      ),
      'module' => 'field_sql_storage',
      'settings' => array(),
      'type' => 'field_sql_storage',
    ),
    'translatable' => '0',
    'type' => 'text',
  ),
  'field_instance' => array(
    'bundle' => 'field_financial_supply',
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fs_org_name',
    'label' => 'Наименование организации, предоставляющей фин. гарантии',
    'required' => 0,
    'settings' => array(
      'text_processing' => '0',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => '60',
      ),
      'type' => 'text_textfield',
      'weight' => '5',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'text',
);
