/* turma.c --- implementacao da turma: usa matriz.h e estat.h */
#include <stdio.h>
#include <stdlib.h>
#include "turma.h"
#include "matriz.h"
#include "estat.h"

/* so turma.c enxerga esta funcao */
static void cabecalho(void)
{
    printf("%-8s %8s %8s\n", "aluno", "media", "desvio");
}

Turma *turma_cria(int nalunos, int navaliacoes)
{
    Turma *t = malloc(sizeof(Turma));
    if (t == NULL)
        return NULL;
    t->notas = cria_matriz(nalunos, navaliacoes);
    if (t->notas == NULL) {
        free(t);
        return NULL;
    }
    t->nalunos = nalunos;
    t->navaliacoes = navaliacoes;
    return t;
}

void turma_libera(Turma *t)
{
    if (t == NULL)
        return;
    libera_matriz(t->notas, t->nalunos);
    free(t);
}

void turma_relatorio(const Turma *t)
{
    cabecalho();
    for (int i = 0; i < t->nalunos; i++)
        printf("%-8d %8.2f %8.2f\n", i,
               media(t->notas[i], t->navaliacoes),
               desvio_padrao(t->notas[i], t->navaliacoes));
}
