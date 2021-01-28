#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "centroVacinacao.h"
#include "utente.h"
#include "listaCentros.h"
#include "centroVacinacao.h"
#include "listaVacinas.h"

void tipo_registo(registos);

int main(int argc, char const *argv[])
{
    ListaVacinas lv;
    lv.numeroVacinas = 0;
    CentroVacinacao registos[100];
    int op=0;

    while(op!=4)
    {
        printf("************ BEM VINDO!! ************\n\n\n");
        printf(">>> MENU <<<\n\n");
        printf("1 - REGISTAR\n");
        printf("2 - CONSULTAR\n");
        printf("3 - ELIMINAR\n");
        printf("4 - SAIR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                tipo_registo(registos);
                break;
            case 2:      
                consultar(registos);
                break;
            case 3: 
                eliminar(registos);
                break;
            case 4: 
                printf("\n\n Adeus!!");
                break;
        }
    }
    return 0;
}

void tipo_registo(registos)
{
    ListaCentros lc;
    int op=0;
    while(op!=4)
    {
        printf(">>> Tipo de registos <<<\n\n");
        printf("1 - CENTROS\n");
        printf("2 - UTENTES\n");
        printf("3 - VACINAS\n");
        printf("4 - VOLTAR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:  
                menuCentros(&lc);
                break;
            case 2:     
                verifica_registo_utentes(registos);
                break;
            case 3: 
                verifica_registo_vacinas(registos);
                break;
            case 4: 
                criarUtente(registos);
                break;
        }
    }
}