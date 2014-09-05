<?php

/**
 * A handler to provide a field that is completely custom by the administrator.
 *
 * @ingroup views_field_handlers
 */
class views_handler_bgoi_field extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();

    // Override the alter text option to always alter the text.
//    $options['alter']['contains']['alter_text'] = array('default' => TRUE, 'bool' => TRUE);
//    $options['hide_alter_empty'] = array('default' => FALSE, 'bool' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Remove the checkbox
    unset($form['alter']['alter_text']);
    unset($form['alter']['text']['#dependency']);
    unset($form['alter']['text']['#process']);
    unset($form['alter']['help']['#dependency']);
    unset($form['alter']['help']['#process']);
//    $form['#pre_render'][] = 'views_handler_field_custom_pre_render_move_text';
  }

  function render($values) {
    $output = '';
    $node = node_load($values->nid);
    if (!empty($node->bgoi)) {
      $output .= '<div style="line-height: 1;">';
      $output .= '<a href="https://www.bgoperator.ru/tozaya?idTour=' . $node->bgoi['id'] . '&find=yes" target="_blank">№' . $node->bgoi['num'] . '</a><br>';
      $output .= '<span style="font-size:9px;line-heigth:1;"><strong>Статус заявки:</strong> ' . $node->bgoi['tourStat'] . '</span><br>';
      $output .= '<span style="font-size:9px;line-height:1;"><strong>Статус оплаты:</strong> ' . $node->bgoi['payStatus'] . '</span><br>';
      if ($node->bgoi['debt']) {
        $output .= '<span style="font-size:9px;line-height:1;"><strong>Задолженность:</strong> ' . $node->bgoi['debt'] . '</span>';
      }
      $output .= '</div>';
    }

    return $output;
  }
}