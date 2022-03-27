#include <stdio.h>
/*
    Implemente uma funcao recursiva soma(n) que calcula o somatorio dos n primeiros numeros inteiros. 
    
    - Qual eh a ordem de complexidade da sua funcao? 
    - Qual seria a ordem de complexidade dessa mesma funcao implementada sem utilizar recursividade? 
    - O que voce conclui?
*/
int soma(int);

int main(void)
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Resultado: %d\n", soma(n));

    return 0;
}

/*
    Complexidade do algoritmo = 0(n)
    Conclui-se que a ordem de complexidade seria aproximadamente a mesma sendo iterativa ou recursiva.
*/
int soma(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return n + soma(n-1);
}