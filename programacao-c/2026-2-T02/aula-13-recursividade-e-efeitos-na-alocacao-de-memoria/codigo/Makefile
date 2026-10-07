CFLAGS = -Wall -Wextra -pedantic

todos: memoria gorda invertida

memoria: memoria.c
	gcc $(CFLAGS) $< -o $@

memoria-O2: memoria.c
	gcc -O2 $(CFLAGS) $< -o $@

gorda: gorda.c
	gcc $(CFLAGS) $< -o $@

invertida: invertida.c
	gcc $(CFLAGS) $< -o $@

limpa:
	rm -f memoria memoria-O2 gorda invertida

.PHONY: todos limpa
