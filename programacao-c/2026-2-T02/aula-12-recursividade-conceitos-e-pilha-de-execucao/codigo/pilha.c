/* pilha.c --- o que acontece a cada chamada de uma funcao recursiva */
#include <stdio.h>

/* A: fatorial, contando o que acontece na ida e na volta */
long fatorial(int n)
{
    static int nivel = 0;   /* static: um so para todas as chamadas */
    printf("%*sfatorial(%d) comeca   &n = %p\n", 2 * nivel, "", n,
           (void *) &n);
    nivel++;
    long resultado;
    if (n <= 1)
        resultado = 1;                      /* caso base */
    else
        resultado = n * fatorial(n - 1);    /* passo recursivo */
    nivel--;
    printf("%*sfatorial(%d) devolve %ld\n", 2 * nivel, "", n, resultado);
    return resultado;
}

/* B: o que se faz antes e depois da chamada */
void desce_e_sobe(int n)
{
    if (n == 0)
        return;
    printf("%d ", n);       /* antes da chamada */
    desce_e_sobe(n - 1);
    printf("%d ", n);       /* depois da chamada */
}

/* C: uma funcao que chama a si mesma duas vezes */
long fib(int n, int *chamadas)
{
    (*chamadas)++;
    if (n < 2)
        return n;
    return fib(n - 1, chamadas) + fib(n - 2, chamadas);
}

/* D: a soma de um vetor e' o ultimo mais a soma do resto */
int soma(const int *v, int n)
{
    if (n == 0)
        return 0;
    return soma(v, n - 1) + v[n - 1];
}

int main(void)
{
    printf("A: 4! = %ld\n", fatorial(4));

    printf("B: ");
    desce_e_sobe(3);
    printf("\n");

    int chamadas = 0;
    long f = fib(5, &chamadas);
    printf("C: fib(5) = %ld com %d chamadas\n", f, chamadas);
    chamadas = 0;
    f = fib(20, &chamadas);
    printf("C: fib(20) = %ld com %d chamadas\n", f, chamadas);

    int v[] = {3, 1, 4, 1, 5};
    printf("D: soma = %d\n", soma(v, 5));
    return 0;
}
