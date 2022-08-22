#include <stdio.h>
#include <stdlib.h>

// Implement the function invertPhoto to invert a big map photo
// Function takes three input parameter:
//   - height of photo, which is an integer
//   - width of photo, which is an integer
//   - a big map photo, which is a matrix (integer array)
// You can test your code with sample test case in the run script


// Start your code in here
void invertPhoto(int h, int w, int img[h][w])
{
   for (int i = 0; i < h; i ++) for (int j = 0; j < w; j ++) {
       img[i][j] = 255 - img[i][j];
   }
}
// End of your code

// main function
int main(int argc, char **argv)
{
    int height = atoi(argv[1]);
    int width = atoi(argv[2]);
    
    int img[height][width]; 
    int i = 3; 
    int x, y = 0; 
    for(x = 0; x < height; x++) { 
        for(y = 0; y < width; y++) {
            img[x][y] = atoi(argv[i]); 
            i++;
        }
    }

	invertPhoto(height, width, img);

    for(x = 0; x < height; x++) { 
        for(y = 0; y < width; y++) {
            printf("%d ", img[x][y]);
        }
        printf("\n");
    }
    
    return 0;
}
