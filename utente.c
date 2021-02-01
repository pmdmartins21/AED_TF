#include "utente.h"
#include<stdio.h>
#include<string.h>

Utente criarUtente()
{
    Utente u;
    printf("O nome do Utente:\n");
    fgets(u.nome,100, stdin);
    u.nome[strlen(u.nome) -1 ] = '\0';
    printf("Idade do utente:\n");
    scanf("%d", &u.idade);
    fflush(stdin);
    printf("Contato Telefonico:\n");
    fgets(u.contatoTelefonico,21, stdin);
    u.contatoTelefonico[strlen(u.contatoTelefonico) -1 ] = '\0';
    return u;
}



