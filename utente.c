#include "utente.h"
#include<stdio.h>
#include<string.h>

Utente criarUtente()
{
    Utente u;
    //u.idade = 0;
    //u.numeroDeUtente = 0;
    printf("O nome do Utente:\n");
    while (getchar() != '\n');
    fgets(u.nome,100, stdin);
    u.nome[strlen(u.nome) -1 ] = '\0';
    printf("O numero do utente:\n");
    scanf("%d", &u.numeroDeUtente);
    printf("Idade do utente:\n");
    scanf("%d", &u.idade);
    printf("Contato Telefonico:\n");
    while (getchar() != '\n');
    fgets(u.contatoTelefonico,21, stdin);
    u.contatoTelefonico[strlen(u.contatoTelefonico) -1 ] = '\0';
    return u;
}



