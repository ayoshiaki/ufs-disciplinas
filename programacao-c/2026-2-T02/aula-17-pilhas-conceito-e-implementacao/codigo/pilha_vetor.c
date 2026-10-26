/* pilha_vetor.c --- pilha num vetor que dobra quando enche */
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
    int *v;    /* v[0..n-1]: o topo e v[n-1] */
    int n;     /* quantos elementos ha */
    int cap;   /* quantos cabem em v */
};

static void *aloca(void *antigo, size_t tam)
{
    void *p = realloc(antigo, tam);
    if (p == NULL) {
        perror("realloc");
        exit(1);
    }
    return p;
}

Pilha *pilha_cria(void)
{
    Pilha *p = aloca(NULL, sizeof *p);
    p->n = 0;
    p->cap = 4;
    p->v = aloca(NULL, p->cap * sizeof *p->v);
    return p;
}

void pilha_libera(Pilha *p)
{
    free(p->v);
    free(p);
}

void empilha(Pilha *p, int x)
{
    if (p->n == p->cap) {             /* cheio: dobra a capacidade */
        p->cap *= 2;
        p->v = aloca(p->v, p->cap * sizeof *p->v);
    }
    p->v[p->n] = x;
    p->n++;
}

int desempilha(Pilha *p)
{
    if (p->n == 0) {
        fprintf(stderr, "desempilha: pilha vazia\n");
        exit(1);
    }
    p->n--;
    return p->v[p->n];
}

int topo(const Pilha *p)
{
    if (p->n == 0) {
        fprintf(stderr, "topo: pilha vazia\n");
        exit(1);
    }
    return p->v[p->n - 1];
}

int vazia(const Pilha *p)
{
    return p->n == 0;
}
