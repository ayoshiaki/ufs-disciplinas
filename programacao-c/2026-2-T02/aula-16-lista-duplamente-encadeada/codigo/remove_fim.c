/* remove_fim.c --- montar n nos e remover sempre o ultimo: simples x dupla */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct simples {
    int valor;
    struct simples *prox;
} Simples;

typedef struct dupla {
    int valor;
    struct dupla *ant, *prox;
} Dupla;

static double agora(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

static void *aloca(size_t tam)
{
    void *p = malloc(tam);
    if (p == NULL) {
        perror("malloc");
        exit(1);
    }
    return p;
}

/* simples: para tirar o ultimo, e preciso achar o penultimo */
Simples *remove_fim_simples(Simples *ini)
{
    if (ini->prox == NULL) {
        free(ini);
        return NULL;
    }
    Simples *p = ini;
    while (p->prox->prox != NULL)
        p = p->prox;
    free(p->prox);
    p->prox = NULL;
    return ini;
}

/* dupla: o penultimo e fim->ant */
void remove_fim_dupla(Dupla **ini, Dupla **fim)
{
    Dupla *p = *fim;
    *fim = p->ant;
    if (*fim == NULL)
        *ini = NULL;
    else
        (*fim)->prox = NULL;
    free(p);
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 20000;

    Simples *s = NULL;
    for (int i = 0; i < n; i++) {
        Simples *novo = aloca(sizeof *novo);
        novo->valor = i;
        novo->prox = s;
        s = novo;
    }
    double t0 = agora();
    while (s != NULL)
        s = remove_fim_simples(s);
    double t_simples = agora() - t0;

    Dupla *ini = NULL, *fim = NULL;
    for (int i = 0; i < n; i++) {
        Dupla *novo = aloca(sizeof *novo);
        novo->valor = i;
        novo->ant = fim;
        novo->prox = NULL;
        if (fim == NULL)
            ini = novo;
        else
            fim->prox = novo;
        fim = novo;
    }
    t0 = agora();
    while (fim != NULL)
        remove_fim_dupla(&ini, &fim);
    double t_dupla = agora() - t0;

    printf("n = %d: simples %.4f s, dupla %.4f s\n", n, t_simples, t_dupla);
    printf("sizeof: simples %zu bytes, dupla %zu bytes\n",
           sizeof(Simples), sizeof(Dupla));
    return 0;
}
