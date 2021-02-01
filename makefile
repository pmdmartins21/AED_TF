all: utente.o vacina.o centroVacinacao.o listaCentros.o listaVacinas.o  listaUtentes.o main.c
	gcc -g -o main.exe utente.o vacina.o centroVacinacao.o listaCentros.o listaVacinas.o  listaUtentes.o main.c

listaUtentes.o: listaVacinas.o listaCentros.o utente.o listaUtentes.c
	gcc -g -o listaUtentes.o listaVacinas.o listaCentros.o utente.o  listaUtentes.c -c

listaVacinas.o: vacina.o listaVacinas.c
	gcc -g -o listaVacinas.o vacina.o  listaVacinas.c -c

listaCentros.o: centroVacinacao.o listaCentros.c
	gcc -g -o listaCentros.o centroVacinacao.o  listaCentros.c -c

utente.o: utente.c
	gcc -g -o utente.o utente.c -c

vacina.o: vacina.c
	gcc -g -o vacina.o vacina.c -c

centroVacinacao.o: centroVacinacao.c
	gcc -g -o centroVacinacao.o centroVacinacao.c -c

clean: 
	del centroVacinacao.o utente.o vacina.o main.exe listaCentros.o listaVacinas.o listaUtentes.o

run:
	mingw32-make all
	./main