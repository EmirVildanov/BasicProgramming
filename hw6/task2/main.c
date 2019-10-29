#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

const int maxSize = 10;

void reverseNumber(int* array, int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        int temporary = array[length - 1 - i];
        array[length - 1 - i] = array[i];
        array[i] = temporary;
    }
}

int* makeBinary(int number, int* length)
{
    int *binaryArray = createIntArray(maxSize);
    int digitPower = 0;
    while (number != 0)
    {
        binaryArray[digitPower] = number % 2;
        number /= 2;
        digitPower += 1;
    }
    *length = digitPower;
    for (int i = digitPower - 1; i >= 0; --i)
    {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
    return binaryArray;
}

int findMaxLengths(int firstLength, int secondLength)
{
    int maxLength = 0;
    if (firstLength > secondLength)
    {
        maxLength = firstLength;
    }
    else
    {
        maxLength = secondLength;
    }
    return maxLength;
}

int* getSum(int* firstNumber, int* secondNumber, int maxLength)
{
    int *binarySum = createIntArray(maxSize);
    int sumDigit = 0;
    for (int i = 0; i < maxLength; ++i)
    {
        int digitsSum = firstNumber[i] + secondNumber[i];
        binarySum[i] = digitsSum % 2 + sumDigit;
        sumDigit = digitsSum / 2;
    }
    binarySum[maxLength] = sumDigit;
    reverseNumber(binarySum, maxLength + 1);
    return binarySum;
}

void printBinaryView(int firstNumber, int secondNumber)
{
    int firstNumberLength = 0;
    int secondNumberLength = 0;
    printf("The binary view of the first number is : ");
    int *firstBinaryNumber = makeBinary(firstNumber, &firstNumberLength);
    printf("The binary view of the second number is : ");
    int *secondBinaryNumber = makeBinary(secondNumber, & secondNumberLength);
    int maxLength = findMaxLengths(firstNumberLength, secondNumberLength);
    int* binarySum = getSum(firstBinaryNumber, secondBinaryNumber, maxLength);
    printf("The decimal sum is : %d \n", firstNumber + secondNumber);
    printf("The binary sum is : ");
    for (int i = 0; i < maxLength + 1; ++i)
    {
        if (i == 0 && binarySum[i] == 0)
        {
            continue;
        }
        printf("%d", binarySum[i]);
    }
    free(firstBinaryNumber);
    free(secondBinaryNumber);
    free(binarySum);
}

int main() {
    int firstNumber = 0;
    int secondNumber = 0;
    printf("Enter first number : ");
    scanf("%d", &firstNumber);
    printf("Enter second number : ");
    scanf("%d", &secondNumber);
    printBinaryView(firstNumber, secondNumber);
    return 0;
}