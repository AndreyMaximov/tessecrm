<?php

/**
 * Implements hook_views_data().
 */
function bgoi_views_data() {
  $data['bgoi']['table']['group'] = 'bgoi';
  $data['bgoi']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );

  $data['bgoi']['paystatus'] = array(
    'title' => 'bgoi: pay status',
    'help' => 'bgoi pay status',
    'field' => array(
      'handler' => 'views_handler_bgoi_field',
    ),
  );

  return $data;
}