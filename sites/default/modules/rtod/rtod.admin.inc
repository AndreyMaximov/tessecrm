<?php

/**
 * @file Admin page callback and forms.
 */

function rtod_admin_info_page() {
  $page = array();
  $page['execution_form'] = drupal_get_form('rtod_manual_execute_form');

  $last_update = variable_get('rtod_lastupdate', 0) ? date('c', variable_get('rtod_lastupdate', 0)) : t('Never');
  $page['last_update'] = array(
    '#type' => 'markup',
    '#markup' => t('Last updated: %last_update', array('%last_update' => $last_update)),
    '#prefix' => '<div>',
    '#suffix' => '</div>'
  );

  return $page;
}

/**
 * Russia Tourism manual execution form builder.
 */
function rtod_manual_execute_form() {
  $form = array();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update manually'),
  );

  return $form;
}

/**
 * Russia Tourism manual execution form submit handler.
 */
function rtod_manual_execute_form_submit() {
  try {
    // Moscow
    $passportParser = new Drupal\rtod\PassportParser();
    $passportParser->actualizeAll();
    // Moscow region
    $passportParser = new Drupal\rtod\PassportParser('http://opendata.russiatourism.ru/7708550300-ReestrRosturizm50B');
    $passportParser->actualizeAll();
    variable_set('rtod_lastupdate', time());
  }
  catch (Exception $e) {
    watchdog('rtod', '%s', array('%s' => $e->getMessage()), WATCHDOG_ERROR);
  }
}

/**
 * Russia Tourism integration settings form builder.
 *
 * checkbox "update on cron";
 * select element "update every" with options 3hr, 1day, 7 days;
 * submit button.
 *
 * @param $form
 * @param $form_state
 */
function rtod_settings_form($form, $form_state) {
  $form['rtod_update_on_cron'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update on cron'),
    '#default_value' => variable_get('rtod_update_on_cron', 0),
  );

  $form['rtod_update_period'] = array(
    '#type' => 'radios',
    '#title' => t('Update every'),
    '#options' => array(
      3600 * 3 => '3 hours',
      86400 => '1 day',
      86400 * 7 => '7 days',
    ),
    '#default_value' => variable_get('rtod_update_period', 86400),
  );

  return system_settings_form($form);
}