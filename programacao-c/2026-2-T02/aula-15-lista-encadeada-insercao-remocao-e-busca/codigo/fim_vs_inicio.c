/* fim_vs_inicio.c --- inserir n valores no fim (percorrendo) e no inicio */
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

static No *novo_no(int x, No *prox)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = prox;
    return novo;
}

No *insere_inicio(No *ini, int x)
{
    return novo_no(x, ini);
}

/* percorre ate o ultimo a cada insercao */
No *insere_fim(No *ini, int x)
{
    No *novo = novo_no(x, NULL);
    if (ini == NULL)
        return novo;
    No *p = ini;
    while (p->prox != NULL)
        p = p->prox;
    p->prox = novo;
    return ini;
}

static void libera(No *ini)
{
    while (ini != NULL) {
        No *prox = ini->prox;
        free(ini);
        ini = prox;
    }
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 20000;

    double t0 = agora();
    No *a = NULL;
    for (int i = 0; i < n; i++)
        a = insere_inicio(a, i);
    double t_inicio = agora() - t0;

    t0 = agora();
    No *b = NULL;
    for (int i = 0; i < n; i++)
        b = insere_fim(b, i);
    double t_fim = agora() - t0;

    printf("n = %d: inicio %.4f s, fim %.4f s\n", n, t_inicio, t_fim);
    libera(a);
    libera(b);
    return 0;
}
