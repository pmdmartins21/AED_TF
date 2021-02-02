#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaUtentes.h"

void menuCentros(ListaCentros *lc);
void menuUtentes(ListaUtentes *lu, ListaCentros *lc, ListaVacinas *lv);
void menuVacinas(ListaVacinas *lv);


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    ListaVacinas lv;
    //carregarDadosListaVacinas(&lv);
    lv.numeroVacinas = 0;
    ListaCentros lc;
    //carregarDadosListaCentros(&lc);
    lc.numeroCentros = 0;
    int op=0;
    ListaUtentes lu;
    //carregarDadosListaUtentes(&lu);
    lu.numeroUtentes = 0;
    //CentroVacinacao registos[100]; para que é isto?
    int op1=0;
    int centroID;
    int vacinasAdministradas = 0;
    float mediaIdadeUtentesVacinados = 0.0;

    while(op1!=9)
    {
        vacinasAdministradas = totalVacinasAdministradas(&lu);
        mediaIdadeUtentesVacinados = mediaIdadesVacinados(&lu);


        printf("************ BEM VINDO!! ************\n\n\n");

        printf(">>> DASHBOARD <<<\n\n");
        printf("NUMERO DE VACINAS ADMNISTRADAS: %d\n", vacinasAdministradas);
        printf("MEDIA DE IDADES DOS UTENTES VACINADOS: %.2f\n", mediaIdadeUtentesVacinados);
        numeroUtentesVacinadosporVacinas(&lu, &lv); // lista utentes vacinados por vacinas
        printf(">>> DASHBOARD <<<\n\n");
        printf("1 - CENTROS\n");
        printf("2 - UTENTES\n");
        printf("3 - VACINAS\n");
        printf("4 - LISTAR UTENTES POR VACINA\n");
        printf("5 - LISTAR UTENTES POR CENTRO\n");
        printf("6 - LISTAR VACINAS ALFABETICAMENTE\n");
        printf("9 - SAIR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op1);
        fflush(stdin);
        switch(op1)
        {
            case 1:
                menuCentros(&lc);
                //gravarDadosListaCentros(lc);
                break;
            case 2:     
                menuUtentes(&lu, &lc, &lv);
                //gravarDadosListaUtentes(lu);
                break;
            case 3: 
                listarVacinas(&lv);
                menuVacinas(&lv);
                //gravarDadosListaVacinas(lv);
                break;
            case 4:
                listarUtentesPorVacinas(&lu, &lv);
                break;
            case 5: 
                listarUtentesPorCentro(&lu, &lc);
                break;
            case 6: 
                listarVacinasAlfabeticamente(lv);
                break;    
            case 9: 
                break;
            default:
                printf("Opção errada");
                break;
        }
    }
    return 0;
}

void menuCentros(ListaCentros *lc) {
    int idAManipular;
    int op2 = 0;
    while(op2!=5)
        {
            printf(">>> MENU CENTROS DE VACINACAO <<<\n\n"); 
            printf("1 - Inserir novo Centro \n"); 
            printf("2 - Editar Centro\n");
            printf("3 - Inativar Centro\n");
            printf("4 - Lista Centros\n\n");
            printf("5 - Sair\n\n");
            printf(">>>     ESCOLHA A OPCAO   <<<\n");

            scanf("%d", &op2);
            fflush(stdin);
            switch(op2)
            {
                case 1: 
                    inserirCentro(lc);
                    break;
                case 2:    
                    printf("indique o ID do Centro\n");
                    scanf("%d", &idAManipular);
                    editarCentro(lc, idAManipular);
                    break;
                
                case 3: 
                    printf("indique o ID do Centro\n");
                    scanf("%d", &idAManipular);
                    inactivarCentro(lc, idAManipular);
                    break;
                case 4:
                    listarCentros(lc);
                    break;
                case 5:
                    break;
                default: 
                    printf("Opcao errada");
                    break;
                

            }
        }
}

void menuUtentes(ListaUtentes *lu, ListaCentros *lc, ListaVacinas *lv) 
{
    int numeroAEditar;
    int op3 = 0;
    while(op3!=9)
        {
            printf(">>> MENU UTENTES <<<\n\n"); 
            printf("1 - Inserir Utente\n"); 
            printf("2 - Editar Utente\n");
            printf("3 - Listar Utente\n");
            printf("4 - Eliminar Utente\n");            
            printf("5 - Listar data da proxima vacina de um utente\n");            
            printf("6 - Listar utentes a ser vacinados num dia\n");            
            printf("9 - Voltar\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");
            scanf("%d", &op3);
            fflush(stdin);
            switch(op3){
                case 1:     
                    inserirUtente(lu,lc,lv);
                    break;
                
                case 2: 
                    editarUtente;
                    printf("Qual o numero do Utente que deseja editar?\n");
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
                    proximaVacinaUtente(lu, lv);
                break;
                case 6:
                    listarUtentesAVacinarNoDia(lu,lv);
                break;

                case 9:
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
        printf("4 - Listar vacinas por ID\n");
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
                printf("Qual o id da vacina a editar?\n");
                scanf("%d", &idAInativar);
                editarVacinas(lv, idAInativar);
                break;
            case 3:
                printf("Qual o id da vacina a inativar?\n");
                scanf("%d", &idAInativar);
                inativarVacina(lv, idAInativar);
                break;
            case 4:
                listarVacinas(lv);
                break;
            case 5:

                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }  
}