#include <stdio.h>
#include <stdlib.h>
#include "matvec.h"

int num_rows;
int v[COLUMN_SIZE];

int main(int argc, const char *argv[]) {
    
    // Ensures that there are 2 command-line arguments.
    if (argc != 3) {
        fprintf(stderr, "usage: %s <num_rows> <num_repetitions>\n", argv[0]);
        return 1;
    }
    
    // Reads from command-line argument.
    num_rows = atoi(argv[1]);
    int num_repetitions = atoi(argv[2]);
    
    // Initializes the vector _v_.
    for (int i = 0; i < COLUMN_SIZE; ++i) {
        v[i] = 1;
    }
    
    // Do NOT modify above
    
    // TODO: 
    // 1. Define variables for the 2D array (matrix) and the result array, then 
    //    dynamically allocate memory for both, using num_rows to determine sizes.
    // 2. Initialize the 2D array by assigning the integer value i+j to the array
    //    element of index [i][j].
    Array *Matrix = malloc(sizeof(int) * num_rows * COLUMN_SIZE);
    int *Result = malloc(sizeof(int) * num_rows);
    
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < COLUMN_SIZE; j++)
            (*Matrix)[i][j] = i+j;
    
    for (int i = 0; i < num_repetitions; ++i) {
        matvec(*Matrix, Result);
    }
    
    check_result(*Matrix, Result);
    
    return 0;
}
    
    