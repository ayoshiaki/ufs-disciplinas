/* conjunto.c --- um conjunto de inteiros de 0 a 31 guardado num unsigned:
   o elemento i esta no conjunto se o bit i vale 1 */
#include <stdio.h>

typedef unsigned Conjunto;

Conjunto insere(Conjunto c, int i)  { return c | 1u << i; }
Conjunto retira(Conjunto c, int i)  { return c & ~(1u << i); }
int pertence(Conjunto c, int i)     { return (c >> i) & 1u; }

/* cada c &= c - 1 apaga o 1 mais a direita */
int conta(Conjunto c)
{
    int n = 0;
    while (c != 0) {
        c &= c - 1;
        n++;
    }
    return n;
}

void imprime(const char *nome, Conjunto c)
{
    printf("%-10s {", nome);
    for (int i = 0; i < 32; i++)
        if (pertence(c, i))
            printf(" %d", i);
    printf(" }  %d elementos\n", conta(c));
}

int main(void)
{
    Conjunto pares = 0, mult3 = 0;
    for (int i = 2; i <= 20; i += 2)
        pares = insere(pares, i);
    for (int i = 3; i <= 20; i += 3)
        mult3 = insere(mult3, i);

    imprime("pares", pares);
    imprime("mult3", mult3);
    imprime("p | m", pares | mult3);
    imprime("p & m", pares & mult3);
    imprime("p & ~m", pares & ~mult3);
    imprime("p ^ m", pares ^ mult3);
    imprime("sem o 6", retira(pares, 6));
    return 0;
}
