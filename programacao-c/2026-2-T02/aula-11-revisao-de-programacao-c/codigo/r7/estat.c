#include "estat.h"

double estat_media(const double *v, int n)
{
    double soma = 0.0;
    for (int i = 0; i < n; i++)
        soma += v[i];
    return soma / n;
}

void troca(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}
