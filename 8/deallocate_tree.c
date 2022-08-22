#include <stdio.h>
#include <stdlib.h>
#include "deallocate_tree.h"

int deallocate_tree(struct Tree_Node * tree){
    if(tree == NULL) return -1;
    deallocate_tree(tree->left);
    deallocate_tree(tree->right);
    free(tree->name);
    free(tree);
    return 0;
}