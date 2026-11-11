/* mascaras.c --- a mascara do bit k, para k de 28 a 32 */
#include <stdio.h>

int main(void)
{
    for (int k = 28; k <= 32; k++) {
        int m = 1 << k;
        printf("k = %2d: %11d = 0x%08x\n",
               k, m, (unsigned) m);
    }
    return 0;
}
