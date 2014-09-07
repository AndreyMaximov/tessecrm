<?php
/**
 * @file
 * field.field_collection_item.field_fs_date_signed.field_financial_supply.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'active' => '1',
    'cardinality' => '1',
    'columns' => array(
      'value' => array(
        'length' => 20,
        'not null' => FALSE,
        'sortable' => TRUE,
        'type' => 'varchar',
        'views' => TRUE,
      ),
    ),
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_fs_date_signed',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'date',
    'settings' => array(
      'cache_count' => '4',
      'cache_enabled' => 0,
      'field_encrypt' => array(
        'encrypt' => 0,
      ),
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => '',
      'tz_handling' => 'none',
    ),
    'storage' => array(
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_fs_date_signed' => array(
              'value' => 'field_fs_date_signed_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_fs_date_signed' => array(
              'value' => 'field_fs_date_signed_value',
            ),
          ),
        ),
      ),
      'module' => 'field_sql_storage',
      'settings' => array(),
      'type' => 'field_sql_storage',
    ),
    'translatable' => '0',
    'type' => 'date',
  ),
  'field_instance' => array(
    'bundle' => 'field_financial_supply',
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_fs_date_signed',
    'label' => 'Дата подписания',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => '15',
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 1,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => '4',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'date',
);
