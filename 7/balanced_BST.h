#ifndef BALANCED_BST_H
#define BALANCED_BST_H

/* Structure Definitions */
typedef struct Pair {
  int value;
  char *name;
  struct Pair *next;
} Linked_Pair;

struct Tree_Node {
  int value; 
  int height;
  char *name;
  struct Tree_Node *left, *right;
  struct Tree_Node *parent;
};

/* Function Prototypes */
void check_balance(struct Tree_Node *); 		     // Provided in check_BST.o
struct Tree_Node *build_balanced_BST(Linked_Pair *); // TODO: implement this function

#endif