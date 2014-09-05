<?php
/**
 * @file
 * Field encrypt - Extension of the Field API to allow encryption of fields - class
 *
 * Modify the set & get methods to encrypt/decrypt the cache, use internal key
 */

/**
 * Class FieldEncryptDatabaseCache
 */
class FieldEncryptDatabaseCache extends DrupalDatabaseCache {
  /**
   * Prepare a cached item.
   *
   * Checks that items are either permanent or did not expire, and unserializes
   * data as appropriate.
   *
   * @param $cache
   *   An item loaded from cache_get() or cache_get_multiple().
   *
   * @return
   *   The item with data unserialized as appropriate or FALSE if there is no
   *   valid item to load.
   */
  protected function prepareItem($cache) {
    global $user;
    if (!isset($cache->data)) {
      return FALSE;
    }
    // If enforcing a minimum cache lifetime, validate that the data is
    // currently valid for this user before we return it by making sure the cache
    // entry was created before the timestamp in the current session's cache
    // timer. The cache variable is loaded into the $user object by _drupal_session_read()
    // in session.inc. If the data is permanent or we're not enforcing a minimum
    // cache lifetime always return the cached data.
    if ($cache->expire != CACHE_PERMANENT && variable_get('cache_lifetime', 0) && $user->cache > $cache->created) {
      // This cache data is too old and thus not valid for us, ignore it.
      return FALSE;
    }

    // Decrypt the data just before we return it
    module_load_include('inc', 'field_encrypt');
    $cache->data = field_encrypt_decrypt($cache->data);

    if ($cache->serialized) {
      $cache->data = unserialize($cache->data);
    }

    return $cache;
  }

  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $fields = array(
      'serialized' => 0,
      'created'    => REQUEST_TIME,
      'expire'     => $expire,
    );
    if (!is_string($data)) {
      $fields['data']       = serialize($data);
      $fields['serialized'] = 1;
    }
    else {
      $fields['data']       = $data;
      $fields['serialized'] = 0;
    }

    // encrypt the data just before it's saved
    module_load_include('inc', 'field_encrypt');
    $fields['data'] = field_encrypt_encrypt($fields['data']);

    try {
      db_merge($this->bin)->key(array('cid' => $cid))->fields($fields)
        ->execute();
    }
    catch (Exception $e) {
      // The database may not be available, so we'll ignore cache_set requests.
    }
  }

}
