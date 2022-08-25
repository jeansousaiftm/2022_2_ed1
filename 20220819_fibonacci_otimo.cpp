#include<stdio.h>

long long f[1001];

long long fib(int n) {
    if (f[n] == -1) {
        f[n] = fib(n - 1) + fib(n - 2);
    }
    return f[n];
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        f[i] = -1;
    }
    f[0] = 1;
    f[1] = 1;
    fib(1000);
    for (int i = 0; i <= 1000; i++) {
        printf("%d: %lld\n", i, f[i]);
    }
    return 0;
}
