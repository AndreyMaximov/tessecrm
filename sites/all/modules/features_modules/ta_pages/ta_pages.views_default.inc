<?php
/**
 * @file
 * ta_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ta_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'clients';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Клиенты';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '№';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Sort criterion: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Содержимое: Заголовок */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'upper';
  $handler->display->display_options['arguments']['title']['transform_dash'] = TRUE;
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tourist' => 'tourist',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Заголовок */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'upper';
  $handler->display->display_options['arguments']['title']['transform_dash'] = TRUE;
  $handler->display->display_options['path'] = 'clients';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Клиенты';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Вложение */
  $handler = $view->new_display('attachment', 'Вложение', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Заголовок */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'unformatted_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = TRUE;
  $handler->display->display_options['arguments']['title']['limit'] = '1';
  $handler->display->display_options['arguments']['title']['case'] = 'upper';
  $handler->display->display_options['arguments']['title']['path_case'] = 'upper';
  $handler->display->display_options['arguments']['title']['transform_dash'] = TRUE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $translatables['clients'] = array(
    t('Master'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('№'),
    t('Edit link'),
    t('Все'),
    t('Page'),
    t('Вложение'),
  );
  $export['clients'] = $view;

  $view = new view();
  $view->name = 'clients_contracts';
  $view->description = 'Используется на странице клиента';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Договора клиента';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_departure_date' => 'field_departure_date',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_departure_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Передан аргумент !1';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Дата вылета */
  $handler->display->display_options['fields']['field_departure_date']['id'] = 'field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['table'] = 'field_data_field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['field'] = 'field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Содержимое: Дата вылета (field_departure_date) */
  $handler->display->display_options['sorts']['field_departure_date_value']['id'] = 'field_departure_date_value';
  $handler->display->display_options['sorts']['field_departure_date_value']['table'] = 'field_data_field_departure_date';
  $handler->display->display_options['sorts']['field_departure_date_value']['field'] = 'field_departure_date_value';
  $handler->display->display_options['sorts']['field_departure_date_value']['order'] = 'DESC';
  /* Contextual filter: Содержимое: Туристы (field_tourist) */
  $handler->display->display_options['arguments']['field_tourist_nid']['id'] = 'field_tourist_nid';
  $handler->display->display_options['arguments']['field_tourist_nid']['table'] = 'field_data_field_tourist';
  $handler->display->display_options['arguments']['field_tourist_nid']['field'] = 'field_tourist_nid';
  $handler->display->display_options['arguments']['field_tourist_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_tourist_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_tourist_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_tourist_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_tourist_nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contract' => 'contract',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'clients_contracts_pane');
  $handler->display->display_options['argument_input'] = array(
    'field_tourist_nid' => array(
      'type' => 'user',
      'context' => 'node_edit_form.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Туристы (field_tourist)',
    ),
  );
  $translatables['clients_contracts'] = array(
    t('Master'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Передан аргумент !1'),
    t('Дата вылета'),
    t('Все'),
    t('Content pane'),
    t('View panes'),
  );
  $export['clients_contracts'] = $view;

  $view = new view();
  $view->name = 'contracts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Договоры';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Договоры';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_contragent' => 'field_contragent',
    'title' => 'title',
    'created' => 'created',
    'field_date' => 'field_date',
    'field_departure_date' => 'field_departure_date',
    'field_duration' => 'field_duration',
    'field_tour_operator' => 'field_tour_operator',
    'field_country' => 'field_country',
    'field_client_price' => 'field_client_price',
    'field_price' => 'field_price',
    'expression' => 'expression',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'contextual_links' => 'contextual_links',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contragent' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_departure_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tour_operator' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_client_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'contextual_links' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Поле: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '№';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заказчик */
  $handler->display->display_options['fields']['field_contragent']['id'] = 'field_contragent';
  $handler->display->display_options['fields']['field_contragent']['table'] = 'field_data_field_contragent';
  $handler->display->display_options['fields']['field_contragent']['field'] = 'field_contragent';
  $handler->display->display_options['fields']['field_contragent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_contragent']['type'] = 'node_reference_plain';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Номер';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
[field_contragent]';
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата создания';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Поле: Содержимое: Дата составления договора */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Содержимое: Дата вылета */
  $handler->display->display_options['fields']['field_departure_date']['id'] = 'field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['table'] = 'field_data_field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['field'] = 'field_departure_date';
  $handler->display->display_options['fields']['field_departure_date']['label'] = 'Вылет';
  $handler->display->display_options['fields']['field_departure_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_departure_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_departure_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Содержимое: Продолжительность */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_duration']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Туроператор */
  $handler->display->display_options['fields']['field_tour_operator']['id'] = 'field_tour_operator';
  $handler->display->display_options['fields']['field_tour_operator']['table'] = 'field_data_field_tour_operator';
  $handler->display->display_options['fields']['field_tour_operator']['field'] = 'field_tour_operator';
  $handler->display->display_options['fields']['field_tour_operator']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Страна */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Поле: Содержимое: Сумма для клиентов */
  $handler->display->display_options['fields']['field_client_price']['id'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['table'] = 'field_data_field_client_price';
  $handler->display->display_options['fields']['field_client_price']['field'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['label'] = 'Брутто';
  $handler->display->display_options['fields']['field_client_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_client_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: Содержимое: Сумма к оплате */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['label'] = 'Нетто';
  $handler->display->display_options['fields']['field_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: profit */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['ui_name'] = 'profit';
  $handler->display->display_options['fields']['expression']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['suffix'] = '.00';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_client_price] - [field_price]';
  /* Поле: Содержимое: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '-';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Поле: Содержимое: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '-';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '[edit_node]
[delete_node]';
  /* Поле: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'counter' => 0,
    'field_contragent' => 0,
    'title' => 0,
    'created' => 0,
    'field_date' => 0,
    'field_departure_date' => 0,
    'field_duration' => 0,
    'field_tour_operator' => 0,
    'field_country' => 0,
    'field_client_price' => 0,
    'field_price' => 0,
    'expression' => 0,
  );
  $handler->display->display_options['fields']['contextual_links']['destination'] = '1';
  /* Sort criterion: Содержимое: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contract' => 'contract',
  );
  /* Filter criterion: Содержимое: Туроператор (field_tour_operator) */
  $handler->display->display_options['filters']['field_tour_operator_tid']['id'] = 'field_tour_operator_tid';
  $handler->display->display_options['filters']['field_tour_operator_tid']['table'] = 'field_data_field_tour_operator';
  $handler->display->display_options['filters']['field_tour_operator_tid']['field'] = 'field_tour_operator_tid';
  $handler->display->display_options['filters']['field_tour_operator_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tour_operator_tid']['expose']['operator_id'] = 'field_tour_operator_tid_op';
  $handler->display->display_options['filters']['field_tour_operator_tid']['expose']['label'] = 'Туроператор';
  $handler->display->display_options['filters']['field_tour_operator_tid']['expose']['operator'] = 'field_tour_operator_tid_op';
  $handler->display->display_options['filters']['field_tour_operator_tid']['expose']['identifier'] = 'field_tour_operator_tid';
  $handler->display->display_options['filters']['field_tour_operator_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_tour_operator_tid']['vocabulary'] = 'tour_operators';
  /* Filter criterion: Содержимое: Менеджер (field_manager) */
  $handler->display->display_options['filters']['field_manager_uid']['id'] = 'field_manager_uid';
  $handler->display->display_options['filters']['field_manager_uid']['table'] = 'field_data_field_manager';
  $handler->display->display_options['filters']['field_manager_uid']['field'] = 'field_manager_uid';
  $handler->display->display_options['filters']['field_manager_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_manager_uid']['expose']['operator_id'] = 'field_manager_uid_op';
  $handler->display->display_options['filters']['field_manager_uid']['expose']['label'] = 'Менеджер';
  $handler->display->display_options['filters']['field_manager_uid']['expose']['operator'] = 'field_manager_uid_op';
  $handler->display->display_options['filters']['field_manager_uid']['expose']['identifier'] = 'field_manager_uid';

  /* Display: Страница */
  $handler = $view->new_display('page', 'Страница', 'page_contracts');
  $handler->display->display_options['path'] = 'contracts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Договоры';
  $handler->display->display_options['menu']['weight'] = '-1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['contracts'] = array(
    t('Master'),
    t('Договоры'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('№'),
    t('Заказчик'),
    t('Номер'),
    t('[title]
[field_contragent]'),
    t('Дата создания'),
    t('Дата составления договора'),
    t('Вылет'),
    t('Продолжительность'),
    t('Туроператор'),
    t('Страна'),
    t('Брутто'),
    t('Нетто'),
    t('Прибыль'),
    t('.'),
    t('.00'),
    t('-'),
    t('[edit_node]
[delete_node]'),
    t('Менеджер'),
    t('Страница'),
  );
  $export['contracts'] = $view;

  $view = new view();
  $view->name = 'countries_analytics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Аналитика по странам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Аналитика по странам';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_country' => 'field_country',
    'field_client_price' => 'field_client_price',
    'field_price' => 'field_price',
    'nid' => 'nid',
    'expression' => 'expression',
    'expression_1' => 'expression_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_client_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression_1' => array(
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Содержимое: Страна */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Поле: SUM(Содержимое: Сумма для клиентов) */
  $handler->display->display_options['fields']['field_client_price']['id'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['table'] = 'field_data_field_client_price';
  $handler->display->display_options['fields']['field_client_price']['field'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_client_price']['label'] = 'Брутто';
  $handler->display->display_options['fields']['field_client_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Сумма к оплате) */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_price']['label'] = 'Нетто';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: COUNT(DISTINCT Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: SUM(Global: Math expression) */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['group_type'] = 'sum';
  $handler->display->display_options['fields']['expression']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_client_price] - [field_price]';
  /* Поле: SUM(Global: Math expression) */
  $handler->display->display_options['fields']['expression_1']['id'] = 'expression_1';
  $handler->display->display_options['fields']['expression_1']['table'] = 'views';
  $handler->display->display_options['fields']['expression_1']['field'] = 'expression';
  $handler->display->display_options['fields']['expression_1']['group_type'] = 'sum';
  $handler->display->display_options['fields']['expression_1']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression_1']['precision'] = '0';
  $handler->display->display_options['fields']['expression_1']['separator'] = '';
  $handler->display->display_options['fields']['expression_1']['expression'] = '([field_client_price] - [field_price]) / [nid]';
  /* Sort criterion: Содержимое: Страна (field_country) */
  $handler->display->display_options['sorts']['field_country_tid']['id'] = 'field_country_tid';
  $handler->display->display_options['sorts']['field_country_tid']['table'] = 'field_data_field_country';
  $handler->display->display_options['sorts']['field_country_tid']['field'] = 'field_country_tid';
  /* Filter criterion: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'contract' => 'contract',
  );
  /* Filter criterion: Содержимое: Дата составления договора (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Дата составления договора (field_date)';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-5:+0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'analytics/countries';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Аналитика по странам';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['countries_analytics'] = array(
    t('Master'),
    t('Аналитика по странам'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Страна'),
    t('Брутто'),
    t('Нетто'),
    t('Кол-во'),
    t('Прибыль'),
    t('.'),
    t('Math expression'),
    t('Дата составления договора (field_date)'),
    t('Page'),
  );
  $export['countries_analytics'] = $view;

  $view = new view();
  $view->name = 'touroperators';
  $view->description = 'Таблица туроператоров с данными';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Туроператоры';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Туроператоры';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit terms in 2';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Шапка: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<ul class="action-links">
<?php
if (user_access(\'edit terms in 2\')) {
  print \'<li>\' . l(\'Добавить туроператора\', \'admin/structure/taxonomy/tour_operators/add\') . \'</li>\';
}
?>
</ul>
';
  $handler->display->display_options['header']['area']['format'] = 'ds_code';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Поле: Поле: Телефон представительства в Москве */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Телефон';
  $handler->display->display_options['fields']['field_phone']['delta_offset'] = '0';
  /* Поле: Поле: Договор с туроператором */
  $handler->display->display_options['fields']['field_contract']['id'] = 'field_contract';
  $handler->display->display_options['fields']['field_contract']['table'] = 'field_data_field_contract';
  $handler->display->display_options['fields']['field_contract']['field'] = 'field_contract';
  $handler->display->display_options['fields']['field_contract']['label'] = 'Договор с ТО';
  $handler->display->display_options['fields']['field_contract']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contract']['delta_offset'] = '0';
  /* Поле: Термин таксономии: Полное наименование */
  $handler->display->display_options['fields']['field_fullname']['id'] = 'field_fullname';
  $handler->display->display_options['fields']['field_fullname']['table'] = 'field_data_field_fullname';
  $handler->display->display_options['fields']['field_fullname']['field'] = 'field_fullname';
  /* Поле: Термин таксономии: СТАРОЕ ПОЛЕ. НЕ МЕНЯТЬ ЗНАЧЕНИЯ. Номер договора страхования ответственности Туроператора */
  $handler->display->display_options['fields']['field_ins_contract_number']['id'] = 'field_ins_contract_number';
  $handler->display->display_options['fields']['field_ins_contract_number']['table'] = 'field_data_field_ins_contract_number';
  $handler->display->display_options['fields']['field_ins_contract_number']['field'] = 'field_ins_contract_number';
  $handler->display->display_options['fields']['field_ins_contract_number']['label'] = 'Номер договора страхования ответственности Туроператора';
  /* Поле: Термин таксономии: Реестровый номер */
  $handler->display->display_options['fields']['field_registration_number']['id'] = 'field_registration_number';
  $handler->display->display_options['fields']['field_registration_number']['table'] = 'field_data_field_registration_number';
  $handler->display->display_options['fields']['field_registration_number']['field'] = 'field_registration_number';
  /* Поле: Термин таксономии: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['label'] = 'Ред.';
  /* Filter criterion: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tour_operators' => 'tour_operators',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'touroperators';
  $translatables['touroperators'] = array(
    t('Master'),
    t('Туроператоры'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<ul class="action-links">
<?php
if (user_access(\'edit terms in 2\')) {
  print \'<li>\' . l(\'Добавить туроператора\', \'admin/structure/taxonomy/tour_operators/add\') . \'</li>\';
}
?>
</ul>
'),
    t('Имя'),
    t('Телефон'),
    t('Договор с ТО'),
    t('Полное наименование'),
    t('Номер договора страхования ответственности Туроператора'),
    t('Реестровый номер'),
    t('Ред.'),
    t('Page'),
  );
  $export['touroperators'] = $view;

  $view = new view();
  $view->name = 'touroperators_analytics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Аналитика по туроператорам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_client_price' => 'field_client_price',
    'field_price' => 'field_price',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_client_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'ggg';
  /* Relationship: Термин таксономии: Содержимое using Туроператор */
  $handler->display->display_options['relationships']['reverse_field_tour_operator_node']['id'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['relationships']['reverse_field_tour_operator_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_tour_operator_node']['field'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['relationships']['reverse_field_tour_operator_node']['label'] = 'Договор';
  /* Поле: Термин таксономии: Имя */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Поле: SUM(Содержимое: Сумма для клиентов) */
  $handler->display->display_options['fields']['field_client_price']['id'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['table'] = 'field_data_field_client_price';
  $handler->display->display_options['fields']['field_client_price']['field'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['fields']['field_client_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_client_price']['label'] = 'Брутто';
  $handler->display->display_options['fields']['field_client_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_client_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Сумма к оплате) */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['fields']['field_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_price']['label'] = 'Нетто';
  $handler->display->display_options['fields']['field_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Global: Math expression) */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['group_type'] = 'sum';
  $handler->display->display_options['fields']['expression']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_client_price] - [field_price]';
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Кол-во';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Contextual filter: Содержимое: Менеджер (field_manager) */
  $handler->display->display_options['arguments']['field_manager_uid']['id'] = 'field_manager_uid';
  $handler->display->display_options['arguments']['field_manager_uid']['table'] = 'field_data_field_manager';
  $handler->display->display_options['arguments']['field_manager_uid']['field'] = 'field_manager_uid';
  $handler->display->display_options['arguments']['field_manager_uid']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['arguments']['field_manager_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_manager_uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_manager_uid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_manager_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_manager_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_manager_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tour_operators' => 'tour_operators',
  );

  /* Display: Страница */
  $handler = $view->new_display('page', 'Страница', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_client_price' => 'field_client_price',
    'field_price' => 'field_price',
    'expression' => 'expression',
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_client_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'expression' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['summary'] = 'ggg';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tour_operators' => 'tour_operators',
  );
  /* Filter criterion: Содержимое: Дата составления договора (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['filters']['field_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_value']['expose']['operator_id'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['label'] = 'Дата составления договора (field_date)';
  $handler->display->display_options['filters']['field_date_value']['expose']['operator'] = 'field_date_value_op';
  $handler->display->display_options['filters']['field_date_value']['expose']['identifier'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-3:+0';
  $handler->display->display_options['path'] = 'ta';

  /* Display: Вложение */
  $handler = $view->new_display('attachment', 'Вложение', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: SUM(Global: Custom text) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['group_type'] = 'sum';
  $handler->display->display_options['fields']['nothing']['label'] = 'Итого';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Итого';
  /* Поле: SUM(Содержимое: Сумма для клиентов) */
  $handler->display->display_options['fields']['field_client_price']['id'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['table'] = 'field_data_field_client_price';
  $handler->display->display_options['fields']['field_client_price']['field'] = 'field_client_price';
  $handler->display->display_options['fields']['field_client_price']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['fields']['field_client_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_client_price']['label'] = 'Брутто';
  $handler->display->display_options['fields']['field_client_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_client_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Содержимое: Сумма к оплате) */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['fields']['field_price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['field_price']['label'] = 'Нетто';
  $handler->display->display_options['fields']['field_price']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Поле: SUM(Global: Math expression) */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['group_type'] = 'sum';
  $handler->display->display_options['fields']['expression']['label'] = 'Прибыль';
  $handler->display->display_options['fields']['expression']['precision'] = '0';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_client_price] - [field_price]';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Вложение 2 */
  $handler = $view->new_display('attachment', 'Вложение 2', 'attachment_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Содержимое: Менеджер (field_manager) */
  $handler->display->display_options['arguments']['field_manager_uid']['id'] = 'field_manager_uid';
  $handler->display->display_options['arguments']['field_manager_uid']['table'] = 'field_data_field_manager';
  $handler->display->display_options['arguments']['field_manager_uid']['field'] = 'field_manager_uid';
  $handler->display->display_options['arguments']['field_manager_uid']['relationship'] = 'reverse_field_tour_operator_node';
  $handler->display->display_options['arguments']['field_manager_uid']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_manager_uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_manager_uid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_manager_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_manager_uid']['summary']['format'] = 'jump_menu_summary';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['inherit_arguments'] = FALSE;
  $translatables['touroperators_analytics'] = array(
    t('Master'),
    t('more'),
    t('Применить'),
    t('Сбросить'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Договор'),
    t('Брутто'),
    t('Нетто'),
    t('Прибыль'),
    t('.'),
    t('Кол-во'),
    t('Все'),
    t('Страница'),
    t('Дата составления договора (field_date)'),
    t('Вложение'),
    t('Итого'),
    t('Вложение 2'),
  );
  $export['touroperators_analytics'] = $view;

  return $export;
}
