/* r2_enum.c --- que numeros o compilador atribuiu? */
#include <stdio.h>

enum Cor { VERMELHO, VERDE = 5, AZUL, NUM_CORES };

int main(void)
{
    enum Cor c = 42;            /* (b) compila? */
    printf("%d %d %d %d\n", VERMELHO, VERDE, AZUL, NUM_CORES);
    printf("c = %d\n", c);
    return 0;
}
