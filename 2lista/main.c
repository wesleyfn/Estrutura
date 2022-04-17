#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ferramentas.h"

int main(void)
{
    /* Criar uma listaA não ordenada de tamanho 2*LSIZE
       preenchida de forma aleatória. */
    TListAlunos *listA = geraListAlunos(2 * LSIZE, 2 * LSIZE, FALSE);

    /* Declarar uma listaB não ordenada de capacidade LSIZE */
    TListAlunos *listB = iniListAlunos(LSIZE, FALSE);

    /*
      Selecione em ordem aleatória todos os itens da
      listaA e inclua na listaB. Conte quantas vezes a
      função de inclusão retorna verdadeiro e quantas
      retorna falso. No final mostre os valores
      contabilizados junto com o tamanho da listaB
    */
    int n;
    int i = 0, j = 0;

    srand(time(NULL));

    do
    {
        n = rand() % (2 * LSIZE);
        if (incAlunoNaLista(listA->lista[n], listB) == TRUE)
        {
            i++;
        }
        else
        {
            if (incAlunoNaLista(listA->lista[n], listB))
                continue;
            i++;
        }
    } while (i < 2 * LSIZE);

    /*
      Selecione em ordem aleatória todos os itens da
      listaA e inclua na listaC. Conte quantas vezes a
      função de inclusão retorna verdadeiro e quantas
      retorna falso. No final mostre os valores
      contabilizados junto com o tamanho da listaC
    */
    /* Declarar uma listaC ordenada de capacidade LSIZE */
    TListAlunos *listC = iniListAlunos(LSIZE, TRUE);

    do
    {
        n = rand() % (2 * LSIZE);
        if (incAlunoNaLista(listA->lista[n], listC) == TRUE)
        { // true
            j++;
        }
        else
        {
            if (incAlunoNaLista(listA->lista[n], listC))
                continue;
            j++;
        }
    } while (j < 2 * LSIZE);

    puts("Lista A:");
    printLista(listA);
    puts("Lista B:");
    printLista(listB);
    puts("Lista C:");
    printLista(listC);

    int cap = listB->cap + listC->cap;
    TListAlunos *listUniao = iniListAlunos(cap, FALSE);
    /*
      Crie a lista união da listaB com a ListaC.
      Mostre o tamanho desta lista.
    */
    uniaoListas(listB, listC, listUniao);
    printf("\nLista Uniao B e C:\n");
    printLista(listUniao);
    printf("Tamanho de Uniao: %d\n", listUniao->tam);

    /*
      Crie a lista diferença da listaB com a ListaC.
      Mostre o tamanho desta lista.
    */
    TListAlunos *listDiferBC = iniListAlunos(LSIZE, FALSE);
    diferenListas(listB, listC, listDiferBC);
    printf("\nLista Diferenca B e C:\n");
    printLista(listDiferBC);
    printf("Tamanho da Diferenca: %d\n", listDiferBC->tam);

    /*
      Crie a lista diferença da listaC com a ListaB.
      Mostre o tamanho desta lista
    */
    TListAlunos *listDiferCB = iniListAlunos(LSIZE, FALSE);
    // No pior caso a diferenca sera a propria lista C

    diferenListas(listC, listB, listDiferCB);
    printf("\nLista Diferenca C e B:\n");
    printLista(listDiferCB);
    printf("Tamanho da Diferenca: %d\n", listDiferCB->tam);

    /*
      Crie a lista intersecção da listaB com a ListaC.
      Mostre o tamanho desta lista.
    */
    cap = (listB->cap > listC->cap) ? listC->cap : listB->cap;
    /* No pior caso a intersecao sera a menor lista, ou seja a 
    capacidade da resultante sera igual a capacidade da menor lista */

    TListAlunos *listInterBC = iniListAlunos(cap, FALSE);
    interListas(listB, listC, listInterBC);
    printf("\nLista Interseccao B e C:\n");
    printLista(listInterBC);
    printf("Tamanho da Interseccao: %d\n", listInterBC->tam);

    /*
      Verifique se os tamanhos reportados são
      consistentes.
    */

    /*
       Transforma a listaA numa lista ordenada.
    */
    ordenaLista(listA);
    printf("\nLista A ordenada:\n");
    printLista(listA);
    printf("Tamanho da Lista A: %d\n", listA->tam);

    free(listA);
    free(listB);
    free(listC);
    free(listInterBC);
    free(listUniao);
    free(listDiferBC);
    free(listDiferCB);
    return 0;
}