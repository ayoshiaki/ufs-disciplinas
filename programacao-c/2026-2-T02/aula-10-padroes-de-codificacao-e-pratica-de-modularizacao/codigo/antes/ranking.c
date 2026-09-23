#include <stdio.h>
#include <stdlib.h>
#include "turma.h"
#include "estat.h"

double R[50];
int Q[50];
int N;

void troca(int a,int b){int t=Q[a];Q[a]=Q[b];Q[b]=t;}

int maior(double x,double y){ return x>y; }

void calcula(Turma *t, int flag)
{
  double tmp;
  N = t->nalunos;
  for(int i=0;i<N;i++){
  R[i]=media(t->notas[i],t->navaliacoes);
    Q[i]=i;                 /* guarda o indice i em Q[i] */
  }
	for(int i=0;i<N;i++)
		for(int j=0;j<N-1;j++)
			if(maior(R[Q[j+1]],R[Q[j]])) troca(j,j+1);
}

void mostra()
{
    printf("%-5s %-8s %8s %s\n","pos","aluno","media","situacao");
  for(int i=0;i<N;i++){
    printf("%-5d %-8d %8.2f %s\n", i+1, Q[i], R[Q[i]], R[Q[i]]>=7.0?"aprovado":"reprovado");
  }
}
