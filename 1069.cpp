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
    int i, j, n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        Pilha p;
        int r = 0;
        char tmp[1001];
        scanf("%s", tmp);
        for (j = 0; j < strlen(tmp); j++) {
            if (tmp[j] == '<') {
                p.push('<');
            } else if (tmp[j] == '>') {
                if (!p.empty()) {
                    r++;
                    p.pop();
                }
             }
        }
        printf("%d\n", r);
    }

    return 0;
}
