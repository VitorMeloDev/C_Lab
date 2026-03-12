#include <stdio.h>
#include <string.h>
#include <math.h>

int ternaryToDecimal(char *ter)
{
    int len = strlen(ter);
    int decimal = 0;

    for(int i = 0; i < len; i++)
    {
        decimal += (ter[len - 1 - i] - '0') * pow(3, i);
    }

    return decimal;
}

void decimalToBinary(int num)
{
    int binary[64];
    int i = 0;

    if(num == 0)
    {
        printf("0");
        return;
    }

    while(num > 0)
    {
        binary[i++] = num % 2;
        num /= 2;
    }

    for(int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main()
{
    char ter[64];

    printf("Digite um numero ternario: ");
    scanf("%s", ter);

    int decimal = ternaryToDecimal(ter);

    printf("Binario: ");
    decimalToBinary(decimal);
    printf("\n");

    return 0;
}