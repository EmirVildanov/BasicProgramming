//It might not work in Windows console

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <math.h>
#include <locale.h>
#include "Array.h"

const int maxMantissaLength = 10;

int makeNewMantissa(float mantissa)
{
    mantissa = mantissa * pow(10,6) - pow(10,6);
    int intMantissa = (int) mantissa;
    int lastDigit = intMantissa % 10;
    while (lastDigit == 0 && intMantissa != 0)
    {
        intMantissa /= 10;
        lastDigit = intMantissa % 10;
    }
    return intMantissa;
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

void printPower(bool firstSign, float mantissa, int power, bool secondSign)
{
    wchar_t powerDigit = L' ';
    wchar_t mantissaSign = L' ';
    int noZeroMantissa = makeNewMantissa(mantissa);
    if (firstSign)
    {
        mantissaSign = L'+';
    }
    else
    {
        mantissaSign = L'-';
    }
    int *powerDigitsArray = createIntArray(5);
    int arrayIndex = 0;
    while (power != 0)
    {
        int newDigit = power % 10;
        powerDigitsArray[arrayIndex] = newDigit;
        ++arrayIndex;
        power /= 10;
    }
    if(!secondSign)
    {
        wchar_t powerSign = 0x207B;
        wprintf(L"Result : %lc1.%d*2%lc", mantissaSign, noZeroMantissa, powerSign);
    }
    else
    {
        wprintf(L"Result : %lc1.%d*2", mantissaSign, noZeroMantissa, mantissa);
    }
    for (int i = arrayIndex - 1; i >= 0; --i)
    {
        int currentDigit = powerDigitsArray[i];
        powerDigit = makeAppropriatePower(currentDigit);
        wprintf(L"%lc", powerDigit);
    }
}

void printExponentialView(float number)
{
    bool mantissaSign = true;
    if (number < 0)
    {
        mantissaSign = false;
        number *= -1;
    }
    int power = 0;
    bool powerSign = true;
    int integerPart = (int) number;
    if (abs(integerPart) < 1)
    {
        powerSign = false;
        while(integerPart % 10 != 1)
        {
            ++power;
            number *= 2;
            integerPart = (int) number;
        }
    }
    else
    {
        while(integerPart % 10 != 1)
        {
            ++power;
            number /= 2;
            integerPart = (int) number;
        }
    }
    printPower(mantissaSign, number, power, powerSign);
}

int main()
{
    setlocale(LC_CTYPE, "");
    float number = 0;
    wprintf(L"Enter a number : ");
    scanf("%f", &number);
    printExponentialView(number);
    return 0;
}