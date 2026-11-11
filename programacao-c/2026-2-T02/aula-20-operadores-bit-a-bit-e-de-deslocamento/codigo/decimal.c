/* decimal.c --- o modo 754 escrito sem o zero na frente */
#include <stdio.h>

void mostra(unsigned modo)
{
    const char *letras = "rwx";
    for (int i = 8; i >= 0; i--)
        putchar(modo & (1u << i) ? letras[(8 - i) % 3] : '-');
}

int main(void)
{
    unsigned modo = 754;   /* rwxr-xr-- ? */
    printf("%o ", modo);
    mostra(modo);
    putchar('\n');
    return 0;
}
