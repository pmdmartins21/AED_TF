all: utente.o centroVacinacao.o vacina.o main.c
	gcc -g -o main utente.o  centroVacinacao.o vacina.o main.c


utente.o: utente.c
	gcc -g -o utente.o utente.c -c

vacina.o: vacina.c
	gcc -g -o vacina.o vacina.c -c

centroVacinacao.o: centroVacinacao.c
	gcc -g -o centroVacinacao.o centroVacinacao.c -c


clean: 
	del centroVacinacao.o utente.o vacina.o main.o

run:
	mingw32-make all
	./main