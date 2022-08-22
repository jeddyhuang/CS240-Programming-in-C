void fibo(int value, int array[]){
    array[0] = 0;
    if (value == 0) return;
    array[1] = 1;
    for (int i = 2; i < value + 1; i++){
        array[i] = array[i-1] + array[i-2];
    }
}