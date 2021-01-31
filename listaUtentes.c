#include "listaUtentes.h"
#include "utente.h"
#include <stdio.h>



void inserirUtente(ListaUtentes *lu)
{
    Utente u = criarUtente(lu->numeroUtentes);
    lu->lu[lu->numeroUtentes] = u;
    lu->numeroUtentes ++;
}

int procurarIDNaLista(ListaUtentes *lu, int idAProcurar) 
{
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if(lu->lu[i].numeroDeUtente == idAProcurar) 
        {
            return i;
        }
    }
    return NULL;
}

void eliminarUtente(ListaUtentes *lu)
{
    int numeroAEliminar;
    //imprimir lista
    printf("Lista antes de remover:\nQuantidade: %d\nMembros:\n", lu->numeroUtentes);
    for(int i = 0; i< lu->numeroUtentes; i++) printf("%d\n", lu->lu[i].numeroDeUtente);
    printf("Qual e o numero do utente que deseja eliminar? \n");
    scanf("%d", numeroAEliminar);


    

    //remover o elemento com o numero 15
    int i;
    for(i = 0; i <lu->numeroUtentes;i++){
        if(lu->lu[i].numeroDeUtente == numeroAEliminar) break;
    }
    for(int j = i+1; j < lu->numeroUtentes; j++){
        lu->lu[j-1] = lu->lu[j];
    }
    lu->numeroUtentes= lu->numeroUtentes -1;

    printf("\nLista depois de remover:\nQuantidade: %d\nMembros:\n", lu->numeroUtentes);
    for(int i = 0; i< lu->numeroUtentes; i++) printf("%d\n", lu->lu[i].numeroDeUtente);        
        
    
}

void editarUtente(ListaUtentes *lu, int idAEditar) 
{
    int op = 0;
    while(op!=5)
        {
            printf(">>> Edicao de Utentes %s<<<\n\n"); 
            printf("1 - Nome do Utente\n"); 
            printf("2 - Numero do Utente\n");
            printf("3 - Idade do Utente\n");
            printf("4 - Contacto Telefonico\n");
            printf("5 - Sair\n\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");
            scanf("%d", &op);
            fflush(stdin);
            switch(op){
                case 1: {
                    alterarNomeUtente(&lu, idAEditar);
                    break;
                }
                case 2: {      
                    alterarNumeroUtente(&lu, idAEditar);
                    break;
                }
                case 3: {
                    alterarIdadeUtente(&lu, idAEditar);
                    break;
                }
                case 4: {
                    alterarContacto(&lu, idAEditar);
                    break;
                }
                case 5:
                //gravarDados(t);
                break;
                default: {
                    printf("Opcao errada");
                    break;
                }

            }
        }
}

void alterarNomeUtente(ListaUtentes *lu, int idAEditar) 
{

    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].nome == idAEditar)
        {
            printf("Insira o novo nome do Utente:\n");
            while (getchar() != '\n');
            strcpy(lu->lu[i].nome,"\0");
            fgets(lu->lu[i].nome, 101, stdin);
            lu->lu[i].nome[strlen(lu->lu[i].nome) -1 ] = '\0';
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarContacto(ListaUtentes *lu, int idAEditar) 
{

    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].contatoTelefonico == idAEditar)
        {
            printf("Insira o novo contacto telefonico do Utente:\n");
            while (getchar() != '\n');
            strcpy(lu->lu[i].contatoTelefonico,"\0");
            fgets(lu->lu[i].contatoTelefonico, 101, stdin);
            lu->lu[i].contatoTelefonico[strlen(lu->lu[i].contatoTelefonico) -1 ] = '\0';
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarIdadeUtente(ListaUtentes *lu, int idAEditar) 
{
    int novaIdade;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].idade == idAEditar)
        {
            printf("Insira a idade do Utente:\n");
            scanf("%d", &novaIdade);
            lu->lu[i].idade = novaIdade;
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarNumeroUtente(ListaUtentes *lu, int idAEditar) 
{
    int novoNumeroUtente;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o numero do Utente:\n");
            scanf("%d", &novoNumeroUtente);
            lu->lu[i].numeroDeUtente = novoNumeroUtente;
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}


 