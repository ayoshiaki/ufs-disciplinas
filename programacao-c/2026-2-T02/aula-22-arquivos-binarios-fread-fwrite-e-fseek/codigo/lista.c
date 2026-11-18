/* lista.c --- le turma.bin registro a registro e imprime o boletim */
#include <stdio.h>
#include "aluno.h"

int main(int argc, char *argv[])
{
    const char *nome = argc > 1 ? argv[1] : "turma.bin";
    FILE *f = fopen(nome, "rb");
    if (f == NULL) {
        perror(nome);
        return 1;
    }
    struct aluno a;
    while (fread(&a, sizeof a, 1, f) == 1) {
        double m = (a.v[0] + a.v[1] + a.v[2] + a.v[3]) / NAV;
        printf("%d %-22s %5.2f\n", a.mat, a.nome, m);
    }
    fclose(f);
    return 0;
}
