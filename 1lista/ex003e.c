#include <stdio.h>
#include <string.h>
/*
    Verifique se uma palavra eh palindromo.
*/
int isPalindromo(char *str, int start, int end);

int main(void)
{
    char str[50];

    printf("Digite uma string: ");
    scanf("%[^\n]", str);

    printf("Resultado: ");
    if (isPalindromo(str, 0, strlen(str)-1)) //oi
        printf("é um palindromo!\n");
    else
        printf("não é um palindromo!\n");
    return 0;
}

int isPalindromo(char *str, int start, int end) //tennet
{
    if (start == end || start == (start+end+1)/2)
        return 1;
    else if (str[start] == str[end]) //str[3] == str[2]
        return isPalindromo(str, ++start, --end);
    else 
        return 0;
}