<?php
/**
 * @file
 * ta_vocabularies.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function ta_vocabularies_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|tour_operators|form';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'tour_operators';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'name',
        1 => 'field_contract',
      ),
      'left' => array(
        2 => 'field_fullname',
        3 => 'field_shortname',
        4 => 'field_fact_address',
        5 => 'field_phone',
        6 => 'field_registration_number',
        15 => 'field_ins_contract_number',
        16 => 'field_ins_contract_date',
      ),
      'footer' => array(
        7 => 'description',
      ),
      'right' => array(
        8 => 'field_email',
        9 => 'field_site',
        10 => 'field_financial_security',
        11 => 'field_financial_guaranteer_name',
        12 => 'field_financial_guaranty_contr',
        13 => 'field_financial_guaranteer_addr',
        14 => 'field_financial_guaranteer_padd',
      ),
      'hidden' => array(
        17 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'name' => 'header',
      'field_contract' => 'header',
      'field_fullname' => 'left',
      'field_shortname' => 'left',
      'field_fact_address' => 'left',
      'field_phone' => 'left',
      'field_registration_number' => 'left',
      'description' => 'footer',
      'field_email' => 'right',
      'field_site' => 'right',
      'field_financial_security' => 'right',
      'field_financial_guaranteer_name' => 'right',
      'field_financial_guaranty_contr' => 'right',
      'field_financial_guaranteer_addr' => 'right',
      'field_financial_guaranteer_padd' => 'right',
      'field_ins_contract_number' => 'left',
      'field_ins_contract_date' => 'left',
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
  $export['taxonomy_term|tour_operators|form'] = $ds_layout;

  return $export;
}
