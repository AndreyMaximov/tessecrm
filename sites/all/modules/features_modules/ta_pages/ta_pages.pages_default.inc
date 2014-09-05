<?php
/**
 * @file
 * ta_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ta_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_http_response';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'tourist_redirect_to_editpage',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'node/%node:nid/edit',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'tourist' => 'tourist',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Passport is fullfilled',
            'php' => '$o = $contexts[\'argument_entity_id:node_1\']->data;
return
empty($o->field_passport_serie) ||
empty($o->field_passport_number) ||
empty($o->field_passport_emitter) ||
empty($o->field_passport_date);',
          ),
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Referer page',
            'php' => 'return $_SERVER[\'HTTP_REFERER\'] != url(\'node/\' . arg(1) . \'/edit\', array(\'absolute\' => TRUE));',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view_http_response'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ta_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'create_contract_from_tourist_page';
  $page->task = 'page';
  $page->admin_title = 'Создание договора со страницы туриста';
  $page->admin_description = '';
  $page->path = 'node/%node/create_contract';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'tourist' => 'tourist',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'action',
    'title' => 'Создать новый договор',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_create_contract_from_tourist_page_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'create_contract_from_tourist_page';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Context Admin',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'tourist' => 'tourist',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'context_admin_options' => 'noderef_create_node',
    'context_admin_options_items' => 'contract',
    'context_admin_content_types' => array(
      'contract' => 'field_contragent',
    ),
    'context_admin_field' => 'field_contragent',
    'context_admin_autoforward' => 0,
    'context_admin_custom_redirect' => '',
    'submitted_context' => 'argument_entity_id:node_1',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['create_contract_from_tourist_page'] = $page;

  return $pages;

}
