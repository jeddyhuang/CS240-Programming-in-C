#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    long long int result = 1;
    int n = 20; 
    /* Do not modify above */
    
    for (int i = 2; i <= n; i ++) {
        result = result * i;
    }
    
    /* Do not modify below */
    printf("Result: %lld\n",result);
}