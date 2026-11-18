/* lote.c --- le turma.bin de 3 em 3 registros */
#include <stdio.h>
#include "aluno.h"

#define LOTE 3

int main(void)
{
    FILE *f = fopen("turma.bin", "rb");
    if (f == NULL) {
        perror("turma.bin");
        return 1;
    }
    struct aluno buf[LOTE];
    size_t lidos;
    while ((lidos = fread(buf, sizeof buf[0], LOTE, f)) > 0) {
        printf("fread devolveu %zu:", lidos);
        for (size_t i = 0; i < lidos; i++)
            printf(" %d", buf[i].mat);
        printf("\n");
    }
    if (ferror(f))
        perror("turma.bin");
    else if (feof(f))
        printf("fim do arquivo\n");
    fclose(f);
    return 0;
}
