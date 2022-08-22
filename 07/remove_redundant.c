#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "remove_redundant.h"

void delete_dupe(struct Tree_Node *root, struct Tree_Node *tocheck){
    int temp = 0;
    if(root->left != NULL){
        if(strcmp(root->left->name, tocheck->name) == 0){
            if(root->left->value != tocheck->value){
                temp = 1;
                if(root->left->left != NULL){
                    struct Tree_Node *temp1 = root->left->right;
                    struct Tree_Node *temp2 = root->left->left;
                    root->left = temp2;
                    while(temp2->right != NULL){
                        temp2 = temp2->right;
                    }
                    temp2->right = temp1;
                } else{
                    struct Tree_Node *temp1 = root->left->right;
                    root->left = temp1;
                }
            }
        }
    }
    if(root->right != NULL){
        if(strcmp(root->right->name, tocheck->name) == 0){
            if(root->right->value != tocheck->value){
                temp = 1;
                if(root->right->left != NULL){
                    struct Tree_Node *temp1 = root->right->right;
                    struct Tree_Node *temp2 = root->right->left;
                    root->right = temp2;
                    while(temp2->right != NULL){
                        temp2 = temp2->right;
                    }
                    temp2->right = temp1;
                } else{
                    struct Tree_Node *temp1 = root->right->right;
                    root->right = temp1;
                }
            }
        }
    }
    if(temp){
        delete_dupe(root, tocheck);
    } else{
        if(root->left != NULL) delete_dupe(root->left, tocheck);
        if(root->right != NULL) delete_dupe(root->right, tocheck);
    }
}

void traverse_tree(struct Tree_Node *subtree, struct Tree_Node *root){
    delete_dupe(root, subtree);
    if(subtree->left != NULL) traverse_tree(subtree->left, root);
    if(subtree->right != NULL) traverse_tree(subtree->right, root);
}

struct Tree_Node *remove_redundant(struct Tree_Node * head){
    struct Tree_Node *root = head;
    traverse_tree(root, root);
    return head;
}