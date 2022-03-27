#include <stdio.h>
/*
    Multiplicacao de dois numeros naturais, atraves de incrementos sucessivos.
*/
int mult_incremento(int, int, int);
int main(void)
{
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("Resultado: %d\n", mult_incremento(x, y, x));
    return 0;
}

int mult_incremento(int x, int y, int buffer)
{
    if (y == 1)
        return x;
    else 
    {
        if (buffer > 0)
            return mult_incremento(x, y, --buffer) + 1;
        else
            return mult_incremento(x, --y, x);
    }
}