#include <stdio.h>
/*
    Multiplicacao de dois números naturais, atraves de somas sucessivas (Ex.: 6 ∗ 4 = 4+4+4+4+4+4).
*/
int mult_soma(int x, int y);

int main(void)
{
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);

    printf("Resultado: %d\n", mult_soma(x, y));
    return 0;
}

int mult_soma(int x, int y)
{
    if (y < 1)
        return 0;
    return x + mult_soma(x, --y);
}