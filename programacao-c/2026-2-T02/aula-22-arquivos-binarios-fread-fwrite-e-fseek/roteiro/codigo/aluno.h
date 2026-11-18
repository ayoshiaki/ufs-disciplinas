/* aluno.h --- o registro gravado em turma.bin */
#ifndef ALUNO_H
#define ALUNO_H

#define NAV 4   /* avaliacoes por aluno */

struct aluno {
    int    mat;
    char   nome[50];
    double v[NAV];
};

#endif
