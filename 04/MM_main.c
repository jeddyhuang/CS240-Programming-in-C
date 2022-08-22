/* Program to Multiply two 2x2 matrices */
/* Matrix Vector Multiplication */

#include <stdio.h>
#include <stdlib.h>
#include "print_matrix.c"

#define NUM_ROWS 2
#define NUM_COLUMNS 2


int main(int argc, char **argv)
{

	// Declare two matrices
	int mat1[NUM_ROWS][NUM_COLUMNS];
	int mat2[NUM_ROWS][NUM_COLUMNS];
	int result[NUM_ROWS][NUM_COLUMNS];
	
	// Initialize elements of the two matrices
	mat1[0][0] = atoi(argv[1]);
	mat1[0][1] = atoi(argv[2]);
	mat1[1][0] = atoi(argv[3]);
	mat1[1][1] = atoi(argv[4]);
	
	mat2[0][0] = atoi(argv[5]);
	mat2[0][1] = atoi(argv[6]);
	mat2[1][0] = atoi(argv[7]);
	mat2[1][1] = atoi(argv[8]);	
	
	// Write your code to perform matrix-vector multiplication
    result[0][0] = mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0];
    result[0][1] = mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1];
    result[1][0] = mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0];
    result[1][1] = mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1];
    
    result[0][0] = result[0][0] + 1;
    result[0][0] = result[0][0] - 1;
    
    // Write your code to call print_matrix funtion with a DEBUG option.
#ifdef DEBUG
    print_matrix(result);
#endif
    
    return 0;
}