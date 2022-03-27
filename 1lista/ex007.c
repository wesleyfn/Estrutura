#include <stdio.h>
/*
    Considere a seguinte sequencia definida a partir de uma equacao de diferencas de segunda ordem: 
    y(n) = 2y(n−1) + y(n−2) + n, com y(1) = 0 e y(2) = 0

    - Elaborar um algoritmo recursivo para calcular esta sequência para qualquer valor de n;
    - Determinar o número de chamadas recursivas e a complexidade do algoritmo implementado;
    - Construir um algoritmo não recursivo para calcular o elemento n da sequência, cuja complexidade seja linear com n;
*/
int recSequencia(int n);

int main(void)
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Resultado: %d\n", recSequencia(n));
    
    return 0;
}

/*
    Numero de chamadas recursivas = n
    Complexidade do algoritmo = O(2^n)
*/
int recSequencia(int n)
{
    if (n == 1 || n == 2)
        return 0;
    return 2 * recSequencia(n-1) + recSequencia(n-2) + n;
}
/*
T(N) = T(N-1) + T(N-2) + O(1)
T(1) = O(1)
T(2) = O(1)

//Simplificando
T(N) = T(N-1) + T(N-2) + 1


*/