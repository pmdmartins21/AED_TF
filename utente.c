#include "utente.h"
#include "listaUtentes.h"
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

void menuUtentes(ListaUtentes *lu) 
{
    int numeroAEditar;
    int op = 0;
    while(op!=6)
        {
            printf(">>> MENU UTENTES %s<<<\n\n"); 
            printf("1 - Inserir Utente\n"); 
            printf("2 - Editar Utente\n");
            printf("3 - Listar Utente\n");
            printf("4 - Eliminar Utente\n");            
            printf("5 - Voltar\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");
            scanf("%d", &op);
            fflush(stdin);
            switch(op){
                case 1:     
                    inserirUtente(&lu);
                    break;
                
                case 2: 
                    editarUtente;
                    printf("Qual o numero do Utente que deseja editar?");
                    scanf("%d", &numeroAEditar);
                    editarUtente(&lu, numeroAEditar);
                    break;
                
                case 3: 
                    listarUtente(&lu);
                    break;
    
                case 4:
                    eliminarUtente(&lu);
                break;
                
                default: 
                    printf("Opcao errada");
                    break;
                

            }
        }
}


