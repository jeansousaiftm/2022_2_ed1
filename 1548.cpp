#include<stdio.h>

typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};

struct Fila {

    Node *cabeca, *cauda;
    int size;

    Fila() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* enqueue(dado valor) { //O(1) - push back
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* dequeue() { //O(1) -- pop front
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    dado front() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
        }
    }

};

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] < v[j + 1]) {
                int x = v[j];
                v[j] = v[j + 1];
                v[j + 1] = x;
            }
        }
    }
}

int main() {
    int n, m, i, j;
    int v[1001];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {

        Fila f;
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &v[j]);
            f.enqueue(v[j]);
        }

        bubbleSort(v, m);

        int r = 0;

        for (j = 0; j < m; j++) {
            //printf("%d %d\n", v[j], f.front());
            if (v[j] == f.front()) {
                r++;
            }
            f.dequeue();
        }

        printf("%d\n", r);

    }



    return 0;
}
