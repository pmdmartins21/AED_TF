all: utente.o centroVacinacao.o main.c
	gcc -g -o main utente.o  centroVacinacao.o main.c


utente.o: utente.c
	gcc -g -o utente.o utente.c -c

centroVacinacao.o: centroVacinacao.c
	gcc -g -o centroVacinacao.o centroVacinacao.c -c


clean: 
	del centroVacinacao.o utente.o main.o

run:
	mingw32-make all
	./main