#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

void reverse(char *str)
{
    int i, j;
    char temp;
    int len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void add(char *a, char *b, char *result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bitA + bitB + carry;

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';
    reverse(result);
}

void subtract(char *a, char *b, char *result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int borrow = 0;

    while (i >= 0)
    {
        int bitA = a[i--] - '0';
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        bitA -= borrow;

        if (bitA < bitB)
        {
            bitA += 2;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result[k++] = (bitA - bitB) + '0';
    }

    result[k] = '\0';
    reverse(result);
}

void multiply(char *a, char *b, char *result)
{
    char temp[MAX];
    char sum[MAX] = "0";

    int lenB = strlen(b);

    for (int i = lenB - 1; i >= 0; i--)
    {
        if (b[i] == '1')
        {
            strcpy(temp, a);

            int shift = lenB - 1 - i;

            for (int s = 0; s < shift; s++)
                strcat(temp, "0");

            char newSum[MAX];
            add(sum, temp, newSum);
            strcpy(sum, newSum);
        }
    }

    strcpy(result, sum);
}

int main()
{
    char a[MAX], b[MAX];
    char result[MAX];

    printf("Binary A: ");
    scanf("%s", a);

    printf("Binary B: ");
    scanf("%s", b);

    add(a, b, result);
    printf("Add: %s\n", result);

    subtract(a, b, result);
    printf("Subtract (A-B): %s\n", result);

    multiply(a, b, result);
    printf("Multiply: %s\n", result);

    return 0;
}