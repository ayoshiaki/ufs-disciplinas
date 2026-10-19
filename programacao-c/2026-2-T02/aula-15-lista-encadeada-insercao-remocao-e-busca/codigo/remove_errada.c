/* remove_errada.c --- a remocao sem o caso do primeiro no */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

/* devolve o primeiro no com valor x, ou NULL */
No *busca(No *ini, int x)
{
    No *p = ini;
    while (p != NULL && p->valor != x)
        p = p->prox;
    return p;
}

/* insere x mantendo a ordem; devolve o novo inicio */
No *insere_ordenado(No *ini, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    if (ini == NULL || x < ini->valor) {   /* vira o primeiro */
        novo->prox = ini;
        return novo;
    }
    No *ant = ini;
    while (ant->prox != NULL && ant->prox->valor < x)
        ant = ant->prox;
    novo->prox = ant->prox;
    ant->prox = novo;
    return ini;
}

/* remove o primeiro no com valor x; devolve o novo inicio */
No *remove_valor(No *ini, int x)
{
    No *ant = NULL, *p = ini;
    while (p != NULL && p->valor != x) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)          /* nao achou */
        return ini;
    ant->prox = p->prox;    /* e se p for o primeiro? */
    free(p);
    return ini;
}

void imprime(const No *ini)
{
    for (const No *p = ini; p != NULL; p = p->prox)
        printf("%d -> ", p->valor);
    printf("NULL\n");
}

void libera(No *ini)
{
    while (ini != NULL) {
        No *prox = ini->prox;
        free(ini);
        ini = prox;
    }
}

int main(void)
{
    int entrada[] = {30, 10, 40, 20};
    No *lista = NULL;
    for (int i = 0; i < 4; i++)
        lista = insere_ordenado(lista, entrada[i]);
    imprime(lista);
    printf("busca 20: %s\n", busca(lista, 20) ? "achou" : "nao achou");
    printf("busca 25: %s\n", busca(lista, 25) ? "achou" : "nao achou");
    lista = remove_valor(lista, 10);
    lista = remove_valor(lista, 40);
    lista = remove_valor(lista, 99);
    imprime(lista);
    libera(lista);
    return 0;
}
