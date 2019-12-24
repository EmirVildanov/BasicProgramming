#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "array.h"

const int maxSize = 9;

char *getInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
    printf("Enter number(absolute value less than 256) : ");
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        return NULL;
    }
    else
    {
        int lastSymbolIndex = 0;
        int bufferIndex = 0;
        while (true)
        {
            while (bufferIndex < expandValue - 1)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[bufferIndex] == '\n' || buffer[bufferIndex] == '\0')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[bufferIndex];
                ++lastSymbolIndex;
                ++bufferIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            bufferIndex = 0;
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

bool checkInput(int number, const char* input)
{
    if (number == 0 && !isdigit(input[0]))
    {
        printf("There is no number in the input\n");
        return false;
    }
    if (number >= 256 || number <= -256)
    {
        printf("Absolute value is greater than 255\n");
        return false;
    }
    return true;
}

int getNumber()
{
    char *input = getInput();
    int number = (int) strtol(input, NULL, 10);
    while (!checkInput(number, input))
    {
        free(input);
        input = getInput();
        number = (int) strtol(input, NULL, 10);
    }
    free(input);
    return number;
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

int *findBiggestNumber(int* firstNumber, int *secondNumber)
{
    for (int i = 1; i < maxSize; ++i)
    {
        if (firstNumber[i] > secondNumber[i])
        {
            return firstNumber;
        }
        else if (secondNumber[i] > firstNumber[i])
        {
            return secondNumber;
        }
    }
    return firstNumber;
}

int findFirstUnitIndex(const int* biggestNumber, int currentIndex)
{
    for (int i = currentIndex; i >= 1; --i)
    {
        if (biggestNumber[i] == 1)
        {
            return i;
        }
    }
    return 0;
}

int *makeBinary(int number)
{
    int *binaryArray = createIntArray(maxSize);
    int digitPower = 0;
    if (number < 0)
    {
        binaryArray[maxSize - 1] = 1;
        number *= -1;
    }
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

int* getBinaryDifference(int* binarySum, int* firstNumber, int *secondNumber)
{
    int *biggestNumber = findBiggestNumber(firstNumber, secondNumber);//by absolute value
    int *smallestNumber = NULL;
    if (biggestNumber == firstNumber)
    {
        smallestNumber = secondNumber;
    }
    else
    {
        smallestNumber = firstNumber;
    }
    for (int i = maxSize - 1; i >= 1; --i)
    {
        if (biggestNumber[i] < smallestNumber[i])
        {
            int unitIndex = findFirstUnitIndex(biggestNumber, i);
            biggestNumber[unitIndex] = 0;
            for (int j = unitIndex + 1; j < i; ++j)
            {
                biggestNumber[j] += 1;
            }
            biggestNumber[i] = 2;
        }
        binarySum[i] = biggestNumber[i] - smallestNumber[i];
    }
    binarySum[0] = biggestNumber[0];
    return binarySum;
}

int *getBinarySum(int *firstNumber, int *secondNumber)
{
    int *binarySum = createIntArray(maxSize);
    int sumDigit = 0;
    if (firstNumber[0] != secondNumber[0])
    {
        binarySum = getBinaryDifference(binarySum, firstNumber, secondNumber);
    }
    else
    {
        for (int i = maxSize - 1; i > 0; --i)
        {
            int digitsSum = firstNumber[i] + secondNumber[i];
            binarySum[i] = (digitsSum + sumDigit) % 2;
            sumDigit = (digitsSum + sumDigit) / 2;
        }
        binarySum[1] = sumDigit;
        binarySum[0] = firstNumber[0];
    }
    return binarySum;
}

int main()
{
    int firstNumber = getNumber();
    int *firstBinaryNumber = makeBinary(firstNumber);
    int secondNumber = getNumber();
    int *secondBinaryNumber = makeBinary(secondNumber);
    printf("The binary view of the first number is : ");
    printBinary(firstBinaryNumber, maxSize);
    printf("The binary view of the second number is : ");
    printBinary(secondBinaryNumber, maxSize);
    int *binarySum = getBinarySum(firstBinaryNumber, secondBinaryNumber);
    printf("The decimal sum is : %d \n", firstNumber + secondNumber);
    printf("The binary sum is : ");
    printBinary(binarySum, maxSize);

    free(binarySum);
    free(firstBinaryNumber);
    free(secondBinaryNumber);
    return 0;
}