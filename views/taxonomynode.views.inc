<?php
// $Id$

/**
 * Implementation of hook_views_data().
 */
function taxonomynode_views_data() {
  $data = array();

   // Definitions for uc_product_adjustments
  $data['taxonomynode']['table']['group'] = t('Taxonomy Node');

  $data['taxonomynode']['table']['join']['node'] = array(
      'left_field' => 'nid',
      'field' => 'nid',
  );

  $data['taxonomynode']['tid'] = array(
    'title' => 'Term ID',
    'help' => t('Term ID of the mapping term of each node.'),
    'relationship' => array(
      'base' => 'term_data',
      'field' => 'tid',
      'handler' => 'views_handler_relationship',
      'label' => t('Taxonomy Node Term'),
    ),
  );

  return $data;
}