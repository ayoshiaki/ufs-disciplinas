/* r4_remove.c --- uma remocao que funciona so no caso do meio */
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

No *remove_valor(No *ini, int x)
{
    No *ant = NULL, *p = ini;
    while (p->valor != x && p != NULL) {
        ant = p;
        p = p->prox;
    }
    ant->prox = p->prox;
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

int main(int argc, char *argv[])
{
    int x = (argc > 1) ? atoi(argv[1]) : 20;
    No *lista = NULL;
    for (int v = 30; v >= 10; v -= 10)       /* 10 -> 20 -> 30 */
        lista = insere_inicio(lista, v);
    imprime(lista);
    printf("remove_valor(lista, %d)\n", x);
    fflush(stdout);
    lista = remove_valor(lista, x);
    imprime(lista);
    libera(lista);
    return 0;
}
