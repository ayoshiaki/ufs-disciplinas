CC      = gcc
CFLAGS  = -std=c17 -Wall -Wextra -Werror -pedantic -g
LDLIBS  = -lm
OBJ     = main.o turma.o matriz.o estat.o ranking.o

notas: $(OBJ)
	$(CC) $(OBJ) -o notas $(LDLIBS)

main.o:    main.c    turma.h ranking.h
turma.o:   turma.c   turma.h matriz.h estat.h
matriz.o:  matriz.c  matriz.h
estat.o:   estat.c   estat.h
ranking.o: ranking.c ranking.h turma.h estat.h

.PHONY: clean formato
clean:
	rm -f $(OBJ) notas

formato:
	clang-format -i *.c *.h
