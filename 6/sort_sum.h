typedef struct Pair {
  int num_1, num_2;  // a pair of numbers
  struct Pair *next;
}  Linked_Pair;

struct Sum {
  int sum; 
  struct Sum *next;
};

struct Sum *sort_sum(Linked_Pair *);