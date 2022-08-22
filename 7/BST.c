#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

void insert_leaf(struct Tree_Node *subtree, struct Tree_Node *temp){
    if(subtree->value > temp->value){
        if(subtree->left != NULL)
            insert_leaf(subtree->left, temp);
        else subtree->left = temp;
    } else{
        if(subtree->right != NULL)
            insert_leaf(subtree->right, temp);
        else subtree->right = temp;
    }
}

struct Tree_Node *build_BST(Linked_Pair * pair){
    Linked_Pair *move = pair;
    struct Tree_Node *root = NULL;
    while(move != NULL){
        struct Tree_Node *next = malloc(sizeof(struct Tree_Node));
        next->value = move->value;
        next->name = move->name;
        next->left = next->right = NULL;
        if(!root) root = next;
        else insert_leaf(root, next);
        move = move->next;
    }
    return root;
}