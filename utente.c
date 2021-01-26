#include "utente.h"
#include<stdio.h>
#include<string.h>

Utente criarAluno(){
    Utente u;
    printf("O nome do Utente:");
    while (getchar() != '\n');
    fgets(u.nome,100, stdin);
    u.nome[strlen(u.nome) -1 ] = '\0';
    printf("O numero do utente :");
    scanf("%d", &u.numeroDeUtente);
    return u;
}