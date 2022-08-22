#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    int result[200]; 
    int n = atoi(argv[1]);
    // Do not modify above
    
    int num_digits = 1;
    result[0] = 1;
    
    for (int counter = 2; counter <= n; counter++) {
        int carry = 0;
        for (int i = 0; i < num_digits; i++) {
            int temp = result[i] * counter + carry;
            result[i] = temp % 10;
            carry = temp / 10;
        }
        while (carry != 0) {
            result[num_digits] = carry % 10;
            carry = carry/10;
            num_digits ++;
        }
    }

    // Do not modify below
    // Print results

    for (int i = num_digits-1; i >=0; i--)
    {
        printf("%d",result[i]);
    }
    
    return 0;
}