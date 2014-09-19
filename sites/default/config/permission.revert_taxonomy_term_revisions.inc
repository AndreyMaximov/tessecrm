<?php
/**
 * @file
 * permission.revert_taxonomy_term_revisions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'revert taxonomy term revisions',
  'roles' => array(
    0 => 'Старший менеджер',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy_revision',
);
