/* tamanho.c --- quantos bytes ocupa cada campo de struct aluno */
#include <stdio.h>
#include <stddef.h>
#include "aluno.h"

int main(void)
{
    printf("mat  em %2zu, ocupa %zu\n", offsetof(struct aluno, mat),
           sizeof(int));
    printf("nome em %2zu, ocupa %zu\n", offsetof(struct aluno, nome),
           sizeof(char[50]));
    printf("v    em %2zu, ocupa %zu\n", offsetof(struct aluno, v),
           sizeof(double[NAV]));
    printf("sizeof(struct aluno) = %zu\n", sizeof(struct aluno));
    return 0;
}
