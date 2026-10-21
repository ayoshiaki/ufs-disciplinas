/* insere_errada.c --- insere_ordenado sem atualizar o ant do seguinte */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant;    /* no anterior, ou NULL */
    struct no *prox;   /* proximo no, ou NULL */
} No;

typedef struct {
    No *ini;   /* primeiro no, ou NULL */
    No *fim;   /* ultimo no, ou NULL */
} Lista;

/* devolve o primeiro no com valor x, ou NULL */
No *busca(const Lista *l, int x)
{
    No *p = l->ini;
    while (p != NULL && p->valor != x)
        p = p->prox;
    return p;
}

/* insere x mantendo a ordem crescente */
void insere_ordenado(Lista *l, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    No *p = l->ini;               /* o novo entra antes de p */
    while (p != NULL && p->valor < x)
        p = p->prox;
    novo->prox = p;
    novo->ant = (p == NULL) ? l->fim : p->ant;
    if (novo->ant == NULL)        /* virou o primeiro */
        l->ini = novo;
    else
        novo->ant->prox = novo;
    if (p == NULL)                /* virou o ultimo */
        l->fim = novo;
}

/* tira o no p da lista, sem procurar o anterior */
void remove_no(Lista *l, No *p)
{
    if (p->ant == NULL)
        l->ini = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox == NULL)
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
    printf("\n");
}

void imprime_volta(const Lista *l)
{
    printf("volta:");
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
    int entrada[] = {30, 10, 40, 20};
    Lista l = {NULL, NULL};
    for (int i = 0; i < 4; i++)
        insere_ordenado(&l, entrada[i]);
    imprime(&l);
    imprime_volta(&l);
    No *p = busca(&l, 20);
    if (p != NULL)
        remove_no(&l, p);
    remove_no(&l, l.fim);
    imprime(&l);
    imprime_volta(&l);
    libera(&l);
    return 0;
}
