<?php
/**
 * @file
 * ta_content_types.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function ta_content_types_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contract|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contract';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|contract|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|tourist|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'tourist';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'tourist_contracts' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:9:"arguments";a:1:{s:17:"field_tourist_nid";s:9:"%node:nid";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:40:"clients_contracts-clients_contracts_pane";}',
        'load_terms' => 0,
      ),
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|tourist|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function ta_content_types_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'tourist_contracts';
  $ds_field->label = 'Договоры туриста';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'tourist|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['tourist_contracts'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function ta_content_types_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contract|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contract';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_3col_stacked_equal_width';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_client_price',
        2 => 'field_departure_date',
        3 => 'field_country',
      ),
      'middle' => array(
        4 => 'field_date',
        5 => 'field_price',
        6 => 'field_duration',
        7 => 'field_manager',
      ),
      'right' => array(
        8 => 'field_tour_operator',
        9 => 'field_contragent',
        10 => 'field_tourist',
        11 => 'field_prepay',
      ),
      'footer' => array(
        12 => 'field_contract',
        13 => 'field_attachment_text',
        14 => 'field_attachment',
      ),
      'hidden' => array(
        15 => 'field_description',
        16 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_client_price' => 'left',
      'field_departure_date' => 'left',
      'field_country' => 'left',
      'field_date' => 'middle',
      'field_price' => 'middle',
      'field_duration' => 'middle',
      'field_manager' => 'middle',
      'field_tour_operator' => 'right',
      'field_contragent' => 'right',
      'field_tourist' => 'right',
      'field_prepay' => 'right',
      'field_contract' => 'footer',
      'field_attachment_text' => 'footer',
      'field_attachment' => 'footer',
      'field_description' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'role="form"',
  );
  $export['node|contract|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contract|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contract';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'field_date',
        1 => 'field_price',
        2 => 'field_client_price',
      ),
      'left' => array(
        3 => 'field_contract',
        4 => 'field_tour_operator',
        5 => 'field_departure_date',
        6 => 'field_duration',
        7 => 'field_country',
      ),
      'right' => array(
        8 => 'field_prepay',
        9 => 'field_manager',
        10 => 'field_contragent',
        11 => 'field_tourist',
      ),
      'footer' => array(
        12 => 'comments',
        13 => 'field_description',
        14 => 'field_attachment',
        15 => 'field_attachment_text',
      ),
    ),
    'fields' => array(
      'field_date' => 'header',
      'field_price' => 'header',
      'field_client_price' => 'header',
      'field_contract' => 'left',
      'field_tour_operator' => 'left',
      'field_departure_date' => 'left',
      'field_duration' => 'left',
      'field_country' => 'left',
      'field_prepay' => 'right',
      'field_manager' => 'right',
      'field_contragent' => 'right',
      'field_tourist' => 'right',
      'comments' => 'footer',
      'field_description' => 'footer',
      'field_attachment' => 'footer',
      'field_attachment_text' => 'footer',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
  );
  $export['node|contract|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tourist|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tourist';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'footer' => array(
        0 => 'body',
      ),
      'right' => array(
        1 => 'tourist_contracts',
      ),
      'header' => array(
        2 => 'title',
      ),
      'left' => array(
        3 => 'field_birth_day',
        4 => 'field_passport_serie',
        5 => 'field_passport_number',
        6 => 'field_passport_emitter',
        7 => 'field_passport_date',
        8 => 'field_address',
        9 => 'field_phone',
      ),
    ),
    'fields' => array(
      'body' => 'footer',
      'tourist_contracts' => 'right',
      'title' => 'header',
      'field_birth_day' => 'left',
      'field_passport_serie' => 'left',
      'field_passport_number' => 'left',
      'field_passport_emitter' => 'left',
      'field_passport_date' => 'left',
      'field_address' => 'left',
      'field_phone' => 'left',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
  );
  $export['node|tourist|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|tourist|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'tourist';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_birth_day',
        6 => 'field_address',
        7 => 'field_phone',
      ),
      'right' => array(
        2 => 'field_passport_serie',
        3 => 'field_passport_number',
        4 => 'field_passport_emitter',
        5 => 'field_passport_date',
      ),
      'footer' => array(
        8 => 'body',
      ),
      'hidden' => array(
        9 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_birth_day' => 'left',
      'field_passport_serie' => 'right',
      'field_passport_number' => 'right',
      'field_passport_emitter' => 'right',
      'field_passport_date' => 'right',
      'field_address' => 'left',
      'field_phone' => 'left',
      'body' => 'footer',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
  );
  $export['node|tourist|form'] = $ds_layout;

  return $export;
}
