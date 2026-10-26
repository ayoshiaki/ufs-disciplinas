CFLAGS = -Wall -Wextra -pedantic

todos: balanco balanco_errada transborda balanco_vetor balanco_lista crescimento vetor_vs_lista

balanco: balanco.c
	gcc $(CFLAGS) $< -o $@

balanco_errada: balanco_errada.c
	gcc $(CFLAGS) $< -o $@

balanco_errada-asan: balanco_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

transborda: transborda.c
	gcc $(CFLAGS) $< -o $@

balanco_vetor: balanco_tad.c pilha_vetor.c pilha.h
	gcc $(CFLAGS) balanco_tad.c pilha_vetor.c -o $@

balanco_lista: balanco_tad.c pilha_lista.c pilha.h
	gcc $(CFLAGS) balanco_tad.c pilha_lista.c -o $@

crescimento: crescimento.c
	gcc -O2 $(CFLAGS) $< -o $@

vetor_vs_lista: vetor_vs_lista.c
	gcc -O2 $(CFLAGS) $< -o $@

limpa:
	rm -rf balanco balanco_errada balanco_errada-asan balanco_errada-asan.dSYM transborda balanco_vetor balanco_lista crescimento vetor_vs_lista

.PHONY: todos limpa
