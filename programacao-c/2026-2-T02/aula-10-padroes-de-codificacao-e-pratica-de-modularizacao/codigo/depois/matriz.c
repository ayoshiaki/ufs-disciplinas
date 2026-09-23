/* matriz.c --- implementacao das matrizes dinamicas */
#include <stdlib.h>
#include "matriz.h"

double **cria_matriz(int nl, int nc)
{
    double **m = malloc(nl * sizeof(double *));
    if (m == NULL)
        return NULL;
    for (int i = 0; i < nl; i++) {
        m[i] = malloc(nc * sizeof(double));
        if (m[i] == NULL) {
            for (int k = 0; k < i; k++)
                free(m[k]);
            free(m);
            return NULL;
        }
    }
    return m;
}

void libera_matriz(double **m, int nl)
{
    for (int i = 0; i < nl; i++)
        free(m[i]);
    free(m);
}
