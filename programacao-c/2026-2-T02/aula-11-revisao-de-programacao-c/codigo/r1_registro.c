/* r1_registro.c --- quantos bytes ocupa cada registro? */
#include <stdio.h>
#include <stddef.h>

struct Leitura {
    char sensor;
    double valor;
    int codigo;
};

struct LeituraReordenada {
    double valor;
    int codigo;
    char sensor;
};

int main(void)
{
    printf("Leitura: %zu bytes (valor em %zu, codigo em %zu)\n",
           sizeof(struct Leitura), offsetof(struct Leitura, valor),
           offsetof(struct Leitura, codigo));
    printf("LeituraReordenada: %zu bytes\n", sizeof(struct LeituraReordenada));
    return 0;
}
