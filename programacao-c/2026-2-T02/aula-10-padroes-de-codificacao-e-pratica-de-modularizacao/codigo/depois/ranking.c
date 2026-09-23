/* ranking.c --- implementacao da classificacao por media */
#include <stdio.h>
#include <stdlib.h>
#include "ranking.h"
#include "estat.h"

/* Ordena as posicoes por media decrescente.
   Insercao, e nao um algoritmo melhor, porque uma turma cabe em uma sala. */
static void ordena(Ranking *r)
{
    for (int i = 1; i < r->quantidade; i++) {
        int atual = r->posicao[i];
        int j = i - 1;
        while (j >= 0 && r->media[r->posicao[j]] < r->media[atual]) {
            r->posicao[j + 1] = r->posicao[j];
            j--;
        }
        r->posicao[j + 1] = atual;
    }
}

Ranking *ranking_cria(const Turma *t)
{
    if (t == NULL || t->nalunos <= 0)
        return NULL;

    Ranking *r = malloc(sizeof(Ranking));
    if (r == NULL)
        return NULL;

    r->posicao = malloc(t->nalunos * sizeof(int));
    r->media = malloc(t->nalunos * sizeof(double));
    if (r->posicao == NULL || r->media == NULL) {
        ranking_libera(r);
        return NULL;
    }
    r->quantidade = t->nalunos;

    for (int i = 0; i < r->quantidade; i++) {
        r->media[i] = media(t->notas[i], t->navaliacoes);
        r->posicao[i] = i;
    }
    ordena(r);
    return r;
}

void ranking_libera(Ranking *r)
{
    if (r == NULL)
        return;
    free(r->posicao);
    free(r->media);
    free(r);
}

int ranking_aprovado(const Ranking *r, int colocacao)
{
    return r->media[r->posicao[colocacao]] >= RANKING_NOTA_CORTE;
}

void ranking_imprime(const Ranking *r)
{
    printf("%-5s %-8s %8s %s\n", "pos", "aluno", "media", "situacao");
    for (int i = 0; i < r->quantidade; i++) {
        int aluno = r->posicao[i];
        printf("%-5d %-8d %8.2f %s\n", i + 1, aluno, r->media[aluno],
               ranking_aprovado(r, i) ? "aprovado" : "reprovado");
    }
}
