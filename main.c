#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaUtentes.h"

void menuCentros(ListaCentros *lc);
void menuUtentes(ListaUtentes *lu);
void menuVacinas(ListaVacinas *lv);


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    ListaVacinas lv;
    lv.numeroVacinas = 0;
    ListaCentros lc;
    lc.numeroCentros = 0;
    int op=0;
    ListaUtentes lu;
    lu.numeroUtentes = 0;
    CentroVacinacao registos[100];
    int op1=0;
    int centroID;
    /*
    //Metodo entrada?
    if (lc.numeroCentros != 0)
    {
        printf(">>> Por favor escolha o seu Centro <<<\n\n");
        listarCentros(lc);
        scanf("%d",&centroID);

        while (procurarIDNaListaCentros(&lc,centroID) < 0)
        {
            printf("ID incorrecto, por favor introduza outro:\n");
            scanf("%d",&centroID);
        }
    }
    */
    while(op1!=9)
    {
        printf("************ BEM VINDO!! ************\n\n\n");
        printf(">>> DASHBOARD <<<\n\n");
        printf("NUMERO DE VACINAS ADMNISTRADAS\n");
        printf("MEDIA DE IDADES DOS UTENTES VACINADOS\n");
        printf("VACINA (POR VACINA): NUMERO DE UTENTES VACINADOS\n");
        printf("1 - CENTROS\n\n");
        printf("2 - UTENTES\n\n");
        printf("3 - VACINAS\n\n");
        printf("4 - LISTAR UTENTES POR VACINA\n\n");
        printf("5 - LISTAR UTENTES POR CENTRO\n\n");
        printf("9 - SAIR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op1);
        fflush(stdin);
        switch(op1)
        {
            case 1:
                menuCentros(&lc);
                gravarDadosListaCentros(lc);
                break;
            case 2:     
                menuUtentes(&lu);
                gravarDadosListaUtentes(lu);
                break;
            case 3: 
                listarVacinas(lv);
                menuVacinas(&lv);
                gravarDadosListaVacinas(lv);
                break;
            case 4:
                listarUtentesPorVacinas(&lu, &lv);
                break;
            case 5: 
                listarUtentesPorCentro(&lu, &lc);
                break;
            case 9: 
                break;
            default:
                printf("Opção errada");
                break;
        }
    }
    getchar();

    return 0;
}

void menuCentros(ListaCentros *lc) {
    int idAManipular;
    int op2 = 0;
    while(op2!=4)
        {
            printf(">>> MENU CENTROS DE VACINACAO <<<\n\n"); //inserir atual com funcao search by id ??
            printf("1 - Inserir novo Centro \n"); 
            printf("2 - Editar Centro\n");
            printf("3 - Inativar Centro\n");
            printf("4 - Sair\n\n");
            printf(">>>     ESCOLHA A OPCAO A ALTERAR  <<<\n");

            scanf("%d", &op2);
            fflush(stdin);
            switch(op2)
            {
                case 1: 
                    inserirCentro(lc);
                    break;
                case 2:    
                    printf("indique o ID do Centro");
                    scanf("%d", &idAManipular);
                    editarCentro(lc, idAManipular);
                    break;
                
                case 3: 
                    printf("indique o ID do Centro");
                    scanf("%d", &idAManipular);
                    inactivarCentro(lc, idAManipular);
                    break;
                
                case 4:
                break;

                default: 
                    printf("Opcao errada");
                    break;
                

            }
        }
}

void menuUtentes(ListaUtentes *lu) 
{
    int numeroAEditar;
    int op3 = 0;
    while(op3!=5)
        {
            printf(">>> MENU UTENTES %s<<<\n\n"); 
            printf("1 - Inserir Utente\n"); 
            printf("2 - Editar Utente\n");
            printf("3 - Listar Utente\n");
            printf("4 - Eliminar Utente\n");            
            printf("5 - Voltar\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");
            scanf("%d", &op3);
            fflush(stdin);
            switch(op3){
                case 1:     
                    inserirUtente(lu);
                    break;
                
                case 2: 
                    editarUtente;
                    printf("Qual o numero do Utente que deseja editar?");
                    scanf("%d", &numeroAEditar);
                    editarUtente(lu, numeroAEditar);
                    break;
                
                case 3: 
                    listarUtentes(lu);
                    break;
    
                case 4:
                    eliminarUtente(lu);
                break;
                case 5:
                break;
                default: 
                    printf("Opcao errada\n");
                    break;
            }
        }
}

void menuVacinas(ListaVacinas *lv) {
    int idAInativar;
    int op4 = 0;
    while (op4 != 5)
    {
        printf(">>> MENU VACINAS <<<\n\n");
        printf("1 - Inserir nova vacina\n"); 
        printf("2 - Editar vacina\n");
        printf("3 - Inativar vacina\n");
        printf("4 - Listar vacinas\n");
        printf("5 - Sair\n\n");
        printf(">>> ESCOLHA A OPCAO A ALTERAR <<<\n");

        scanf("%d", &op4);
        fflush(stdin);

        switch (op4)
        {
            case 1:
                inserirVacina(lv);
                break;
            case 2:
                printf("Qual o id da vacina a editar?");
                scanf("%d", &idAInativar);
                editarVacinas(lv, idAInativar);
                break;
            case 3:
                printf("Qual o id da vacina a inativar?");
                scanf("%d", &idAInativar);
                inativarVacina(lv, idAInativar);
                break;
            case 4:
                //listarVacinas(lv);
                break;
            case 5:

                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }  
}