#include "centroVacinacao.h"
#include<stdio.h>
#include<string.h>
#include"listaCentros.h"

CentroVacinacao criarCentro() {
    CentroVacinacao cv;
    cv.centroID = 0;
    printf("Inserir o nome do Centro:\n");
    while (getchar() != '\n');
    fgets(cv.nomeCentro,101, stdin);
    cv.nomeCentro[strlen(cv.nomeCentro) -1 ] = '\0';
    printf("A morada do Centro:\n");
    while (getchar() != '\n');
    fgets(cv.morada,101, stdin);
    cv.morada[strlen(cv.morada) -1 ] = '\0';
    printf("O ID do Centro de Vacinacao:\n");
    scanf("%d", &cv.centroID);
    cv.activo = 1;
    return cv;
}

void menuCentros(ListaCentros *lc) {
    int idAManipular;
    int op = 0;
    while(op!=4)
        {
            printf(">>> MENU CENTROS DE VACINACAO %s<<<\n\n"); //inserir atual com funcao search by id ??
            printf("1 - Inserir novo Centro \n"); 
            printf("2 - Editar Centro\n");
            printf("3 - Inativar Centro\n");
            printf("4- Sair\n\n");
            printf(">>>     ESCOLHA A OPCAO A ALTERAR  <<<\n");

            scanf("%d", &op);
            fflush(stdin);
            switch(op){
                case 1: {
                    inserirCentro(&lc);
                    break;
                }
                case 2: {      
                    listarCentros(&lc); // falta fazer
                    printf("indique o ID do Centro");
                    scanf("%d", &idAManipular);
                    editarCentro(&lc, idAManipular);
                    break;
                }
                case 3: {
                    listarCentros(&lc); // falta fazer
                    printf("indique o ID do Centro");
                    scanf("%d", &idAManipular);
                    inactivarCentro(&lc, idAManipular);
                    break;
                }
                case 4: {
                    alterarEstado(cv);
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