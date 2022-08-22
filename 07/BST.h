#ifndef BST_H
#define BST_H

/* Structure Definitions */
typedef struct Pair {
  int value;
  char *name;
  struct Pair *next;
}  Linked_Pair;

struct Tree_Node {
  int value; 
  char *name;
  struct Tree_Node *left, *right;
};

/* Function Prototypes */
void check_BST(struct Tree_Node *); 		// Provided in check_BST.o
struct Tree_Node *build_BST(Linked_Pair *); // TODO: implement this function

#endif