/* r3_ponteiros.c --- rastreie antes de rodar */
#include <stdio.h>

int main(void)
{
    int v[] = { 10, 20, 30, 40 };
    int *p = v + 1;
    int x = 5;
    int *q = &x;

    *q = *p + 1;
    p += 2;
    *p = x * 2;

    printf("%d %d %d %td\n", x, v[3], *(v + 2), p - v);
    return 0;
}
