<?php
/**
 * Created by PhpStorm.
 * User: savage
 * Date: 08.09.14
 * Time: 15:25
 */

namespace Drupal\rtod;

class PassportParser {

  public $passportURI;
  public $datasetURI;
  public $structure;
  public $timestamp;
  public $structureHandler;

  function __construct($passportURI = 'http://opendata.russiatourism.ru/7708550300-ReestrRosturizm77B') {
    $this->passportURI = $passportURI;

    // Load easyrdf
    if ($path = libraries_get_path('easyrdf')) {
      require_once($path . '/lib/EasyRdf.php');
    }
    else {
      throw new \Exception('easyrdf library not found');
    }

    $this->extractSetInfo();
    if ($structureHandler = $this->lookupStructureHandler()) {
      $structureHandler = __NAMESPACE__ . '\\structure\\' . $structureHandler;
      $this->structureHandler = new $structureHandler($this->datasetURI);
    }
    else {
      throw new \Exception('No structure handler found');
    }
  }

  /**
   * Loop through all touroperators taxonomy term and actualize them.
   */
  public function actualizeAll() {
    $efq = new \EntityFieldQuery();
    $efq->entityCondition('entity_type', 'taxonomy_term');
    $efq->entityCondition('bundle', 'tour_operators');
    $results = $efq->execute();

    foreach (array_keys($results['taxonomy_term']) as $tid) {
      $this->actualize($tid);
    }
  }

  /**
   * Updates touroperato taxonomy term with data from dataset.
   *
   * @param int $tid
   *
   * @return bool
   */
  public function actualize($tid) {
    $local = taxonomy_term_load($tid);

    if (!empty($local->field_inn[LANGUAGE_NONE][0]['value'])) {
      $inn = $local->field_inn[LANGUAGE_NONE][0]['value'];
      if ($incoming = $this->structureHandler->lookupByINN($inn)) {
        $this->structureHandler->update($local, $incoming);
        return TRUE;
      }
      else {
        return FALSE;
      }
    }
    else {
      return FALSE;
    }

  }

  /**
   * @return array(string $datasetURI, string $structure, int $timestamp)
   */
  private function extractSetInfo () {
    \EasyRdf_Namespace::set('dc', 'http://purl.org/dc/terms/');

    $graph = \EasyRdf_Graph::newAndLoad($this->passportURI);
    if ($graph) {
      $passport = $graph->resource();

      // Dataset revisions
      $parts = $passport
        ->get('dc:source')
        ->all('dc:hasPart');

      // Select actual revision
      $max_date = '';
      foreach ($parts as $part) {
        $data_create = $part->get('dc:created')->__toString();
        if ($data_create > $max_date) {
          $actual_part = $part;
          $max_date = $data_create;
        }
      }

      // Uncomment when rosturizm fix passport rdfa
      // $structure = $actual_part->get('dc:conformsTo');
      // if ($_s = $structure->get('dc:source')) {
      //   $structure = $_s->__toString();
      // };

      $this->datasetURI = $actual_part->get('dc:source')->__toString();
      $this->structure = $actual_part->get('dc:conformsTo')->__toString();
      $this->timestamp = strtotime($actual_part->get('dc:created')->__toString());
    }
  }

  /**
   *
   * @param string $structure
   *
   * @return string $className
   */
  private function lookupStructureHandler ($structure = '') {
    if (!$structure) {
      $structure = $this->structure;
    }

    $handlers = module_invoke_all('rtod_structure_handlers');

    foreach ($handlers as $handler_data) {
      if (is_array($handler_data['handledStructures'])) {
        foreach ($handler_data['handledStructures'] as $structureName) {
          if ($structureName == $structure) {
            return $handler_data['className'];
          }
        }
      }
      else {
        if ($handler_data['handledStructures'] == $structure) {
          return $handler_data['className'];
        }
      }
    }

    return FALSE;
  }
}
