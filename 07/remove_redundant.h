#ifndef REMOVE_REDUNDANT_H
#define REMOVE_REDUNDANT_H

/* Structure Definitions */
struct Tree_Node {
  int value; 
  char *name;
  int ToRemove;
  struct Tree_Node *left, *right;
};

/* Function Prototypes */
struct Tree_Node *construct_BST(struct Tree_Node *, struct Tree_Node *); // Provided in check_tree.o
void check_tree(struct Tree_Node*);										 // Provided in check_tree.o
struct Tree_Node *remove_redundant(struct Tree_Node *); 				 // TODO: implement this function

#endif

