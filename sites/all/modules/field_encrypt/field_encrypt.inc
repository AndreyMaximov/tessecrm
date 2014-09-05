<?php
/**
 * @file
 * Encryption functionality for the Field encrypt module.
 */

/**
 * Add encryption to a field.
 *
 * Called when the "Encrypt this field" setting is first applied.
 *
 * @param $field_info
 * @param $has_data
 */
function field_encrypt_do_encrypt($field_info, $has_data) {
  // Column spec for encrypted data.
  $spec = array(
    'type'        => 'text',
    'size'        => 'medium',
    'description' => 'The encrypted value for this entity field column.',
  );

  // Prepare field so the storage details are available.
  $cache = _field_info_field_cache();
  $cache->flush();
  $field_info = $cache->prepareField($field_info);

  foreach (array(FIELD_LOAD_CURRENT, FIELD_LOAD_REVISION) as $key) {
    $table = key($field_info['storage']['details']['sql'][$key]);

    if ($has_data) {
      // Get all the current entries.
      $data = db_select($table, 't')->fields('t')->execute()->fetchAll();

      // Delete the existing unencrypted data.
      db_delete($table)->execute();
    }

    // Alter field columns to allow for encrypted data.
    foreach ($field_info['storage']['details']['sql'][$key][$table] as $column => $field) {
      if (!isset($field_info['indexes'][$column])) {
        db_change_field($table, $field, $field, $spec);
      }
    }

    // Encrypt and re-insert the data.
    if ($has_data) {
      foreach ($data as $record) {
        foreach ($field_info['storage']['details']['sql'][$key][$table] as $column => $field) {
          if (!isset($field_info['indexes'][$column])) {
            $record->{$field} = field_encrypt_encrypt($record->{$field});
          }
        }
        drupal_write_record($table, $record);
      }
    }
  }

  drupal_set_message(t('%field_name is now being encrypted', array('%field_name' => $field_info['field_name'])));
}

/**
 * Remove encryption from a field.
 *
 * Called when the "Encrypt this field" setting is disabled.
 *
 * @param $field_info
 * @param $has_data
 */
function field_encrypt_un_encrypt($field_info, $has_data) {
  // Prepare field so the storage details are available.
  $cache = _field_info_field_cache();
  $cache->flush();
  $field_info = $cache->prepareField($field_info);

  foreach (array(FIELD_LOAD_CURRENT, FIELD_LOAD_REVISION) as $key) {
    $table = key($field_info['storage']['details']['sql'][$key]);

    if ($has_data) {
      // Get all the current entries.
      $data = db_select($table, 't')->fields('t')->execute()->fetchAll();

      // Delete the existing encrypted data.
      db_delete($table)->execute();
    }

    // Revert the field columns back to their original state.
    foreach ($field_info['storage']['details']['sql'][$key][$table] as $column => $field) {
      if (!isset($field_info['indexes'][$column])) {
        db_change_field($table, $field, $field, $field_info['columns'][$column]);
      }
    }

    // Decrypt and re-insert the data.
    if ($has_data) {
      foreach ($data as $record) {
        foreach ($field_info['storage']['details']['sql'][$key][$table] as $column => $field) {
          if (isset($record->{$field}) && !empty($record->{$field}) && !isset($field_info['indexes'][$column])) {
            $record->{$field} = field_encrypt_decrypt($record->{$field});
          }
        }
        drupal_write_record($table, $record);
      }
    }
  }

  drupal_set_message(t('%field_name is no longer being encrypted', array('%field_name' => $field_info['field_name'])));
}

/**
 * Implements hook_field_storage_pre_update().
 */
function _field_encrypt_field_storage_pre_update($entity_type, $entity, &$skip_fields) {
  static $field_info = NULL;
  if ($field_info === NULL) {
    $field_info = field_info_field_by_ids();
  }

  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
  if (is_null($vid)) {
    $vid = $id;
  }
  $default_options = array(
    'default'  => FALSE,
    'deleted'  => FALSE,
    'language' => NULL,
  );
  $instances       = _field_invoke_get_instances($entity_type, $bundle, $default_options);

  foreach ($instances as $instance) {
    // Get the field data
    $field_id           = $instance['field_id'];
    $current_field_info = $field_info[$field_id];

    // Are we encrypting this field?
    if (!isset($current_field_info['settings']['field_encrypt']['encrypt']) || !$current_field_info['settings']['field_encrypt']['encrypt']) {
      // Encryption setting is set to FALSE, skip it.
      continue;
    }

    $field_name     = $instance['field_name'];
    $data_table     = key($current_field_info['storage']['details']['sql'][FIELD_LOAD_CURRENT]);
    $revision_table = key($current_field_info['storage']['details']['sql'][FIELD_LOAD_REVISION]);

    // We're bypassing usual storage, mark field for skipping.
    $skip_fields[$field_id] = $current_field_info;

    // If there's nothing in the field, go no further.
    if (empty($entity->{$field_name})) {
      continue;
    }

    // Now we need to insert the data, we can't do multiple merges so we have to
    // do each language/delta separately.
    foreach ($entity->{$field_name} as $language => $items) {
      foreach ($items as $delta => $item) {
        $merge_keys = array(
          'entity_type' => $entity_type,
          'bundle'      => $bundle,
          'deleted'     => 0,
          'entity_id'   => $id,
          'language'    => $language,
          'delta'       => $delta,
        );

        $fields = array(
          'revision_id' => $vid,
        );
        foreach ($current_field_info['storage']['details']['sql'][FIELD_LOAD_CURRENT][$data_table] as $column => $field) {
          if (isset($item[$column]) && !empty($item[$column])) {
            $fields[$field] = !isset($current_field_info['indexes'][$column]) ? field_encrypt_encrypt($item[$column]) : $item[$column];
          }
        }

        // Put data in data table.
        db_merge($data_table)->key($merge_keys)->fields($fields)->execute();

        // Put data in revision table.
        $merge_keys['revision_id'] = $vid;
        unset($fields['revision_id']);
        db_merge($revision_table)->key($merge_keys)->fields($fields)->execute();
      }
    }
  }
}

/**
 * Implements hook_field_storage_pre_load().
 */
function _field_encrypt_field_storage_pre_load($entity_type, $queried_entities, $age, &$skip_fields, $options) {
  static $field_info = NULL;
  if ($field_info === NULL) {
    $field_info = field_info_field_by_ids();
  }

  foreach ($queried_entities as $entity) {
    list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);
    if (is_null($vid)) {
      $vid = $id;
    }
    $default_options = array(
      'default'  => FALSE,
      'deleted'  => FALSE,
      'language' => NULL,
    );
    $instances       = _field_invoke_get_instances($entity_type, $bundle, $default_options);

    foreach ($instances as $instance) {
      // Get the field data
      $field_id           = $instance['field_id'];
      $current_field_info = $field_info[$field_id];

      // Are we encrypting this field?
      if (!isset($current_field_info['settings']['field_encrypt']['encrypt']) || !$current_field_info['settings']['field_encrypt']['encrypt']) {
        continue;
      }

      $field_name = $instance['field_name'];
      $table      = key($current_field_info['storage']['details']['sql'][FIELD_LOAD_REVISION]);

      // We're bypassing usual storage, mark field for skipping
      $skip_fields[$field_id] = $current_field_info;

      // Now we need to fetch the encrypted data
      $results = db_select($table, 'r')->fields('r')
        ->condition('r.entity_type', $entity_type)
        ->condition('r.entity_id', $id)->condition('r.revision_id', $vid)
        ->orderBy('r.language', 'ASC')->orderBy('r.delta', 'ASC')->execute()
        ->fetchAll();

      $field_data = array();
      foreach ($results as $result) {
        foreach ($current_field_info['storage']['details']['sql'][FIELD_LOAD_REVISION][$table] as $column => $field) {
          if (isset($result->{$field}) && !empty($result->{$field})) {
            $field_data[$result->language][$result->delta][$column] = !isset($current_field_info['indexes'][$column]) ? field_encrypt_decrypt($result->{$field}) : $result->{$field};
          }
        }
      }
      $entity->{$field_name} = $field_data;
    }
  }
}

/**
 * Encrypt raw message.
 *
 * @param $raw
 *
 * @return string
 */
function field_encrypt_encrypt($raw) {
  $encrypted = encrypt($raw, array('base64' => TRUE));

  return utf8_encode($encrypted);
}

/**
 * Decrypt encrypted message.
 *
 * @param $encrypted
 *
 * @return mixed|string
 */
function field_encrypt_decrypt($encrypted) {
  $encrypted = utf8_decode($encrypted);
  $decrypted = decrypt($encrypted, array('base64' => TRUE));

  return $decrypted;
}
