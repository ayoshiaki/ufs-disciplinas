#include "turma.h"

void troca(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

struct Resumo turma_resume(const double *v, int n)
{
    struct Resumo r = { estat_media(v, n), v[0] };
    for (int i = 1; i < n; i++)
        if (v[i] > r.maior)
            r.maior = v[i];
    return r;
}
