#include "listaVacinas.h"
#include <stdio.h>
#include <string.h>

void inserirVacina(ListaVacinas *lv){
    Vacina v = criarVacina(lv->numeroVacinas);
    lv->lv[lv->numeroVacinas] = v;
    lv->numeroVacinas++;
}


int listarVacinas(ListaVacinas lv){
    int idVacina;
    for (int i = 0; i< lv.numeroVacinas; i++) {
        printf("%d -> %s \n", lv.lv[i].idVacina, lv.lv[i].designacao);
    }
    scanf("%d", &idVacina);

    //falta controlar se a opcao inserida
    return idVacina;
}

void procurarVacina(ListaVacinas *lv, int vacinaId){
    for (int i = 0; i < lv->numeroVacinas; i++) {
        if (lv->lv[i].idVacina == vacinaId) {
            return i;
            //menu
        }
    }
    return NULL;
} 

/*
void getVacinaById(ListaVacinas *lv, int vacinaID){
    for(int i = 0; i < lv.numeroVacinas; i++ ){
        if(lv.lv[i].idVacina == vacinaID) {
            printf("Designação: %s", lv.lv[i].designacao);
        }
    }
}
*/

void inativarVacina(ListaVacinas *lv, int idAInativar) {
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAInativar)
        {
            lv->lv[i].ativo = 0;
        }
    }
}

void gravarDadosListaVacinas(ListaVacinas lv) {
    FILE * ficheiro = fopen("listaAlunos.dat", "wb");
    rewind(ficheiro);
    fwrite(&lv, sizeof(ListaVacinas), 1, ficheiro);
    fclose(ficheiro);
}

void carregarDadosListaVacinas(ListaVacinas *lv){
    FILE *ficheiro;
    ficheiro = fopen("listaVacinas.dat", "rb");

    if(ficheiro == NULL) return;

    fread(lv, sizeof(ListaVacinas), 1, ficheiro);

    fclose(ficheiro);
}

void editarVacinas(ListaVacinas *lv) {
    int op = 0;
    while(op != 4) {
        printf(">>> Edição de Vacinas <<<\n\n");
        printf("1 - Nome da Vacina\n"); 
        printf("2 - Número de doses\n");
        printf("3 - Tempo entre vacinas\n");
        printf("4 - Sair\n\n");
        printf(">>>ESCOLHA A OPÇÃO A ALTERAR<<<\n");

        scanf("%d", &op);
        fflush(stdin);
        switch(op) {
            case 1: 
                editarNomeVacina(&lv, idAEditar);
                break;
            case 2:      
                editarNumeroDoses(&lv, idAEditar);
                break;
            case 3: 
                editarTempoVacinas(&lv, idAEditar);
                break;
            default: 
                printf("Opção errada");
                break;
        }
    }
}

void editarNomeVacina(ListaVacinas *lv, int idAEditar) {

    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo Nome da Vacina:\n");
            while (getchar() != '\n');
            strcpy(lv->lv[i].designacao,"\0");
            fgets(lv->lv[i].designacao,101, stdin);
            lv->lv[i].designacao[strlen(lv->lv[i].designacao) -1 ] = '\0';
        }else{
            printf("ID nao encontrado");
        }
        
    }
}