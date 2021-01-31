#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "centroVacinacao.h"
#include "utente.h"
#include "listaCentros.h"
#include "centroVacinacao.h"
#include "listaVacinas.h"
#include "listaUtentes.h"

void tipo_registo(registos);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
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

    getchar();

    return 0;
}

void tipo_registo(registos)
{
    ListaVacinas lv;
    lv.numeroVacinas = 0;
    ListaCentros lc;
    int op=0;
    ListaUtentes lu;

    while(op!=4)
    {
        printf(">>> Tipo de registos <<<\n\n");
        printf("1 - CENTROS\n");
        printf("2 - UTENTES\n");
        printf("3 - VACINAS\n");
        printf("4 - VOLTAR\n\n");
        printf("OPÇÃO: ");

        scanf("%d", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                menuCentros(&lc);
                break;
            case 2:     
                menuUtentes(&lu);
                break;
            case 3: 
                menuVacinas(&lv);
                break;
            case 4: 
                break;
            default:
                printf("Opção errada");
                break;
        }
    }
}