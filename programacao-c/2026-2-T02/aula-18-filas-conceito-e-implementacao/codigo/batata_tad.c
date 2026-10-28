/* batata_tad.c --- a roda de batata.c, usando so fila.h
   gcc batata_tad.c fila_vetor.c   ou   gcc batata_tad.c fila_lista.c */
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* devolve quem sobra; se imprime, mostra a ordem de saida */
int roda(int n, int k, int imprime)
{
    Fila *f = fila_cria();
    for (int i = 1; i <= n; i++)
        enfileira(f, i);
    while (tamanho(f) > 1) {
        for (int j = 0; j < k; j++)
            enfileira(f, desenfileira(f));
        int sai = desenfileira(f);
        if (imprime)
            printf(" %d", sai);
    }
    int fica = desenfileira(f);
    fila_libera(f);
    return fica;
}

int main(void)
{
    int casos[][2] = {{6, 0}, {5, 2}, {7, 1}};
    for (int i = 0; i < 3; i++) {
        printf("n = %d, k = %d: sai", casos[i][0], casos[i][1]);
        int fica = roda(casos[i][0], casos[i][1], 1);
        printf(" | fica %d\n", fica);
    }
    printf("n = 41, k = 2: fica %d\n", roda(41, 2, 0));
    printf("n = 100000, k = 1: fica %d\n", roda(100000, 1, 0));
    return 0;
}
