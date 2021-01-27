#include "listaUtentes.h"
#include <stdio.h>



void menuUtente(ListaUtentes *lu)
{
    Utente u = criarUtente();   
    printf("Introduza a turma:\n" );
    a.numeroDeUtente = listarUtente(lu);
    acrestentaUtente(lu,u);
}


void acrestentaUtente(ListaUtentes *lu)
{
    lu->utentes[lu->numeroUtentes] = a;
    lu->numeroUtentes ++;
}

void carregarDadosListaUtentes(ListaUtentes *lu)
{
    FILE *ficheiro;
    ficheiro = fopen("listaUtentes.dat", "rb");

    if(ficheiro == NULL) return;

    fread(lu, sizeof(ListaUtentes), 1, ficheiro);

    fclose(ficheiro);
}

int listarUtentes( ListaUtentes lu)
{
    int numeroDeUtente;
    for (int i = 0; i< lu.numeroUtentes; i++)
    {
        printf("%d -> %s \n", lu.lu[i].numeroDeUtente, lu.lu[i].nome );
    }
    scanf("%d", &numeroDeUtente);

    return numeroDeUtente;
}   

void getUtenteById(int numeroDeUtente, ListaUtentes lu)
{
    for(int i = 0; i < lu.numeroUtentes; i++ )
    {
        if(lu.lu[i].numeroDeUtente == numeroDeUtente) 
        {
            printf("Nome do Utente: %s", lu.lu[i].nome);
        }
    }
}


void opcaoUtentes()
{   
    int op=0;
    while(op!=4){
        printf(">>> Tipo de registos <<<\n\n");
        printf("1 - INSERIR\n");
        printf("2 - INATIVAR\n");
        printf("3 - REMOVER\n");
        printf("4 - VOLTAR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op);
        fflush(stdin);
        switch(op){
            case 1: {       
                criarUtente(&lu, );
                break;
            }

            case 2: {      
                criarUtente();
                break;
            }
            case 3: {
                verifica_registo_vacinas();
                break;
            }

        }
    }
getch();
}