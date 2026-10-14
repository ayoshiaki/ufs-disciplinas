/* libera_errada.c --- o free que vem antes da hora */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *insere_inicio(No *ini, int valor)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL)
        exit(1);
    novo->valor = valor;
    novo->prox = ini;
    return novo;
}

void libera(No *ini)
{
    for (No *p = ini; p != NULL; p = p->prox)   /* p->prox depois do free */
        free(p);
}

int main(void)
{
    No *lista = NULL;
    for (int i = 1; i <= 4; i++)
        lista = insere_inicio(lista, 10 * i);
    libera(lista);
    printf("liberada\n");
    return 0;
}
