CFLAGS = -Wall -Wextra -pedantic

todos: batata batata_circular dobra_errada batata_vetor batata_lista esvazia custo

batata: batata.c
	gcc $(CFLAGS) $< -o $@

batata_circular: batata_circular.c
	gcc $(CFLAGS) $< -o $@

dobra_errada: dobra_errada.c
	gcc $(CFLAGS) $< -o $@

dobra_errada-asan: dobra_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

batata_vetor: batata_tad.c fila_vetor.c fila.h
	gcc $(CFLAGS) batata_tad.c fila_vetor.c -o $@

batata_lista: batata_tad.c fila_lista.c fila.h
	gcc $(CFLAGS) batata_tad.c fila_lista.c -o $@

esvazia: esvazia.c
	gcc $(CFLAGS) $< -o $@

esvazia-asan: esvazia.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

custo: custo.c
	gcc -O2 $(CFLAGS) $< -o $@

limpa:
	rm -rf batata batata_circular dobra_errada dobra_errada-asan dobra_errada-asan.dSYM batata_vetor batata_lista esvazia esvazia-asan esvazia-asan.dSYM custo

.PHONY: todos limpa
