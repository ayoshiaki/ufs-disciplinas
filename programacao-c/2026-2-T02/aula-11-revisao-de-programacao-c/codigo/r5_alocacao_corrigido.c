/* r5_alocacao_corrigido.c --- as quatro falhas corrigidas */
#include <stdio.h>
#include <stdlib.h>

int *cria(int n)
{
    int *v = malloc(n * sizeof(int));
    if (v == NULL)
        return NULL;
    for (int i = 0; i < n; i++)
        v[i] = i * i;
    return v;
}

int main(void)
{
    int *v = cria(5);
    if (v == NULL)
        return 1;
    int *tmp = realloc(v, 10 * sizeof(int));
    if (tmp == NULL) {
        free(v);
        return 1;
    }
    v = tmp;
    printf("%d\n", v[4]);
    free(v);
    v = NULL;
    return 0;
}
