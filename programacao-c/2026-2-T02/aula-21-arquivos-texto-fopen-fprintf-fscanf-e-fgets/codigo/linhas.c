/* linhas.c --- le turma.csv linha a linha, com um buffer pequeno */
#include <stdio.h>

int main(void)
{
    FILE *ent = fopen("turma.csv", "r");
    if (ent == NULL) {
        perror("turma.csv");
        return 1;
    }
    char linha[24];
    while (fgets(linha, sizeof linha, ent) != NULL)
        printf("[%s]\n", linha);
    fclose(ent);
    return 0;
}
