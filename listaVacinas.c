#include "listaVacinas.h"
#include <stdio.h>

void adicionarVacina(ListaVacinas *lv){
    Vacina v = criarVacina(lv->numeroVacinas);
    lv->lv[lv->numeroVacinas] = v;
    lv->numeroVacinas++;
}

ListaVacinas procurarVacina(ListaVacinas *lv, int vacinaID){
    printf("Introduzir o id:\n");
    scanf("%d", &vacinaID);
    for (int i = 0; i < v.idVacina; i++)
    {
        if (v.idVacina == vacinaID)
        {
            return v;
            //menu
        }
    }
    int = opcao;
    printf("Escolha a opcao para alterar a vacina:\n");
    printf("1- ID\n");
    printf("2- Designacao\n");
    printf("3- Numero de doses\n");
    printf("4- Tempo entre vacinas\n");
    scanf("%d", &opcao);

    ListaVacinas editarVacinas();

    switch (opcao)
    {
        case 1:
            adicionarVacina(&lv);
            break;
        case 2:
            editarVacina(&lv);
            break;
        case 3:
            inativarVacina();
            break;
        case 4:
            listarVacina();
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }
}   

