<?php

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

  $data['taxonomynode']['table']['join']['term_data'] = array(
      'left_field' => 'tid',
      'field' => 'tid',
  );

  $data['taxonomynode']['table']['join']['vocabulary'] = array(
      'left_field' => 'vid',
      'field' => 'vid',
  );

  $data['taxonomynode']['tid'] = array(
      'title' => 'Term ID',
      'help' => t('Term ID of the mapping term of each node.'),
      'relationship' => array(
          'base' => 'term_data',
          'field' => 'tid',
          'handler' => 'views_handler_relationship',
          'label' => t('Taxonomy Node - Term'),
      ),
  );

  $data['taxonomynode']['vid'] = array(
      'title' => 'Vocabulary ID',
      'help' => t('Vocabulary ID of the mapping term of each node.'),
      'relationship' => array(
          'base' => 'vocabulary',
          'field' => 'vid',
          'handler' => 'views_handler_relationship',
          'label' => t('Taxonomy Node - Vocabulary'),
      ),
  );

  $data['taxonomynode']['nid'] = array(
      'title' => 'Node ID',
      'help' => t('Node ID of the mapping term of each node.'),
      'relationship' => array(
          'base' => 'node',
          'field' => 'nid',
          'handler' => 'views_handler_relationship',
          'label' => t('Taxonomy Node - Node'),
      ),
  );

  return $data;
}