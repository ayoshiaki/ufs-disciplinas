/* pilha.h --- o que o usuario da pilha precisa saber, e nada mais */
#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;   /* os campos ficam no .c */

Pilha *pilha_cria(void);
void pilha_libera(Pilha *p);

void empilha(Pilha *p, int x);
int desempilha(Pilha *p);     /* tira e devolve o topo */
int topo(const Pilha *p);     /* devolve o topo sem tirar */
int vazia(const Pilha *p);

#endif
