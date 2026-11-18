/* cadastro.c --- converte turma.csv (texto) em turma.bin (registros)
   uso: ./cadastro                        (turma.csv -> turma.bin)
        ./cadastro entrada.csv saida.bin */
#include <stdio.h>
#include <string.h>
#include "aluno.h"

int main(int argc, char *argv[])
{
    const char *nome_ent = argc > 1 ? argv[1] : "turma.csv";
    const char *nome_sai = argc > 2 ? argv[2] : "turma.bin";

    FILE *ent = fopen(nome_ent, "r");
    if (ent == NULL) {
        perror(nome_ent);
        return 1;
    }
    FILE *sai = fopen(nome_sai, "wb");
    if (sai == NULL) {
        perror(nome_sai);
        fclose(ent);
        return 1;
    }

    char linha[256];
    int n = 0;
    while (fgets(linha, sizeof linha, ent) != NULL) {
        struct aluno a = {0};          /* comeca zerado: sem lixo no disco */
        if (sscanf(linha, "%d;%49[^;];%lf;%lf;%lf;%lf", &a.mat, a.nome,
                   &a.v[0], &a.v[1], &a.v[2], &a.v[3]) != 6)
            continue;
        if (fwrite(&a, sizeof a, 1, sai) != 1) {
            perror(nome_sai);
            break;
        }
        n++;
    }
    fclose(ent);
    fclose(sai);

    printf("%d alunos gravados em %s\n", n, nome_sai);
    return 0;
}
