<?php
/**
 * @file
 * field.taxonomy_term.field_financial_supply.tour_operators.inc
 */

$api = '2.0.0';

$data = array(
  'field_config' => array(
    'active' => '1',
    'cardinality' => '-1',
    'columns' => array(
      'revision_id' => array(
        'description' => 'The field collection item revision id.',
        'not null' => FALSE,
        'type' => 'int',
      ),
      'value' => array(
        'description' => 'The field collection item id.',
        'not null' => FALSE,
        'type' => 'int',
      ),
    ),
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_financial_supply',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => '0',
    'module' => 'field_collection',
    'settings' => array(
      'field_encrypt' => array(
        'encrypt' => 0,
      ),
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'storage' => array(
      'active' => '1',
      'details' => array(
        'sql' => array(
          'FIELD_LOAD_CURRENT' => array(
            'field_data_field_financial_supply' => array(
              'revision_id' => 'field_financial_supply_revision_id',
              'value' => 'field_financial_supply_value',
            ),
          ),
          'FIELD_LOAD_REVISION' => array(
            'field_revision_field_financial_supply' => array(
              'revision_id' => 'field_financial_supply_revision_id',
              'value' => 'field_financial_supply_value',
            ),
          ),
        ),
      ),
      'module' => 'field_sql_storage',
      'settings' => array(),
      'type' => 'field_sql_storage',
    ),
    'translatable' => '0',
    'type' => 'field_collection',
  ),
  'field_instance' => array(
    'bundle' => 'tour_operators',
    'default_value' => NULL,
    'deleted' => '0',
    'description' => 'Документы (договоры) фин обеспечения (страхования или фин. гарантии туроператора).
Не только актуальные, но и вообще!',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Добавить',
          'delete' => 'Удалить',
          'description' => TRUE,
          'edit' => 'Редактировать',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_financial_supply',
    'label' => 'Документы фин. обеспечения',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => '16',
    ),
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'field_sql_storage',
  1 => 'field_collection',
);
