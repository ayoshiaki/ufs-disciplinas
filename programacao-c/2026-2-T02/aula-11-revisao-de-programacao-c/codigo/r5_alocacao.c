/* r5_alocacao.c --- compila sem aviso, mas tem quatro falhas */
#include <stdio.h>
#include <stdlib.h>

int *cria(int n)
{
    int *v = malloc(n);
    for (int i = 0; i < n; i++)
        v[i] = i * i;
    return v;
}

int main(void)
{
    int *v = cria(5);
    v = realloc(v, 10 * sizeof(int));
    free(v);
    printf("%d\n", v[4]);
    return 0;
}
