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
    FILE * ficheiro = fopen("listaVacinas.dat", "wb");
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

void editarVacinas(ListaVacinas *lv, int idAEditar) {
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
            printf("Insira o novo nome da vacina:\n");
            while (getchar() != '\n');
            strcpy(lv->lv[i].designacao,"\0");
            fgets(lv->lv[i].designacao, 101, stdin);
            lv->lv[i].designacao[strlen(lv->lv[i].designacao) -1 ] = '\0';
        }else{
            printf("ID não encontrado");
        }
    }
}

void editarIdVacina(ListaVacinas *lv, int idAEditar) {
    int novoID;
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo id da vacina:\n");
            scanf("%d", &novoID);
            lv->lv[i].idVacina = novoID;
        }else{
            printf("ID não encontrado");
        }
    }
}

void editarNumeroDosesVacina(ListaVacinas *lv, int idAEditar) {
    int novoNumeroDoses;
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo número de doses da vacina:\n");
            scanf("%d", &novoNumeroDoses);
            lv->lv[i].nDoses = novoNumeroDoses;
        }else{
            printf("ID não encontrado");
        }
    }
}

void editarTempoEntreVacina(ListaVacinas *lv, int idAEditar) {
    int novoTempoEntreVacinas;
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo tempo entre vacinas:\n");
            scanf("%d", &novoTempoEntreVacinas);
            lv->lv[i].idVacina = novoTempoEntreVacinas;
        }else{
            printf("ID não encontrado");
        }
    }
}

void listarVacinasAlfabeticamente(ListaVacinas *lv) {
    Vacina temp;
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        for (int j = i + 1; j < lv->numeroVacinas; j++)
        {
            if (stricmp(lv->lv[i].designacao, lv->lv[j].designacao) > 0)
            {
                temp = lv->lv[i];
                lv->lv[i] = lv->lv[j];
                lv->lv[j] = temp;   
            }
        }     
    }
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        puts(lv->lv[i].designacao);
    }
}