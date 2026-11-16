/* diario.c --- acrescenta uma anotacao ao diario de estudos
   uso: ./diario "estudei fopen" */
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "uso: %s \"anotacao\"\n", argv[0]);
        return 1;
    }
    FILE *f = fopen("diario.txt", "w");
    if (f == NULL) {
        perror("diario.txt");
        return 1;
    }
    fprintf(f, "- %s\n", argv[1]);
    fclose(f);
    return 0;
}
