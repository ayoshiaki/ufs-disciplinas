CFLAGS = -Wall -Wextra -pedantic

PROGS = precisao cadastro lista consulta corrige corrige_rb ponteiro

todos: $(PROGS)

precisao: precisao.c
	gcc $(CFLAGS) $< -o $@

ponteiro: ponteiro.c
	gcc $(CFLAGS) $< -o $@

cadastro lista consulta corrige corrige_rb: %: %.c aluno.h
	gcc $(CFLAGS) $< -o $@

limpa:
	rm -f $(PROGS) x.txt x.bin turma.bin contato.bin core

.PHONY: todos limpa
