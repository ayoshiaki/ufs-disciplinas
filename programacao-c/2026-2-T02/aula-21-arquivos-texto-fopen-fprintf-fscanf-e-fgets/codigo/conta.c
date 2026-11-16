/* conta.c --- conta linhas, palavras e bytes de um arquivo, como o wc
   uso: ./conta arquivo */
#include <stdio.h>
#include <ctype.h>

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
    int c;                       /* int, nao char: EOF nao e um caractere */
    long linhas = 0, palavras = 0, bytes = 0;
    int dentro = 0;
    while ((c = fgetc(f)) != EOF) {
        bytes++;
        if (c == '\n')
            linhas++;
        if (isspace(c))
            dentro = 0;
        else if (!dentro) {
            dentro = 1;
            palavras++;
        }
    }
    fclose(f);
    printf("%ld %ld %ld %s\n", linhas, palavras, bytes, argv[1]);
    return 0;
}
