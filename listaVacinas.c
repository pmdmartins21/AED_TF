#include "listaVacinas.h"
#include <stdio.h>

void inserirVacina(ListaVacinas *lv){
    Vacina v = criarVacina(lv->numeroVacinas);
    lv->lv[lv->numeroVacinas] = v;
    lv->numeroVacinas++;
}

int listarVacinas(ListaVacinas lv){
    int idVacina;
    for (int i = 0; i< lv.numeroVacinas; i++){
        printf("%d -> %s \n", lv.lv[i].idVacina, lv.lv[i].designacao);
    }
    scanf("%d", &idVacina);

    //falta controlar se a opcao inserida
    return idVacina;
}

void getTurmaById(int turmaID, ListaTurmas lt){
    for(int i = 0; i < lt.numeroTurmas; i++ ){
        if(lt.lt[i].turmaID == turmaID) {
            printf("Descritivo: %s", lt.lt[i].descritivo);
        }
    }
}

ListaVacinas procurarVacina(ListaVacinas lv, int vacinaId){
    for (int i = 0; i < lv->numeroVacinas; i++)
    {
        if (lv.lt[i].idVacina == vacinaId)
        {
            return v;
            //menu
        }
    }
} 
ListaVacinas editarVacinas();