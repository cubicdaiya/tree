#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <bst.h>
#include <mpool.h>

static void bst_test001(void);
static void bst_test002(void);
static void bst_test003(void);
static void bst_test004(void);
static void bst_test005(void);


static void bst_test001(void) {
  mpool_t *pool    = mpool_create(1024);
  bst_node_t *root = bst_create(0, &pool);
  CU_ASSERT(root->elem == 0);
  bst_destroy(pool);
}

static void bst_test002(void) {
  mpool_t *pool    = mpool_create(1024);
  bst_node_t *root = bst_create(0, &pool);
  CU_ASSERT(root->elem == 0);
  for (int i=0;i<10;++i) {
    bst_insert(root, i + 1, &pool);
  }
  for (int i=0;i<11;++i) {
    CU_ASSERT(bst_search(root, i));
  }
  bst_destroy(pool);
}

static void bst_test003(void) {

}

static void bst_test004(void) {

}

static void bst_test005(void) {

}

int main (int argc, char *argv[]) {
  CU_pSuite suite_bstree;
  CU_initialize_registry();
  suite_bstree = CU_add_suite("bstree", NULL, NULL);
  CU_add_test(suite_bstree, "bstree_test001", bst_test001);
  CU_add_test(suite_bstree, "bstree_test002", bst_test002);
  CU_add_test(suite_bstree, "bstree_test003", bst_test003);
  CU_add_test(suite_bstree, "bstree_test004", bst_test004);
  CU_add_test(suite_bstree, "bstree_test005", bst_test005);
  CU_basic_run_tests();
  CU_cleanup_registry();
  
  return 0;
}
