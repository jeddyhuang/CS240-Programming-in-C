/* Program to Multiply two 2x2 matrices */
/* Matrix Vector Multiplication */

#include <stdio.h>
#include <stdlib.h>
#include "matvec.h" // Try to make matvec.c and matvec.h file yourself :)

#define NUM_ROWS 2
#define NUM_COLUMNS 2


int main(int argc, char **argv)
{

	// Declare two matrices
	int mat[NUM_ROWS][NUM_COLUMNS];
	int vec[NUM_ROWS];
	int result[NUM_ROWS];
    
	// Initialize elements of the two matrices
	mat[0][0] = atoi(argv[1]);
	mat[0][1] = atoi(argv[2]);
	mat[1][0] = atoi(argv[3]);
	mat[1][1] = atoi(argv[4]);
	
	vec[0] = atoi(argv[5]);
	vec[1] = atoi(argv[6]);
	
	// Write your code to call matvec() that will perform a matrix-vector multiplication
    matvec(mat, vec, result);
   
	printf("%d %d\n", result[0], result[1]);
    return 0;
}