<?php

function _contract_print_version_5($node) {
  //Creating a document
  //Environment path (current module)
  $env_path = drupal_get_path('module', 'contract_print');

  $template = new ZipArchive();
  $template->open($env_path . '/contract.v3.docx');
  $tempdir = tempnam(sys_get_temp_dir(), drupal_substr(md5(time()), 0, 4));

  //Delete the file and create dir instead
  unlink($tempdir);
  mkdir($tempdir);

  //Extract our zip into it
  $template->extractTo($tempdir);
  $template->close();


  $zipfilename = 'sites/default/files/contract_' . date("d_m_y_h_i", time()) . '.docx';

  $zip = new ZipArchive();
  $zip->open($_SERVER['DOCUMENT_ROOT'] . '/' . $zipfilename, ZIPARCHIVE::CREATE);

  $list = array();
  _contract_print_scan_dir($tempdir, $list);

  //This file wont be added to the archive yet
  $toskip = array(
    'word/document.xml',
    'word/header2.xml'
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
    $tourists[] = '<w:p w:rsidR="00AA045D" w:rsidRPr="0088204A" w:rsidRDefault="007E5DA4">
      <w:r w:rsidRPr="0088204A">
        <w:t>' . ($key + 1) . ') ' . $t_node->title . '</w:t>
      </w:r>
    </w:p>';
  }

  $finsupplies = array();
  if ($field_items = field_get_items('taxonomy_term', $touroperator, 'field_financial_supply')) {
    // Calculate significant period:
    // from contract sign date to return date (departure date + duration)
    $sign_date = strtotime($node->field_date[LANGUAGE_NONE][0]['value']);
    $return_date = strtotime($node->field_departure_date[LANGUAGE_NONE][0]['value']);
    $return_date += 86400 * intval($node->field_duration[LANGUAGE_NONE][0]['value']);

    foreach ($field_items as $item) {
      $fs = field_collection_item_load($item['value']);
      // Period of financial supply validity
      $fs_from = strtotime($fs->field_fs_period[LANGUAGE_NONE][0]['value']);
      $fs_to = strtotime($fs->field_fs_period[LANGUAGE_NONE][0]['value2']);
      if ($fs_from <= $return_date && $fs_to >= $sign_date) {
        $finsupplies[] = _contract_print_v5_format_finsupply_item($fs);
      }
    }
  }


  $replacements = array(
    '{{title}}' => $node->title,
    '{{field_data_formatted}}' => format_date($date),
    '{{client_title}}' => $client->title,
    '{{client_field_passport_date}}' => $passport_date_formatted,
    '{{tourists}}' => implode('', $tourists),
    '{{client_short_title}}' => $st,
    '{{touroperator_field_fullname}}' => $touroperator->field_fullname[LANGUAGE_NONE][0]['value'],
    '{{touroperator_field_shortname}}' => $touroperator->field_shortname[LANGUAGE_NONE][0]['value'],
    '{{touroperator_field_fact_address}}' => $touroperator->field_fact_address[LANGUAGE_NONE][0]['value'],
    '{{touroperator_field_phone}}' => $touroperator->field_phone[LANGUAGE_NONE][0]['value'],
    '{{touroperator_field_site}}' => $touroperator->field_site[LANGUAGE_NONE][0]['value'],
    '{{touroperator_financial_supplies}}' => implode('', $finsupplies),
  );

  $fields = array(
    '{{client_field_passport_serie}}' => 'field_passport_serie',
    '{{client_field_passport_number}}' => 'field_passport_number',
    '{{cliend_field_passport_emitter}}' => 'field_passport_emitter',
    '{{client_field_address}}' => 'field_address',
    '{{client_field_phone}}' => 'field_phone',
    '{{client_field_email}}' => 'field_email',
  );
  $client_view = node_view($client);
  foreach ($fields as $key => $field_name) {
    $_access = !empty($client_view[$field_name]['#access']) && $client_view[$field_name]['#access'] && !empty($client->{$field_name});
    $replacements[$key] = $_access ? $client_view[$field_name][0]['#markup'] : '';
  }

  // Add skipped files.
  foreach ($toskip as $file) {
    $source_document = file_get_contents($env_path . '/contract.v5/' . $file);
    $replaced_document = str_replace(array_keys($replacements), array_values($replacements), $source_document);
    $suc = $zip->addFromString($file, $replaced_document);
  }
  if (!$zip->close()) {
    watchdog('contract_print', 'Failed closing archive %s', array('%s' => $zipfilename));
  }

  return $zipfilename;
}

function _contract_print_v5_format_finsupply_item($item) {
  $output = '<w:p>
      <w:pRp>
        <w:spacing w:before="360" w:after="120" w:line="480" w:lineRule="auto" w:beforeAutospacing="0" w:afterAutospacing="0"/>
      </w:pRp>
      <w:r>
        <w:rPr>
          <w:rFonts w:ascii="Verdana" w:hAnsi="Verdana"/>
          <w:sz w:val="14"/>
          <w:szCs w:val="14"/>
        </w:rPr>
        <w:t>'
          . $item->field_fs_type[LANGUAGE_NONE][0]['value']
          .' на ' . $item->field_fs_size[LANGUAGE_NONE][0]['value'] . ' рублей'
          . ' № ' . $item->field_fs_doc_number[LANGUAGE_NONE][0]['value']
          . ' от ' . date('d/m/Y', strtotime($item->field_fs_date_signed[LANGUAGE_NONE][0]['value'])) . '
        </w:t>
        <w:br/>
        <w:t>
          Срок действия с ' . date('d/m/Y', strtotime($item->field_fs_period[LANGUAGE_NONE][0]['value']))
          . ' по ' . date('d/m/Y', strtotime($item->field_fs_period[LANGUAGE_NONE][0]['value2'])) . '
        </w:t>
        <w:br/>
        <w:t>
          Наименование организации, предоставляющей фин. гарантии: '
          . $item->field_fs_org_name[LANGUAGE_NONE][0]['value'] . '
        </w:t>
        <w:br/>
        <w:t>
          Адрес организации, предоставляющей фин. гарантии: '
          . $item->field_fs_org_fact_addr[LANGUAGE_NONE][0]['value'] . '
        </w:t>
        <w:br/>
        <w:t>
          Почтовый адрес организации, предоставляющей фин. гарантии: '
          . $item->field_fs_org_post_addr[LANGUAGE_NONE][0]['value'] . '
        </w:t>
        <w:br/>
      </w:r>
    </w:p>';

  return $output;
}