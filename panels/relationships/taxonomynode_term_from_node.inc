<?php

/**
 * @file
 * Provides a CTools (Panels) relationship that gets a term context from the
 * node context based on terms used by Taxonomy Node.
 */

/**
 * Implementation of specially named hook_ctools_relationships().
 */
function taxonomynode_taxonomynode_term_from_node_ctools_relationships() {
  $args['taxonomynode_term_from_node'] = array(
    'title' => t("Term from node (Taxonomy Node)"),
    'keyword' => 'taxonomynode_term',
    'description' => t('Adds a Taxonomy Node term from node context'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'context' => 'taxonomynode_taxonomynode_term_from_node_ctools_context',
    //'settings form' => 'taxonomynode_taxonomynode_term_from_node_ctools_settings_form', // Not needed
    //'settings form validate' => 'taxonomynode_taxonomynode_term_from_node_ctools_settings_form_validate', // Not needed
  );
  
  return $args;
}

/**
 * Return a new context based on an existing context.
 */
function taxonomynode_taxonomynode_term_from_node_ctools_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL
  if (empty($context->data) || !isset($context->data->uid)) {
    $new_context = ctools_context_create_empty('term', NULL);
  }
  else {
    // Load the node for the requested type
    $nid = $context->data->nid;
    $taxonomynode_term = taxonomy_get_term(_taxonomynode_get_tid_from_nid($nid));

    // Send it to ctools.
    $new_context = ctools_context_create('term', $taxonomynode_term);
  }

  return $new_context;
}
