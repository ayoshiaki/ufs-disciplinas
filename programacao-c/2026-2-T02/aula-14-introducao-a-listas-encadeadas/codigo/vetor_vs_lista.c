/* vetor_vs_lista.c --- inserir n valores no INICIO: vetor x lista */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int n = (argc > 1) ? atoi(argv[1]) : 100000;
    long movidos = 0, moveu_bloco = 0;

    /* vetor que cresce com realloc; cada insercao desloca tudo uma casa */
    double t0 = agora();
    int *v = NULL;
    int cap = 0;
    for (int k = 0; k < n; k++) {
        if (k == cap) {
            int *antigo = v;
            cap = (cap == 0) ? 4 : 2 * cap;
            v = realloc(v, cap * sizeof *v);
            if (v == NULL)
                return 1;
            if (antigo != NULL && v != antigo)
                moveu_bloco++;
        }
        memmove(v + 1, v, k * sizeof *v);
        movidos += k;
        v[0] = k;
    }
    double t_vetor = agora() - t0;
    free(v);

    /* lista: cada insercao cria um no e acerta dois ponteiros */
    t0 = agora();
    No *ini = NULL;
    for (int k = 0; k < n; k++) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL)
            return 1;
        novo->valor = k;
        novo->prox = ini;
        ini = novo;
    }
    double t_lista = agora() - t0;
    while (ini != NULL) {
        No *prox = ini->prox;
        free(ini);
        ini = prox;
    }

    printf("n = %d\n", n);
    printf("vetor: %.3f s, %ld elementos deslocados, bloco mudou de lugar %ld vezes\n",
           t_vetor, movidos, moveu_bloco);
    printf("lista: %.3f s, nenhum elemento deslocado\n", t_lista);
    return 0;
}
