#include<stdio.h>
#include<string.h>
#define MAX 1000001
typedef int dado;

struct Pilha {

    dado v[MAX];
    int s;

    Pilha() {
        s = 0;
    }

    bool empty() {
        return (s == 0);
    }

    int size() {
        return s;
    }

    void push(dado e) {
        if (s >= MAX) {
            //printf("Pilha cheia\n");
        } else {
            v[s++] = e;
        }
    }

    void pop() {
         if (s <= 0) {
            printf("EMPTY\n");
         } else {
            s--;
         }
    }

    dado top() {
        if (s <= 0) {
            //printf("Pilha vazia\n");
            return NULL;
        } else {
            return v[s - 1];
        }
    }

    void menor() {
        if (s <= 0) {
            printf("EMPTY\n");
        } else {
            dado m = v[0];
            for (int i = 1; i < s; i++) {
                m = (v[i] < m) ? v[i] : m;
            }
            printf("%d\n", m);
        }
    }

};

int main() {

    int n, i;
    Pilha p;
    scanf("%d%*c", &n);

    for (i = 0; i < n; i++) {
        char tmp[100];
        scanf("%s%*c", tmp);
        if (strcmp(tmp, "PUSH") == 0) {
            int x;
            scanf("%d%*c", &x);
            p.push(x);
        } else if (strcmp(tmp, "POP") == 0) {
            p.pop();
        } else if (strcmp(tmp, "MIN") == 0) {
            p.menor();
        }
    }

    return 0;
}
