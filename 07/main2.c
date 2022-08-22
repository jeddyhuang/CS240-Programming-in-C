#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "remove_redundant.h"

#define MAXIDLEN 100

/* main function */
int main(int argc, const char *argv[]) 
{
    int value = 0;
    char name[MAXIDLEN] = "\0";
    struct Tree_Node * head = NULL;
    
    /* Scan in the input and build the list */
    while (scanf("%d %s", &value, name) == 2)
    {    
        struct Tree_Node* node = malloc(sizeof(struct Tree_Node));
        assert(node != NULL);
        node->value = value;
        node->name = (char *)malloc(strlen(name)+1);
        strcpy(node->name, name);
        node->left = NULL;
        node->right = NULL;
        
        /* Constructing the Binary Search Tree by calling construct_BST() function*/
        head = construct_BST(head, node); 
    }
   	
    /* Your function called here */
    struct Tree_Node *root = remove_redundant(head);
    
    /* Verify your result by calling check_BST() function. */
    check_tree(root);
    
    return 0;
}