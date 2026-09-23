/* turma.h --- interface: a turma e seu relatorio */
#ifndef TURMA_H
#define TURMA_H

typedef struct {
    double **notas;
    int nalunos;
    int navaliacoes;
} Turma;

Turma *turma_cria(int nalunos, int navaliacoes);
void turma_libera(Turma *t);
void turma_relatorio(const Turma *t);

#endif /* TURMA_H */
