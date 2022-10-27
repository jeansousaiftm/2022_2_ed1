#include<stdio.h>
#include<string.h>
#define MAX 1001
typedef char dado;

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
            //printf("Pilha vazia\n");
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

};

int main() {
    char tmp[1001];
    int j;

    while (scanf("%s", tmp) != EOF) {
        Pilha p;
        bool certo = true;
        for (j = 0; j < strlen(tmp); j++) {
            if (tmp[j] == '(') {
                p.push('(');
            } else if (tmp[j] == ')') {
                if (p.empty()) {
                    certo = false;
                } else {
                    p.pop();
                }
             }
        }
        if (p.size() > 0) certo = false;
        if (certo) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
