<?php

function _contract_print_note($node) {
  //Creating a document
  //Environment path (current module)
  $env_path = drupal_get_path('module', 'contract_print');

  $template = new ZipArchive();
  $template->open($env_path . '/note_template.docx');
  $tempdir = tempnam(sys_get_temp_dir(), drupal_substr(md5(time()), 0, 4));

  //Delete the file and create dir instead
  unlink($tempdir);
  mkdir($tempdir);

  //Extract our zip into it
  $template->extractTo($tempdir);
  $template->close();


  $zipfilename = 'sites/default/files/note_' . date("d_m_y_h_i", time()) . '.docx';

  $zip = new ZipArchive();
  $zip->open($_SERVER['DOCUMENT_ROOT'] . '/' . $zipfilename, ZIPARCHIVE::CREATE);

  $list = array();
  _contract_print_scan_dir($tempdir, $list);

  //This file wont be added to the archive yet
  $toskip = array(
    'word/document.xml',
  );
  foreach ($toskip as $file) {
    $list[$file]->skip = TRUE;
  }

  // Fullfill archive structure with files.
  foreach ($list as $file) {
    if (empty($file->skip)) {
      if ($file->type == 'dir') {
        $zip->addEmptyDir($file->short);
      }
      elseif ($file->type == 'file') {
        $zip->addFile($file->path, $file->short);
      }
    }
  }

  // Дата заключения договора
  list($year, $month, $day) = explode('-', reset(explode(' ', $node->field_date[LANGUAGE_NONE][0]['value'])));
  $date = mktime(0, 0, 0, $month, $day, $year);
  // Клиент
  $client = node_load($node->field_contragent[LANGUAGE_NONE][0]['nid']);
  // Дата выдачи паспорта клиента
  list($year, $month, $day) = explode('-', reset(explode(' ', $client->field_passport_date[LANGUAGE_NONE][0]['value'])));
  $passport_date_formatted = $day . '.' . $month . '.' . $year;
  // Краткое имя клиента
  $st = explode(' ', $client->title);
  $st[1] = mb_substr($st[1], 0, 1);
  $st[2] = mb_substr($st[2], 0, 1);
  $st = $st[0] . ' ' . $st[1] . '.' . $st[2] . '.';
  // Туроператор
  $touroperator = taxonomy_term_load($node->field_tour_operator[LANGUAGE_NONE][0]['tid'], TRUE);
  // Клиенты
  foreach ($node->field_tourist[LANGUAGE_NONE] as $key => $tourist) {
    $t_node = node_load($tourist['nid']);
    $tourists[] = $t_node->title;
  }

  $replacements = array(
    '{{contract_number}}' => $node->title,
    '{{contract_date}}' => format_date($date),

    '{{tourist_fio}}' => $client->title,
    '{{tourist_fio_short}}' => $st,
    '{{tourists_list}}' => implode(', ', $tourists),
    '{{tourists_count}}' => count($tourists),

    '{{passport_emit_date}}' => $passport_date_formatted,
  );

  $fields = array(
    '{{passport_serie}}' => 'field_passport_serie',
    '{{passport_number}}' => 'field_passport_number',
    '{{passport_emitter}}' => 'field_passport_emitter',
  );
  $client_view = node_view($client);
  foreach ($fields as $key => $field_name) {
    $_access = !empty($client_view[$field_name]['#access']) && $client_view[$field_name]['#access'] && !empty($client->{$field_name});
    $replacements[$key] = $_access ? $client_view[$field_name][0]['#markup'] : '';
  }

  // Add skipped files.
  foreach ($toskip as $file) {
    $source_document = file_get_contents($env_path . '/note/' . $file);
    $replaced_document = $source_document;
    $replaced_document = str_replace(array_keys($replacements), array_values($replacements), $source_document);
    $suc = $zip->addFromString($file, $replaced_document);
  }
  if (!$zip->close()) {
    watchdog('contract_print', 'Failed closing archive %s', array('%s' => $zipfilename));
  }

  return $zipfilename;
}