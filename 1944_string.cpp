#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#define MAX 101

using namespace std;

struct Pilha {

    char v[MAX][10];
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

    void push(char e[]) {
        if (s >= MAX) {
            //printf("Pilha cheia\n");
        } else {
            strcpy(v[s++], e);
        }
    }

    void pop() {
         if (s <= 0) {
            //printf("Pilha vazia\n");
         } else {
            s--;
         }
    }

    char* top() {
        if (s <= 0) {
            //printf("Pilha vazia\n");
            return NULL;
        } else {
            return v[s - 1];
        }
    }

};

char* inverter(const char s[]) {
    char* tmp = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    for (int i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--) {
        tmp[i] = s[j];
    }
    tmp[strlen(s)] = '\0';
    return tmp;
}

int main() {

    int n, i, r = 0;
    char tmp[100];
    Pilha p;
    scanf("%d%*c", &n);

    for (i = 0; i < n; i++) {

        scanf("%[^\n]%*c", tmp);
        //printf("%s\n", tmp);

        if (p.empty()) {
            p.push("F A C E");
        }

        //printf("[%s][%s]\n", tmp, inverter(p.top()));

        if (strcmp(inverter(p.top()), tmp) == 0) {
            r++;
            p.pop();
        } else {
            p.push(tmp);
        }

    }

    printf("%d\n", r);

    return 0;
}
