/* repete.c --- le turma.csv com fscanf, controlando o laco com feof */
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("turma.csv", "r");
    if (f == NULL) {
        perror("turma.csv");
        return 1;
    }
    int mat, n = 0;
    char nome[50];
    double v1, v2, v3, v4;
    while (!feof(f)) {
        fscanf(f, "%d;%49[^;];%lf;%lf;%lf;%lf",
               &mat, nome, &v1, &v2, &v3, &v4);
        n++;
        printf("%d: %d %s\n", n, mat, nome);
    }
    fclose(f);
    return 0;
}
