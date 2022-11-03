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

int main() {

    Fila f;

    f.enqueue(10);
    f.enqueue(20);
    f.enqueue(30);

    printf("%d\n", f.front());

    f.dequeue();

    printf("%d\n", f.front());

    f.dequeue();

    printf("%d\n", f.front());

    return 0;
}
