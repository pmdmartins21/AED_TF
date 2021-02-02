#include "listaCentros.h"
#include <stdio.h>
#include <string.h>



// Inserir, editar e inactivar centros de vacinação;

void inserirCentro(ListaCentros *lc) {
    CentroVacinacao cv = criarCentro();
    cv.centroID = (lc->numeroCentros+1);
    lc->centros[lc->numeroCentros] = cv;
    lc->numeroCentros++;
} //***quando inicializar a lista de centros, por o numero de centros a 0!

void listarCentros(ListaCentros *lc) {
    printf("=====================================================================================\n");   
    printf(">>>                            LISTA DE CENTROS                                   <<<\n\n");
    printf("ID Centro |           Designacao      |           MORADA          |  ATIVO/INATIVO   \n");
    for (int i = 0; i < lc->numeroCentros; i++) {
        int id = lc->centros[i].centroID;
        char nome[100];
        char morada[101];
        char ativo[10];
        if (lc->centros[i].activo ==1 )
        {
            strcpy(ativo,"ATIVO");
        }else strcpy(ativo,"INATIVO");
        
        strcpy(nome,lc->centros[i].nomeCentro);
        strcpy(morada,lc->centros[i].morada);
        printf("     %d    |%27s|%27s|%10s \n",id,nome,morada,ativo);
    }
    printf("=====================================================================================\n");
    printf("=====================================================================================\n\n");  
}

void ativarInactivarCentro(ListaCentros *lc, int IdAInativar) { // inativo = 0
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if (lc->centros[i].centroID == IdAInativar)
        {
           if (lc->centros[i].activo == 1)
            {
                lc->centros[i].activo = 0;
                break;
            }
            else
                lc->centros[i].activo = 1;
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

void gravarDadosListaCentros(ListaCentros lc) 
{
    FILE * ficheiro = fopen("listaCentros.dat", "wb");
    rewind(ficheiro);
    fwrite(&lc, sizeof(ListaCentros), 1, ficheiro);
    fclose(ficheiro);
}

void carregarDadosListaCentros(ListaCentros *lc)
{
    FILE *ficheiro;
    ficheiro = fopen("listaCentros.dat", "rb");

    if(ficheiro == NULL) return;

    fread(lc, sizeof(ListaCentros), 1, ficheiro);

    fclose(ficheiro);
}



void alterarNomeCentro(ListaCentros *lc,int idAEditar) {
    int counter = 0;
    for (int i = 0; i < lc->numeroCentros; i++)
    {
        if (lc->centros[i].centroID == idAEditar)
        {
            printf("Insira o novo Nome de Centro:\n");
            strcpy(lc->centros[i].nomeCentro,"\0");
            fgets(lc->centros[i].nomeCentro,101, stdin);
            lc->centros[i].nomeCentro[strlen(lc->centros[i].nomeCentro) -1 ] = '\0';
            break;
        }                
    }
    if (counter == 0)
    {
        printf("Numero do Centro nao encontrado não encontrado");
    }
}

void alterarMoradaCentro(ListaCentros *lc, int idAEditar) {
    //procurar o id na lista
    int indiceID = procurarIDNaListaCentros(lc, idAEditar);
    strcpy(lc->centros[indiceID].morada,"\0");
    printf("Insira a nova Morada de Centro:\n");
    fgets(lc->centros[indiceID].morada,101, stdin);
    lc->centros[indiceID].morada[strlen(lc->centros[indiceID].morada) -1 ] = '\0';
}


int mostrarEstadoAtual(ListaCentros *lc, int idAEditar) {
     int indiceID = procurarIDNaListaCentros(lc, idAEditar);
     return lc->centros[indiceID].activo;
 }

void alterarEstado(ListaCentros *lc, int idAEditar){
    int indiceID = procurarIDNaListaCentros(lc, idAEditar);
    mostrarEstadoAtual(lc, idAEditar) == 0 ? lc->centros[indiceID].activo = 1 : printf("Erro! Centro activo");
 }

 

void editarCentro(ListaCentros *lc, int idAEditar) {
    int op6 = 0;
    
   while(op6!=9) 
        {
            printf(">>> Edicao de Centros de Vacinacao <<<\n\n"); //inserir estado atual com funcao search by id ??
            printf("1 - Nome do Centro \n"); 
            printf("2 - Morada\n");
            printf("9 - Sair\n\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");

            scanf("%d", &op6);
            fflush(stdin);
            switch(op6){
                case 1: {
                    alterarNomeCentro(lc, idAEditar);
                    break;

                }
                case 2: {      
                    alterarMoradaCentro(lc, idAEditar);
                    break;
                }
                case 9:
                break;
                default: {
                    printf("Opcao errada");
                    break;
                }

            }
        }
}

