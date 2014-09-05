<?php

/**
 * Module configuration form builder.
 */
function bgoi_admin_form($form, &$form_state) {
  $form['credentials'] = array(
    '#type' => 'fieldset',
    '#title' => t('Credentials'),
  );
  $form['credentials']['bgoi_login'] = array(
    '#type' => 'textfield',
    '#title' => 'login',
    '#default_value' => variable_get('bgoi_login', ''),
  );
  $form['credentials']['bgoi_passwd'] = array(
    '#type' => 'password',
    '#title' => 'password',
    '#default_value' => _variable_get_decrypted('bgoi_passwd', ''),
    '#element_validate' => array(
      'bgoi_password_validate',
    ),
  );

  $options = _bgoi_get_bundles_options();
  $form['storage'] = array(
    '#type' => 'fieldset',
    '#title' => t('Storage'),
  );
  $form['storage']['bgoi_bundle'] = array(
    '#type' => 'select',
    '#title' => 'Entity bundle',
    '#options' => $options,
    '#default_value' => variable_get('bgoi_bundle', 0),
    '#ajax' => array(
      'callback' => 'bgoi_ajax_bundle_callback',
      'wrapper' => 'bgoi-field-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  $bundle = isset($form_state['values']['bgoi_bundle'])
    ? $form_state['values']['bgoi_bundle']
    : $form['storage']['bgoi_bundle']['#default_value'];

  $fields = _bgoi_bundle_text_fields($bundle);

  $form['storage']['bgoi_field'] = array(
    '#type' => 'select',
    '#title' => 'Field containing remote id',
    '#options' => $fields,
    '#default_value' => variable_get('bgoi_field', ''),
    '#prefix' => '<div id="bgoi-field-wrapper">',
    '#suffix' => '</div>',
  );

  return system_settings_form($form);
}

function bgoi_ajax_bundle_callback($form, $form_state) {
  return $form['storage']['bgoi_field'];
}

function _bgoi_bundle_text_fields($_bundle) {
  if (!$_bundle) return array();
  list($entity_type, $bundle) = explode(':', $_bundle);
  $fi = field_info_instances($entity_type, $bundle);
  foreach ($fi as $field_name => $field_info) {
    $options[$field_name] = $field_name . ' - ' . $field_info['label'];
  }
  return $options;
}

/**
 * Password element validate callback.
 */
function bgoi_password_validate($element, &$form_state) {
  $p = $form_state['values']['bgoi_passwd'];
  $value = $p ? $p : _variable_get_decrypted('bgoi_passwd');
  $form_state['values']['bgoi_passwd'] = encrypt($value);
}

function _bgoi_get_bundles_options() {
  $options = array(0 => '- none -');
  foreach (field_info_bundles() as $entity_type => $bundles) {
    foreach ($bundles as $bundle => $bundle_info) {
      $options[$entity_type . ':' . $bundle] = $entity_type . ':' . $bundle . ' - ' . $bundle_info['label'];
    }
  }
  return $options;
}