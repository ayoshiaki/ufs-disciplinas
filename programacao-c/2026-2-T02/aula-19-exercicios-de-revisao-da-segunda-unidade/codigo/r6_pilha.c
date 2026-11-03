/* r6_pilha.c --- rastreio de uma pilha, balanceamento e crescimento do vetor */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;      /* v[0..n-1]: o topo e v[n-1] */
    int n;
    int cap;
    int cresceu; /* quantas vezes o vetor aumentou */
} Pilha;

static void *aloca(void *antigo, size_t tam)
{
    void *p = realloc(antigo, tam);
    if (p == NULL) {
        perror("realloc");
        exit(1);
    }
    return p;
}

Pilha *pilha_cria(void)
{
    Pilha *p = aloca(NULL, sizeof *p);
    p->n = 0;
    p->cap = 4;
    p->cresceu = 0;
    p->v = aloca(NULL, p->cap * sizeof *p->v);
    return p;
}

void pilha_libera(Pilha *p)
{
    free(p->v);
    free(p);
}

/* passo = 0: dobra a capacidade; passo > 0: soma passo */
void empilha_com(Pilha *p, int x, int passo)
{
    if (p->n == p->cap) {
        p->cap = (passo == 0) ? 2 * p->cap : p->cap + passo;
        p->v = aloca(p->v, p->cap * sizeof *p->v);
        p->cresceu++;
    }
    p->v[p->n] = x;
    p->n++;
}

void empilha(Pilha *p, int x)
{
    empilha_com(p, x, 0);
}

int desempilha(Pilha *p)
{
    if (p->n == 0) {
        fprintf(stderr, "desempilha: pilha vazia\n");
        exit(1);
    }
    p->n--;
    return p->v[p->n];
}

int topo(const Pilha *p)
{
    if (p->n == 0) {
        fprintf(stderr, "topo: pilha vazia\n");
        exit(1);
    }
    return p->v[p->n - 1];
}

int vazia(const Pilha *p)
{
    return p->n == 0;
}

/* -1 se balanceada; senao, a posicao onde o erro foi notado
   (o tamanho de s, se sobrou algum aberto) */
int primeiro_erro(const char *s)
{
    Pilha *p = pilha_cria();
    int i, erro = -1;
    for (i = 0; s[i] != '\0' && erro < 0; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
            empilha(p, c);
        else if (c == ')' || c == ']' || c == '}') {
            if (vazia(p)) {
                erro = i;
            } else {
                char a = (char) desempilha(p);
                if (!((a == '(' && c == ')') || (a == '[' && c == ']') ||
                      (a == '{' && c == '}')))
                    erro = i;
            }
        }
    }
    if (erro < 0 && !vazia(p))
        erro = i;
    pilha_libera(p);
    return erro;
}

int main(void)
{
    /* (a) */
    Pilha *p = pilha_cria();
    for (int i = 1; i <= 5; i++)
        empilha(p, 10 * i);
    int a = desempilha(p);
    int b = desempilha(p);
    empilha(p, a - b);
    printf("(a) topo: %d\n", topo(p));
    printf("    esvaziando:");
    while (!vazia(p))
        printf(" %d", desempilha(p));
    printf("\n");
    pilha_libera(p);

    /* (b) */
    const char *testes[] = {"{[()()]}", "[(])", "{}("};
    for (int i = 0; i < 3; i++) {
        int e = primeiro_erro(testes[i]);
        if (e < 0)
            printf("(b) %-10s balanceada\n", testes[i]);
        else
            printf("(b) %-10s erro notado na posicao %d\n", testes[i], e);
    }

    /* (c) */
    int passos[] = {0, 4};
    for (int k = 0; k < 2; k++) {
        p = pilha_cria();
        for (int i = 0; i < 100; i++)
            empilha_com(p, i, passos[k]);
        printf("(c) %s: cresceu %d vezes, cap final %d\n",
               passos[k] == 0 ? "dobrando " : "somando 4", p->cresceu, p->cap);
        pilha_libera(p);
    }
    return 0;
}
