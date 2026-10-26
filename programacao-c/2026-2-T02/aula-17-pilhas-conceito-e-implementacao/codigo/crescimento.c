/* crescimento.c --- empilhar n valores num vetor que cresce de 1 em 1
   ou que dobra quando enche: quantas copias e quanto tempo.
   Aqui o vetor cresce "na mao" (aloca, copia, libera), que e o que o
   realloc precisa fazer quando nao consegue aumentar o bloco no lugar. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static double agora(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

/* troca v por um bloco de nova_cap elementos com os tam primeiros copiados */
static int *cresce(int *v, int tam, int nova_cap, long long *copias)
{
    int *novo = malloc(nova_cap * sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    memcpy(novo, v, tam * sizeof *v);
    *copias += tam;
    free(v);
    return novo;
}

/* empilha n valores; dobra != 0 escolhe a estrategia; devolve as copias */
long long empilha_n(int n, int dobra)
{
    int cap = 1, tam = 0;
    int *v = malloc(cap * sizeof *v);
    long long copias = 0;
    if (v == NULL) {
        perror("malloc");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        if (tam == cap) {
            int nova = dobra ? 2 * cap : cap + 1;
            v = cresce(v, tam, nova, &copias);
            cap = nova;
        }
        v[tam] = i;
        tam++;
    }
    free(v);
    return copias;
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 50000;
    double t0 = agora();
    long long c1 = empilha_n(n, 0);
    double t1 = agora();
    long long c2 = empilha_n(n, 1);
    double t2 = agora();
    printf("n = %d: +1 copias %lld (%.4f s)  x2 copias %lld (%.4f s)\n",
           n, c1, t1 - t0, c2, t2 - t1);
    return 0;
}
