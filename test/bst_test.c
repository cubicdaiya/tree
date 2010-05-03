#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <bst.h>
#include <mpool.h>

static void bst_test001(void);
static void bst_test002(void);
static void bst_test003(void);

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
    mpool_t *pool    = mpool_create(1024);
    bst_node_t *root = bst_create(0, &pool);
    CU_ASSERT(root->elem == 0);
    bst_insert(root, 3,  &pool);
    bst_insert(root, 8,  &pool);
    bst_insert(root, 4,  &pool);
    bst_insert(root, 5,  &pool);
    bst_insert(root, 9,  &pool);
    bst_insert(root, 7,  &pool);
    bst_insert(root, 1,  &pool);
    bst_insert(root, 2,  &pool);
    bst_insert(root, 6,  &pool);
    bst_insert(root, 10, &pool);
    
    for (int i=0;i<11;++i) {
        CU_ASSERT(bst_search(root, i));
    }
    bst_destroy(pool);
}

int main (int argc, char *argv[]) {
    CU_pSuite suite_bstree;
    CU_initialize_registry();
    suite_bstree = CU_add_suite("bstree", NULL, NULL);
    CU_add_test(suite_bstree, "bstree_test001", bst_test001);
    CU_add_test(suite_bstree, "bstree_test002", bst_test002);
    CU_add_test(suite_bstree, "bstree_test003", bst_test003);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
