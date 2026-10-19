CFLAGS = -Wall -Wextra -pedantic

todos: lista busca_errada remove_errada ponteiro_duplo fim_vs_inicio

lista: lista.c
	gcc $(CFLAGS) $< -o $@

busca_errada: busca_errada.c
	gcc $(CFLAGS) $< -o $@

busca_errada-O2: busca_errada.c
	gcc -O2 $(CFLAGS) $< -o $@

remove_errada: remove_errada.c
	gcc $(CFLAGS) $< -o $@

remove_errada-asan: remove_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

ponteiro_duplo: ponteiro_duplo.c
	gcc $(CFLAGS) $< -o $@

fim_vs_inicio: fim_vs_inicio.c
	gcc -O2 $(CFLAGS) $< -o $@

limpa:
	rm -rf lista busca_errada busca_errada-O2 remove_errada remove_errada-asan remove_errada-asan.dSYM ponteiro_duplo fim_vs_inicio

.PHONY: todos limpa
