/* memoria.c --- quanto de memoria a recursao gasta, e onde */
#include <stdio.h>
#include <stdlib.h>
/* A: a soma da aula passada: a adicao fica para a volta */
long soma(const int *v, int n)
{
    if (n == 0)
        return 0;
    return soma(v, n - 1) + v[n - 1];
}

/* B: a mesma soma, levando o parcial na ida: nada fica para a volta */
long soma_acum(const int *v, int n, long parcial)
{
    if (n == 0)
        return parcial;
    return soma_acum(v, n - 1, parcial + v[n - 1]);
}

/* C: Fibonacci que anota cada resultado em uma tabela no heap */
long fib_memo(int n, long *memo)
{
    if (n < 2)
        return n;
    if (memo[n] == 0)
        memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 1000;
    int *v = malloc(n * sizeof *v);         /* o vetor mora no heap */
    long *memo = calloc(91, sizeof *memo);  /* tabela zerada */
    if (v == NULL || memo == NULL) {
        free(v);
        free(memo);
        return 1;
    }
    for (int i = 0; i < n; i++)
        v[i] = 1;
    printf("C: fib(90) = %ld\n", fib_memo(90, memo));
    free(memo);

    printf("B: soma_acum(v, %d) = %ld\n", n, soma_acum(v, n, 0));
    printf("A: soma(v, %d) = %ld\n", n, soma(v, n));
    free(v);
    return 0;
}
