long long int factorial(int value){
    long long int result = 1;
    for (int i = 2; i <= value; i ++) {
        result = result * i;
    }
    return result;
}