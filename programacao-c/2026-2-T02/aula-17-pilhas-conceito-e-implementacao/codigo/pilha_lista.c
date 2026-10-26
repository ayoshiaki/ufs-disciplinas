/* pilha_lista.c --- pilha numa lista encadeada: o topo e o primeiro no */
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    int valor;
    struct no *prox;   /* o de baixo, ou NULL */
} No;

struct pilha {
    No *topo;          /* primeiro no, ou NULL */
};

Pilha *pilha_cria(void)
{
    Pilha *p = malloc(sizeof *p);
    if (p == NULL) {
        perror("malloc");
        exit(1);
    }
    p->topo = NULL;
    return p;
}

void pilha_libera(Pilha *p)
{
    while (!vazia(p))
        desempilha(p);
    free(p);
}

void empilha(Pilha *p, int x)          /* insere no inicio */
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int desempilha(Pilha *p)               /* remove o primeiro */
{
    if (p->topo == NULL) {
        fprintf(stderr, "desempilha: pilha vazia\n");
        exit(1);
    }
    No *velho = p->topo;
    int x = velho->valor;
    p->topo = velho->prox;
    free(velho);
    return x;
}

int topo(const Pilha *p)
{
    if (p->topo == NULL) {
        fprintf(stderr, "topo: pilha vazia\n");
        exit(1);
    }
    return p->topo->valor;
}

int vazia(const Pilha *p)
{
    return p->topo == NULL;
}
