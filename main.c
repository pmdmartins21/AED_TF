#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaCentros.h"
#include "listaVacinas.h"
#include "listaUtentes.h"

void menuCentros(ListaCentros *lc , int idCentroAtivo);
void menuUtentes(ListaUtentes *lu);
void menuVacinas(ListaVacinas *lv);


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    ListaVacinas lv;
    lv.numeroVacinas = 0;
    ListaCentros lc;
    int op=0;
    ListaUtentes lu;
    CentroVacinacao registos[100];
    int op=0;
    int centroID;

    //Metodo entrada?
    printf(">>> Por favor escolha o seu Centro <<<\n\n");
    listarCentros(&lc);
    scanf("%d",&centroID);
    while (procurarIDNaListaCentros(&lc,centroID) < 0)
    {
        printf("ID incorrecto, por favor introduza outro:\n");
        scanf("%d",&centroID);
    }
    
    while(op!=4)
    {
        printf("************ BEM VINDO!! ************\n\n\n");
        printf(">>> DASHBOARD <<<\n\n");
        printf("NÚMERO DE VACINAS ADMNISTRADAS\n");
        printf("MÉDIA DE IDADES DOS UTENTES VACINADOS\n");
        printf("VACINA %s (POR VACINA): NÚMERO DE UTENTES VACINADOS\n");
        printf("1 - CENTROS\n\n");
        printf("2 - UTENTES\n\n");
        printf("3 - VACINAS\n\n");
        printf("4 - LISTAR UTENTES POR VACINA\n\n");
        printf("5 - LISTAR UTENTES POR CENTRO\n\n");
        printf("9 - SAIR\n\n");
        printf("OPCAO: ");

        scanf("%d", &op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                menuCentros(&lc, centroID);
                void gravarDadosListaCentros(lc);
                break;
            case 2:     
                menuUtentes(&lu);
                void gravarDadosListaUtentes(lu);
                break;
            case 3: 
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

void menuCentros(ListaCentros *lc , int idCentroAtivo) {
    int idAManipular;
    int op = 0;
    while(op!=4)
        {
            printf(">>> MENU CENTROS DE VACINACAO %s<<<\n\n"); //inserir atual com funcao search by id ??
            printf("1 - Inserir novo Centro \n"); 
            printf("2 - Editar Centro\n");
            printf("3 - Inativar Centro\n");
            printf("4 - Sair\n\n");
            printf(">>>     ESCOLHA A OPCAO A ALTERAR  <<<\n");

            scanf("%d", &op);
            fflush(stdin);
            switch(op)
            {
                case 1: 
                    CentroVacinacao cv = criarCentro();
                    inserirCentro(lc, cv);
                    break;
                case 2:    
                    listarCentros(lc);
                    printf("indique o ID do Centro");
                    scanf("%d", &idAManipular);
                    editarCentro(lc, idAManipular);
                    break;
                
                case 3: 
                    listarCentros(lc);
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

void menuVacinas(ListaVacinas *lv) {
    int idAInativar;
    int opcao = 0;
    while (opcao != 5)
    {
        printf(">>> MENU VACINAS <<<\n\n");
        printf("1 - Inserir nova vacina\n"); 
        printf("2 - Editar vacina\n");
        printf("3 - Inativar vacina\n");
        printf("4 - Listar vacinas\n");
        printf("5 - Sair\n\n");
        printf(">>> ESCOLHA A OPCAO A ALTERAR <<<\n");

        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                inserirVacina(&lv);
                break;
            case 2:
                listarVacina();
                printf("Qual o id da vacina a editar?");
                scanf("%d", &idAInativar);
                editarVacina(&lv, idAInativar);
                break;
            case 3:
                listarVacina();
                printf("Qual o id da vacina a inativar?");
                scanf("%d", &idAInativar);
                inativarVacina(&lv, idAInativar);
                break;
            case 4:
                listarVacina();
                break;
            case 5:

                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }  
}