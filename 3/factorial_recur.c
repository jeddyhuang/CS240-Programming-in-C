extern int count;

long long int factorial(int value){
    count ++;
    if (value == 0 || value == 1) return 1;
    else return value * factorial(value - 1);
}