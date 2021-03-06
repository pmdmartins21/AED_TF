#include "listaUtentes.h"
#include <stdio.h>
#include <string.h>

void inserirUtente(ListaUtentes *lu, ListaCentros *lc, ListaVacinas *lv)
{
    Utente u = criarUtente();
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

void listarUtentes(ListaUtentes *lu, ListaVacinas *lv, ListaCentros *lc) {
    int indiceIDCentro;
    int indiceIDVacina;

    printf("N.UTENTE   |       NOME         |  IDADE |  TELEFONE  |       Vacina    |DOSES|     CENTRO VAC.    | DATA ULTIMA DOSE\n");
    char dataUltimaDose[20];
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        indiceIDCentro = procurarIDNaListaCentros(lc, lu->lu[i].centroID);
        indiceIDVacina = procurarIDNaListaVacinas(lv, lu->lu[i].vacinaID);
        sprintf(dataUltimaDose, "%d/%d/%d", lu->lu[i].dataUltimaDosagem.dias,lu->lu[i].dataUltimaDosagem.meses, lu->lu[i].dataUltimaDosagem.ano);
        printf(" %d  | %19s|    %d  |%12s| %15s |  %d  |%18s  | %s\n",lu->lu[i].numeroDeUtente,lu->lu[i].nome,lu->lu[i].idade,lu->lu[i].contatoTelefonico,lv->lv[indiceIDVacina ].designacao,lu->lu[i].quantidadeDosesAdmn,lc->centros[indiceIDCentro].nomeCentro,dataUltimaDose);
    }
    
}

void listarUtentesPorVacinas(ListaUtentes *lu, ListaVacinas *lv)
{
    printf("===== LISTAGEM POR VACINA =====\n");
    for (int i = 0; i < lv->numeroVacinas; i++) // correr lista vacinas
    {
        char dataUltimaDose[20];
        printf("======== VACINA %s ========\n", lv->lv[i].designacao);
        printf("N. UTENTE|          NOME          |  IDADE |  TELEFONE  | DOSES ADMINISTRADAS | DATA ULTIMA DOSE ADMINISTRADA\n");
                   
        for (int j = 0; j < lu->numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
        {
            if (lu->lu[j].vacinaID == lv->lv[i].idVacina)
            {
                sprintf(dataUltimaDose, "%d/%d/%d", lu->lu[i].dataUltimaDosagem.dias,lu->lu[i].dataUltimaDosagem.meses, lu->lu[i].dataUltimaDosagem.ano);
                printf("%d |%-23s |   %d   |%12s|           %d         |            %s\n",lu->lu[j].numeroDeUtente, lu->lu[j].nome, lu->lu[j].idade, lu->lu[j].contatoTelefonico, lu->lu[j].quantidadeDosesAdmn ,dataUltimaDose);
            }
            
        }
        printf("\n") ;   
    }
    printf("===============================\n\n\n");
}

void listarUtentesPorCentro(ListaUtentes *lu, ListaCentros *lc) {
    printf("===== LISTAGEM POR CENTRO =====\n");
    for (int i = 0; i < lc->numeroCentros; i++) // correr lista de centros
        {
            
            printf("====== Centro %s ======\n", lc->centros[i].nomeCentro);
            printf("N. UTENTE|          NOME           |  IDADE|  TELEFONE  | DOSES ADMINISTRADAS | DATA ULTIMA DOSE ADMINISTRADA\n");
            for (int j = 0; j < lu->numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
            {
                if (lu->lu[j].centroID == i+1)
                {
                    char dataUltimaDose[20];
                    sprintf(dataUltimaDose, "%d/%d/%d", lu->lu[i].dataUltimaDosagem.dias,lu->lu[i].dataUltimaDosagem.meses, lu->lu[i].dataUltimaDosagem.ano);
                    printf("%d |%-24s |   %d  |%12s|           %d         |            %s\n",lu->lu[j].numeroDeUtente, lu->lu[j].nome, lu->lu[j].idade, lu->lu[j].contatoTelefonico, lu->lu[j].quantidadeDosesAdmn ,dataUltimaDose);
                }
                
            }
            printf("\n") ;
        }
        printf("===============================\n\n\n");
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

void vacinarUtente(ListaUtentes *lu, ListaVacinas *lv, ListaCentros *lc) {
    int id;
    printf("Introduza o ID do Utente a ser vacinado: \n");
    scanf("%d", &id);
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == id)
        {
            int centroID, vacinaID, qttdDosesAdministradas;
            Data dataVacina;
            listarCentros(lc);
            printf("Indique o ID do centro onde foi vacinado\n");
            scanf("%d", &centroID);
            listarVacinas(lv);
            printf("Indique o ID da vacina administrada\n");
            scanf("%d", &vacinaID);
            printf("Indique qual a dose administrada (1a, 2a, ...)\n");
            scanf("%d", &qttdDosesAdministradas);
            printf("Indique a data de vacinacao: Ex: 21/01/2020\n");
            printf("Dia: ");
            scanf("%d", &dataVacina.dias);
            printf("Mes: ");
            scanf("%d", &dataVacina.meses);
            printf("Ano: ");
            scanf("%d", &dataVacina.ano);
            lu->lu[i].centroID = centroID;
            lu->lu[i].vacinaID = vacinaID;
            lu->lu[i].quantidadeDosesAdmn = qttdDosesAdministradas;
            lu->lu[i].dataUltimaDosagem.dias = dataVacina.dias;
            lu->lu[i].dataUltimaDosagem.meses = dataVacina.meses;
            lu->lu[i].dataUltimaDosagem.ano = dataVacina.ano;
        }
    }
    
    
}



void alterarNomeUtente(ListaUtentes *lu, int idAEditar) 
{
    int counter = 0;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o novo nome do Utente:\n");
            strcpy(lu->lu[i].nome,"\0");
            fgets(lu->lu[i].nome, 101, stdin);
            lu->lu[i].nome[strlen(lu->lu[i].nome) -1 ] = '\0';
            break;
            counter ++;
        }
    }
    if (counter == 0)
    {
        printf("Numero do Utente nao encontrado não encontrado");
    }
}

void alterarContacto(ListaUtentes *lu, int idAEditar) 
{
    int counter = 0;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o novo contacto telefonico do Utente:\n");
            strcpy(lu->lu[i].contatoTelefonico,"\0");
            fgets(lu->lu[i].contatoTelefonico, 101, stdin);
            lu->lu[i].contatoTelefonico[strlen(lu->lu[i].contatoTelefonico) -1 ] = '\0';
            break;
            counter ++;
        }
    }
    if (counter == 0)
    {
        printf("Numero do Utente nao encontrado não encontrado");
    }
}

void alterarIdadeUtente(ListaUtentes *lu, int idAEditar) 
{
    int novaIdade;
    int counter = 0;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira a idade do Utente:\n");
            scanf("%d", &novaIdade);
            lu->lu[i].idade = novaIdade;
            counter++;
            break;
        }
    
    }
    if (counter == 0)
    {
        printf("Numero do Utente nao encontrado não encontrado");
    }
    
}

void alterarNumeroUtente(ListaUtentes *lu, int idAEditar) 
{
    int novoNumeroUtente;
    int counter = 0;
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].numeroDeUtente == idAEditar)
        {
            printf("Insira o numero do Utente:\n");
            scanf("%d", &novoNumeroUtente);
            lu->lu[i].numeroDeUtente = novoNumeroUtente;
        break;
        counter ++;
        }
    }
    if (counter == 0)
    {
        printf("Numero do Utente nao encontrado não encontrado");
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
                break;
                
                default: 
                    printf("Opcao errada");
                    break;
            }

            
        }
}

int totalVacinasAdministradas (ListaUtentes *lu) {
    int totalVacinas = 0;
    int vacinaUser;
    if (lu->numeroUtentes == 0)
    {
        return totalVacinas;
    }
    
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        int vacinaUser =  lu->lu[i].quantidadeDosesAdmn;
        totalVacinas = totalVacinas + vacinaUser;
    }   
    return totalVacinas;
}

float mediaIdadesVacinados(ListaUtentes *lu) {
    float media;
    int totalIdade = 0, idadeUser, numeroUtentesVacinados = 0;
    if (lu->numeroUtentes == 0)
    {
        return 0.0f;
    }
    for (int i = 0; i < lu->numeroUtentes; i++)
    {
        if (lu->lu[i].quantidadeDosesAdmn > 0)
        {
            idadeUser = lu->lu[i].idade;
            totalIdade = totalIdade + idadeUser;
            numeroUtentesVacinados++;
        } 
    }
    if (numeroUtentesVacinados == 0)
    {
        return 0;
    }
    
    media = totalIdade*1.0/numeroUtentesVacinados;
    return media;
}

void numeroUtentesVacinadosporVacinas(ListaUtentes *lu, ListaVacinas *lv) {
    
    for (int i = 0; i < lv->numeroVacinas; i++) // correr lista vacinas
    {  
        int counterUtentes = 0;
        for (int j = 0; j < lu->numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
        {
           if (lu->lu[j].vacinaID == lv->lv[i].idVacina)
           {
               counterUtentes++;
           }
           
        }
        printf("===== VACINA %25s | UTENTES VACINADOS: %d=====\n", lv->lv[i].designacao,counterUtentes);
    }
}

void proximaVacinaUtente(ListaUtentes *lu, ListaVacinas *lv) {
    int idUtente;
    int idVacina;
    int intervaloEntreVacinas;
    char dataProximaDose[50];
    Data dataProximaVacina;
    
    printf("Indique o ID do Utente: \n");
    scanf("%d", &idUtente);
    for (int i = 0; i < lu->numeroUtentes; i++) // corre lista utentes
    {
        if (lu->lu[i].numeroDeUtente == idUtente) //encontra utente 
        {
            for (int j = 0; j < lv->numeroVacinas; j++) // correr lista vacinas
            {
                if (lu->lu[i].vacinaID == lv->lv[j].idVacina) // encontra a vacina
                {
                    intervaloEntreVacinas = lv->lv[j].tempoEntreVacinas;
                    dataProximaVacina.dias = lu->lu[i].dataUltimaDosagem.dias; //1
                    dataProximaVacina.meses = lu->lu[i].dataUltimaDosagem.meses + intervaloEntreVacinas; // pode ultrapassar o mes  + 2
                    dataProximaVacina.ano = lu->lu[i].dataUltimaDosagem.ano; // 2020
                    if(dataProximaVacina.meses > 12) {
                        
                        dataProximaVacina.meses = (lu->lu[i].dataUltimaDosagem.meses +  intervaloEntreVacinas) - 12;
                        dataProximaVacina.ano++;
                    }
                    sprintf(dataProximaDose, "A data da proxima dose e: %d/%d/%d", dataProximaVacina.dias,dataProximaVacina.meses, dataProximaVacina.ano);
                    puts(dataProximaDose);
                }
                
            }
        }
        
    }
}

void listarUtentesAVacinarNoDia(ListaUtentes *lu, ListaVacinas *lv) {
    int idUtente;
    int idVacina;
    int totalAVacinar = 0;
    //char dataProximaDose[50];
    Data dataVacinacaoAVerificaar;
    printf("Indique a Data a verificar: (ex: 21/01/2021)\n");
    printf("Dia: ");
    scanf("%d", &dataVacinacaoAVerificaar.dias);
    printf("Mes: ");
    scanf("%d", &dataVacinacaoAVerificaar.meses);
    printf("Ano: ");
    scanf("%d", &dataVacinacaoAVerificaar.ano);


    for (int i = 0; i < lu->numeroUtentes; i++) // percorrer a lista de utentes e fazer match ao dia
    {
        char dataUltimaDose[20];
        if (lu->lu[i].dataUltimaDosagem.dias == dataVacinacaoAVerificaar.dias 
        && lu->lu[i].dataUltimaDosagem.meses + lv->lv[lu->lu[i].vacinaID - 1].tempoEntreVacinas == dataVacinacaoAVerificaar.meses 
        && lu->lu[i].dataUltimaDosagem.ano == dataVacinacaoAVerificaar.ano) 
        {
            printf(" N.UTENTE |       NOME        |   TELEFONE   | CENTRO VAC. | DATA ULTIMA DOSE\n");
            sprintf(dataUltimaDose, "%d/%d/%d", lu->lu[i].dataUltimaDosagem.dias,lu->lu[i].dataUltimaDosagem.meses, lu->lu[i].dataUltimaDosagem.ano);
            printf(" %d | %18s|  %s   |     %d       | %s\n",lu->lu[i].numeroDeUtente,lu->lu[i].nome,lu->lu[i].contatoTelefonico,lu->lu[i].centroID,dataUltimaDose);
            totalAVacinar++;
        }
        
    }
    if(totalAVacinar == 0) {
        printf("Ninguem tem de ser vacinado nesse dia!\n\n");
    }
}



 