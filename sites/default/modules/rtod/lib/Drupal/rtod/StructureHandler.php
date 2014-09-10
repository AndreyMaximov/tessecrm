<?php
/**
 * Base abstract class for structure handling.
 */

namespace Drupal\rtod;

/**
 * Class StructureHandler
 * @package Drupal\rtod
 */
abstract class StructureHandler {
  const handlerStructureURI = '';

  public $datasetURI;
  public $structureURI;
  protected $dataset = array();
  protected $originData = array();

  function __construct($datasetURI, $structureURI = '') {
    $this->datasetURI = $datasetURI;
    $this->structureURI = $structureURI;
    $this->originData = file_get_contents($this->datasetURI);

    if ($this->matchAgainstSchema()) {
      $this->parseDataset();
    }
    else {
      throw new \Exception('File ' . $datasetURI . ' does not match schema');
    }
  }

  /**
   * Simply extract incoming data for TO by his INN.
   *
   * @param \string $inn
   *
   * @return mixed
   *   Returns data if exists otherwise FALSE.
   */
  public function lookupByINN($inn) {
    return isset($this->dataset[$inn]) ? $this->dataset[$inn] : FALSE;
  }

  /**
   * Compares local and incoming data for specific tour operator and return
   * difference.
   *
   * @param \stdClass $local
   * @param \stdClass $incoming
   *
   * @return \stdClass
   *   Diff object, each property - old and new value of TO attribute.
   */
  public function compare(\stdClass $local, \stdClass $incoming) {
    $diff = new \stdClass();

    // TODO: compare moscow phones
    $fields = array(
      'field_fullname' => 'fullname',
      'field_shortname' => 'shortname',
      'field_fact_address' => 'fact_address',
      'field_registration_number' => 'registry_number',
      'field_site' => 'site',
    );

    foreach ($fields as $field_name => $prop_name) {
      $tmp = '';
      if (!empty($local->{$field_name}[LANGUAGE_NONE][0]['value'])) {
        $tmp = $local->{$field_name}[LANGUAGE_NONE][0]['value'];
      }
      if ($this->_sanitate($tmp) !== $incoming->{$prop_name}) {
        $diff->{$prop_name} = array(
          'old' => $tmp,
          'new' => $incoming->{$prop_name},
        );
      }
    }

    // First load existing local fin supplies.
    $local_fin_supplies = array();
    if ($items = field_get_items('taxonomy_term', $local, 'field_financial_supply')) {
      foreach ($items as $delta => $item) {
        $fc_item = field_collection_item_load($item['value']);
        $local_fin_supplies[] = $this->_finSupplyItemToInternal($fc_item, $delta);
      }
    }

    // Now we sort both arrays or financial supplies objects by sign date and
    // organization name and loop thru so we can match and merge arrays.
    // Merged array is a new state, that will be stored in DB.
    // Diff between current state and merged array will be logged.
    $diff->finsupplies = $this->_mergeFinSupplies($local_fin_supplies, $incoming->finsupplies);

    return $diff;
  }

  /**
   * Updates local taxonomy term.
   *
   * @param \stdClass $local
   * @param \stdClass $incoming
   */
  public function update(\stdClass &$local, \stdClass $incoming) {
    if ($diff = $this->compare($local, $incoming)) {
      $this->updateBase($local, $diff);
      $this->logBaseUpdates($diff);
      $this->updateFinsupply($local, $diff);
      $this->logFinsupplyUpdates($diff);

      taxonomy_term_save($local);
    }
  }

  /**
   * Updated local TO (taxonomy term) object, not writing it to DB.
   *
   * @param \stdClass $local
   * @param \stdClass $incoming
   */
  public function updateBase(\stdClass &$local, \stdClass $diff) {
    if (isset($diff->fullname)) {
      $local->field_fullname[LANGUAGE_NONE] = array(
        0 => array('value' => $diff->fullname['new']),
      );
    }
    if (isset($diff->shortname)) {
      $local->field_shortname[LANGUAGE_NONE] = array(
        0 => array('value' => $diff->shortname['new']),
      );
    }
    if (isset($diff->fact_address)) {
      $local->field_fact_address[LANGUAGE_NONE] = array(
        0 => array('value' => $diff->fact_address['new']),
      );
    }
    if (isset($diff->registry_number)) {
      $local->field_registration_number[LANGUAGE_NONE] = array(
        0 => array('value' => $diff->registry_number['new']),
      );
    }
    if (isset($diff->site)) {
      $local->field_site[LANGUAGE_NONE] = array(
        0 => array('value' => $diff->site['new']),
      );
    }

    // TODO: moscow phones

    return $diff;
  }

  public function updateFinsupply (\stdClass &$local, \stdClass $diff) {
    // Copy old data to temp variable
    $old_finsupply = array();
    if (!empty($local->field_financial_supply[LANGUAGE_NONE])) {
      $old_finsupply = $local->field_financial_supply[LANGUAGE_NONE];
    };

    // Clear object's field array.
    $local->field_financial_supply[LANGUAGE_NONE] = array();

    foreach ($diff->finsupplies as $_item) {
      if (isset($_item->delta)) {
        $local->field_financial_supply[LANGUAGE_NONE][] = $old_finsupply[$_item->delta];
      }
      else {
        $new = entity_create('field_collection_item', array('field_name' => 'field_financial_supply'));
        $new->setHostEntity('taxonomy_term', $local);
        $new->archived = 0;
        $new->field_fs_doc_number[LANGUAGE_NONE][0]['value'] = $_item->doc_number;
        $new->field_fs_type[LANGUAGE_NONE][0]['value'] = $_item->type;
        $new->field_fs_size[LANGUAGE_NONE][0]['value'] = $_item->size;
        $new->field_fs_date_signed[LANGUAGE_NONE][0]['value'] = $_item->date_signed . 'T00:00:00';
        $new->field_fs_period[LANGUAGE_NONE][0]['value'] = $_item->date_from . 'T00:00:00';
        $new->field_fs_period[LANGUAGE_NONE][0]['value2'] = $_item->date_to . 'T00:00:00';
        $new->field_fs_org_name[LANGUAGE_NONE][0]['value'] = $_item->org_name;
        $new->field_fs_org_fact_addr[LANGUAGE_NONE][0]['value'] = $_item->org_fact_address;
        $new->field_fs_org_post_addr[LANGUAGE_NONE][0]['value'] = $_item->org_post_address;
        $new->save(TRUE);
      }
    }

    return $diff;
  }

  public function logBaseUpdates (\stdClass $updates) {
    // TODO: impement logBaseUpdates
  }

  public function logFinsupplyUpdates (\stdClass $updates) {
    // TODO: impement logFinsupplyUpdates
  }

  abstract public function matchAgainstSchema();
  abstract public function parseDataset();

  protected function _sanitate($s) {
    $s = trim($s);
    $s = str_replace('  ', ' ', $s);
    return $s;
  }

  /**
   * Format local field collection item linked to entity for easier to compare.
   * We store delta and id to be able to referer Drupal entities such field
   * collection item and field item as we sometimes want to shuffle origin
   * order of items.
   *
   * @param $item
   * @param $delta
   *
   * @return \stdClass
   */
  protected function _finSupplyItemToInternal($item, $delta) {
    $formatted = new \stdClass();
    $formatted->delta = $delta;
    $formatted->doc_number = '';
    $formatted->type = '';
    $formatted->size = 0;
    $formatted->date_signed = '';
    $formatted->date_from = '';
    $formatted->date_to = '';
    $formatted->org_name = '';
    $formatted->org_fact_address = '';
    $formatted->org_post_address = '';

    if (!empty($item->field_fs_doc_number[LANGUAGE_NONE][0]['value'])) {
      $formatted->doc_number = $item->field_fs_doc_number[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($item->field_fs_type[LANGUAGE_NONE][0]['value'])) {
      $formatted->type = $item->field_fs_type[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($item->field_fs_size[LANGUAGE_NONE][0]['value'])) {
      $formatted->size = intval($item->field_fs_size[LANGUAGE_NONE][0]['value']);
    }
    if (!empty($item->field_fs_date_signed[LANGUAGE_NONE][0]['value'])) {
      // Ignoring timezone
      $_date = strtotime($item->field_fs_date_signed[LANGUAGE_NONE][0]['value']);
      $formatted->date_signed = date('Y-m-d', $_date);
    }
    if (!empty($item->field_fs_period[LANGUAGE_NONE][0]['value'])) {
      // Ignoring timezone
      $_from = strtotime($item->field_fs_period[LANGUAGE_NONE][0]['value']);
      $formatted->date_from = date('Y-m-d', $_from);
      $_to = strtotime($item->field_fs_period[LANGUAGE_NONE][0]['value2']);
      $formatted->date_to = date('Y-m-d', $_to);
    }
    if (!empty($item->field_fs_org_name[LANGUAGE_NONE][0]['value'])) {
      $formatted->org_name = $item->field_fs_org_name[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($item->field_fs_org_fact_addr[LANGUAGE_NONE][0]['value'])) {
      $formatted->org_fact_address = $item->field_fs_org_fact_addr[LANGUAGE_NONE][0]['value'];
    }
    if (!empty($item->field_fs_org_post_addr[LANGUAGE_NONE][0]['value'])) {
      $formatted->org_post_address = $item->field_fs_org_post_addr[LANGUAGE_NONE][0]['value'];
    }

    return $formatted;
  }

  /**
   * Build financial supply document composite key.
   *
   * @param $fs
   *
   * @return string
   */
  protected function _finSupplyCompositeKey($fs) {
    return $fs->date_signed . $fs->org_name . $fs->doc_number;
  }

  /**
   * Produces merged fin supply array of formatted objects that would be stored
   * in db.
   *
   * @param $local
   * @param $incoming
   *
   * @return array
   */
  function _mergeFinSupplies(array $local, array $incoming) {
    $copy_local = array();
    foreach ($local as $item) {
      $copy_local[$this->_finSupplyCompositeKey($item)] = $item;
    }

    $copy_incoming = array();
    foreach ($incoming as $item) {
      $copy_incoming[$this->_finSupplyCompositeKey($item)] = $item;
    }

    $merged = array_merge($copy_incoming, $copy_local);
    ksort($merged);

    return $merged;
  }

}