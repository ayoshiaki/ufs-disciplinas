/* fila_lista.c --- fila numa lista encadeada: sai do primeiro no,
   entra depois do ultimo */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no {
    int valor;
    struct no *prox;   /* o de tras, ou NULL */
} No;

struct fila {
    No *ini;           /* a frente: primeiro no, ou NULL */
    No *fim;           /* o ultimo no, ou NULL */
    int n;
};

Fila *fila_cria(void)
{
    Fila *f = malloc(sizeof *f);
    if (f == NULL) {
        perror("malloc");
        exit(1);
    }
    f->ini = f->fim = NULL;
    f->n = 0;
    return f;
}

void fila_libera(Fila *f)
{
    while (!vazia(f))
        desenfileira(f);
    free(f);
}

void enfileira(Fila *f, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim == NULL)          /* fila vazia: o novo e tambem a frente */
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    f->n++;
}

int desenfileira(Fila *f)
{
    if (f->ini == NULL) {
        fprintf(stderr, "desenfileira: fila vazia\n");
        exit(1);
    }
    No *velho = f->ini;
    int x = velho->valor;
    f->ini = velho->prox;
    if (f->ini == NULL)          /* saiu o ultimo: nao ha mais fim */
        f->fim = NULL;
    free(velho);
    f->n--;
    return x;
}

int frente(const Fila *f)
{
    if (f->ini == NULL) {
        fprintf(stderr, "frente: fila vazia\n");
        exit(1);
    }
    return f->ini->valor;
}

int vazia(const Fila *f)
{
    return f->ini == NULL;
}

int tamanho(const Fila *f)
{
    return f->n;
}
