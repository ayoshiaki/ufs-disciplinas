/* invertida.c --- malloc em cada chamada: quem libera, e quando? */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long vivos = 0, pico = 0;        /* bytes no heap agora e no maximo */

static char *aloca(size_t t)
{
    vivos += (long) t;
    if (vivos > pico)
        pico = vivos;
    return malloc(t);
}

static void libera(char *s)
{
    vivos -= (long) strlen(s) + 1;
    free(s);
}

/* devolve uma copia de s de tras para frente, alocada no heap */
char *invertida(const char *s)
{
    if (*s == '\0') {                   /* caso base: string vazia */
        char *r = aloca(1);
        r[0] = '\0';
        return r;
    }
    char *resto = invertida(s + 1);     /* o resto, ja' invertido */
    size_t k = strlen(resto);
    char *r = aloca(k + 2);
    strcpy(r, resto);                   /* o resto invertido...   */
    r[k] = *s;                          /* ...e a minha letra     */
    r[k + 1] = '\0';
    libera(resto);                      /* na volta: resto ja' nao serve */
    return r;
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 10;
    char *s = malloc(n + 1);
    for (int i = 0; i < n; i++)
        s[i] = 'a' + i % 26;
    s[n] = '\0';

    char *r = invertida(s);
    printf("%.10s... (%zu letras)\n", r, strlen(r));
    printf("no heap agora: %ld bytes; pico: %ld bytes\n", vivos, pico);
    libera(r);
    free(s);
    return 0;
}
