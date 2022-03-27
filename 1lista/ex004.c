#include <stdio.h>
/*
    O problema da Torre de Hanoi eh comumente utilizado como exemplo de um algoritmo recursivo. 
    O objetivo do problema eh mover todos os discos do pino de origem para o pino destino (o pino da 
    esquerda) para o pino destino (o pino da direita). Voce deve seguir as regras basicas que sao: 
    Somente pode mover um disco de cada vez e um disco maior nunca pode ficar em cima de um disco menor.

    - Discuta a forma de resolver o problema;
    - Faca uma implementacao em C que permita resolver o problema para qualquer quantidade de discos;
    - Determine a complexidade do problema.
*/
void torre_hanoi(int discos, char orig, char dest, char aux);

int main(void)
{
    int n;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &n);
    torre_hanoi(n,'A','C','B');
    return 0;
}

/*
    Complexidade do algoritmo: 0(2^n)
*/
void torre_hanoi(int discos, char orig, char dest, char aux) //T(n)
{
    if(discos == 1)
    {
        printf("Mova disco de %c para %c\n", orig, dest);
        return;
    }

    torre_hanoi(discos-1, orig, aux, dest); //2 A B C
    printf("Mova disco de %c para %c\n", orig, dest); //1 A C B
    torre_hanoi(discos-1, aux, dest, orig); //1 B C A
}