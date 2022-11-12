#include<stdio.h>

int main() {

    int n, m, i, x;
    int e[50001], c[1000001];

    for (i = 0; i <= 100000; i++) c[i] = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &e[i]);
        c[e[i]] = 1;
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        c[x] = 0;
    }

    bool imprimiu = false;

    for (i = 0; i < n; i++) {
        if (c[e[i]] == 1) {
            if (imprimiu) printf(" ");
            printf("%d", e[i]);
            imprimiu = true;
        }
    }

    printf("\n");

    return 0;
}
