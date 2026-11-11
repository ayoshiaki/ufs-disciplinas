/* bytes.c --- os quatro bytes de um unsigned, na ordem da memoria */
#include <stdio.h>

int main(void)
{
    unsigned x = 0x01020304;
    unsigned char *p = (unsigned char *) &x;
    for (int i = 0; i < 4; i++)
        printf("p[%d] = %02x\n", i, p[i]);
    printf("(x >> 24) & 0xFF = %02x\n", (x >> 24) & 0xFFu);
    return 0;
}
