#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "remove_redundant.h"

Student_Record *remove_redundant(Student_Record * student) {
    Student_Record *next = NULL, *curr = student;
    while (curr != NULL) {
        next = curr;
        while (next->next != NULL){
            if (strcmp(curr->name, next->next->name) == 0) {
                next->next = next->next->next;
            } else next = next->next;
        }
        curr = curr->next;
    }
    return student;
}