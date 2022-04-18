#include <stdio.h>
#include <stdlib.h>
#define LMAX 100

void printlista(int* lista, int tam);
void bubbleSort(int* lista, int tam);
void quickSort(int *lista, int esq, int dir);

int main(void)
{
    int lista[LMAX] = {1,5,4,6,2,10,3,8};
    int tam = 8;

    printlista(lista, tam);
    //bubbleSort(lista, tam);
    printlista(lista, tam);
    
    quickSort(lista, 0, tam-1);
    printlista(lista, tam);

    return 0;
}

void printlista(int *lista, int tam)
{
    printf("[ ");
    for (int i = 0; i < tam; i++)
        printf("%d ", lista[i]);
    puts("]");
    return;
}

void bubbleSort(int *lista, int tam)
{
    int wall = 1;
    for (int i = 1; i < tam; i++)
    {
        for (int j = 0; j < tam-wall; j++)
        {
            if (lista[j] > lista[j+1])
            {
                int buffer = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = buffer;
                if (j+1 == tam-wall)
                    wall++;
            }
        }
    }
    return;
}

void quickSort(int lista[], int inicio, int fim)
{
    /*
        lista[8,5,4,6,2,10,3] pivo=[3], i=0, j=0
        if(j[8] <= pivo[3])
    */
    if (inicio < fim) {

        int pivo = lista[fim];
        int i = inicio;
        int buffer = 0;

        for (int j = inicio; j < fim; j++)
        {
            if (lista[j] <= pivo) {
                buffer = lista[j];
                lista[j] = lista[i];
                lista[i] = buffer;
                i++;
            }
            printlista(lista, fim+1);
        }
        buffer = lista[fim];
        lista[fim] = lista[i];
        lista[i] = buffer;
        printlista(lista, fim+1);

        quickSort(lista, inicio, i - 1);
        quickSort(lista, i + 1, fim);
    }
    return;
}


int partition(int *lista, int inicio, int fim) 
{
    int pivo = lista[fim];
    int i = inicio;
    int buffer = 0;

    for (int j = inicio; j < fim; j++)
    {
        if (lista[j] <= pivo) {
            buffer = lista[j];
            lista[j] = lista[i];
            lista[i] = buffer;
            i++;
        }
    }
    buffer = lista[fim];
    lista[fim] = lista[i];
    lista[i] = buffer;
    return i;
}