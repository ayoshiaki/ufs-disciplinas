/* r8_ranking_corrigido.c --- o mesmo calculo dentro do padrao */
#include <stdio.h>

#define RANKING_MEDIA_APROVACAO 7.0

/* Copia para aprovados as medias >= RANKING_MEDIA_APROVACAO.
 * aprovados deve ter espaco para n elementos. Devolve quantas copiou. */
static int ranking_filtra_aprovados(const double *medias, int n,
                                    double *aprovados)
{
    int qtd = 0;
    for (int i = 0; i < n; i++)
        if (medias[i] >= RANKING_MEDIA_APROVACAO)
            aprovados[qtd++] = medias[i];
    return qtd;
}

int main(void)
{
    const double medias[] = { 8.0, 5.5, 7.0, 9.5 };
    const int n = (int)(sizeof medias / sizeof medias[0]);
    double aprovados[sizeof medias / sizeof medias[0]];

    int qtd = ranking_filtra_aprovados(medias, n, aprovados);
    for (int i = 0; i < qtd; i++)
        printf("%.1f ", aprovados[i]);
    printf("\n");
    return 0;
}
