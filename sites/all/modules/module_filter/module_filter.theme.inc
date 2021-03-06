<?php

/**
 * @file
 *
 * @author greenSkin
 */

function theme_module_filter($variables) {
  $element = $variables['element'];
  return '<div class="module-filter-inputs-wrapper">' . drupal_render_children($element) . '</div>';
}

/**
 * A router theme function.
 *
 * Appropriately themes the system modules page with alterations and based on
 * set variables
 *
 * @param $form
 *   An associative array containing the structure of the form.
 *
 * @return
 *   An output string.
 */
function theme_module_filter_system_modules($variables) {
  $form = $variables['form'];

  $output = '';
  if (variable_get('module_filter_tabs', 1)) {
    $form['module_filter']['#attached']['css'][] = drupal_get_path('module', 'module_filter') .'/css/module_filter_tab.css';
    $form['module_filter']['#attached']['js'][] = 'misc/jquery.ba-bbq.js';
    $form['module_filter']['#attached']['js'][] = drupal_get_path('module', 'module_filter') .'/js/module_filter_tab.js';

    $output .= theme('module_filter_system_modules_tabs', $form);
  }
  else {
    $form['#theme'] = 'system_modules';

    $output .= drupal_render($form['module_filter']);
    $output .= drupal_render($form['modules']);
    $output .= drupal_render($form['actions']);
  }

  return $output;
}

/**
 * Theme callback for the modules tabbed form.
 */
function theme_module_filter_system_modules_tabs($variables) {
  $form = $variables['form'];

  $form['actions']['#prefix'] = '<div id="module-filter-submit">';
  $form['actions']['#suffix'] = '</div>';

  $header = array(
    t('Enabled'),
    t('Name'),
    t('Version'),
    t('Description')
  );
  $package_ids = array('all', 'new');
  $enabled['all'] = $enabled['new'] = array();

  // Determine what modules are new (within a week).
  $new_modules = module_filter_new_modules();

  $rows = array();
  $flip = array('even' => 'odd', 'odd' => 'even');
  foreach (element_children($form['modules']) as $package) {
    $package_id = module_filter_get_id($package);
    $package_ids[] = $package_id;

    $rows[] = array('data' => array(array('data' => '<h3>' . $form['modules'][$package]['#title'] . '</h3>', 'colspan' => 4)), 'id' => $package_id, 'class' => array('admin-package-title'));
    $rows[] = array('data' => $header, 'class' => array('admin-package-header'));

    $stripe = 'odd';
    $enabled[$package] = array();
    foreach (element_children($form['modules'][$package]) as $key) {
      $module = &$form['modules'][$package][$key];

      $is_enabled = isset($module['enable']['#default_value']) ? $module['enable']['#default_value'] : '';
      $enabled['all'][] = $enabled[$package][] = $is_enabled;
      if (isset($new_modules[$key])) {
        $enabled['new'][] = $is_enabled;
      }

      $row = array();
      unset($module['enable']['#title']);
      $class = ($is_enabled ? 'enabled' : 'off');
      if (!empty($module['enable']['#disabled'])) {
        $class .= ' disabled';
      }
      $row[] = array('class' => array('checkbox'), 'data' => '<div class="js-hide toggle-enable ' . $class . '"><div>&nbsp;</div></div>' . drupal_render($module['enable']));
      $label = '<label';
      if (isset($module['enable']['#id'])) {
        $label .= ' for="' . $module['enable']['#id'] . '"';
      }
      $row[] = array('class' => array('name'), 'data' => $label . '><strong>' . drupal_render($module['name']) . '</strong><br><span class="module-machine-name">(' . $key . ')</span></label>');
      $row[] = array('class' => array('version'), 'data' => drupal_render($module['version']));
      // Add the description, along with any modules it requires and any
      // operation links.
      $description = drupal_render($module['description']);
      if ($module['#requires']) {
        $description .= '<div class="admin-requirements">' . t('Requires: !module-list', array('!module-list' => implode(', ', $module['#requires']))) . '</div>';
      }
      if ($module['#required_by']) {
        $description .= '<div class="admin-requirements">' . t('Required by: !module-list', array('!module-list' => implode(', ', $module['#required_by']))) . '</div>';
      }
      $items = array();
      foreach (array('help', 'permissions', 'configure') as $link) {
        $data = drupal_render($module['links'][$link]);
        if (!empty($data)) {
          $items[] = array('data' => $data);
        }
      }
      if (!empty($items)) {
        $description .= '<div class="admin-operations">' . theme('item_list', array('items' => $items, 'attributes' => array('class' => array('links', 'inline')))) . '</div>';
      }
      $description .= drupal_render($module['links']);
      $row[] = array('data' => $description, 'class' => array('description'));

      $class = array(module_filter_get_id($package) . '-tab', 'module', $stripe);
      if (isset($new_modules[$key])) {
        $class[] = 'new-module';
      }
      $rows[] = array('data' => $row, 'no_striping' => TRUE, 'class' => $class);
      $stripe = $flip[$stripe];
    }

    // Set the package as printed.
    $form['modules'][$package]['#printed'] = TRUE;
  }

  if (variable_get('module_filter_count_enabled', 1)) {
    $enabled_counts = array();
    foreach ($enabled as $package => $value) {
      $enabled_counts[module_filter_get_id($package)] = array(
        'enabled' => count(array_filter($value)),
        'total' => count($value),
      );
    }
    drupal_add_js(array(
      'moduleFilter' => array(
        'packageIDs' => $package_ids,
        'enabledCounts' => $enabled_counts,
      )
    ), 'setting');
  }

  // Add first and last class to rows.
  $rows[0]['class'][] = 'first';
  $rows[count($rows) - 1]['class'][] = 'last';

  $output = '<div id="module-filter-wrapper">';
  $output .= '<div id="module-filter-modules">' . drupal_render($form['module_filter']);
  $output .= theme('table', array('header' => $header, 'rows' => $rows));
  $output .= drupal_render_children($form);
  $output .= '</div>';
  $output .= '</div>';
  return $output;
}
