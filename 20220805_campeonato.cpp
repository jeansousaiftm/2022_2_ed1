#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Time {
    char nome[4];
    int jogos, pontos, vitorias, empates, derrotas;
    int golsPro, golsContra, saldo;
    double aproveitamento;

    Time() {
        strcpy(nome, "");
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    Time(char _nome[4]) {
        strcpy(nome, _nome);
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    void computarJogo(int _golsPro, int _golsContra) {
        jogos++;
        if (_golsPro > _golsContra) {
            vitorias++;
            pontos += 3;
        } else if (_golsPro == _golsContra) {
            empates++;
            pontos += 1;
        } else {
            derrotas++;
        }
        golsPro += _golsPro;
        golsContra += _golsContra;
        saldo = golsPro - golsContra;
        aproveitamento = (pontos / (jogos * 3.0)) * 100.0;
    }

    void imprimirTime() {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\n",
               nome, jogos, pontos, vitorias, empates,
               derrotas, saldo, golsPro, golsContra,
               aproveitamento);
    }
};

int main() {

    Time times[12];
    char t1[4], t2[4];
    int r1, r2, ultimo_id = -1;
    FILE *f = fopen("20220805_jogos.txt", "r+");

    while(fscanf(f, "%s %dX%d %s", t1, &r1, &r2, t2) != EOF) {
        int i1 = -1, i2 = -1;
        for (int i = 0; i <= ultimo_id; i++) {
            if (strcmp(times[i].nome, t1) == 0) { // Checa se t1 já existe
                i1 = i;
            }
            if (strcmp(times[i].nome, t2) == 0) { // Checa se t2 já existe
                i2 = i;
            }
        }
        if (i1 == -1) { // Se t1 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t1);
            i1 = ultimo_id;
        }
        if (i2 == -1) { // Se t2 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t2);
            i2 = ultimo_id;
        }
        times[i1].computarJogo(r1, r2); // Computa para t1
        times[i2].computarJogo(r2, r1); // Computa para t2
    }
    for (int i = 0; i <= ultimo_id; i++) {
        times[i].imprimirTime();
    }
    return 0;
}







