#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char *bin)
{
    int len = strlen(bin);
    int decimal = 0;

    for(int i = 0; i < len; i++)
    {
        if(bin[len - 1 - i] == '1')
            decimal += pow(2, i);
    }

    return decimal;
}

void decimalToTernary(int num)
{
    int ternary[64];
    int i = 0;

    if(num == 0)
    {
        printf("0");
        return;
    }

    while(num > 0)
    {
        ternary[i++] = num % 3;
        num /= 3;
    }

    for(int j = i - 1; j >= 0; j--)
        printf("%d", ternary[j]);
}

int main()
{
    char bin[64];

    printf("Digite um numero binario: ");
    scanf("%s", bin);

    int decimal = binaryToDecimal(bin);

    printf("Ternario: ");
    decimalToTernary(decimal);
    printf("\n");

    return 0;
}