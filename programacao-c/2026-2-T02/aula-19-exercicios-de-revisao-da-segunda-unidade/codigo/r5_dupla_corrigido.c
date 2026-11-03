/* r5_dupla_corrigido.c --- remove_no cuidando dos dois extremos */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *ini;
    No *fim;
} Lista;

/* coloca x no fim da lista */
void insere_fim(Lista *l, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = NULL;
    novo->ant = l->fim;
    if (l->fim == NULL)
        l->ini = novo;
    else
        l->fim->prox = novo;
    l->fim = novo;
}

/* encaixa x logo depois do no p (p nao e o ultimo) */
void insere_depois(No *p, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->ant = p;               /* 1 */
    novo->prox = p->prox;        /* 2 */
    p->prox->ant = novo;         /* 3 */
    p->prox = novo;              /* 4 */
}

void remove_no(Lista *l, No *p)
{
    if (p->ant == NULL)
        l->ini = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox == NULL)         /* era o ultimo: muda o fim */
        l->fim = p->ant;
    else
        p->prox->ant = p->ant;
    free(p);
}

void imprime(const Lista *l)
{
    printf("ida:  ");
    for (const No *p = l->ini; p != NULL; p = p->prox)
        printf(" %d", p->valor);
    printf("\nvolta:");
    for (const No *p = l->fim; p != NULL; p = p->ant)
        printf(" %d", p->valor);
    printf("\n");
}

void libera(Lista *l)
{
    No *p = l->ini;
    while (p != NULL) {
        No *prox = p->prox;
        free(p);
        p = prox;
    }
    l->ini = l->fim = NULL;
}

int main(void)
{
    Lista l = {NULL, NULL};
    for (int v = 10; v <= 30; v += 10)
        insere_fim(&l, v);
    insere_depois(l.ini->prox, 25);      /* entre o 20 e o 30 */
    imprime(&l);
    remove_no(&l, l.ini->prox);          /* (b) tira o 20, do meio */
    imprime(&l);
    remove_no(&l, l.fim);                /* (c) tira o 30, o ultimo */
    imprime(&l);
    libera(&l);
    return 0;
}
