#include "listaUtentes.h"
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
        if(lu->numeroUtentes[i].numeroDeUtente == idAProcurar) 
        {
            return i;
        }
    }
    return NULL;
}

void eliminarUtente(ListaUtentes *lu,int idAProcurar)
{
    int i;
    for(i = 0; i <lu->numeroUtentes;i++)
    {
        if(lu.ListaUtentes[i] == numeroDeUtente) break;
    }
    for(int j = i+1; j < lu->numeroUtentes; j++)
    {
        lu.ListaUtentes[j-1] = lu.ListaUtentes[j];
    }
    lu->numeroUtentes = lu->numeroUtentes -1;
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

void alterarNomeUtente(ListaUtentes *lu, int idAEditar) {
    int indiceID = procurarIDNaLista(&lu, idAEditar);
    printf("Insira o novo Nome do Utente:\n");
    while (getchar() != '\n');
    lu->utente[indiceID].nome = "";
    fgets(lu->utentes[indiceID].nome,101, stdin);
    lu->utentes[indiceID]->nome[strlen(lu->utentes[indiceID].nome) -1 ] = '\0';
}

void alterarContacto(ListaUtentes *lu, int idAEditar) {
    int indiceID = procurarIDNaLista(&lu, idAEditar);
    printf("Insira o novo Contacto Telefonico:\n");
    while (getchar() != '\n');
    lu->utentes[indiceID].contatoTelefonico = "";
    fgets(lu->utentes[indiceID].contatoTelefonico,101, stdin);
    lu->utentes[indiceID].contatoTelefonico[strlen(lu->utentes[indiceID].contatoTelefonico) -1 ] = '\0';
}

void alterarIdadeUtente(ListaUtentes *lu, int idAEditar) {
    int indiceID = procurarIDNaLista(&lu, idAEditar);
    printf("Insira a idade do Utente:\n");
    while (getchar() != '\n');
    lu->utentes[indiceID].idade = "";
    fgets(lu->utentes[indiceID].idade,101, stdin);
    lu->utentes[indiceID].idade[strlen(lu->utentes[indiceID].idade) -1 ] = '\0';
}

void alterarNumeroUtente(ListaUtentes *lu, int idAEditar){
    int novoIndice;
    int indiceID = procurarIDNaLista(&lu, idAEditar);
    printf("Insira o novo numero do Utente:\n");
    scanf("%d", novoIndice);
    lu->utentes[indiceID].numeroDeUtente = novoIndice;
}


 