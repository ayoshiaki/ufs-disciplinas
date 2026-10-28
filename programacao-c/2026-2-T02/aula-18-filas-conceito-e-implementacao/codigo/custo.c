/* custo.c --- a roda com n criancas e k = 1 em tres filas:
   vetor que desloca tudo a cada saida, vetor circular que dobra e lista.
   uso: ./custo n */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double agora(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec / 1e9;
}

static void *aloca(void *antigo, size_t tam)
{
    void *p = realloc(antigo, tam);
    if (p == NULL) {
        perror("realloc");
        exit(1);
    }
    return p;
}

/* --- vetor que desloca: a frente e sempre v[0] --- */
typedef struct {
    int *v;
    int n;
} FilaD;

static void enfileira_d(FilaD *f, int x)
{
    f->v[f->n++] = x;
}

static int desenfileira_d(FilaD *f)
{
    int x = f->v[0];
    for (int i = 1; i < f->n; i++)     /* todos andam uma casa */
        f->v[i - 1] = f->v[i];
    f->n--;
    return x;
}

/* --- vetor circular que dobra --- */
typedef struct {
    int *v;
    int ini, n, cap;
} FilaC;

static void enfileira_c(FilaC *f, int x)
{
    if (f->n == f->cap) {
        int *novo = aloca(NULL, 2 * f->cap * sizeof *novo);
        for (int i = 0; i < f->n; i++)
            novo[i] = f->v[(f->ini + i) % f->cap];
        free(f->v);
        f->v = novo;
        f->ini = 0;
        f->cap *= 2;
    }
    f->v[(f->ini + f->n) % f->cap] = x;
    f->n++;
}

static int desenfileira_c(FilaC *f)
{
    int x = f->v[f->ini];
    f->ini = (f->ini + 1) % f->cap;
    f->n--;
    return x;
}

/* --- lista: sai do primeiro no, entra depois do ultimo --- */
typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct {
    No *ini, *fim;
    int n;
} FilaL;

static void enfileira_l(FilaL *f, int x)
{
    No *novo = aloca(NULL, sizeof *novo);
    novo->valor = x;
    novo->prox = NULL;
    if (f->fim == NULL)
        f->ini = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
    f->n++;
}

static int desenfileira_l(FilaL *f)
{
    No *velho = f->ini;
    int x = velho->valor;
    f->ini = velho->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(velho);
    f->n--;
    return x;
}

int main(int argc, char *argv[])
{
    int n = (argc > 1) ? atoi(argv[1]) : 20000;
    int fd, fc, fl;

    double t0 = agora();
    FilaD d = {aloca(NULL, n * sizeof(int)), 0};
    for (int i = 1; i <= n; i++) enfileira_d(&d, i);
    while (d.n > 1) {
        enfileira_d(&d, desenfileira_d(&d));
        desenfileira_d(&d);
    }
    fd = desenfileira_d(&d);
    free(d.v);
    double t1 = agora();

    FilaC c = {aloca(NULL, 4 * sizeof(int)), 0, 0, 4};
    for (int i = 1; i <= n; i++) enfileira_c(&c, i);
    while (c.n > 1) {
        enfileira_c(&c, desenfileira_c(&c));
        desenfileira_c(&c);
    }
    fc = desenfileira_c(&c);
    free(c.v);
    double t2 = agora();

    FilaL l = {NULL, NULL, 0};
    for (int i = 1; i <= n; i++) enfileira_l(&l, i);
    while (l.n > 1) {
        enfileira_l(&l, desenfileira_l(&l));
        desenfileira_l(&l);
    }
    fl = desenfileira_l(&l);
    double t3 = agora();

    printf("n = %d: desloca %.4f s  circular %.4f s  lista %.4f s  (fica %d %d %d)\n",
           n, t1 - t0, t2 - t1, t3 - t2, fd, fc, fl);
    return 0;
}
