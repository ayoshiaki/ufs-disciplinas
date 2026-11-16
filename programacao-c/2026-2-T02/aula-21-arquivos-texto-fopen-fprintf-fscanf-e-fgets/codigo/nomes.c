/* nomes.c --- tenta ler turma.csv com fscanf e %s */
#include <stdio.h>

int main(void)
{
    FILE *ent = fopen("turma.csv", "r");
    if (ent == NULL) {
        perror("turma.csv");
        return 1;
    }
    int mat, r;
    char nome[50];
    double v[4];
    while ((r = fscanf(ent, "%d;%49s;%lf;%lf;%lf;%lf", &mat, nome,
                       &v[0], &v[1], &v[2], &v[3])) == 6)
        printf("%d %s\n", mat, nome);
    printf("fscanf devolveu %d; nome = \"%s\"\n", r, nome);
    fclose(ent);
    return 0;
}
