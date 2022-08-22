#include <stdio.h>
#include <stdlib.h>


int byte_swap(int val){
    int res;
    // Enter your code in here
    char *temp1 = (char *)&val;
    char temp2[4] = {};
    temp2[0] = temp1[3];
    temp2[1] = temp1[2];
    temp2[2] = temp1[1];
    temp2[3] = temp1[0];
    res = *(int *)&temp2;
    return res;
    
}

int main(int argc, char **argv)
{
    int val;
    val = atoi(argv[1]);
    
    printf("%d\n", byte_swap(val));
    
    return 0;
    
}


