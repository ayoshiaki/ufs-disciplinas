/* fim.c --- o mesmo laco de boletim.c, controlado por feof */
#include <stdio.h>

int main(void)
{
    FILE *ent = fopen("turma.txt", "r");
    if (ent == NULL) {
        perror("turma.txt");
        return 1;
    }
    int mat, n = 0;
    double v[4];
    while (!feof(ent)) {
        fscanf(ent, "%d %lf %lf %lf %lf",
               &mat, &v[0], &v[1], &v[2], &v[3]);
        n++;
        printf("%d: %d\n", n, mat);
    }
    fclose(ent);
    return 0;
}
