<?php
/**
 * @file
 * permission.view_taxonomy_term_revisions.inc
 */

$api = '2.0.0';

$data = array(
  'permission' => 'view taxonomy term revisions',
  'roles' => array(
    0 => 'authenticated user',
  ),
);

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'taxonomy_revision',
);
