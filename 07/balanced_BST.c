#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balanced_BST.h"

struct Tree_Node *root = NULL;

int height(struct Tree_Node *subtree) {
	if (subtree==NULL) return -1;
	else return ((height(subtree->left)) < (height(subtree->right))
                 ? (height(subtree->right)) : (height(subtree->left))) +1;
}

void rotate(struct Tree_Node *subtree, int direction){
    if(subtree->parent == NULL){
        if(direction == 0){
            struct Tree_Node *temp2 = subtree->right;
            struct Tree_Node *temp3 = subtree->right->left;
            temp2->left = subtree;
            subtree->right = temp3;

            temp2->parent = NULL;
            subtree->parent = temp2;
            if(temp3 != NULL) temp3->parent = subtree;
            root = temp2;
        } else{
            struct Tree_Node *temp2 = subtree->left;
            struct Tree_Node *temp3 = subtree->left->right;
            temp2->right = subtree;
            subtree->left = temp3;

            temp2->parent = NULL;
            subtree->parent = temp2;
            if(temp3 != NULL) temp3->parent = subtree;
            root = temp2;
        }
    } else if(direction == 0){
        struct Tree_Node *temp1 = subtree->parent;
        struct Tree_Node *temp2 = subtree->right;
        struct Tree_Node *temp3 = subtree->right->left;
        if(temp1->left == subtree) temp1->left = temp2;
        else temp1->right = temp2;
        temp2->left = subtree;
        subtree->right = temp3;
        
        temp2->parent = temp1;
        subtree->parent = temp2;
        if(temp3 != NULL) temp3->parent = subtree;
    } else{
        struct Tree_Node *temp1 = subtree->parent;
        struct Tree_Node *temp2 = subtree->left;
        struct Tree_Node *temp3 = subtree->left->right;
        if(temp1->left == subtree) temp1->left = temp2;
        else temp1->right = temp2;
        temp2->right = subtree;
        subtree->left = temp3;
        
        temp2->parent = temp1;
        subtree->parent = temp2;
        if(temp3 != NULL) temp3->parent = subtree;
    }
}

void insert_leaf(struct Tree_Node *subtree, struct Tree_Node *temp, int from){
    if(subtree->value == temp->value){
        if(height(subtree->left) < height(subtree->right)){
            insert_leaf(subtree->left, temp, 0);
        } else if(height(subtree->left) > height(subtree->right)){
            insert_leaf(subtree->right, temp, 1);
        } else{
            if(from == 0) insert_leaf(subtree->left, temp, 0);
            else insert_leaf(subtree->right, temp, 1);
        }
    }
    if(subtree->value > temp->value){
        if(subtree->left != NULL)
            insert_leaf(subtree->left, temp, 0);
        else{
            temp->parent = subtree;
            subtree->left = temp;
        }
    } else{
        if(subtree->right != NULL)
            insert_leaf(subtree->right, temp, 1);
        else{
            temp->parent = subtree;
            subtree->right = temp;
        }
    }
    if(from == 0){
        if(height(subtree->right) == height(subtree->left)+1)
            rotate(subtree, 0);
        if(height(subtree->left) == height(subtree->right)+2)
            rotate(subtree, 1);
    } else{
        if(height(subtree->left) == height(subtree->right)+1)
            rotate(subtree, 1);
        if(height(subtree->right) == height(subtree->left)+2)
            rotate(subtree, 0);
    }
}

void insert(struct Tree_Node *subtree, struct Tree_Node *temp){
    if(subtree->value > temp->value) insert_leaf(subtree, temp, 0);
    else insert_leaf(subtree, temp, 1);
}

struct Tree_Node *build_balanced_BST(Linked_Pair * pair){
    while(pair != NULL){
        struct Tree_Node *next = malloc(sizeof(struct Tree_Node));
        next->value = pair->value;
        next->name = pair->name;
        next->left = next->right = NULL;
        if(root == NULL) {
           next->parent = NULL;
           root = next;
        } else insert(root, next);
        pair = pair->next;
    }
    return root;
}