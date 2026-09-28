/* r4_vetores.c --- o que se perde ao entrar na funcao */
#include <stdio.h>
#include <string.h>

void f(int v[10])
{
    printf("B: %zu\n", sizeof(v));
}

int main(void)
{
    int a[10];
    char s[20] = "prova";

    printf("A: %zu %zu %zu\n", sizeof(a), sizeof(s), strlen(s));
    f(a);
    s[2] = '\0';
    printf("C: %s %zu\n", s, strlen(s));
    return 0;
}
