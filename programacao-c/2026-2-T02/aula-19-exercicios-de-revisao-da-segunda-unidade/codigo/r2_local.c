/* r2_local.c --- devolver o endereco de uma variavel local */
#include <stdio.h>

int *dobro(int x)
{
    int r = 2 * x;
    return &r;          /* r morre com o return */
}

int main(void)
{
    int *p = dobro(21);
    printf("%d\n", *p);
    return 0;
}
