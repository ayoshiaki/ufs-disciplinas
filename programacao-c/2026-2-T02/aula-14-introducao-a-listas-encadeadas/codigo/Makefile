CFLAGS = -Wall -Wextra -pedantic

todos: lista vetor_vs_lista percorre libera_errada

lista: lista.c
	gcc $(CFLAGS) $< -o $@

vetor_vs_lista: vetor_vs_lista.c
	gcc -O2 $(CFLAGS) $< -o $@

percorre: percorre.c
	gcc -O2 $(CFLAGS) $< -o $@

libera_errada: libera_errada.c
	gcc $(CFLAGS) $< -o $@

libera_errada-asan: libera_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

limpa:
	rm -f lista vetor_vs_lista percorre libera_errada libera_errada-asan

.PHONY: todos limpa
