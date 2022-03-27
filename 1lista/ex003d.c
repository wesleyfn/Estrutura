#include <stdio.h>
#define MAX 5
/*
    A partir de um vetor de números inteiros, calcule a soma e o produto dos elementos do vetor.
*/
int soma(int *, int);
int mult(int *, int);

int main(void)
{
    int vetor[MAX] = {2,2,2,2,2};
    printf("Soma: %d\n", soma(vetor, MAX));
    printf("Mult: %d\n", mult(vetor, MAX));

    return 0;
}

int soma(int *vetor, int qtd)
{
    if (qtd == 0)
        return 0;
    return *vetor + soma(vetor+1, --qtd);
}

int mult(int *vetor, int qtd)
{
    if (qtd == 0)
        return 1;
    return *vetor * mult(vetor+1, --qtd);
}