/* corrige.c --- troca uma nota dentro de turma.bin, sem reescrever o resto
   uso: ./corrige turma.bin matricula avaliacao nota */
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(int argc, char *argv[])
{
    if (argc != 5) {
        fprintf(stderr, "uso: %s arquivo matricula avaliacao nota\n", argv[0]);
        return 1;
    }
    int mat = atoi(argv[2]), av = atoi(argv[3]);
    double nota = atof(argv[4]);

    FILE *f = fopen(argv[1], "r+b");             /* ler e gravar */
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }
    struct aluno a;
    while (fread(&a, sizeof a, 1, f) == 1) {
        if (a.mat != mat)
            continue;
        a.v[av] = nota;
        fseek(f, -(long) sizeof a, SEEK_CUR);    /* volta um registro */
        if (fwrite(&a, sizeof a, 1, f) != 1)
            perror(argv[1]);
        else
            printf("%d: nota %d agora vale %.1f\n", mat, av, nota);
        fclose(f);
        return 0;
    }
    printf("matricula %d nao encontrada\n", mat);
    fclose(f);
    return 1;
}
