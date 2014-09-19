<?php
/**
 * @file
 * permission.delete_taxonomy_term_revisions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'delete taxonomy term revisions',
  'roles' => array(),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy_revision',
);
