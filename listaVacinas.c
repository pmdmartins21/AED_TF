#include "listaVacinas.h"
#include <stdio.h>
#include <string.h>


void inserirVacina(ListaVacinas *lv){
    Vacina v = criarVacina();
    v.idVacina = (lv->numeroVacinas + 1);
    lv->lv[lv->numeroVacinas] = v;
    lv->numeroVacinas++;
}

void listarVacinas(ListaVacinas *lv){
    for (int i = 0; i< lv->numeroVacinas; i++) 
        {
            int id = lv->lv[i].idVacina;
            char nome[100];
            strcpy(nome,lv->lv[i].designacao);
            printf("ID: %d ->NOME: %20s \n", id, nome);
        }
}

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

void editarNomeVacina(ListaVacinas *lv, int idAEditar) {

    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo nome da vacina:\n");
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

void editarVacinas(ListaVacinas *lv, int idAEditar) {
    int op = 0;
    while(op != 4) {
        printf(">>> Edicao de Vacinas <<<\n\n");
        printf("1 - Nome da Vacina\n"); 
        printf("2 - Número de doses\n");
        printf("3 - Tempo entre vacinas\n");
        printf("4 - Sair\n\n");
        printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");

        scanf("%d", &op);
        fflush(stdin);
        switch(op) {
            case 1: 
                editarNomeVacina(lv, idAEditar);
                break;
            case 2:      
                editarNumeroDosesVacina(lv, idAEditar);
                break;
            case 3: 
                editarTempoEntreVacina(lv, idAEditar);
                break;
            default: 
                printf("Opção errada");
                break;
        }
    }
}