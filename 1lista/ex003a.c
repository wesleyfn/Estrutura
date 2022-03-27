#include <stdio.h>
/*
    Multiplicacao de dois números naturais, atraves de somas sucessivas (Ex.: 6 ∗ 4 = 4+4+4+4+4+4).
*/
int mult_soma(int, int);

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

/*
3+4
f(0) = 3
f(1) = f(0) + 1 // 4 // 4
f(2) = f(1) + 1 // 5 // 3
f(3) = f(2) + 1 // 6 // 2
f(4) = f(3) + 1 // 7 // 1
                     // 0
*/