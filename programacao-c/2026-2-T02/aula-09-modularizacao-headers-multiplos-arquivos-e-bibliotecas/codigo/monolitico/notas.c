/* notas.c --- tudo em um arquivo so (versao da aula passada) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

double media(const double *v, int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return n > 0 ? s / n : 0.0;
}

double desvio_padrao(const double *v, int n)
{
    double mu = media(v, n), s = 0.0;
    for (int i = 0; i < n; i++)
        s += (v[i] - mu) * (v[i] - mu);
    return n > 0 ? sqrt(s / n) : 0.0;
}

int main(void)
{
    int nalunos = 3, navaliacoes = 4;
    double valores[3][4] = {
        { 8.0, 6.5, 9.0, 7.0 },
        { 5.0, 7.0, 4.0, 7.0 },
        { 9.0, 10.0, 8.5, 9.5 }
    };
    double **notas = cria_matriz(nalunos, navaliacoes);
    if (notas == NULL)
        return 1;
    for (int i = 0; i < nalunos; i++)
        for (int j = 0; j < navaliacoes; j++)
            notas[i][j] = valores[i][j];

    for (int i = 0; i < nalunos; i++)
        printf("aluno %d -> media %.2f  desvio %.2f\n", i,
               media(notas[i], navaliacoes),
               desvio_padrao(notas[i], navaliacoes));

    libera_matriz(notas, nalunos);
    return 0;
}
