<?php
/**
 * Specific structure handler for structure
 * http://opendata.russiatourism.ru/7708550300-ReestrRosturizm77B/structure-20140904.json
 */

namespace Drupal\rtod\structure;

use Drupal\rtod\StructureHandler;

class StructureHandler20140904 extends StructureHandler {
  public function matchAgainstSchema() {
    return TRUE;
  }

  public function parseDataset() {
    $_data = json_decode($this->originData);
    $this->dataset = array();

    foreach ($_data as $_item) {
      $item = new \stdClass();
      $item->registry_number = $this->_sanitate($_item->E1);
      $item->fullname = $this->_sanitate($_item->E2);
      $item->shortname = $this->_sanitate($_item->E3);
      $item->fact_address = $this->_sanitate($_item->E4);
      $item->post_address = $this->_sanitate($_item->E5);
      $item->site = $this->_sanitate($_item->E6);
      $item->inn = $this->_sanitate($_item->E7);
      // TODO: other attributes

      // Financial supply for current period
      $item->finsupplies = array();
      foreach ($_item->E12[0]->E12C as $_fs_item) {
        $finsupply = new \stdClass();
        $finsupply->doc_number = $_fs_item->E12C3;
        $finsupply->type = $_fs_item->E12C2;
        $finsupply->size = intval($_fs_item->E12C1);
        $finsupply->date_signed = $_fs_item->E12C4;
        $finsupply->date_from = $_fs_item->E12C5;
        $finsupply->date_to = $_fs_item->E12C6;
        $finsupply->org_name = $_fs_item->E12C7;
        $finsupply->org_fact_address = $_fs_item->E12C8;
        $finsupply->org_post_address = $_fs_item->E12C9;
        $item->finsupplies[] = $finsupply;
      }

      if (empty($item->finsupplies)) {
        continue;
        // throw new \Exception('Empty Financial supplies for ' . $item->fullname . ' in dataset ' . $this->datasetURI);
      }
      if (empty($item->inn)) {
        continue;
        // throw new \Exception('Empty INN for ' . $item->fullname . ' in dataset ' . $this->datasetURI);
      }
      if (isset($this->dataset[$item->inn])) {
        throw new \Exception('Duplicated INN: ' . $item->inn . ' in dataset ' . $this->datasetURI);
      }

      $this->dataset[$item->inn] = $item;
    }
  }
}
