#include<stdio.h>
#define MAX 500
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

    int n, i, r = 0;
    char a, b, c, d;
    Pilha p;
    scanf("%d%*c", &n);
    //fflush(stdin);

    for (i = 0; i < n; i++) {

        scanf("%c %c %c %c%*c", &a, &b, &c, &d);
        //fflush(stdin);

        if (p.empty()) {
            p.push('F');
            p.push('A');
            p.push('C');
            p.push('E');
        }

        int t = p.size();
        //printf("%d\n", t);

        if (p.v[t - 1] == a && p.v[t - 2] == b && p.v[t - 3] == c && p.v[t - 4] == d) {
            r++;
            p.pop();
            p.pop();
            p.pop();
            p.pop();
        } else {
            p.push(a);
            p.push(b);
            p.push(c);
            p.push(d);
        }

    }

    printf("%d\n", r);

    return 0;
}
