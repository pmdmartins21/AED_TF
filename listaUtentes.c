#include "listaUtentes.h"
#include <stdio.h>
#include <string.h>

void inserirUtente(ListaUtentes *lu, ListaCentros *lc, ListaVacinas *lv)
{
    Utente u = criarUtente();
    listarCentros(lc);
    printf("Indique o ID do centro onde foi vacinado\n");
    scanf("%d", &u.centroID);
    listarVacinas(lv);
    printf("Indique o ID da vacina administrada\n");
    scanf("%d", &u.vacinaID);
    u.quantidadeDosesAdmn = 1; //ao criar estamos a assumir que está a receber a primeira dose
    printf("Indique a data de hoje: Ex: 21/01/2020\n");
    printf("Dia: ");
    scanf("%d", &u.dataUltimaDosagem.dias);
    printf("Mes: ");
    scanf("%d", &u.dataUltimaDosagem.meses);
    printf("Ano: ");
    scanf("%d", &u.dataUltimaDosagem.ano);
    u.numeroDeUtente = (lu->numeroUtentes + 1);
    lu->lu[lu->numeroUtentes] = u;
    lu->numeroUtentes ++;
}

int procurarIDNaLista(ListaUtentes *lu, int idAProcurar) 
{
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if(lu->lu[i].numeroDeUtente == idAProcurar) 
        {
            return i;
        }
    }
    return -1;
}

void eliminarUtente(ListaUtentes *lu)
{
    int numeroAEliminar;
    //imprimir lista
    printf("Lista antes de remover:\nQuantidade: %d\nMembros:\n", lu->numeroUtentes);
    for(int i = 0; i< lu->numeroUtentes; i++) printf("%d\n", lu->lu[i].numeroDeUtente);
    printf("Qual e o numero do utente que deseja eliminar? \n");
    scanf("%d", &numeroAEliminar);

    int i;
    for(i = 0; i <lu->numeroUtentes;i++){
        if(lu->lu[i].numeroDeUtente == numeroAEliminar) break;
    }
    for(int j = i+1; j < lu->numeroUtentes; j++){
        lu->lu[j-1] = lu->lu[j];
    }
    lu->numeroUtentes= lu->numeroUtentes -1;

    printf("\nLista depois de remover:\nQuantidade: %d\nMembros:\n", lu->numeroUtentes);
    for(int i = 0; i< lu->numeroUtentes; i++) printf("%d\n", lu->lu[i].numeroDeUtente);        
        
    
}

void listarUtentes(ListaUtentes *lu) {
    printf("N.UTENTE |       NOME       |  IDADE | TELEFONE | Vacina |  DOSES | CENTRO VAC. | DATA ULTIMA DOSE\n");
    char dataUltimaDose[20];
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        sprintf(dataUltimaDose, "%d/%d/%d", lu->lu[i].dataUltimaDosagem.dias,lu->lu[i].dataUltimaDosagem.meses, lu->lu[i].dataUltimaDosagem.ano);
        printf(" %d  | %15s| %d  |  %s    |  %d   |  %d  |  %d  | %s\n",lu->lu[i].numeroDeUtente,lu->lu[i].nome,lu->lu[i].idade,lu->lu[i].contatoTelefonico,lu->lu[i].vacinaID,lu->lu[i].quantidadeDosesAdmn,lu->lu[i].centroID,dataUltimaDose);
    }
    
}

void listarUtentesPorVacinas(ListaUtentes *lu, ListaVacinas *lv)
{
    for (int i = 0; i < lv->numeroVacinas; i++) // correr lista vacinas
    {
        printf("===== VACINA %d =====", lv->lv[i].idVacina);
        printf("NOME   |  IDADE | TELEFONE | DOSES ADMINISTRADAS | DATA ULTIMA DOSE ADMINISTRADA");

        for (int j = 0; j < lu->numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
        {
            if (lu->lu[j].vacinaID == lv->lv[i].idVacina)
            {
                
                printf("%s | %d  |  %s  |  %d  |    %s", lu->lu[j].nome, lu->lu[j].idade, lu->lu[j].contatoTelefonico, lu->lu[j].quantidadeDosesAdmn ,lu->lu[j].dataUltimaDosagem);
            }
            
        }
            
    }
}

void gravarDadosListaUtentes(ListaUtentes lu) 
{
    FILE * ficheiro = fopen("listaUtentes.dat", "wb");
    rewind(ficheiro);
    fwrite(&lu, sizeof(ListaUtentes), 1, ficheiro);
    fclose(ficheiro);
}

void carregarDadosListaUtentes(ListaUtentes *lu)
{
    FILE *ficheiro;
    ficheiro = fopen("listaUtentes.dat", "rb");

    if(ficheiro == NULL) return;

    fread(lu, sizeof(ListaUtentes), 1, ficheiro);

    fclose(ficheiro);
}



void listarUtentesPorCentro(ListaUtentes *lu, ListaCentros *lc) {
    for (int i = 0; i < lc->numeroCentros; i++) // correr lista de centros
        {
            printf("===== Centro %d =====", i+1);
            printf("NOME   |  IDADE | TELEFONE | DOSES ADMINISTRADAS | DATA ULTIMA DOSE ADMINISTRADA");
            for (int j = 0; j < lu->numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
            {
                if (lu->lu[j].centroID == i+1)
                {
                    printf("%s | %d  |  %s  |  %d  |    %s", lu->lu[j].nome, lu->lu[j].idade, lu->lu[j].contatoTelefonico, lu->lu[j].quantidadeDosesAdmn ,lu->lu[j].dataUltimaDosagem);
                }
                
            }
            
        }
}

void alterarNomeUtente(ListaUtentes *lu, int idAEditar) 
{

    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o novo nome do Utente:\n");
            strcpy(lu->lu[i].nome,"\0");
            fgets(lu->lu[i].nome, 101, stdin);
            lu->lu[i].nome[strlen(lu->lu[i].nome) -1 ] = '\0';
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarContacto(ListaUtentes *lu, int idAEditar) 
{

    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o novo contacto telefonico do Utente:\n");
            strcpy(lu->lu[i].contatoTelefonico,"\0");
            fgets(lu->lu[i].contatoTelefonico, 101, stdin);
            lu->lu[i].contatoTelefonico[strlen(lu->lu[i].contatoTelefonico) -1 ] = '\0';
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarIdadeUtente(ListaUtentes *lu, int idAEditar) 
{
    int novaIdade;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira a idade do Utente:\n");
            scanf("%d", &novaIdade);
            lu->lu[i].idade = novaIdade;
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void alterarNumeroUtente(ListaUtentes *lu, int idAEditar) 
{
    int novoNumeroUtente;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o numero do Utente:\n");
            scanf("%d", &novoNumeroUtente);
            lu->lu[i].numeroDeUtente = novoNumeroUtente;
        }else{
            printf("Numero do Utente nao encontrado não encontrado");
        }
    }
}

void editarUtente(ListaUtentes *lu, int idAEditar) 
{
    int op = 0;
    while(op!=5)
        {
            printf(">>> Edicao de Utentes <<<\n\n"); 
            printf("1 - Nome do Utente\n"); 
            printf("2 - Numero do Utente\n");
            printf("3 - Idade do Utente\n");
            printf("4 - Contacto Telefonico\n");
            printf("5 - Sair\n\n");
            printf(">>>ESCOLHA A OPCAO A ALTERAR<<<\n");
            scanf("%d", &op);
            fflush(stdin);
            switch(op)
            {
                case 1: 
                    alterarNomeUtente(lu, idAEditar);
                    break;
                
                case 2: 
                    alterarNumeroUtente(lu, idAEditar);
                    break;
                
                case 3: 
                    alterarIdadeUtente(lu, idAEditar);
                    break;
                
                case 4: 
                    alterarContacto(lu, idAEditar);
                    break;
                
                case 5:
                //gravarDados(t);
                break;
                
                default: 
                    printf("Opcao errada");
                    break;
            }

            
        }
}







 