/* boletim.c --- le as notas de turma.txt e escreve boletim.txt
   uso: ./boletim                         (turma.txt -> boletim.txt)
        ./boletim entrada.txt saida.txt */
#include <stdio.h>

#define NAV 4   /* avaliacoes por aluno */

int main(int argc, char *argv[])
{
    const char *nome_ent = argc > 1 ? argv[1] : "turma.txt";
    const char *nome_sai = argc > 2 ? argv[2] : "boletim.txt";

    FILE *ent = fopen(nome_ent, "r");
    if (ent == NULL) {
        perror(nome_ent);
        return 1;
    }
    FILE *sai = fopen(nome_sai, "w");
    if (sai == NULL) {
        perror(nome_sai);
        fclose(ent);
        return 1;
    }

    int mat, n = 0, aprovados = 0;
    double v[NAV];
    while (fscanf(ent, "%d %lf %lf %lf %lf",
                  &mat, &v[0], &v[1], &v[2], &v[3]) == 5) {
        double m = (v[0] + v[1] + v[2] + v[3]) / NAV;
        fprintf(sai, "%d %5.2f %s\n", mat, m,
                m >= 5.0 ? "aprovado" : "reprovado");
        n++;
        if (m >= 5.0) aprovados++;
    }
    fclose(ent);
    fclose(sai);

    printf("%d alunos lidos de %s, %d aprovados\n", n, nome_ent, aprovados);
    printf("boletim gravado em %s\n", nome_sai);
    return 0;
}
