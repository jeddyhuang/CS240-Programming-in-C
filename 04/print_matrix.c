#define NUM_ROWS 2
#define NUM_COLUMNS 2

void print_matrix(int mat[NUM_ROWS][NUM_COLUMNS]){
     
	for (int i = 0; i < NUM_ROWS; i++){
		for(int j = 0; j < NUM_COLUMNS; j++){
			printf("%d ", mat[i][j]);
        }
        printf("\n");
	}
    
     return;   
}