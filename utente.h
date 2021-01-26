#include<stdio.h>
#include<string.h>

typedef struct sUtente{
    char nome[101];
    int numeroDeUtente;
    int idade;
    int contactoTelefonico;
    int vacinaID;
    int centroID;
    int quantidadeDosesAdmn;
    char dataUltimaDosagem[41];
} Utente;

Utente criarUtente() {
    Utente u;
    printf("O nome do Utente:");
    while (getchar() != '\n');
    fgets(u.nome,100, stdin);
    u.nome[strlen(u.nome) -1 ] = '\0';
    printf("O numero do utente :");
    scanf("%d", &u.numeroDeUtente);
    printf("Idade do utente :");
    scanf("%d", &u.idade);
    

    return u;
};
