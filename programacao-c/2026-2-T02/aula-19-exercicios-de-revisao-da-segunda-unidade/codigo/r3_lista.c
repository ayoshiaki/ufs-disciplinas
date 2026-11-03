/* r3_lista.c --- inserir no inicio inverte a ordem */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

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

void libera(No *ini)
{
    while (ini != NULL) {
        No *prox = ini->prox;   /* guarda o caminho antes do free */
        free(ini);
        ini = prox;
    }
}

int main(void)
{
    No *lista = NULL;
    int entrada[] = {5, 8, 2};
    for (int i = 0; i < 3; i++)
        lista = insere_inicio(lista, entrada[i]);
    imprime(lista);
    printf("sizeof(No) = %zu\n", sizeof(No));
    libera(lista);
    return 0;
}
