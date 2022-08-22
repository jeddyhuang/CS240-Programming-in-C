#include <stdio.h>
#include <stdlib.h>

void matvec(int mat[2][2], int vec[], int result[]){
    result[0] = mat[0][0]*vec[0] + mat[0][1]*vec[1];
    result[1] = mat[1][0]*vec[0] + mat[1][1]*vec[1];
    return;
}