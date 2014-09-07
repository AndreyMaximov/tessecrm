<?php
/**
 * @file
 * ds_layout_settings.taxonomy_term_tour_operators_form.inc
 */

$api = '2.0.0';

$data = $ds_layout = new stdClass();
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
      7 => 'field_ins_contract_number',
      8 => 'field_ins_contract_date',
    ),
    'right' => array(
      9 => 'field_site',
      10 => 'field_financial_security',
      11 => 'field_financial_guaranteer_name',
      12 => 'field_financial_guaranty_contr',
      13 => 'field_financial_guaranteer_addr',
      14 => 'field_financial_guaranteer_padd',
    ),
    'footer' => array(
      15 => 'field_inn',
      16 => 'field_financial_supply',
      17 => 'description',
    ),
    'hidden' => array(
      18 => '_add_existing_field',
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
    'field_ins_contract_number' => 'left',
    'field_ins_contract_date' => 'left',
    'field_site' => 'right',
    'field_financial_security' => 'right',
    'field_financial_guaranteer_name' => 'right',
    'field_financial_guaranty_contr' => 'right',
    'field_financial_guaranteer_addr' => 'right',
    'field_financial_guaranteer_padd' => 'right',
    'field_inn' => 'footer',
    'field_financial_supply' => 'footer',
    'description' => 'footer',
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


$dependencies = array();

$optional = array();

$modules = array(
  0 => 'ctools',
  1 => 'ds',
);
