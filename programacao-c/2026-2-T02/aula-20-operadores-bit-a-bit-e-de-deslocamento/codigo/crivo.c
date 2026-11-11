/* crivo.c --- quantos primos ate n? O crivo de Eratostenes com um char por
   numero e com um bit por numero.
   uso: ./crivo [n]      (padrao: n = 100000000) */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* composto[i] = 1 se i nao e primo */
long crivo_char(long n)
{
    char *composto = calloc(n + 1, 1);
    long primos = 0;
    for (long i = 2; i <= n; i++) {
        if (composto[i])
            continue;
        primos++;
        for (long j = i * i; j <= n; j += i)
            composto[j] = 1;
    }
    free(composto);
    return primos;
}

/* o bit i % 32 da palavra v[i / 32] vale 1 se i nao e primo */
#define LIGA(v, i)  ((v)[(i) >> 5] |= 1u << ((i) & 31))
#define TESTA(v, i) (((v)[(i) >> 5] >> ((i) & 31)) & 1u)

long crivo_bits(long n)
{
    unsigned *composto = calloc(n / 32 + 1, sizeof(unsigned));
    long primos = 0;
    for (long i = 2; i <= n; i++) {
        if (TESTA(composto, i))
            continue;
        primos++;
        for (long j = i * i; j <= n; j += i)
            LIGA(composto, j);
    }
    free(composto);
    return primos;
}

int main(int argc, char *argv[])
{
    long n = argc > 1 ? atol(argv[1]) : 100000000;
    clock_t t = clock();
    long p = crivo_char(n);
    printf("char: %ld primos, %6.1f MB, %.2f s\n", p, (n + 1) / 1e6,
           (double) (clock() - t) / CLOCKS_PER_SEC);
    t = clock();
    p = crivo_bits(n);
    printf("bits: %ld primos, %6.1f MB, %.2f s\n", p,
           (n / 32 + 1) * sizeof(unsigned) / 1e6,
           (double) (clock() - t) / CLOCKS_PER_SEC);
    return 0;
}
