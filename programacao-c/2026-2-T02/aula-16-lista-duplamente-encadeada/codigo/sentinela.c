/* sentinela.c --- lista dupla circular com no cabeca: sem casos especiais */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *ant;
    struct no *prox;
} No;

/* a cabeca nao guarda valor: cab->prox e o primeiro, cab->ant o ultimo */
void inicia(No *cab)
{
    cab->ant = cab->prox = cab;
}

/* insere x imediatamente antes do no p */
void insere_antes(No *p, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = p;
    novo->ant = p->ant;
    p->ant->prox = novo;
    p->ant = novo;
}

void insere_ordenado(No *cab, int x)
{
    No *p = cab->prox;
    while (p != cab && p->valor < x)
        p = p->prox;
    insere_antes(p, x);
}

void remove_no(No *p)
{
    p->ant->prox = p->prox;
    p->prox->ant = p->ant;
    free(p);
}

No *busca(No *cab, int x)
{
    No *p = cab->prox;
    while (p != cab && p->valor != x)
        p = p->prox;
    return (p == cab) ? NULL : p;
}

void imprime(const No *cab)
{
    printf("ida:  ");
    for (const No *p = cab->prox; p != cab; p = p->prox)
        printf(" %d", p->valor);
    printf("\n");
}

void imprime_volta(const No *cab)
{
    printf("volta:");
    for (const No *p = cab->ant; p != cab; p = p->ant)
        printf(" %d", p->valor);
    printf("\n");
}

void libera(No *cab)
{
    while (cab->prox != cab)
        remove_no(cab->prox);
}

int main(void)
{
    int entrada[] = {30, 10, 40, 20};
    No cab;
    inicia(&cab);
    for (int i = 0; i < 4; i++)
        insere_ordenado(&cab, entrada[i]);
    imprime(&cab);
    imprime_volta(&cab);
    No *p = busca(&cab, 20);
    if (p != NULL)
        remove_no(p);
    remove_no(cab.ant);
    imprime(&cab);
    imprime_volta(&cab);
    libera(&cab);
    return 0;
}
