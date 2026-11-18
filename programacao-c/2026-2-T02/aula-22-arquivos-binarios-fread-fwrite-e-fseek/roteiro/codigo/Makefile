CFLAGS = -Wall -Wextra -pedantic

PROGS = conta media pedacos repete cadastro tamanho lista lote consulta precisao

todos: $(PROGS) turma.bin

turma.bin: cadastro turma.csv
	./cadastro

conta media pedacos repete precisao: %: %.c
	gcc $(CFLAGS) $< -o $@

cadastro tamanho lista lote consulta: %: %.c aluno.h
	gcc $(CFLAGS) $< -o $@

limpa:
	rm -f $(PROGS) turma.bin x.txt x.bin

.PHONY: todos limpa
