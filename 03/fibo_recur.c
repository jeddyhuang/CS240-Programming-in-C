extern int count;

long long int fibo(int value){
    count ++;
    if (value == 0) return 0;
    else if (value == 1) return 1;
    else return fibo(value - 1) + fibo(value - 2);
}