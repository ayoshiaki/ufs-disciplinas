/* r3_libera_errada.c --- o laco que le p->prox de um no ja liberado */
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

int main(void)
{
    No *lista = NULL;
    int entrada[] = {5, 8, 2};
    for (int i = 0; i < 3; i++)
        lista = insere_inicio(lista, entrada[i]);
    for (No *p = lista; p != NULL; p = p->prox)   /* p->prox depois do free */
        free(p);
    printf("liberou (sera?)\n");
    return 0;
}
