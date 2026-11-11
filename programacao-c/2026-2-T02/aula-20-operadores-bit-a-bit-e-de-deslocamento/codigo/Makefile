CFLAGS = -Wall -Wextra -pedantic

todos: permissoes decimal precedencia mascaras bytes conjunto crivo

permissoes: permissoes.c
	gcc $(CFLAGS) $< -o $@

decimal: decimal.c
	gcc $(CFLAGS) $< -o $@

precedencia: precedencia.c
	gcc $(CFLAGS) $< -o $@

mascaras: mascaras.c
	gcc $(CFLAGS) $< -o $@

mascaras-ubsan: mascaras.c
	gcc -g -fsanitize=undefined $(CFLAGS) $< -o $@

bytes: bytes.c
	gcc $(CFLAGS) $< -o $@

conjunto: conjunto.c
	gcc $(CFLAGS) $< -o $@

crivo: crivo.c
	gcc -O2 $(CFLAGS) $< -o $@

limpa:
	rm -rf permissoes decimal precedencia mascaras mascaras-ubsan mascaras-ubsan.dSYM bytes conjunto crivo

.PHONY: todos limpa
