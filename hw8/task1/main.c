#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

int **createArray(int size)
{
    int **newArray = (int **) malloc(size * sizeof(int *));
    if (newArray == NULL)
    {
        return NULL;
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

bool checkInput(const int *pair)
{
    if (pair == NULL)
    {
        return false;
    }
    return !(pair[0] == 0 || pair[1] == 0 || (pair[0] > 3 && pair[0] == pair[1]));
}

int *readNewPair()
{
    printf("Enter new pair: ");
    fflush(stdout);
    int *pair = createIntArray(2);
    scanf("%d %d", &pair[0], &pair[1]);
    while(!checkInput(pair))
    {
        printf("Wrong input. Try again: ");
        fflush(stdout);
        fscanf(stdin, "%*[^\n]");
        scanf("%d %d", &pair[0], &pair[1]);
    }
    return pair;
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