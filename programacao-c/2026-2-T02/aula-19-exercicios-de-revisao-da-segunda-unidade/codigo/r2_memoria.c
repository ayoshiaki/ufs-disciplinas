/* r2_memoria.c --- a conta que fica para a volta e o limite da pilha */
#include <stdio.h>
#include <stdlib.h>

/* A: o "1 +" fica pendente em cada registro */
long conta(int n)
{
    if (n == 0)
        return 0;
    return 1 + conta(n - 1);
}

/* B: o parcial desce junto; nada fica para a volta */
long conta_acum(int n, long acc)
{
    if (n == 0)
        return acc;
    return conta_acum(n - 1, acc + 1);
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 100000;
    printf("B: conta_acum(%d) = %ld\n", n, conta_acum(n, 0));
    fflush(stdout);
    printf("A: conta(%d) = %ld\n", n, conta(n));
    return 0;
}
