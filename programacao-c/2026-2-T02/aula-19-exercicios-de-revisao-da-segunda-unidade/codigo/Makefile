CFLAGS = -Wall -Wextra -pedantic

todos: r1 r2 r2_local r2_local_corrigido r3 r3_libera_errada r4 r4_corrigido \
       r5 r5_corrigido r6 r7 r7_dobra_errada

r1: r1_recursao.c
	gcc $(CFLAGS) $< -o $@

r2: r2_memoria.c
	gcc $(CFLAGS) $< -o $@

r2_local: r2_local.c
	gcc $(CFLAGS) $< -o $@

r2_local_corrigido: r2_local_corrigido.c
	gcc $(CFLAGS) $< -o $@

r3: r3_lista.c
	gcc $(CFLAGS) $< -o $@

r3_libera_errada: r3_libera_errada.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

r4: r4_remove.c
	gcc $(CFLAGS) $< -o $@

r4_corrigido: r4_remove_corrigido.c
	gcc $(CFLAGS) $< -o $@

r5: r5_dupla.c
	gcc -g -fsanitize=address $(CFLAGS) $< -o $@

r5_corrigido: r5_dupla_corrigido.c
	gcc $(CFLAGS) $< -o $@

r6: r6_pilha.c
	gcc $(CFLAGS) $< -o $@

r7: r7_fila.c
	gcc $(CFLAGS) $< -o $@

r7_dobra_errada: r7_dobra_errada.c
	gcc $(CFLAGS) $< -o $@

limpa:
	rm -f r1 r2 r2_local r2_local_corrigido r3 r3_libera_errada r4 r4_corrigido \
	      r5 r5_corrigido r6 r7 r7_dobra_errada; rm -rf *.dSYM

.PHONY: todos limpa
