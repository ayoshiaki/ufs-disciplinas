/* estat.c --- implementacao das estatisticas */
#include <math.h>
#include "estat.h"

double media(const double *v, int n)
{
    double s = 0.0;
    for (int i = 0; i < n; i++)
        s += v[i];
    return n > 0 ? s / n : 0.0;
}

double desvio_padrao(const double *v, int n)
{
    double mu = media(v, n), s = 0.0;
    for (int i = 0; i < n; i++)
        s += (v[i] - mu) * (v[i] - mu);
    return n > 0 ? sqrt(s / n) : 0.0;
}
