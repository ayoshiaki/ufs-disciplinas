/* gorda.c --- um vetor local em cada nivel da recursao */
#include <stdio.h>
#include <stdlib.h>

int desce(int n)
{
    char linha[4096];                   /* 4 KB em CADA registro */
    linha[0] = (char) n;
    if (n == 0)
        return linha[0];
    return desce(n - 1) + linha[0];
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 100;
    printf("desce(%d) = %d\n", n, desce(n));
    return 0;
}
