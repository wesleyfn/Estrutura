#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
    int key;
    struct lista *prox;
} TLista;

TLista *inserirLista(TLista *lista, int key);

int main(void)
{
    TLista *raiz = NULL, *ultimo;

    int n;
    do {
        printf("Digite o valor != 0: ");
        scanf(" %d", &n);

        raiz = inserirLista(raiz, n);
    } while (n);
    

    for( ; raiz != NULL ; )
    {
        ultimo = raiz;
        printf("[ Key: %d ] ", ultimo->key);
        raiz = ultimo->prox;
        free(ultimo);
    }
    printf("\n");
    return 0;
}

/*
    Adiciona um elemento no inicio da lista
    @param lista elemento que será apontado pelo novo elemento
    @param key valor chave (identificador)
*/
TLista *inserirLista(TLista *lista, int key)
{
    TLista *novo = malloc(sizeof(TLista));
    if (novo == NULL) {
        puts("Erro de alocacao!");
        exit(-1);
    }
    novo->key = key;
    novo->prox = lista;
    return novo;
}
