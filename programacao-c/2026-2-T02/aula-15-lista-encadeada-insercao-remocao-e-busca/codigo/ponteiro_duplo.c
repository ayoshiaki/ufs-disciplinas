/* ponteiro_duplo.c --- insercao e remocao sem caso especial */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

/* pp aponta para o ponteiro que sera mudado: o inicio ou um prox */
void insere_ordenado(No **pp, int x)
{
    while (*pp != NULL && (*pp)->valor < x)
        pp = &(*pp)->prox;
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = x;
    novo->prox = *pp;
    *pp = novo;
}

void remove_valor(No **pp, int x)
{
    while (*pp != NULL && (*pp)->valor != x)
        pp = &(*pp)->prox;
    if (*pp != NULL) {
        No *p = *pp;
        *pp = p->prox;
        free(p);
    }
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
        insere_ordenado(&lista, entrada[i]);
    imprime(lista);
    remove_valor(&lista, 10);
    remove_valor(&lista, 40);
    remove_valor(&lista, 99);
    imprime(lista);
    libera(lista);
    return 0;
}
