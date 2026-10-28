/* fila.h --- o que o usuario da fila precisa saber, e nada mais */
#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;     /* os campos ficam no .c */

Fila *fila_cria(void);
void fila_libera(Fila *f);

void enfileira(Fila *f, int x);   /* entra no fim */
int desenfileira(Fila *f);        /* sai da frente */
int frente(const Fila *f);        /* devolve a frente sem tirar */
int vazia(const Fila *f);
int tamanho(const Fila *f);

#endif
