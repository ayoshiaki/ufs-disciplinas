/* permissoes.c --- le um modo Unix em octal e aplica ordens como as do chmod
   uso: ./permissoes                  (exemplos)
        ./permissoes 754 u-x go+w     (um modo e uma ou mais ordens) */
#include <stdio.h>
#include <stdlib.h>

/* nove bits: rwx do dono (u), rwx do grupo (g), rwx dos outros (o) */
#define R 4u
#define W 2u
#define X 1u

/* imprime os nove bits como o ls -l: rwxr-xr-- */
void mostra(unsigned modo)
{
    const char *letras = "rwx";
    for (int i = 8; i >= 0; i--)
        putchar(modo & (1u << i) ? letras[(8 - i) % 3] : '-');
}

/* aplica uma ordem como "u+x", "go-w" ou "a+r" e devolve o novo modo */
unsigned aplica(unsigned modo, const char *ordem)
{
    unsigned quem = 0, bits = 0, mascara = 0;
    const char *p = ordem;

    for (; *p == 'u' || *p == 'g' || *p == 'o' || *p == 'a'; p++)
        quem |= *p == 'u' ? 4u : *p == 'g' ? 2u : *p == 'o' ? 1u : 7u;
    char op = *p++;
    for (; *p != '\0'; p++)
        bits |= *p == 'r' ? R : *p == 'w' ? W : *p == 'x' ? X : 0u;

    if (quem & 4u) mascara |= bits << 6;   /* dono   */
    if (quem & 2u) mascara |= bits << 3;   /* grupo  */
    if (quem & 1u) mascara |= bits;        /* outros */

    if (op == '+')
        modo |= mascara;
    else if (op == '-')
        modo &= ~mascara;
    else
        fprintf(stderr, "ordem invalida: %s\n", ordem);
    return modo;
}

void mostra_linha(unsigned modo)
{
    printf("%03o ", modo);
    mostra(modo);
    putchar('\n');
}

int main(int argc, char *argv[])
{
    unsigned modo = 0644;
    const char *exemplo[] = {"u+x", "go+w", "a-r", "o+rwx"};
    int n = 4;
    const char **ordens = exemplo;

    if (argc >= 2) {
        modo = strtoul(argv[1], NULL, 8);   /* le em base 8 */
        ordens = (const char **) argv + 2;
        n = argc - 2;
    }
    printf("%-6s", "");
    mostra_linha(modo);
    for (int i = 0; i < n; i++) {
        modo = aplica(modo, ordens[i]);
        printf("%-6s", ordens[i]);
        mostra_linha(modo);
    }
    return 0;
}
