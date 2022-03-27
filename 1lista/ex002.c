#include <stdio.h>
/*
    Considere um sistema numerico que nao tenha a operacao de adicao implementada e que voce disponha 
    somente dos operadores (funcoes) sucessor e predecessor. Entao, pede-se para escrever uma funcao 
    recursiva que calcule a soma de dois numeros x e y atraves desses dois operadores.
*/
int soma(int x, int y);
int sucessor(int x);
int predecessor(int x);

int main(void)
{
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("Resultado: %d\n", soma(x, y));
    return 0;
}

int soma(int x, int y)
{
    if (y < 1)
        return x;
    return soma(sucessor(x), predecessor(y));
}

int sucessor(int x) { return ++x; }
int predecessor(int x) { return --x; }