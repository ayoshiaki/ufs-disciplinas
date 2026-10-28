/* batata_circular.c --- a roda de batata.c com a fila circular:
   o fim volta ao inicio do vetor. MAX agora e so 41. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 41

typedef struct {
    int v[MAX];    /* a frente e v[ini]; os n seguintes, dando a volta */
    int ini, n;
} Fila;

void enfileira(Fila *f, int x)
{
    if (f->n == MAX) {
        fprintf(stderr, "\nenfileira: fila cheia\n");
        exit(1);
    }
    f->v[(f->ini + f->n) % MAX] = x;    /* o fim da a volta */
    f->n++;
}

int desenfileira(Fila *f)
{
    if (f->n == 0) {
        fprintf(stderr, "\ndesenfileira: fila vazia\n");
        exit(1);
    }
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % MAX;        /* o inicio tambem */
    f->n--;
    return x;
}

int tamanho(const Fila *f)
{
    return f->n;
}

int roda(int n, int k)
{
    Fila f = {.ini = 0, .n = 0};
    for (int i = 1; i <= n; i++)
        enfileira(&f, i);
    while (tamanho(&f) > 1) {
        for (int j = 0; j < k; j++)
            enfileira(&f, desenfileira(&f));
        printf(" %d", desenfileira(&f));
    }
    return desenfileira(&f);
}

int main(int argc, char *argv[])
{
    int n = (argc > 2) ? atoi(argv[1]) : 41;
    int k = (argc > 2) ? atoi(argv[2]) : 2;
    printf("n = %d, k = %d: sai", n, k);
    int fica = roda(n, k);
    printf(" | fica %d\n", fica);
    return 0;
}
