#include <stdio.h>
#include "estat.h"
#include "turma.h"

int main(void)
{
    double notas[] = { 7.5, 9.0, 4.0 };
    struct Resumo r = turma_resume(notas, 3);
    printf("media %.2f, maior %.1f\n", r.media, r.maior);
    return 0;
}
