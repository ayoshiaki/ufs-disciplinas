/* conta.c --- le um arquivo caractere a caractere
   uso: ./conta arquivo */
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "uso: %s arquivo\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror(argv[1]);
        return 1;
    }
    int c;                       /* int, nao char: precisa caber EOF */
    long ncar = 0, nlin = 0;
    while ((c = fgetc(f)) != EOF) {
        ncar++;
        if (c == '\n')
            nlin++;
    }
    fclose(f);
    printf("%ld caracteres, %ld linhas\n", ncar, nlin);
    return 0;
}
