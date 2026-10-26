/* balanco_tad.c --- o mesmo teste de balanco.c, usando so pilha.h
   gcc balanco_tad.c pilha_vetor.c   ou   gcc balanco_tad.c pilha_lista.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int combina(int abre, int fecha)
{
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

int balanceada(const char *s)
{
    Pilha *p = pilha_cria();
    int ok = 1;
    for (int i = 0; ok && s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
            empilha(p, c);
        else if (c == ')' || c == ']' || c == '}')
            ok = !vazia(p) && combina(desempilha(p), c);
    }
    ok = ok && vazia(p);
    pilha_libera(p);
    return ok;
}

int main(void)
{
    const char *testes[] = {"v[f(x)] = {1, 2}", "([)]", "(()", "())", ""};
    for (int i = 0; i < 5; i++)
        printf("%-18s %s\n", testes[i], balanceada(testes[i]) ? "sim" : "nao");

    int k = 100000;                    /* k abertos seguidos de k fechados */
    char *s = malloc(2 * k + 1);
    if (s == NULL) {
        perror("malloc");
        return 1;
    }
    memset(s, '(', k);
    memset(s + k, ')', k);
    s[2 * k] = '\0';
    char rotulo[32];
    snprintf(rotulo, sizeof rotulo, "%d niveis", k);
    printf("%-18s %s\n", rotulo, balanceada(s) ? "sim" : "nao");
    free(s);
    return 0;
}
