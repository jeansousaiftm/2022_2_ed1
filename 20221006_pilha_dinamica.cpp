#include<stdio.h>
typedef int dado;

struct No {

    dado valor;
    No *prox;

    No(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No *cabeca;
    int s;

    Pilha() {
        cabeca = NULL;
        s = 0;
    }

    bool empty() {
        return (cabeca == NULL);
    }

    int size() {
        return s;
    }

    void push(dado e) {
        if (empty()) {
            cabeca = new No(e);
        } else {
            No *novo = new No(e);
            novo->prox = cabeca;
            cabeca = novo;
        }
        s++;
    }

    void pop() {
        if (!empty()) {
            No *aux = cabeca;
            cabeca = cabeca->prox;
            delete(aux);
            s--;
        }
    }

    dado top() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
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

