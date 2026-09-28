# Código da aula — revisão de Programação C

Um programa por rodada da revisão. Cada um reproduz o exercício dos slides e imprime o que o
gabarito afirma; compile com `gcc -Wall -Wextra` e confira.

| Rodada | Arquivo | Tema |
|--------|---------|------|
| R1 | `r1_registro.c` | `sizeof`, `offsetof` e alinhamento de registros |
| R2 | `r2_enum.c`, `r2_typedef.c` | valores de `enum` e o que `typedef` não garante |
| R3 | `r3_ponteiros.c` | ponteiros e aritmética sobre vetor |
| R4 | `r4_vetores.c` | vetores, strings e parâmetros |
| R5 | `r5_alocacao.c` → `r5_alocacao_corrigido.c` | os quatro erros de alocação dinâmica |
| R6 | `r6_matriz.c` | matriz em bloco único e ordem de liberação |
| R7 | `r7/` | guardas de inclusão, ligação e `static` |
| R8 | `r8_ranking.c` → `r8_ranking_corrigido.c` | padrões de codificação |

```
gcc -Wall -Wextra r1_registro.c -o r1 && ./r1
gcc -Wall -Wextra -g -fsanitize=address r5_alocacao.c -o r5 && ./r5
gcc -Wall -Wextra r7/*.c -o r7/turma   # falha de propósito: é o exercício (a)
```

Em R7 o erro é a resposta: o projeto não compila até que se corrijam, em ordem, a guarda de
inclusão que falta, o `estat.c` fora da ligação e a `troca` sem `static`.
