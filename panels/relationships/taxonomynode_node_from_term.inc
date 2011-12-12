<?php

/**
 * @file
 * Provides a CTools (Panels) relationship that gets a node context from the
 * term context based on nodes from Taxonomy Node.
 */

/**
 * Implementation of specially named hook_ctools_relationships().
 */
function taxonomynode_taxonomynode_node_from_term_ctools_relationships() {
  $args['taxonomynode_node_from_term'] = array(
    'title' => t("Node from term (Taxonomy Node)"),
    'keyword' => 'taxonomynode_node',
    'description' => t('Adds a Taxonomy Node node from term context'),
    'required context' => new ctools_context_required(t('Term'), 'term'),
    'context' => 'taxonomynode_taxonomynode_node_from_term_ctools_context',
    //'settings form' => 'taxonomynode_taxonomynode_node_from_term_ctools_settings_form', // Not needed
    //'settings form validate' => 'taxonomynode_taxonomynode_node_from_term_ctools_settings_form_validate', // Not needed
  );
  
  return $args;
}

/**
 * Return a new context based on an existing context.
 */
function taxonomynode_taxonomynode_node_from_term_ctools_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL
  if (empty($context->data)) {
    $new_context = ctools_context_create_empty('node', NULL);
  }
  else {
    // Load the node for the requested type
    $tid = $context->data->tid;
    $taxonomynode_node = node_load(_taxonomynode_get_nid_from_tid($tid));

    // Send it to ctools.
    $new_context = ctools_context_create('node', $taxonomynode_node);
  }

  return $new_context;
}
