#include<stdio.h>
#include<ctime>


struct Data {

    int dia, mes, ano;

    void lerData() {
        fflush(stdin);
        scanf("%d %d %d", &dia, &mes, &ano);
    }

    void imprimirData() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {
        Data atual = obterDataAtual();
        if (mes < atual.mes || (mes == atual.mes && dia <= atual.dia)) {
            return atual.ano - ano;
        }
        return (atual.ano - ano) - 1;
    }

    Data obterDataAtual() {
        Data atual;
        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);
        atual.ano = now->tm_year + 1900;
        atual.mes = now->tm_mon + 1;
        atual.dia = now->tm_mday;
        return atual;
    }

};

struct Cliente {

    char nome[100];
    Data nascimento;
    int idade;
    char sexo;

    void lerCliente() {
        fflush(stdin);
        scanf("%[^\n]s", nome);
        fflush(stdin);
        scanf("%c", &sexo);
        fflush(stdin);
        nascimento.lerData();
        idade = nascimento.calcularIdade();
    }

    void imprimirCliente() {
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Nascimento: ");
        nascimento.imprimirData();
        printf("Idade: %d\n", idade);
    }

};

int main() {
    Cliente clientes[50];
    int ultimoCliente = -1;
    char op;

    do {

        printf("1. Ler\n");
        printf("2. Imprimir\n");
        printf("3. Sair\n");

        fflush(stdin);
        scanf("%c", &op);

        switch(op) {
            case '1':
                clientes[++ultimoCliente].lerCliente();
                break;
            case '2':
                for (int i = 0; i <= ultimoCliente; i++) {
                    clientes[i].imprimirCliente();
                }
                break;
            case '3':
                printf("Tchau!");
                break;
            default:
                printf("Op invalida!");
                break;
        }

    } while (op != '3');


    return 0;
}
