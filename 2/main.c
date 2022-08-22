#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long long int result;
    
    int n = atoi(argv[1]);
    
    result = factorial(n); 
    
    printf("Result: %lld\n",result);
    
    return 0;
}