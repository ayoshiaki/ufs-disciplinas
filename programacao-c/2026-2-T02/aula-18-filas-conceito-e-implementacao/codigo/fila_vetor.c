/* fila_vetor.c --- fila circular num vetor que dobra quando enche */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila {
    int *v;    /* a frente e v[ini]; os n seguintes, dando a volta */
    int ini;   /* posicao da frente */
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

Fila *fila_cria(void)
{
    Fila *f = aloca(NULL, sizeof *f);
    f->ini = 0;
    f->n = 0;
    f->cap = 4;
    f->v = aloca(NULL, f->cap * sizeof *f->v);
    return f;
}

void fila_libera(Fila *f)
{
    free(f->v);
    free(f);
}

/* troca v por um vetor com o dobro do tamanho, ja na ordem: frente em 0 */
static void cresce(Fila *f)
{
    int *novo = aloca(NULL, 2 * f->cap * sizeof *novo);
    for (int i = 0; i < f->n; i++)
        novo[i] = f->v[(f->ini + i) % f->cap];
    free(f->v);
    f->v = novo;
    f->ini = 0;
    f->cap *= 2;
}

void enfileira(Fila *f, int x)
{
    if (f->n == f->cap)
        cresce(f);
    f->v[(f->ini + f->n) % f->cap] = x;
    f->n++;
}

int desenfileira(Fila *f)
{
    if (f->n == 0) {
        fprintf(stderr, "desenfileira: fila vazia\n");
        exit(1);
    }
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->cap;
    f->n--;
    return x;
}

int frente(const Fila *f)
{
    if (f->n == 0) {
        fprintf(stderr, "frente: fila vazia\n");
        exit(1);
    }
    return f->v[f->ini];
}

int vazia(const Fila *f)
{
    return f->n == 0;
}

int tamanho(const Fila *f)
{
    return f->n;
}
