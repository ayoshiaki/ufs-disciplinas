/* r8_ranking.c --- funciona, mas nao passa na revisao */
#include <stdio.h>

int n, k;
double R[50];

void calc(double *v)
{
    k = 0;
    for (int i = 0; i < n; i++)
        if (v[i] >= 7.0)
            R[k++] = v[i];
}

int main(void)
{
    double medias[] = { 8.0, 5.5, 7.0, 9.5 };
    n = 4;
    calc(medias);
    for (int i = 0; i < k; i++)
        printf("%.1f ", R[i]);
    printf("\n");
    return 0;
}
