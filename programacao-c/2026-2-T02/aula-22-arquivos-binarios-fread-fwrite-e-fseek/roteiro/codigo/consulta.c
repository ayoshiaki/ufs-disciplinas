/* consulta.c --- vai direto ao registro k de turma.bin
   uso: ./consulta turma.bin k */
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "uso: %s arquivo k\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);                       /* vai para o fim...  */
    long n = ftell(f) / (long) sizeof(struct aluno);  /* ...e mede */

    long k = atol(argv[2]);
    struct aluno a;
    fseek(f, k * (long) sizeof a, SEEK_SET);     /* salta k registros */
    if (fread(&a, sizeof a, 1, f) != 1) {
        printf("registro %ld nao existe (o arquivo tem %ld)\n", k, n);
        fclose(f);
        return 1;
    }
    printf("registro %ld de %ld: %d %s\n", k, n, a.mat, a.nome);
    fclose(f);
    return 0;
}
