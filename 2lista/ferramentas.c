#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(TAluno *vet, int esq, int dir);

TListAlunos *iniListAlunos(int cap, int eOrd)
{
    TAluno *lista = malloc(sizeof(TAluno) * (cap + 1));
    TListAlunos *lAlunos = malloc(sizeof(TListAlunos));
    if (lAlunos == NULL || lista == NULL)
    {
        puts("Erro de memoria!");
        exit(-1);
    }

    lAlunos->tam = 0;
    lAlunos->cap = cap;
    lAlunos->eOrd = eOrd;
    lAlunos->lista = lista;

    return lAlunos;
}

TListAlunos *geraListAlunos(int tam, int cap, int eOrd)
{
    TListAlunos *lAlunos = iniListAlunos(cap, eOrd);

    srand(time(NULL));

    for (int i = 0; i < tam; i++)
    {
        TAluno aluno;
        // Ano 2000 a 2022 * 100000, ex. 201900000
        aluno.numMatricula = ((rand() % 22) + 2000) * 100000;
        // Semestre 1 a 2 * 10000, ex. 20000
        aluno.numMatricula += ((rand() % 2) + 1) * 10000;
        // Numero sequencial 1 a 800, ex. 240
        aluno.numMatricula += (rand() % 800) + 1; // 201920240
        sprintf(aluno.email, "aluno%d@gmail.com", i);
        sprintf(aluno.nome, "Aluno%d", i);
        // printf("\n %s",aluno.email);

        incAlunoNaLista(aluno, lAlunos);
    }
    return lAlunos;
}

int buscaChaveNaLista(int chave, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return buscaAluno_NOrd(lista->lista, lista->tam, chave);
    return buscaAluno_Ord(lista->lista, lista->tam, chave);
}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap);
    return incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap);
}

int remAlunoDaLista(TAluno aluno, TListAlunos *lista)
{
    if (lista->eOrd == FALSE)
        return remAluno_NOrd(aluno.numMatricula, lista->lista, &lista->tam);
    return remAluno_Ord(aluno.numMatricula, lista->lista, &lista->tam);
}

/* Manipulação de listas NÃO ordenadas */
int buscaAluno_NOrd(TAluno *lista, int tam, int chave)
{
    lista[tam].numMatricula = chave;
    int i = 0;

    while (lista[i].numMatricula != chave)
    {
        i++; // retorna o tam se nao encontrar ou o indice se achar
    }
    return i;
}
int incAluno_NOrd(TAluno aluno, TAluno *lista, int *tam, int cap)
{
    if (*tam == cap)
    {
        // printf("Lista cheia!\n");
        return FALSE; /* Lista cheia */
    }
    if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam)
    {
        /* Chave nao foi encontrada entao add no final da lista */
        lista[*tam] = aluno; /* Copia os dados de aluno para lista[*tam] */
        *tam += 1;
        return TRUE;
    }
    else
        return FALSE; /* Chave foi encontrada */
}
int remAluno_NOrd(int chave, TAluno *lista, int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia

    int pos = buscaAluno_NOrd(lista, *tam, chave);
    if (pos < *tam)
    {
        *tam -= 1;
        lista[pos] = lista[*tam];
        return TRUE;
    }
    else
        return FALSE;
}

/* Manipulação de listas ordenadas */
int buscaAluno_Ord(TAluno *lista, int tam, int chave)
{
    int min = 0, max = tam, i = 0;
    while (min != max)
    {
        i = (max + min) / 2;
        if (lista[i].numMatricula < chave)
            min = ++i;
        else if (lista[i].numMatricula > chave)
            max = i;
        else
            return i;
    }
    return i;
}
int incAluno_Ord(TAluno aluno, TAluno *lista, int *tam, int cap)
{
    if (*tam == cap)
        return FALSE; // lista cheia

    int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
    if (pos == *tam)
    {
        lista[*tam] = aluno;
        *tam += 1;
        return TRUE;
    }
    else if (lista[pos].numMatricula != aluno.numMatricula)
    {
        for (int i = *tam; i > pos; i--)
        {
            lista[i] = lista[i - 1];
        }
        lista[pos] = aluno;
        *tam += 1;
        return TRUE;
    }
    else
        return FALSE;
}
int remAluno_Ord(int chave, TAluno *lista, int *tam)
{
    if (*tam == 0)
        return FALSE; // lista vazia

    int pos = buscaAluno_Ord(lista, *tam, chave);
    if (pos < *tam && lista[pos].numMatricula == chave)
    {
        for (int i = pos; i < *tam - 1; i++)
        {
            lista[i] = lista[i + 1];
        }
        *tam -= 1;
        return TRUE;
    }
    else
        return FALSE;
}

void ordenaLista(TListAlunos *listaA)
{
    if (listaA->eOrd == TRUE)
        return;

    quickSort(listaA->lista, 0, listaA->tam - 1);
    listaA->eOrd = TRUE;
    return;
}

void quickSort(TAluno *vet, int esq, int dir)
{
    int pivo = esq;
    int i, ch, j;

    for (i = esq + 1; i <= dir; i++)
    {
        j = i;
        if (vet[j].numMatricula < vet[pivo].numMatricula)
        {
            ch = vet[j].numMatricula;
            while (j > pivo)
            {
                vet[j].numMatricula = vet[j - 1].numMatricula;
                j--;
            }
            vet[j].numMatricula = ch;
            pivo++;
        }
    }
    if (pivo - 1 >= esq)
        quickSort(vet, esq, pivo - 1);
    if (pivo + 1 <= dir)
        quickSort(vet, pivo + 1, dir);
}

void printLista(TListAlunos *lista)
{
    printf("[");
    for (int i = 0; i < lista->tam; i++)
        printf(" %d", lista->lista[i].numMatricula);
    printf(" ]\n");
    return;
}

void uniaoListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    diferenListas(lista1, lista2, lista3);
    diferenListas(lista2, lista1, lista3);
    interListas(lista1, lista2, lista3);
}
void diferenListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    for (int i = 0; i < lista1->tam; i++)
    {
        if (buscaAluno_NOrd(lista2->lista, lista2->tam,
                            lista1->lista[i].numMatricula) == lista2->tam)
        {
            // printf("\nDiferenca: %d",lista1->lista[i].numMatricula);
            incAlunoNaLista(lista1->lista[i], lista3);
        }
    }
}
void interListas(TListAlunos *lista1, TListAlunos *lista2, TListAlunos *lista3)
{
    for (int i = 0; i < lista1->tam; i++)
    {
        if (buscaAluno_NOrd(lista2->lista, lista2->tam, 
                            lista1->lista[i].numMatricula) != lista2->tam)
        {
            // printf("\nIntersecao: %d",lista1->lista[i].numMatricula);
            incAlunoNaLista(lista1->lista[i], lista3);
        }
    }
}
