#include "utente.h"
#include<stdio.h>
#include<string.h>

Utente criarUtente()
{
    Utente u;
    //u.idade = 0;
    //u.numeroDeUtente = 0;
    printf("O nome do Utente:");
    while (getchar() != '\n');
    fgets(u.nome,100, stdin);
    u.nome[strlen(u.nome) -1 ] = '\0';
    printf("O numero do utente :");
    scanf("%d", &u.numeroDeUtente);
    printf("Idade do utente :");
    scanf("%d", &u.idade);
    printf("Contato Telefonico:");
    while (getchar() != '\n');
    fgets(u.contatoTelefonico,21, stdin);
    u.contatoTelefonico[strlen(u.contatoTelefonico) -1 ] = '\0';
    return u;
}



