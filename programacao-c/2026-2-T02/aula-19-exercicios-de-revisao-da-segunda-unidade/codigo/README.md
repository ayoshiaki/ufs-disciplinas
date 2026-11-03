# Código da aula — exercícios de revisão da segunda unidade

Um programa por rodada. Cada um reproduz o exercício dos slides e imprime o que o gabarito
afirma; os que têm defeito de propósito vêm acompanhados da versão corrigida.

| Rodada | Arquivo | Tema |
|--------|---------|------|
| R1 | `r1_recursao.c` | ida e volta, árvore de chamadas e altura da pilha |
| R2 | `r2_memoria.c`, `r2_local.c` → `r2_local_corrigido.c` | recursão de cauda, limite da pilha, endereço de local |
| R3 | `r3_lista.c`, `r3_libera_errada.c` | inserir no início, `sizeof(No)` e liberar a lista |
| R4 | `r4_remove.c` → `r4_remove_corrigido.c` | os três casos da remoção e o ponteiro para ponteiro |
| R5 | `r5_dupla.c` → `r5_dupla_corrigido.c` | os quatro ponteiros da inserção e o `fim` esquecido |
| R6 | `r6_pilha.c` | rastreio, balanceamento e quantas vezes o vetor cresce |
| R7 | `r7_fila.c`, `r7_dobra_errada.c` | fila circular com `ini` e `n` e por que não basta `realloc` |

R8 é de síntese (escolher a estrutura e preencher a tabela de custos): não tem programa.

```
make                     # compila tudo
./r1
./r2 100000; ./r2 1000000      # o segundo estoura a pilha
./r4 20; ./r4 10; ./r4 99      # so o primeiro funciona
./r3_libera_errada             # compilado com AddressSanitizer
./r5                           # idem: o erro aparece no imprime, nao no remove_no
```
