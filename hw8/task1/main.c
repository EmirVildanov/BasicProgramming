#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "String.h"
#include "array.h"

int **createArray(int size)
{
    int **newArray = (int **) malloc(size * sizeof(int *));
    if (newArray == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = (int*) malloc(2 * sizeof(int));
        if (newArray[i] == NULL)
        {
            return NULL;
        }
        newArray[i][0] = i + 1;
        newArray[i][1] = 0;
    }
    return newArray;
}

char *getInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    if (input == NULL)
    {
        return NULL;
    }
    char *buffer = createCharArray(maxGettingSize);
    if (buffer == NULL)
    {
        return NULL;
    }
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        return NULL;
    }
    else
    {
        int lastSymbolIndex = 0;
        while (true)
        {
            for (int i = 0; i < expandValue - 1; ++i)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[i] == '\n')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[i];
                ++lastSymbolIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

bool checkInput(String **pair)
{
    int index = 0;
    while (pair[index] != NULL)
    {
        ++index;
    }
    if (index != 2)
    {
        return false;
    }
    String *firstNumber = pair[0];
    String *secondNumber = pair[1];
    if (getLength(firstNumber) == 0 || getLength(secondNumber) == 0)
    {
        return false;
    }
    for (int i = 0; i < getLength(firstNumber); ++i)
    {
        if (!isdigit(getChar(firstNumber, i)))
        {
            return false;
        }
    }
    for (int i = 0; i < getLength(secondNumber); ++i)
    {
        if (!isdigit(getChar(secondNumber, i)))
        {
            return false;
        }
    }
    return true;
}

int *readNewPair()
{
    printf("Enter new pair: ");
    fflush(stdout);
    char *newInput = getInput();
    String* newString = createString(newInput);
    int *intPair = createIntArray(2);
    String **pair = split(newString, ' ');
    while(!checkInput(pair))
    {
        printf("Wrong input. Try again: ");
        fflush(stdout);
        newInput = getInput();
        newString = createString(newInput);
        intPair = createIntArray(2);
        pair = split(newString, ' ');
    }
    char *firstVariant = toCharPtr(pair[0]);
    char *secondVariant = toCharPtr(pair[1]);
    intPair[0] = (int) strtol(firstVariant, NULL, 10);
    intPair[1] = (int) strtol(secondVariant, NULL, 10);

    free(newInput);
    deleteString(newString);
    deleteString(pair[0]);
    deleteString(pair[1]);
    free(pair);
    free(firstVariant);
    free(secondVariant);
    return intPair;
}

int** addNewPairToArray(int **array, int numberOfStudents)
{
    int *newPair = readNewPair();
    if (newPair == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < numberOfStudents; ++i)
    {
        if (i + 1 == newPair[0])
        {
            array[i][1] =  newPair[1];
            free(newPair);
            return array;
        }
    }
    free(newPair);
    return array;
}

void printPair(int **pairsArray, int index)
{
    int *currentPair = pairsArray[index];
    printf("%d -> %d\n", currentPair[0], currentPair[1]);
}

int *findVariant(int **pairsArray, int index)
{
    if (pairsArray == NULL)
    {
        return NULL;
    }
    int *currentPair = pairsArray[index];
    int currentPairVariant = currentPair[1];
    while (currentPairVariant != 1 && currentPairVariant != 2 && currentPairVariant != 3 && currentPairVariant != -1)
    {
        printf("%d\n", currentPairVariant - 1);
        fflush(stdout);
        int check = pairsArray[currentPairVariant - 1][1];
        currentPair[1] = check;
        currentPairVariant = currentPair[1];
    }
    return currentPair;
}

int **getStudentsPairs(int numberOfStudents)
{
    int **pairsArray = createArray(numberOfStudents);
    for (int i = 0; i < numberOfStudents; ++i)
    {
        pairsArray = addNewPairToArray(pairsArray, numberOfStudents);
        if (pairsArray == NULL)
        {
            return NULL;
        }
    }
    for (int i = 0; i < numberOfStudents; ++i)
    {
        pairsArray[i] = findVariant(pairsArray, i);
    }
    return pairsArray;
}

void deleteStudentsPairs(int **studentPairs, int studentsNumber)
{
    for (int i = 0; i < studentsNumber; ++i)
    {
        free(studentPairs[i]);
    }
    free(studentPairs);
}

int main()
{
    int numberOfStudents = 0;
    printf("Enter the number of students: ");
    fflush(stdout);
    char* input = getInput();
    numberOfStudents = (int) strtol(input, NULL, 10);
    while (numberOfStudents == 0)
    {
        printf("Please, enter the number of students again:");
        fflush(stdout);
        input = getInput();
        numberOfStudents = (int) strtol(input, NULL, 10);
    }
    int **studentPairs = getStudentsPairs(numberOfStudents);
    if (studentPairs == NULL)
    {
        return 1;
    }
    printf("Pairs are:\n");
    fflush(stdout);
    for (int i = 0; i < numberOfStudents; ++i)
    {
        printPair(studentPairs, i);
    }
    deleteStudentsPairs(studentPairs, numberOfStudents);
    free(input);
    return 0;
}