/* main.c --- monta a turma e pede os relatorios */
#include <stdio.h>
#include "turma.h"

/* o ranking nao tem header: copiei as assinaturas na mao */
void calcula(Turma *t, int flag);
void mostra();

int main(void)
{
    double valores[3][4] = {
        { 8.0, 6.5, 9.0, 7.0 },
        { 5.0, 7.0, 4.0, 7.0 },
        { 9.0, 10.0, 8.5, 9.5 }
    };
    Turma *t = turma_cria(3, 4);
    if (t == NULL) {
        fprintf(stderr, "sem memoria\n");
        return 1;
    }
    for (int i = 0; i < t->nalunos; i++)
        for (int j = 0; j < t->navaliacoes; j++)
            t->notas[i][j] = valores[i][j];

    turma_relatorio(t);
    printf("\n");
    calcula(t, 0);
    mostra();

    turma_libera(t);
    return 0;
}
