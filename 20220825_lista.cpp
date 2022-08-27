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

struct List {

    Node *cabeca, *cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista est� vazia ou n�o
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
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

    Node* pushFront(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
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

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

};

int main() {
    List l;
    l.pushBack(50);
    l.pushBack(30);
    l.pushBack(10);
    l.pushFront(20);
    l.pushFront(10);
    l.popFront();
    l.popFront();
    l.popBack();
    /*l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();
    l.popFront();*/
    l.print();
    printf("%d\n", l.size);
    return 0;
}









