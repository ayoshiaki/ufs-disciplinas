/* r7_dobra_errada.c --- crescer a fila circular com realloc, como na pilha */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;    /* a frente e v[ini]; os n seguintes, dando a volta */
    int ini;
    int n;
    int cap;
} Fila;

static void *aloca(void *antigo, size_t tam)
{
    void *p = realloc(antigo, tam);
    if (p == NULL) {
        perror("realloc");
        exit(1);
    }
    return p;
}

Fila *fila_cria(void)
{
    Fila *f = aloca(NULL, sizeof *f);
    f->ini = 0;
    f->n = 0;
    f->cap = 4;
    f->v = aloca(NULL, f->cap * sizeof *f->v);
    for (int i = 0; i < f->cap; i++)
        f->v[i] = 0;          /* so para o desenho sair limpo */
    return f;
}

void fila_libera(Fila *f)
{
    free(f->v);
    free(f);
}

/* ERRADO: dobra no lugar, sem desenrolar o anel */
static void cresce(Fila *f)
{
    f->v = aloca(f->v, 2 * f->cap * sizeof *f->v);
    for (int i = f->cap; i < 2 * f->cap; i++)
        f->v[i] = -1;         /* marca as posicoes novas, que ninguem preencheu */
    f->cap *= 2;
}

void enfileira(Fila *f, int x)
{
    if (f->n == f->cap)
        cresce(f);
    f->v[(f->ini + f->n) % f->cap] = x;
    f->n++;
}

int desenfileira(Fila *f)
{
    if (f->n == 0) {
        fprintf(stderr, "desenfileira: fila vazia\n");
        exit(1);
    }
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->cap;
    f->n--;
    return x;
}

void mostra(const char *rotulo, const Fila *f)
{
    printf("%s v = [", rotulo);
    for (int i = 0; i < f->cap; i++)
        printf(i ? " %d" : "%d", f->v[i]);
    printf("]  ini = %d  n = %d  cap = %d\n", f->ini, f->n, f->cap);
}

int main(void)
{
    Fila *f = fila_cria();
    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    desenfileira(f);
    desenfileira(f);
    enfileira(f, 4);
    enfileira(f, 5);
    mostra("(a)", f);
    printf("    o proximo enfileira escreve em v[%d]\n",
           (f->ini + f->n) % f->cap);
    enfileira(f, 6);
    mostra("(b) depois do 6:", f);
    enfileira(f, 7);
    mostra("(b) depois do 7:", f);
    printf("    saem:");
    while (f->n > 0)
        printf(" %d", desenfileira(f));
    printf("\n");
    fila_libera(f);
    return 0;
}
