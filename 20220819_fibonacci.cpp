#include<stdio.h>

long long counter = 0;

long long fib(int n) {
    counter++;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        //printf("fib(%d) + fib(%d)\n", n - 1, n - 2);
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n = 60;
    printf("fib(%d): %lld\n", n, fib(n));
    printf("Counter: %lld\n", counter);
    return 0;
}
