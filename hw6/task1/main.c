//It might not work in Windows console as I have to change the locale

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "Array.h"

const int maxInputSize = 13;
const int maxArraySize = 5;
const int exponentSize = 11;
const int mantissaSize = 52;

int findIntPower(int number, int power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
    {
        result *= number;
    }
    return result;
}

float findFloatPower(float number, int power)
{
    float rememberNumber = number;
    for (int i = 0; i < power; ++i)
    {
        number *= rememberNumber;
    }
    return number;
}

int makePower(int* array, int length)
{
    int result = 0;
    for (int i = 0; i < length; ++i)
    {
        result += array[i] * findIntPower(2, length - 1 - i);
    }
    return result;
}

float makeMantissa(int* array, int length)
{
    float result = 1;
    for (int i = 0; i < length; ++i)
    {
        result += array[i] * (1 / findFloatPower(2, i));
    }
    return result;
}

wchar_t makeAppropriatePower(int currentDigit)
{
    wchar_t powerDigit = L' ';
    if (currentDigit == 0)
    {
        powerDigit = 0x2070;
    }
    else if (currentDigit == 1)
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

void divideBinaryDouble(unsigned char* doubleNumberPointer, int* sign, int* exponent, int* mantissa)
{
    int bitNumber = 0;
    int arrayIndex = 0;
    for (int i = 0; i < sizeof(double); ++i)
    {
        long int currentByte = (long int) doubleNumberPointer[i];
        for (int j = 0; j < 8; ++j)
        {
            if (bitNumber == mantissaSize + exponentSize)
            {
                *sign = currentByte & 1;
            }
            else if (bitNumber >= mantissaSize)
            {
                if (bitNumber == mantissaSize)
                {
                    arrayIndex = 0;
                }
                exponent[exponentSize - 1 - arrayIndex] = currentByte & 1;
                currentByte >>= 1;
                ++arrayIndex;
                ++bitNumber;
            }
            else
            {
                mantissa[mantissaSize - 1 - arrayIndex] = currentByte & 1;
                currentByte >>= 1;
                ++arrayIndex;
                ++bitNumber;
            }
        }
    }
}

void printExponential(double number)
{
    unsigned char *doubleNumberPointer = (unsigned char*)&number;
    int sign = 0;
    int *exponent = createIntArray(exponentSize);
    int *mantissa = createIntArray(mantissaSize);
    divideBinaryDouble(doubleNumberPointer, &sign, exponent, mantissa);
    int exponentPower= makePower(exponent, exponentSize);
    float resultMantissa = makeMantissa(mantissa, mantissaSize);
    int power = exponentPower - 1023;
    char signChar = '+';
    if (sign == 1)
    {
        signChar = '-';
    }
    wprintf(L"Result: %c%f*2", signChar, resultMantissa);
    if (power < 0)
    {
        power = power * -1;
        wchar_t powerSign = 0x207B;
        wprintf(L"%lc", powerSign);
    }
    wchar_t powerDigit = L' ';
    int *powerDigitsArray = createIntArray(maxArraySize);
    int arrayIndex = 0;
    while (power != 0)
    {
        int newDigit = power % 10;
        powerDigitsArray[arrayIndex] = newDigit;
        ++arrayIndex;
        power /= 10;
    }
    for (int i = arrayIndex - 1; i >= 0; --i)
    {
        int currentDigit = powerDigitsArray[i];
        powerDigit = makeAppropriatePower(currentDigit);
        wprintf(L"%lc", powerDigit);
    }
    free(exponent);
    free(mantissa);
    free(powerDigitsArray);
}

int main() {
    setlocale(LC_CTYPE, "");
    char *inputLine = createCharArray(maxInputSize);
    wprintf(L"Enter a number : ");
    scanf("%s", inputLine);
    double number = strtod(inputLine, NULL);
    printExponential(number);
    free(inputLine);
    return 0;
}
