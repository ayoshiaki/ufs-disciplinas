/* balanco.c --- os parenteses, colchetes e chaves fecham na ordem certa? */
#include <stdio.h>

#define MAX 100

typedef struct {
    char v[MAX];   /* v[0..n-1]: o topo e v[n-1] */
    int n;         /* quantos elementos ha na pilha */
} Pilha;

void empilha(Pilha *p, char c)
{
    p->v[p->n] = c;
    p->n++;
}

char desempilha(Pilha *p)
{
    p->n--;
    return p->v[p->n];
}

int vazia(const Pilha *p)
{
    return p->n == 0;
}

/* 1 se o par (abre, fecha) combina: ( com ), [ com ], { com } */
int combina(char abre, char fecha)
{
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

int balanceada(const char *s)
{
    Pilha p = {.n = 0};
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
            empilha(&p, c);
        else if (c == ')' || c == ']' || c == '}') {
            if (vazia(&p))
                return 0;          /* fechou sem ter aberto */
            if (!combina(desempilha(&p), c))
                return 0;          /* fechou o par errado */
        }
    }
    return vazia(&p);              /* sobrou algum aberto? */
}

int main(void)
{
    const char *testes[] = {
        "v[f(x)] = {1, 2}",
        "([)]",
        "(()",
        "())",
        "",
    };
    for (int i = 0; i < 5; i++)
        printf("%-18s %s\n", testes[i], balanceada(testes[i]) ? "sim" : "nao");
    return 0;
}
