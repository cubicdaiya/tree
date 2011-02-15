/*
  In short, tree is distributed under so called "BSD license",
  
  Copyright (c) 2010 Tatsuhiko Kubo <cubicdaiya@gmail.com>
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:
  
  * Redistributions of source code must retain the above copyright notice, 
  this list of conditions and the following disclaimer.
  
  * Redistributions in binary form must reproduce the above copyright notice, 
  this list of conditions and the following disclaimer in the documentation 
  and/or other materials provided with the distribution.
  
  * Neither the name of the authors nor the names of its contributors 
  may be used to endorse or promote products derived from this software 
  without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* written by C99 style */

#include "bst.h"
#include <mpool.h>

static bst_node_t *bst_node_create(bst_elem_t elem, mpool_t **pool);

static bst_node_t *bst_node_create(bst_elem_t elem, mpool_t **pool) {
    bst_node_t *root;
    root = mpool_alloc(sizeof(*root), *pool);
    root->left  = NULL;
    root->right = NULL;
    root->elem  = elem;
    return root;
}

bst_node_t *bst_create(bst_elem_t elem, mpool_t **pool) {
    bst_node_t *root;
    root  = bst_node_create(elem, pool);
    return root;
}

bool bst_insert(bst_node_t *root, bst_elem_t elem, mpool_t **pool) {
    bst_node_t **branch;
    
    if (elem < root->elem) {
        branch = &root->left;
    } else if (elem > root->elem) {
        branch = &root->right;
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

bool bst_search(bst_node_t *root, bst_elem_t elem) {
    bst_node_t *branch;
    
    if (elem < root->elem) {
        branch = root->left;
    } else if (elem > root->elem) {
        branch = root->right;
    } else {
        return true;
    }
    
    if (branch == NULL) {
        return false;
    } else {
        return bst_search(branch, elem);
    }
}

bool bst_delete(bst_node_t *root, bst_elem_t elem, mpool_t **pool) {
    return true;
}

void bst_destroy(mpool_t *pool) {
    mpool_destroy(pool);
}



