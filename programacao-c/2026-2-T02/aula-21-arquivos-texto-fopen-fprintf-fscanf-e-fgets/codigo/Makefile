CFLAGS = -Wall -Wextra -pedantic

todos: boletim sem_teste diario queda fim nomes linhas boletim_csv conta

boletim: boletim.c
	gcc $(CFLAGS) $< -o $@

sem_teste: sem_teste.c
	gcc $(CFLAGS) $< -o $@

diario: diario.c
	gcc $(CFLAGS) $< -o $@

queda: queda.c
	gcc $(CFLAGS) $< -o $@

fim: fim.c
	gcc $(CFLAGS) $< -o $@

nomes: nomes.c
	gcc $(CFLAGS) $< -o $@

linhas: linhas.c
	gcc $(CFLAGS) $< -o $@

boletim_csv: boletim_csv.c
	gcc $(CFLAGS) $< -o $@

conta: conta.c
	gcc $(CFLAGS) $< -o $@

limpa:
	rm -f boletim sem_teste diario queda fim nomes linhas boletim_csv conta \
	      boletim.txt boletim.csv diario.txt log.txt core

.PHONY: todos limpa
