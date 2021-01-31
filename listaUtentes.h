#include "utente.h"

typedef struct sListaUtentes
{
    Utente lu[1000];
    int numeroUtentes;
    
} ListaUtentes;

void inserirUtente(ListaUtentes *lu);
int procurarIDNaLista(ListaUtentes *lu, int idAProcurar);
void eliminarUtente(ListaUtentes *lu);
void editarUtente(ListaUtentes *lu, int idAEditar);
void alterarNomeUtente(ListaUtentes *lu, int idAEditar);
void alterarContacto(ListaUtentes *lu, int idAEditar);
void alterarIdadeUtente(ListaUtentes *lu, int idAEditar);
void alterarNumeroUtente(ListaUtentes *lu, int idAEditar);

void listarUtentesPorVacinas(ListaUtentes *lu, ListaCentros *lc, ListaVacinas *lv);
for (int i = 0; i < lv.numeroVacinas; i++) // correr lista vacinas
{
        printf("===== VACINA i =====")

        for (int j = 0; j < lu.numeroUtentes; j++) // correr lista utentes e ver se o vacinaID do utente == i
        {
            if (lu.lu[j].vacinaID == i+1)
            {
                printf("Utente j")
            }
            
        }
            
}

printf("===== VACINA 1 =====")




void listarUtentesPorCentro(ListaUtentes *lu);
