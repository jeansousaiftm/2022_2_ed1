#include<stdio.h>
#define MAX 100
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
            printf("Pilha cheia\n");
        } else {
            v[s++] = e;
        }
    }

    void pop() {
         if (s <= 0) {
            printf("Pilha vazia\n");
         } else {
            s--;
         }
    }

    dado top() {
        if (s <= 0) {
            printf("Pilha vazia\n");
            return NULL;
        } else {
            return v[s - 1];
        }
    }

};

int main() {

    Pilha p;

    p.push(10);
    p.push(20);

    printf("%d\n", p.top());

    p.pop();

    printf("%d\n", p.top());

    p.pop();
    p.pop();

    return 0;
}
