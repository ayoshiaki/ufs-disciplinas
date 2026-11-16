/* queda.c --- o programa grava tres linhas e cai antes do fclose */
#include <stdio.h>
#include <signal.h>

int main(void)
{
    FILE *f = fopen("log.txt", "w");
    if (f == NULL) {
        perror("log.txt");
        return 1;
    }
    for (int i = 1; i <= 3; i++)
        fprintf(f, "passo %d concluido\n", i);
    fprintf(stderr, "3 passos registrados em log.txt\n");

    raise(SIGSEGV);    /* simula um segmentation fault: o fclose nunca acontece */

    fclose(f);
    return 0;
}
