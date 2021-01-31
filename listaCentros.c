#include "listaCentros.h"
#include "centroVacinacao.h"
#include <stdio.h>
#include <string.h>

// Inserir, editar e inactivar centros de vacinação;

void inserirCentro(ListaCentros *lc) {
    CentroVacinacao cv = criarCentro();
    lc->centros[lc->numeroCentros] = cv;
    lc->numeroCentros++;
} //***quando inicializar a lista de centros, por o numero de centros a 0!

void listarCentros(ListaCentros *lc) {
    printf(">>>           LISTA DE CENTROS     <<<\n\n");
    printf("ID Centro |           Designacao         \n");
    //Listar Centros
    for (int i = 0; i < lc->numeroCentros; i++) {
        printf("%d    |  %s   ",lc->centros[i].centroID,lc->centros[i].nomeCentro);

    }
}


void inactivarCentro(ListaCentros *lc, int IdAInativar) { // inativo = 0
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if (lc->centros[i].centroID == IdAInativar)
        {
            lc->centros[i].activo = 0;
        }
    }
}

int procurarIDNaListaCentros(ListaCentros *lc, int idAProcurar) {
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if(lc->centros[i].centroID == idAProcurar) {
            return i;
        }
    }
    return -1;
}

void editarCentro(ListaCentros *lc, int idAEditar) {
    int op = 0;
    while(op!=5)
        {
            printf(">>> Edicao de Centros de Vacinacao %s<<<\n\n"); //inserir estado atual com funcao search by id ??
            printf("1 - Nome do Centro \n"); 
            printf("2 - Morada\n");
            printf("3 - ID do Centro\n");
            printf("4 - Estado Atual: %s | (Só aplicavel para reativar)\n\n",mostrarEstadoAtual(&lc, idAEditar) == 1 ? "Activo" : "Inativo"); // mostrar estado atual e permitir alterar?? ja tem opcao para inativar... Opcao valida se inativo?
            printf("5 - Sair\n\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");

            scanf("%d", &op);
            fflush(stdin);
            switch(op){
                case 1: {
                    alterarNomeCentro(&lc, idAEditar);
                    break;
                }
                case 2: {      
                    alterarMoradaCentro(&lc, idAEditar);
                    break;
                }
                case 3: {
                    alterarIdCentro(&lc, idAEditar);
                    break;
                }
                case 4: {
                    alterarEstado(&lc, idAEditar);
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

void alterarNomeCentro(ListaCentros *lc,int idAEditar) {
    /*
    int indiceID = procurarIDNaLista(&lc, idAEditar);
    printf("Insira o novo Nome de Centro:\n");
    while (getchar() != '\n');
    strcpy(lc->centros[indiceID].nomeCentro,"\0");
    fgets(lc->centros[indiceID].nomeCentro,101, stdin);
    lc->centros[indiceID].nomeCentro[strlen(lc->centros[indiceID].nomeCentro) -1 ] = '\0';
*/
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if (lc->centros[i].centroID == idAEditar)
        {
            printf("Insira o novo Nome de Centro:\n");
            while (getchar() != '\n');
            strcpy(lc->centros[i].nomeCentro,"\0");
            fgets(lc->centros[i].nomeCentro,101, stdin);
            lc->centros[i].nomeCentro[strlen(lc->centros[i].nomeCentro) -1 ] = '\0';
        }else{
            printf("ID nao encontrado");
        }
        
    }
    
}

void alterarMoradaCentro(ListaCentros *lc, int idAEditar) {
    //procurar o id na lista
    int indiceID = procurarIDNaLista(&lc, idAEditar);
    strcpy(lc->centros[indiceID].morada,"\0");
    printf("Insira a nova Morada de Centro:\n");
    while (getchar() != '\n');
    fgets(lc->centros[indiceID].morada,101, stdin);
    lc->centros[indiceID].morada[strlen(lc->centros[indiceID].morada) -1 ] = '\0';
}

void alterarIdCentro(ListaCentros *lc, int idAEditar){
    int novoIndice;
    int indiceID = procurarIDNaLista(&lc, idAEditar);
    printf("Insira o novo ID de Centro:\n");
    scanf("%d", novoIndice);
    lc->centros[indiceID].centroID = novoIndice;
}

void alterarEstado(ListaCentros *lc, int idAEditar){
    int indiceID = procurarIDNaLista(&lc, idAEditar);
    mostrarEstadoAtual(&lc, idAEditar) == 0 ? lc->centros[indiceID].activo = 1 : print("Erro! Centro activo");
 }

 int mostrarEstadoAtual(ListaCentros *lc, int idAEditar) {
     int indiceID = procurarIDNaLista(&lc, idAEditar);
     return lc->centros[indiceID].activo;
 }