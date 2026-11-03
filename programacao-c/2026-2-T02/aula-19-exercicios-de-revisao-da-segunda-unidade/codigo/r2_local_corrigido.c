/* r2_local_corrigido.c --- tres formas de devolver o dobro sem endereco de local */
#include <stdio.h>
#include <stdlib.h>

/* 1) devolver o valor: a copia sobrevive ao return */
int dobro(int x)
{
    return 2 * x;
}

/* 2) o chamador da o lugar onde guardar */
void dobro_em(int x, int *saida)
{
    *saida = 2 * x;
}

/* 3) bloco no heap: quem recebe e dono e precisa dar free */
int *dobro_heap(int x)
{
    int *r = malloc(sizeof *r);
    if (r != NULL)
        *r = 2 * x;
    return r;
}

int main(void)
{
    int a;
    dobro_em(21, &a);
    int *h = dobro_heap(21);
    if (h == NULL)
        return 1;
    printf("%d %d %d\n", dobro(21), a, *h);
    free(h);
    return 0;
}
