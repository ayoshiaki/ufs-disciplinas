/* r1_recursao.c --- o que se imprime na ida e na volta, e quantas chamadas */
#include <stdio.h>

void f(int n)
{
    if (n <= 0)
        return;
    printf("%d ", n);      /* na ida */
    f(n - 2);
    printf("%d ", n);      /* na volta */
}

static int chamadas = 0;   /* quantas vezes g foi chamada */
static int nivel = 0;      /* quantos registros de g estao na pilha agora */
static int pico = 0;       /* o maior valor que nivel atingiu */

int g(int n)
{
    chamadas++;
    nivel++;
    if (nivel > pico)
        pico = nivel;
    int r;
    if (n < 2)
        r = 1;
    else
        r = g(n - 1) + g(n - 2);
    nivel--;
    return r;
}

int main(void)
{
    printf("(a) f(5): ");
    f(5);
    printf("\n");
    int r = g(4);
    printf("(b) g(4) = %d, com %d chamadas\n", r, chamadas);
    printf("(c) no maximo %d registros de g ao mesmo tempo\n", pico);
    return 0;
}
