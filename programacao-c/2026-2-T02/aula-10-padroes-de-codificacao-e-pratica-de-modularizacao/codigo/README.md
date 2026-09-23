# Código da aula — padrões de codificação

O projeto é o mesmo das aulas anteriores (`matriz`, `estat`, `turma`, `main`), acrescido de um
módulo novo: o `ranking`, que classifica os alunos pela média.

## `antes/`

O `ranking.c` como ele chega na aula: funciona, roda e acerta — e ainda assim carrega quase
tudo que um padrão de codificação existe para evitar.

```
make        # compila com 2 avisos
./notas
nm ranking.o | grep -E ' (T|D|B|S|C) '   # tudo vazou: _troca, _maior, _R, _Q, _N
```

Para a turma de 60 alunos (o estouro de `R[50]`), o que acontece **depende do compilador**: onde
clang/macOS escreve por cima de `Q` (medias `0.00` nas ultimas colocacoes), gcc/Linux com
`-fno-common` escreve por cima de `N` (a contagem vira 50). Nao adianta prometer um desfecho: o
comportamento e indefinido. Para torna-lo visivel e deterministico:

```
gcc -w -g -fno-common -fsanitize=address main60.c turma.c matriz.c estat.c ranking.c -o notas60 -lm
./notas60   # AddressSanitizer: global-buffer-overflow ... WRITE of size 8 ... ranking.c:19
```

O `-fno-common` e obrigatorio aqui: o sanitizador nao instrumenta variaveis globais que entram
no objeto como *tentative definition* (as que o `nm` mostra na coluna `C`).

O que está errado: três variáveis globais no lugar de estado passado por parâmetro; nomes de
uma letra (`R`, `Q`, `N`); `calcula`/`mostra` sem prefixo de módulo; o limite `50` e a nota de
corte `7.0` como números soltos; nenhum `.h`, com as assinaturas copiadas à mão no `main.c`;
funções auxiliares sem `static`; indentação misturando tabulação e espaço; um parâmetro
(`flag`) e uma variável (`tmp`) que ninguém usa.

## `depois/`

O mesmo módulo no padrão, com `ranking.h` como contrato, estado na `struct Ranking` alocada
conforme o tamanho da turma, `static` no que é interno e `const` em quem só lê.

```
make        # -std=c17 -Wall -Wextra -Werror -pedantic, sem um aviso
./notas     # saida identica a de antes/
make formato   # clang-format -i *.c *.h
```

A saída dos dois é igual **byte por byte** (`diff <(antes/notas) <(depois/notas)` não acusa
nada): o que muda é quem consegue manter o código.
