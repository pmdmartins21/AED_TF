#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char const *argv[])
{
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    printf("===========MENU PRINCIPAL===========");
    return 0;
}

typedef struct Utente{
    char nome[101];
    int numeroDeUtente;
    int idade;
    int contactoTelefonico;
    Vacina vacinaUtilizada;
    int quantidadeDosesAdmn;
    char dataUltimaDosagem[41];
    
    
} CUtente;