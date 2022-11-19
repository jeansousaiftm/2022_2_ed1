#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

int main() {

    int n, i, x, y;
    while (scanf("%d", &n) != EOF) {
        int fila = 1, pilha = 1, filaPrioridade = 1;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            if (x == 1) {
                q.push(y);
                s.push(y);
                pq.push(y);
            }
            if (x == 2) {
                if (q.front() != y) {
                    fila = 0;
                }
                if (s.top() != y) {
                    pilha = 0;
                }
                if (pq.top() != y) {
                    filaPrioridade = 0;
                }
                q.pop();
                s.pop();
                pq.pop();
            }
        }
        //printf("%d %d %d\n", fila, pilha, filaPrioridade);
        if (fila + pilha + filaPrioridade > 1) {
            printf("not sure\n");
        } else if (fila + pilha + filaPrioridade == 0) {
            printf("impossible\n");
        } else if (fila == 1) {
            printf("queue\n");
        } else if (pilha == 1) {
            printf("stack\n");
        } else {
            printf("priority queue\n");
        }
    }
    return 0;
}
