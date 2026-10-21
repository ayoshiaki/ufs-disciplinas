CFLAGS = -Wall -Wextra -pedantic

todos: dupla insere_errada remove_errada sentinela remove_fim

dupla: dupla.c
	gcc $(CFLAGS) $< -o $@

insere_errada: insere_errada.c
	gcc $(CFLAGS) $< -o $@

remove_errada: remove_errada.c
	gcc $(CFLAGS) $< -o $@

remove_errada-asan: remove_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

sentinela: sentinela.c
	gcc $(CFLAGS) $< -o $@

remove_fim: remove_fim.c
	gcc -O2 $(CFLAGS) $< -o $@

limpa:
	rm -rf dupla insere_errada remove_errada remove_errada-asan remove_errada-asan.dSYM sentinela remove_fim

.PHONY: todos limpa
