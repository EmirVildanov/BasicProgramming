#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

const int maxSize = 8;

void reverseNumber(int* array, int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        int temporary = array[length - 1 - i];
        array[length - 1 - i] = array[i];
        array[i] = temporary;
    }
}

int* makeBinary(int number, int* length) //Also prints the binary view to save space
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
    for (int i = maxSize - 1; i >= 0; --i)
    {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
    return binaryArray;
}

int* getSum(int* firstNumber, int* secondNumber)
{
    int *binarySum = createIntArray(maxSize + 1);
    int sumDigit = 0;
    for (int i = 0; i < maxSize; ++i)
    {
        int digitsSum = firstNumber[i] + secondNumber[i];
        binarySum[i] = digitsSum % 2 + sumDigit;
        sumDigit = digitsSum / 2;
    }
    binarySum[maxSize] = sumDigit;
    reverseNumber(binarySum, maxSize + 1);
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
    int* binarySum = getSum(firstBinaryNumber, secondBinaryNumber);
    printf("The decimal sum is : %d \n", firstNumber + secondNumber);
    printf("The binary sum is : ");
    for (int i = 0; i < maxSize + 1; ++i)
    {

        printf("%d", binarySum[i]);
    }
    free(firstBinaryNumber);
    free(secondBinaryNumber);
    free(binarySum);
}

int main() {
    int firstNumber = 0;
    int secondNumber = 0;
    printf("Enter first number(less than 256) : ");
    scanf("%d", &firstNumber);
    printf("Enter second number(less than 256) : ");
    scanf("%d", &secondNumber);
    printBinaryView(firstNumber, secondNumber);
    return 0;
}