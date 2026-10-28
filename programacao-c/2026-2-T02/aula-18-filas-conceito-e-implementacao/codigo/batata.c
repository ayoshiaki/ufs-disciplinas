/* batata.c --- quem sobra na roda da batata quente?
   n criancas em roda; a batata passa k vezes e quem fica com ela sai.
   uso: ./batata          (tres rodas de exemplo)
        ./batata n k      (uma roda) */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int v[MAX];    /* a frente e v[ini]; o proximo entra em v[fim] */
    int ini, fim;
} Fila;

void enfileira(Fila *f, int x)
{
    if (f->fim == MAX) {
        fprintf(stderr, "\nenfileira: fila cheia\n");
        exit(1);
    }
    f->v[f->fim] = x;
    f->fim++;
}

int desenfileira(Fila *f)
{
    if (f->ini == f->fim) {
        fprintf(stderr, "\ndesenfileira: fila vazia\n");
        exit(1);
    }
    int x = f->v[f->ini];
    f->ini++;
    return x;
}

int tamanho(const Fila *f)
{
    return f->fim - f->ini;
}

/* imprime a ordem de saida e devolve quem sobrou */
int roda(int n, int k)
{
    Fila f = {.ini = 0, .fim = 0};
    for (int i = 1; i <= n; i++)
        enfileira(&f, i);
    while (tamanho(&f) > 1) {
        for (int j = 0; j < k; j++)
            enfileira(&f, desenfileira(&f));   /* passa a batata */
        printf(" %d", desenfileira(&f));        /* quem ficou com ela sai */
        fflush(stdout);
    }
    return desenfileira(&f);
}

int main(int argc, char *argv[])
{
    if (argc == 3) {
        int n = atoi(argv[1]), k = atoi(argv[2]);
        printf("n = %d, k = %d: sai", n, k);
        int fica = roda(n, k);
        printf(" | fica %d\n", fica);
        return 0;
    }
    int casos[][2] = {{6, 0}, {5, 2}, {7, 1}};
    for (int i = 0; i < 3; i++) {
        printf("n = %d, k = %d: sai", casos[i][0], casos[i][1]);
        int fica = roda(casos[i][0], casos[i][1]);
        printf(" | fica %d\n", fica);
    }
    return 0;
}
