/* ponteiro.c --- grava uma struct que tem um ponteiro dentro
   uso: ./ponteiro grava    depois    ./ponteiro le */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contato {
    int   mat;
    char *nome;          /* ponteiro, nao vetor */
};

int main(int argc, char *argv[])
{
    struct contato c;
    if (argc > 1 && strcmp(argv[1], "grava") == 0) {
        c.mat = 202600101;
        c.nome = malloc(50);
        strcpy(c.nome, "Ana Souza");
        FILE *f = fopen("contato.bin", "wb");
        if (f == NULL) {
            perror("contato.bin");
            return 1;
        }
        fwrite(&c, sizeof c, 1, f);
        fclose(f);
        printf("gravei %d %s (%zu bytes)\n", c.mat, c.nome, sizeof c);
        free(c.nome);
    } else {
        FILE *f = fopen("contato.bin", "rb");
        if (f == NULL) {
            perror("contato.bin");
            return 1;
        }
        fread(&c, sizeof c, 1, f);
        fclose(f);
        printf("li %d\n", c.mat);
        printf("nome: %s\n", c.nome);
    }
    return 0;
}
