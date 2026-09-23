CC      = gcc
CFLAGS  = -Wall -Wextra -g
LDLIBS  = -lm
OBJ     = main.o turma.o matriz.o estat.o ranking.o

notas: $(OBJ)
	$(CC) $(OBJ) -o notas $(LDLIBS)

main.o:    main.c    turma.h
turma.o:   turma.c   turma.h matriz.h estat.h
matriz.o:  matriz.c  matriz.h
estat.o:   estat.c   estat.h
ranking.o: ranking.c

.PHONY: clean
clean:
	rm -f $(OBJ) notas
