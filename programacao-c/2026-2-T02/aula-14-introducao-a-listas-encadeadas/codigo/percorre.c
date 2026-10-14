/* percorre.c --- somar n valores: num vetor e numa lista */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

static double agora(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 10000000;
    int *v = malloc(n * sizeof *v);
    No *ini = NULL;
    if (v == NULL)
        return 1;
    for (int k = n - 1; k >= 0; k--) {
        v[k] = 1;
        No *novo = malloc(sizeof *novo);
        if (novo == NULL)
            return 1;
        novo->valor = 1;
        novo->prox = ini;
        ini = novo;
    }

    double t0 = agora();
    long sv = 0;
    for (int k = 0; k < n; k++)
        sv += v[k];
    double t_vetor = agora() - t0;

    t0 = agora();
    long sl = 0;
    for (const No *p = ini; p != NULL; p = p->prox)
        sl += p->valor;
    double t_lista = agora() - t0;

    printf("n = %d: vetor %ld em %.4f s, lista %ld em %.4f s\n",
           n, sv, t_vetor, sl, t_lista);
    free(v);
    while (ini != NULL) {
        No *prox = ini->prox;
        free(ini);
        ini = prox;
    }
    return 0;
}
