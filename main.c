#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCentroDeVacinacao{
    char nomeCentro[101];
    char morada[101];
    int idCentro;
    
} CentroDeVacinacao;

typedef struct sVacina{
    char designacao[101];
    int nDoses;
    int tempoEntreVacinas;
    int idVacina; //codigo
   
} Vacina;

typedef struct Utente{
    char nome[101];
    int numeroDeUtente;
    int idade;
    int contactoTelefonico;
    Vacina vacinaUtilizada;
    int quantidadeDosesAdmn;
    char dataUltimaDosagem[41];
    
    
} CUtente;