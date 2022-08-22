/* Program to Multiply two 2x2 matrices */
/* Matrix Multiplication with Dynamic Memory Allocation*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void check_fibo(int n, int fibo_num[]){    
    
    if (n>=0) assert(0 == fibo_num[0]);
    if (n>=1) assert(1 == fibo_num[1]);
    for (int i=2; i<=n; i++) assert(fibo_num[i] == (fibo_num[i-1] + fibo_num[i-2]));

    return;
}

int main(int argc, char **argv){

	int n;
    int *fibo_num;
    
    
	// Write code to read n from command line
    n = atoi(argv[1]);
    
    // Use malloc() to allocate memory of the size n to fibo_num
    fibo_num = malloc(sizeof(int)*(n+1));
    
    // calculate fibo values 
    (fibo_num)[0] = 0;
    (fibo_num)[1] = 1;
    for (int i = 2; i < n + 1; i++){
        (fibo_num)[i] = (fibo_num)[i-1] + (fibo_num)[i-2];
    }
    check_fibo(n, fibo_num);
    
    printf("%d\n", fibo_num[n]); 
	

    return 0;
}
