
#include "bst.h"
#include <mpool.h>

static bst_node_t *bst_node_create(bst_elem_t elem, mpool_t **pool);

static bst_node_t *bst_node_create(bst_elem_t elem, mpool_t **pool) {
  bst_node_t *node;
  node = mpool_alloc(pool, sizeof(*node));
  node->left  = NULL;
  node->right = NULL;
  node->elem  = elem;
  return node;
}

bst_node_t *bst_create(bst_elem_t elem, mpool_t **pool) {
  bst_node_t *root;
  root  = bst_node_create(elem, pool);
  return root;
}

bool bst_insert(bst_node_t *node, bst_elem_t elem, mpool_t **pool) {
  bst_node_t **branch;

  if (elem < node->elem) {
    branch = &node->left;
  } else if (elem > node->elem) {
    branch = &node->right;
  } else {
    return false;
  }

  if (*branch == NULL) {
    *branch = bst_node_create(elem, pool);
    return true;
  } else {
    return bst_insert(*branch, elem, pool);
  }
}

bool bst_search(bst_node_t *node, bst_elem_t elem) {
  bst_node_t *branch;

  if (elem < node->elem) {
    branch = node->left;
  } else if (elem > node->elem) {
    branch = node->right;
  } else {
    return true;
  }

  if (branch == NULL) {
    return false;
  } else {
    return bst_search(branch, elem);
  }
}

void bst_destroy(mpool_t *pool) {
  mpool_destroy(pool);
}



