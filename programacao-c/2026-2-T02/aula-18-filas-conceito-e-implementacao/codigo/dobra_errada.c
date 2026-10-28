/* dobra_errada.c --- fila circular que dobra com um realloc e nada mais */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int ini, n, cap;
} Fila;

void enfileira(Fila *f, int x)
{
    if (f->n == f->cap) {                 /* cheia: dobra */
        f->cap *= 2;
        f->v = realloc(f->v, f->cap * sizeof *f->v);
        if (f->v == NULL) { perror("realloc"); exit(1); }
    }
    f->v[(f->ini + f->n) % f->cap] = x;
    f->n++;
}

int desenfileira(Fila *f)
{
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->cap;
    f->n--;
    return x;
}

int main(void)
{
    Fila f = {.ini = 0, .n = 0, .cap = 4};
    f.v = malloc(f.cap * sizeof *f.v);
    if (f.v == NULL) { perror("malloc"); exit(1); }

    for (int x = 1; x <= 4; x++) enfileira(&f, x);   /* 1 2 3 4 */
    desenfileira(&f);                                /* sai 1   */
    desenfileira(&f);                                /* sai 2   */
    enfileira(&f, 5);                                /* 3 4 5   */
    enfileira(&f, 6);                                /* 3 4 5 6: cheia */
    enfileira(&f, 7);                                /* dobra   */

    printf("cap = %d, ini = %d, n = %d\nsai:", f.cap, f.ini, f.n);
    while (f.n > 0)
        printf(" %d", desenfileira(&f));
    printf("\n");
    free(f.v);
    return 0;
}
