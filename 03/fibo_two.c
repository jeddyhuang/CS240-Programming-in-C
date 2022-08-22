#include <stdio.h>
#include <stdlib.h>

#include "fibo_table.h"

int main(int argc, char **argv)
{    
    int n = atoi(argv[1]);
    int i = 0;
    int fibo_num[n+1];
    
    fibo(n, fibo_num); 
    
    printf("Fibo array: ");
    for (i = 0; i <= n; i++) { 
        printf("%d ", fibo_num[i]);
    }
    printf("\n");
        
    return 0;
}