/* pedacos.c --- fgets com um buffer pequeno demais */
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("turma.csv", "r");
    if (f == NULL) {
        perror("turma.csv");
        return 1;
    }
    char linha[16];
    int n = 0;
    while (n < 6 && fgets(linha, sizeof linha, f) != NULL) {
        printf("[%s]\n", linha);
        n++;
    }
    fclose(f);
    return 0;
}
