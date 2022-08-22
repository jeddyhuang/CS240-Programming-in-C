#ifndef MATVEC_H
#define MATVEC_H

#define COLUMN_SIZE 4096

typedef int Array[][COLUMN_SIZE];

// The value is read from command-line argument in the main function.
extern int num_rows;

// This is initialized in main function and should be used as the right
// hand side of matrix-vector multiplication in _matvec()_.
extern int v[COLUMN_SIZE];


// Verifies values in _result_ and ensures that _A_ and _result_ 
// are properly allocated. Prints an error message if there are incorrect
// values or arrays are not properly allocated.
// The implementation of this function is precompiled in file check_result.o.
void check_result(Array A, int result[]);

// Multiplies _matrix_ with vector _v_, and writes the product to vector
// _result_. The number of rows of _matrix_ and _result_ is implicitly
// _num_rows_.
// TODO: implement this function in matvecRow.c and matvecCol.c.
void matvec(Array matrix, int result[]);

#endif
