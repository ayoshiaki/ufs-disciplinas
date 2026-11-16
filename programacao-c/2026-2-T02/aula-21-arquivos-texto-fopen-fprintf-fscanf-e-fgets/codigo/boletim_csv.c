/* boletim_csv.c --- le turma.csv (com nomes) e escreve boletim.csv
   uso: ./boletim_csv                         (turma.csv -> boletim.csv)
        ./boletim_csv entrada.csv saida.csv */
#include <stdio.h>
#include <string.h>

#define NAV 4

int main(int argc, char *argv[])
{
    const char *nome_ent = argc > 1 ? argv[1] : "turma.csv";
    const char *nome_sai = argc > 2 ? argv[2] : "boletim.csv";

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

    char linha[256], nome[50];
    int mat, nlinha = 0, n = 0;
    double v[NAV];
    while (fgets(linha, sizeof linha, ent) != NULL) {
        nlinha++;
        linha[strcspn(linha, "\n")] = '\0';      /* tira o '\n' */
        if (sscanf(linha, "%d;%49[^;];%lf;%lf;%lf;%lf", &mat, nome,
                   &v[0], &v[1], &v[2], &v[3]) != 6) {
            fprintf(stderr, "%s:%d: linha ignorada: \"%s\"\n",
                    nome_ent, nlinha, linha);
            continue;
        }
        double m = (v[0] + v[1] + v[2] + v[3]) / NAV;
        fprintf(sai, "%d;%s;%.2f;%s\n", mat, nome, m,
                m >= 5.0 ? "aprovado" : "reprovado");
        n++;
    }
    fclose(ent);
    fclose(sai);

    printf("%d alunos gravados em %s\n", n, nome_sai);
    return 0;
}
