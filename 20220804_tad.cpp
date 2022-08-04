#include<stdio.h>

struct Aluno {

    int id;
    char nome[100];
    char cpf[20];
    int idade;

    void lerAluno() {
        printf("Digite o id do aluno: ");
        scanf("%d", &id);
        fflush(stdin);
        printf("Digite o nome do aluno: ");
        scanf("%[^\n]s", nome);
        fflush(stdin);
        printf("Digite o CPF: ");
        scanf("%s", cpf);
        fflush(stdin);
        printf("Digite a idade: ");
        scanf("%d", &idade);
        fflush(stdin);
    }

    void imprimirAluno() {
        printf("Id: %d\n", id);
        printf("Nome: %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Idade: %d\n", idade);
    }

};

int main() {

    Aluno alunos[3];

    for (int i = 0; i < 3; i++) {
        alunos[i].lerAluno();
        alunos[i].imprimirAluno();
    }


    return 0;
}












