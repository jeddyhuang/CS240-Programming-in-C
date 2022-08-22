#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "balanced_BST.h"

#define MAXIDLEN 100

/* main function */
int main(int argc, const char *argv[]) 
{
    int value = 0;
    char name[MAXIDLEN] = "\0";
    Linked_Pair * head = NULL;
    
    /* Scan in the input and build the list */
    while (scanf("%d %s", &value, name) == 2)
    {    
        Linked_Pair* new_pair = malloc(sizeof(Linked_Pair));
        assert(new_pair != NULL);
        new_pair->value = value;
        new_pair->name = (char *)malloc(strlen(name)+1);
        strcpy(new_pair->name, name);
        new_pair->next = NULL;
        
        if (!head) 
        {
            head = new_pair;
        }
        else 
        {
            Linked_Pair* current = head;

            while (current->next)
            {
                current = current->next;
            }
            current->next = new_pair;
        } 
    }
    
    /* Your function called here */
    struct Tree_Node *root = build_balanced_BST(head);
   
    /* Verify your result by calling check_BST() function. */
    check_balance(root);
    
    return 0;
}