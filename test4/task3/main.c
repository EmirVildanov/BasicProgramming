#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <wchar.h>
#include <malloc.h>
#include "array.h"

const int maxArraySize = 5;

void getPowerArray(int *powerDigitsArray, int *arrayIndex, int *power)
{
    while (*power != 0)
    {
        int newDigit = *power % 10;
        powerDigitsArray[*arrayIndex] = newDigit;
        ++*arrayIndex;
        *power /= 10;
    }
}

wchar_t makeAppropriatePower(int currentDigit)
{
    wchar_t powerDigit = L' ';
    if (currentDigit == 1)
    {
        powerDigit = 0x00B9;
    }
    else if (currentDigit == 2)
    {
        powerDigit = 0x00B2;
    }
    else if (currentDigit == 3)
    {
        powerDigit = 0x00B3;
    }
    else
    {
        powerDigit = 0x2070 + currentDigit;
    }
    return powerDigit;
}

void checkPowerSign(int *power)
{
    if (*power < 0)
    {
        *power *= -1;
        wchar_t powerSign = 0x207B;
        wprintf(L"%lc", powerSign);
    }
}

void printDegree(int *power)
{
    int *powerDigitsArray = createIntArray(maxArraySize);
    int powerArrayIndex = 0;
    wchar_t powerDigit = L' ';
    checkPowerSign(power);//changes power sign in case of negative number and prints it
    getPowerArray(powerDigitsArray, &powerArrayIndex, power);//makes array from the power to print it later
    for (int i = powerArrayIndex - 1; i >= 0; --i)
    {
        int currentDigit = powerDigitsArray[i];
        powerDigit = makeAppropriatePower(currentDigit);
        wprintf(L"%lc", powerDigit);
    }
    free(powerDigitsArray);
}

int main()
{
    setlocale(LC_CTYPE, "");
    int maxDegree = 0;
    wprintf(L"Enter the max polynomial degree: ");
    scanf("%d", &maxDegree);
    int *array = createIntArray(maxDegree + 1);
    for (int i = 0; i < maxDegree + 1; ++i)
    {
        int newValue = 0;
        wprintf(L"Enter new value: ");
        scanf("%d", &newValue);
        array[i] = newValue;
    }
    for (int i = 0; i < maxDegree; ++i)
    {
        if (array[i] < 0)
        {
            wprintf(L" %dx", array[i]);
        }
        else
        {
            wprintf(L"+ %dx", array[i]);
        }
        int power = maxDegree - i;
        printDegree(&power);
    }
    if (array[maxDegree] < 0)
    {
        wprintf(L"%d", array[maxDegree]);
    }
    else
    {
        wprintf(L"+ %d", array[maxDegree]);
    }
    free(array);
    return 0;
}
