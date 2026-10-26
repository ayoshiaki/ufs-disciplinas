/* vetor_vs_lista.c --- empilhar n valores e desempilhar todos:
   pilha em vetor que dobra x pilha em lista encadeada */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double agora(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

static void *aloca(void *antigo, size_t tam)
{
    void *p = realloc(antigo, tam);
    if (p == NULL) {
        perror("realloc");
        exit(1);
    }
    return p;
}

/* --- vetor que dobra --- */
typedef struct {
    int *v;
    int n, cap;
} PilhaV;

static void empilha_v(PilhaV *p, int x)
{
    if (p->n == p->cap) {
        p->cap = (p->cap == 0) ? 4 : 2 * p->cap;
        p->v = aloca(p->v, p->cap * sizeof *p->v);
    }
    p->v[p->n++] = x;
}

static int desempilha_v(PilhaV *p)
{
    return p->v[--p->n];
}

/* --- lista encadeada: o topo e o primeiro no --- */
typedef struct no {
    int valor;
    struct no *prox;
} No;

static void empilha_l(No **topo, int x)
{
    No *novo = aloca(NULL, sizeof *novo);
    novo->valor = x;
    novo->prox = *topo;
    *topo = novo;
}

static int desempilha_l(No **topo)
{
    No *velho = *topo;
    int x = velho->valor;
    *topo = velho->prox;
    free(velho);
    return x;
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 1000000;
    long long soma_v = 0, soma_l = 0;

    double t0 = agora();
    PilhaV pv = {NULL, 0, 0};
    for (int i = 0; i < n; i++)
        empilha_v(&pv, i);
    while (pv.n > 0)
        soma_v += desempilha_v(&pv);
    free(pv.v);
    double t1 = agora();

    No *topo = NULL;
    for (int i = 0; i < n; i++)
        empilha_l(&topo, i);
    while (topo != NULL)
        soma_l += desempilha_l(&topo);
    double t2 = agora();

    printf("n = %d: vetor %.4f s  lista %.4f s  (somas %s)\n", n, t1 - t0,
           t2 - t1, soma_v == soma_l ? "iguais" : "DIFERENTES");
    printf("bytes por elemento: vetor %zu (ate o dobro, se meio vazio)"
           "  lista %zu + o que o malloc gasta por bloco\n",
           sizeof(int), sizeof(No));
    return 0;
}
