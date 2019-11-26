#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

const int maxSize = 8;
const int maxInputSize = 3;

int getInput(int size)
{
    char *input = createCharArray(size + 1);// size + 1 to capture '\n' symbol
    printf("Enter number(less than 256) : ");
    fgets(input, size + 1, stdin);
    int number = (int) strtol(input, NULL, 10);
    free(input);
    return number;
}

void checkInput(int number)
{
    if (number > 256)
    {
        printf("Your number is greater than 255\n");
        exit(1);
    }
}

void reverseNumber(int *array, int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        int temporary = array[length - 1 - i];
        array[length - 1 - i] = array[i];
        array[i] = temporary;
    }
}

int *makeBinary(int number)
{
    int *binaryArray = createIntArray(maxSize);
    int digitPower = 0;
    while (number != 0)
    {
        binaryArray[digitPower] = number % 2;
        number /= 2;
        digitPower += 1;
    }
    reverseNumber(binaryArray, maxSize);
    return binaryArray;
}

void printBinary(int *binaryArray, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d", binaryArray[i]);
    }
    printf("\n");
}

int *getBinarySum(const int *firstNumber, const int *secondNumber)
{
    int *binarySum = createIntArray(maxSize + 1);
    int sumDigit = 0;
    for (int i = maxSize - 1; i > 0; --i)
    {
        int digitsSum = firstNumber[i] + secondNumber[i];
        binarySum[i + 1] = (digitsSum + sumDigit) % 2;
        sumDigit = (digitsSum + sumDigit) / 2;
    }
    binarySum[0] = sumDigit;
    return binarySum;
}

int main()
{
    int firstNumber = getInput(maxInputSize);
    checkInput(firstNumber);
    int *firstBinaryNumber = makeBinary(firstNumber);
    int secondNumber = getInput(maxInputSize);
    checkInput(secondNumber);
    int *secondBinaryNumber = makeBinary(secondNumber);
    printf("The binary view of the first number is : ");
    printBinary(firstBinaryNumber, maxSize);
    printf("The binary view of the second number is : ");
    printBinary(secondBinaryNumber, maxSize);
    int *binarySum = getBinarySum(firstBinaryNumber, secondBinaryNumber);
    printf("The decimal sum is : %d \n", firstNumber + secondNumber);
    printf("The binary sum is : ");
    printBinary(binarySum, maxSize + 1);

    free(binarySum);
    free(firstBinaryNumber);
    free(secondBinaryNumber);
    return 0;
}