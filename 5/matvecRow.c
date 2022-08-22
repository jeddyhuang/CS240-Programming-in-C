#include <stdio.h>
#include <stdlib.h>
#include "matvec.h"

void matvec(Array matrix, int result[COLUMN_SIZE]){
    for (int i = 0; i < num_rows; i++) {
        result[i] = 0;
        for (int j = 0; j < COLUMN_SIZE; j++)
            result[i] += matrix[i][j] * v[j];
    }
}