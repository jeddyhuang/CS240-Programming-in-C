#include <stdio.h>
#include <stdlib.h>
#include "sort_sum.h"
struct Sum *sort_sum(Linked_Pair * pair){
    Linked_Pair *move = pair;
    struct Sum *head = NULL;
    while (move != NULL) {
        struct Sum *next = malloc(sizeof(struct Sum));
        next->sum = move->num_1 + move->num_2;
        next->next = head;
        head = next;
        move = move->next;
    }
    struct Sum *next = NULL, *curr = head;
    while (curr != NULL) {
        next = curr->next;
        while (next != NULL){
            if(curr->sum < next->sum){
                int tempsum = next->sum;
                next->sum = curr->sum;
                curr->sum = tempsum;
            }
            next = next->next;
        }
        curr = curr->next;
    }
    return head;
}