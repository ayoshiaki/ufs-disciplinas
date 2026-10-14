/* lista.c --- uma lista encadeada */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;  /* ou NULL */
} No;

/* devolve o novo inicio da lista */
No *insere_inicio(No *ini, int valor)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        perror("malloc");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = ini;
    return novo;
}

void imprime(const No *ini)
{
    for (const No *p = ini; p != NULL; p = p->prox)
        printf("%d -> ", p->valor);
    printf("NULL\n");
}

int conta(const No *ini)
{
    if (ini == NULL)
        return 0;
    return 1 + conta(ini->prox);
}

void libera(No *ini)
{
    while (ini != NULL) {
        No *prox = ini->prox; /* antes! */
        free(ini);
        ini = prox;
    }
}

int main(void)
{
    No *lista = NULL;          /* vazia */
    for (int i = 1; i <= 4; i++)
        lista = insere_inicio(lista, 10 * i);
    imprime(lista);
    printf("%d nos, %zu bytes cada\n", conta(lista), sizeof(No));
    libera(lista);
    return 0;
}
