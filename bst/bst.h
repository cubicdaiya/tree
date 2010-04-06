#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <mpool.h>

#define BST_MALLOC(p, siz)			\
  do {                                          \
    if (((p) = malloc(siz)) == NULL) {          \
      fprintf(stderr, "malloc failed");         \
      exit(-1);                                 \
    }                                           \
  } while(false)

#define BST_FREE(p)				\
  do {                                          \
    free(p);                                    \
    (p) = NULL;                                 \
  } while(false)

typedef int bst_elem_t;

typedef struct bst_node_s {
  struct bst_node_s *left;
  struct bst_node_s *right;
  bst_elem_t elem;
} bst_node_t;

bst_node_t *bst_create(bst_elem_t elem, mpool_t **pool);
bool bst_insert(bst_node_t *node, bst_elem_t elem, mpool_t **pool);
bool bst_search(bst_node_t *node, bst_elem_t elem);
void bst_destroy(mpool_t *pool);



#endif // BST_H
