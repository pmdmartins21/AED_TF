#include "listaVacinas.h"
#include <stdio.h>
#include <string.h>


void inserirVacina(ListaVacinas *lv){
    Vacina v = criarVacina();
    v.idVacina = (lv->numeroVacinas + 1);
    lv->lv[lv->numeroVacinas] = v;
    lv->numeroVacinas++;
}

int procurarIDNaListaVacinas(ListaVacinas *lv, int idAProcurar) {
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if(lv->lv[i].idVacina == idAProcurar) {
            return i;
        }
    }
    return -1;
}

void listarVacinas(ListaVacinas *lv){
    printf("=====================================================================================\n");   
    printf(">>>                            LISTA DE VACINA                                    <<<\n\n");
    printf("ID VACINA |     DESIGNACAO    |  N. DOSES TOTAL | TEMPO ENTRE VACINAS(MESES)|   ATIVA \n");
    for (int i = 0; i< lv->numeroVacinas; i++) 
        {
            int id = lv->lv[i].idVacina;
            char nome[100];
            char ativo[20];
            if (lv->lv[i].ativo ==1 )
            {
                strcpy(ativo,"ATIVO");
            }else strcpy(ativo,"INATIVO");
            strcpy(nome,lv->lv[i].designacao);

            printf("     %d    |%19s|        %d        |               %d           | %s\n", id, nome, lv->lv[i].nDoses,lv->lv[i].tempoEntreVacinas, ativo);
        }
    printf("=====================================================================================\n");
    printf("=====================================================================================\n\n");
}

void ativarInativarVacina(ListaVacinas *lv, int idAInativar) {
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAInativar)
        {
            if (lv->lv[i].ativo == 1)
            {
                lv->lv[i].ativo = 0;
                break;
            }
            else
                lv->lv[i].ativo = 1;
            
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
            break;
        }   
    }
    printf("ID não encontrado");
}
//nao vamos usar
void editarIdVacina(ListaVacinas *lv, int idAEditar) {
    int novoID;
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv->lv[i].idVacina == idAEditar)
        {
            printf("Insira o novo id da vacina:\n");
            scanf("%d", &novoID);
            lv->lv[i].idVacina = novoID;
            break;
        } 
    }
    printf("ID não encontrado");
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
        break;
        } 
    }
    printf("ID não encontrado");
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
            break;
        } 
    }
    printf("ID não encontrado");
}

void listarVacinasAlfabeticamente(ListaVacinas lv) {
    Vacina temp;
    printf("==========================================\n"); 
    printf("==LISTA VACINAS ORDENADAS ALFABETICAMENTE=\n\n"); 
    for (int i = 0; i < lv.numeroVacinas; i++) 
    {
        for (int j = i + 1; j < lv.numeroVacinas; j++)
        {
            if (stricmp(lv.lv[i].designacao, lv.lv[j].designacao) > 0)
            {
                temp = lv.lv[i];
                lv.lv[i] = lv.lv[j];
                lv.lv[j] = temp;   
            }
        }     
    }
    for (int i = 0; i < lv.numeroVacinas; i++)
    {
        puts(strupr(lv.lv[i].designacao));
              
    }      
    printf("==========================================\n\n\n"); 
}

void editarVacinas(ListaVacinas *lv, int idAEditar) {
    int op = 0;
    while(op != 4) {
        printf(">>> Edicao de Vacinas <<<\n\n");
        printf("1 - Nome da Vacina\n"); 
        printf("2 - Numero de doses\n");
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
            case 4:
                break;
            default: 
                printf("Opção errada");
                break;
        }
    }
}