#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "homework.h"

#define ACTION_ERROR_MSG "Undefined function"
#define FILE_ERROR_MSG "File open failure"

int min_grade = UNDEFINED;
int max_grade = UNDEFINED;

// TODO: Define the 4 functions processing a node.
void find_min(Student_Record *student){
    if(student != NULL) if((min_grade == UNDEFINED) || (student->grade < min_grade)) min_grade = student->grade;
}

void find_max(Student_Record *student){
    if(student != NULL) if((max_grade == UNDEFINED) || (student->grade > max_grade)) max_grade = student->grade;
}

void reset(Student_Record *student){
    if(student != NULL) student->grade = 0;
}

void printing(Student_Record *student){
    if(student != NULL) printf("%s %d\n", student->name, student->grade);
}

int main(int argc, const char *argv[]) {
    // Ensures that 2 command-line arguments are supplied.
    if (argc < 3) {
        fprintf(stderr, "usage: %s <filename> <action>\n", argv[0]);
        return 1;
    }
    
    FILE *f = fopen(argv[1], "r");
    if(f == NULL){
        fprintf(stderr, "%s\n", FILE_ERROR_MSG);
        return 2;
    }
    int choice = 0;
    if(strcmp(argv[2], "find_min") == 0) choice = 1;
    else if(strcmp(argv[2], "find_max") == 0) choice = 2;
    else if(strcmp(argv[2], "reset") == 0) choice = 3;
    else if(strcmp(argv[2], "printing") == 0) choice = 4;
    else {
        fclose(f);
        fprintf(stderr, "%s\n", ACTION_ERROR_MSG);
        return 3;
    }
    int currline = fgetc(f);
    if(currline == EOF){
        fclose(f);
        return 0;
    }
    ungetc(currline, f);
    char *read_in = NULL;
    size_t num_read = 0;
    Student_Record *head = NULL;
    
    while((currline = getline(&read_in, &num_read, f)) != -1) {
        Student_Record* next_student = malloc(sizeof(Student_Record));
        next_student->name = strsep(&read_in, " ");
        next_student->grade = atoi(strsep(&read_in, " "));
        next_student->next = NULL;
        
        if(head == NULL){
            head = next_student;
        } else{
            next_student->next = head;
            head = next_student;
        }
    }
    free(read_in);
    fclose(f);
    
    switch(choice){
        case 1:
            Iterator(head, find_min);
            break;
        case 2:
            Iterator(head, find_max);
            break;
        case 3:
            Iterator(head, reset);
            break;
        case 4:
            Iterator(head, printing);
            break;
    }
    
    while (head != NULL) {
        Student_Record *temp = head->next;
        free(head->name);
        free(head);
        head = temp;
    }
    
    return 0;
}
