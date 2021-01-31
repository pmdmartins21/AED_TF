all: listaVacinas.o listaCentros.o  listaUtentes.o main.c
	gcc -g -o main listaVacinas.o listaCentros.o listaUtentes.o main.c

listaUtentes.o: listaVacinas.o listaCentros.o utente.o listaUtentes.c
	gcc -g -o listaVacinas.o listaCentros.o utente.o listaUtentes.o listaUtentes.c -c

listaVacinas.o: vacina.o listaVacinas.c
	gcc -g -o vacina.o listaVacinas.o listaVacinas.c -c

listaCentros.o: centroVacinacao.o listaCentros.c
	gcc -g -o centroVacinacao.o listaCentros.o listaCentros.c -c

utente.o: utente.c
	gcc -g -o utente.o utente.c -c

vacina.o: vacina.c
	gcc -g -o vacina.o vacina.c -c

centroVacinacao.o: centroVacinacao.c
	gcc -g -o centroVacinacao.o centroVacinacao.c -c

clean: 
	del centroVacinacao.o utente.o vacina.o main.o listaCentros.o listaVacinas.o listaUtentes.o

run:
	mingw32-make all
	./main