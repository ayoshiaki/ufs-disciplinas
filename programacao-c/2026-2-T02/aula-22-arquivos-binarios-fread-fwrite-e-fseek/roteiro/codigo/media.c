/* media.c --- le turma.csv linha a linha e calcula a media de cada aluno */
#include <stdio.h>

#define TAM 256

int main(void)
{
    FILE *f = fopen("turma.csv", "r");
    if (f == NULL) {
        perror("turma.csv");
        return 1;
    }
    char linha[TAM];
    int mat, nl = 0;
    char nome[50];
    double v1, v2, v3, v4;
    while (fgets(linha, sizeof linha, f) != NULL) {
        nl++;
        if (sscanf(linha, "%d;%49[^;];%lf;%lf;%lf;%lf",
                   &mat, nome, &v1, &v2, &v3, &v4) != 6) {
            fprintf(stderr, "linha %d ignorada\n", nl);
            continue;
        }
        printf("%d %-22s %5.2f\n", mat, nome, (v1 + v2 + v3 + v4) / 4);
    }
    fclose(f);
    return 0;
}
