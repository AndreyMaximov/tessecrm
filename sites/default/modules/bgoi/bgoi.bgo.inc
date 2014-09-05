<?php

/**
 * Retrieves cached tours data or requests from remote if expired.
 */
function bgoi_get_tours_cached() {
  if ($cache = cache_get('bgoi_tours')) {
    if ($cache->expire > time() && $cache->data) {
      return $cache->data;
    }
  }

  $tours = _bgoi_get_tours();
  cache_set('bgoi_tours', $tours, 'cache', time() + 60);

  return $tours;
}

/**
 * Requests actual tours data from remote.
 */
function _bgoi_get_tours() {
  $tours = array();

  $login = variable_get('bgoi_login', '');
  $password = _variable_get_decrypted('bgoi_passwd', '');

  $url = 'https://' . $login . ':' . $password . '@www.bgoperator.ru/rservice?task=agToursXML';

  if (!$login || !$password) return array();

  $result = drupal_http_request($url);

  if ($result->code == '200' && $result->status_message == 'OK') {
    $dom = new DOMDocument();
    $dom->loadXML($result->data);

    $xpath = new DOMXPath($dom);
    $items = $xpath->query('tour');
    foreach ($items as $item) {
      $id = $item->getAttribute('id');
      $num = $item->getAttribute('num');
      $tourStat = $xpath->query('tourStat', $item)->item(0)->nodeValue;
      $payStatus = $xpath->query('payStatus', $item)->item(0)->nodeValue;
      $debt = $xpath->query('debt', $item)->item(0)->nodeValue;
      $tours[$id] = array(
        'id' => $id,
        'num' => $num,
        'tourStat' => $tourStat,
        'payStatus' => $payStatus,
        'debt' => $debt,
      );
      $tours[$num] = $tours[$id];
    }
  }
  else {
    watchdog('bgoi', 'Error: %s', array('%s' => $result->error), WATCHDOG_ERROR);
  }

  //dpm($tours, 'tours');

  return $tours;
}