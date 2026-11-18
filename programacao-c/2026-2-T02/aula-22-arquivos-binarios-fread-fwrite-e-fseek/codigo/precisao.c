/* precisao.c --- o mesmo double gravado como texto e como bytes */
#include <stdio.h>

int main(void)
{
    double x = 1.0 / 3.0, lido_t, lido_b;

    FILE *ft = fopen("x.txt", "w");
    FILE *fb = fopen("x.bin", "wb");
    if (ft == NULL || fb == NULL) {
        perror("x.txt/x.bin");
        return 1;
    }
    fprintf(ft, "%f", x);              /* texto: caracteres */
    fwrite(&x, sizeof x, 1, fb);       /* binario: os bytes de x */
    fclose(ft);
    fclose(fb);

    ft = fopen("x.txt", "r");
    fb = fopen("x.bin", "rb");
    if (ft == NULL || fb == NULL) {
        perror("x.txt/x.bin");
        return 1;
    }
    fscanf(ft, "%lf", &lido_t);
    fread(&lido_b, sizeof lido_b, 1, fb);
    fclose(ft);
    fclose(fb);

    printf("texto:   %.17f  %s\n", lido_t, lido_t == x ? "igual" : "diferente");
    printf("binario: %.17f  %s\n", lido_b, lido_b == x ? "igual" : "diferente");
    return 0;
}
