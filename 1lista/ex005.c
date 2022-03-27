#include <stdio.h>
/*
    A sequência de Fibonacci é uma sequencia de elementos f1, …, fn, definida do seguinte modo: 
    f1 = 0; f2 = 1;
    fj = fj-1 + fj-2 para j > 2.

    - Elaborar um algoritmo recursivo para calcular a sequencia de Fibonacci para qualquer valor de n;
    - Determinar o numero de chamadas recursivas e a complexidade do algoritmo implementado;
    - Construir um algoritmo nao recursivo para calcular o elemento n da sequencia, cuja complexidade seja linear com n.
*/
int rec_fib(int n);
int ite_fib(int n);
int qtd = 0;
int main(void)
{
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("> Recursivo: %d\n", rec_fib(n));
    printf("> Iterativo: %d\n", ite_fib(n));
    printf(":: %d\n", qtd);
    return 0;
}

/*
    Numero de chamadas recursivas = n
    Complexidade do algoritmo = 0(2^n)
*/

int rec_fib(int n)
{
    qtd++;
    if (n == 1 || n == 2) //0(1)
        return 1;
    return rec_fib(n-1) + rec_fib(n-2);
}

/*
    Complexidade do algoritmo = 0(n)
*/
int ite_fib(int n)
{
    int anterior = 1, atual = 1, total;

    if (n == 1 || n == 2)
        return 1;

    for (int i = 2; i < n; i++)
    {
        total = anterior + atual;
        anterior = atual;
        atual = total;
    }
    return total;
}
