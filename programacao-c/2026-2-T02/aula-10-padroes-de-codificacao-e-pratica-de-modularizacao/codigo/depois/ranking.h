/* ranking.h --- interface: classificacao dos alunos de uma turma pela media */
#ifndef RANKING_H
#define RANKING_H

#include "turma.h"

/* Media minima para aprovacao; faz parte do contrato do modulo. */
#define RANKING_NOTA_CORTE 7.0

typedef struct {
    int    *posicao;   /* posicao[0] = indice do aluno de maior media */
    double *media;     /* media[i] = media do aluno de indice i */
    int     quantidade;
} Ranking;

/* Calcula a classificacao de t, da maior para a menor media.
   Devolve o ranking alocado, ou NULL se faltar memoria.
   O chamador e responsavel por chamar ranking_libera. */
Ranking *ranking_cria(const Turma *t);

/* Libera o ranking; aceita NULL. */
void ranking_libera(Ranking *r);

/* Indica se o aluno colocado em `colocacao` (0 = primeiro) foi aprovado. */
int ranking_aprovado(const Ranking *r, int colocacao);

/* Imprime a classificacao: uma linha por aluno, na ordem do ranking. */
void ranking_imprime(const Ranking *r);

#endif /* RANKING_H */
