#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// You can include any standard libraries
// You can write any helper functions here
// You can test your code with sample test case in the run script

int main(int argc, char **argv)
{
    int result[200] = {0};
    // The number of groups of digits in the final result
    // and you need to compute this number correctly
    int num_groups = 0;
    // Do not modify above
    
    int num_group1 = strlen(argv[1]) / 9;
    int group1 = strlen(argv[1]) % 9;
    if (group1 != 0) num_group1 ++;
    else group1 = 9;
    
    for (int i = 0; i < num_group1; i ++){
        char str[9] = "";
        if (i == 0){
            for (int j = 0; j < group1; j++){
                str[j] = argv[1][j];
            }
        } else {
            for (int j = 0; j < 9; j ++){
                str[j] = argv[1][j+(i-1)*9+group1];
            }
        }
        result[num_group1-i-1] = atoi(str);
    }
    
    int num_group2 = strlen(argv[2]) / 9;
    int group2 = strlen(argv[2]) % 9;
    if (group2 != 0) num_group2 ++;
    else group2 = 9;
    
    for (int i = 0; i < num_group2; i ++){
        char str[9] = "";
        if (i == 0){
            for (int j = 0; j < group2; j++){
                str[j] = argv[2][j];
            }
        } else {
            for (int j = 0; j < 9; j ++){
                str[j] = argv[2][j+(i-1)*9+group2];
            }
        }
        result[num_group2-i-1] = result[num_group2-i-1] + atoi(str);
    }
    if (num_group1 > num_group2) num_groups = num_group1;
    else num_groups = num_group2;
    
    for (int i = 0; i < num_groups; i ++){
        if (result[i] / 1000000000 != 0) {
            result[i+1] = result[i+1] + result[i] / 1000000000;
            result[i] = result[i] % 1000000000;
            if (i == (num_groups-1)) num_groups = num_groups + 1;
        }
    }
    
    // Do not modify below
    // Print results
   
    printf("%d ", result[num_groups-1]);
           
    for (int i = num_groups-2; i >=0; i--)
    {
        printf("%09d ",result[i]);
    }
    printf("\n");
    
    return 0;
}