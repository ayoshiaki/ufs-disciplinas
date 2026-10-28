/* esvazia.c --- a fila em lista sem atualizar fim quando ela esvazia */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *ini, *fim;
} Fila;

void enfileira(Fila *f, int x)
{
    No *novo = malloc(sizeof *novo);
    if (novo == NULL) exit(1);
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}

int desenfileira(Fila *f)
{
    No *velho = f->ini;
    int x = velho->valor;
    f->ini = velho->prox;
    /* sumiu: if (f->ini == NULL) f->fim = NULL; */
    free(velho);
    return x;
}

int vazia(const Fila *f)
{
    return f->ini == NULL;
}

int main(void)
{
    Fila f = {NULL, NULL};
    enfileira(&f, 1);
    enfileira(&f, 2);
    printf("sai %d\n", desenfileira(&f));
    printf("sai %d\n", desenfileira(&f));
    enfileira(&f, 3);
    printf("vazia? %s\n", vazia(&f) ? "sim" : "nao");
    return 0;
}
