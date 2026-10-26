/* transborda.c --- a pilha de balanco.c com mais de MAX abertos */
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

int main(void)
{
    int niveis[] = {99, 100, 101, 150};
    for (int i = 0; i < 4; i++) {
        Pilha p = {.n = 0};
        int k = niveis[i], fechou = 0;
        for (int j = 0; j < k; j++)          /* k vezes '(' ... */
            empilha(&p, '(');
        printf("%3d abertos: n = %3d", k, p.n);
        while (!vazia(&p) && fechou < k) {   /* ... e k vezes ')' */
            desempilha(&p);
            fechou++;
        }
        printf(", fechou %3d -> %s\n", fechou,
               fechou == k && vazia(&p) ? "sim" : "nao");
    }
    return 0;
}
