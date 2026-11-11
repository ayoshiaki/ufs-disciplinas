/* precedencia.c --- quem pode escrever? */
#include <stdio.h>

#define W 2u

/* devolve 1 se a classe (6 = dono, 3 = grupo, 0 = outros) NAO pode escrever */
int nao_escreve(unsigned modo, int classe)
{
    if (modo & W << classe == 0)
        return 1;
    return 0;
}

int main(void)
{
    unsigned modos[] = {0644, 0664, 0444};
    for (int i = 0; i < 3; i++)
        printf("%03o: dono %s, grupo %s\n", modos[i],
               nao_escreve(modos[i], 6) ? "nao escreve" : "escreve",
               nao_escreve(modos[i], 3) ? "nao escreve" : "escreve");
    return 0;
}
