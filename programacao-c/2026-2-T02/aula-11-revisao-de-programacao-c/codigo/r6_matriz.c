/* r6_matriz.c --- a mesma matriz 3x4 nos dois formatos */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nl = 3, nc = 4, chamadas = 0;

    double *b = malloc((size_t)nl * nc * sizeof(double));
    chamadas++;
    for (int k = 0; k < nl * nc; k++)
        b[k] = k;
    printf("bloco unico: elemento (2,1) no indice %d, valor %.0f; %d malloc\n",
           2 * nc + 1, b[2 * nc + 1], chamadas);
    free(b);

    chamadas = 0;
    double **m = malloc(nl * sizeof(double *));
    chamadas++;
    for (int i = 0; i < nl; i++) {
        m[i] = malloc(nc * sizeof(double));
        chamadas++;
    }
    printf("double **: %d malloc\n", chamadas);
    for (int i = 0; i < nl; i++)            /* de dentro para fora */
        free(m[i]);
    free(m);
    return 0;
}
