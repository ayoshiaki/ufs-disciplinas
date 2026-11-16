/* sem_teste.c --- o mesmo laco, sem testar o retorno de fopen */
#include <stdio.h>

int main(void)
{
    FILE *ent = fopen("turmas.txt", "r");   /* o nome tem um 's' a mais */
    int mat, n = 0;
    double v[4];
    while (fscanf(ent, "%d %lf %lf %lf %lf",
                  &mat, &v[0], &v[1], &v[2], &v[3]) == 5)
        n++;
    printf("%d alunos lidos\n", n);
    fclose(ent);
    return 0;
}
