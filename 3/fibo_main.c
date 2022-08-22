#include <stdio.h>
#include <stdlib.h>

#include "fibo_recur.h"

int count = 0;

int main(int argc, char **argv)
{
    long long int result;
    
    int n = atoi(argv[1]);
    
    result = fibo(n); 
    
    printf("Result: %lld\n",result);
    
    printf("Count: %d\n",count);
    
    return 0;
}