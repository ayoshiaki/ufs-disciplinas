/* matriz.h --- interface: alocar e liberar matrizes de double */
#ifndef MATRIZ_H
#define MATRIZ_H

double **cria_matriz(int nl, int nc);
void libera_matriz(double **m, int nl);

#endif /* MATRIZ_H */
