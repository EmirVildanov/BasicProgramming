#include <stdlib.h>
#include <stdio.h>

int *createIntArray(int size)
{
    int *array = malloc(size * sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        array[i] = 0;
    }
    return array;
}

int **createDoubleArray(int stringsNumber, int columnsNumber)
{
    int **array = malloc(stringsNumber * sizeof(int *));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < stringsNumber; ++i)
    {
        array[i] = (int *) malloc(columnsNumber * sizeof(int));
        if (array[i] == NULL)
        {
            return NULL;
        }
        for (int j = 0; j < columnsNumber; ++j)
        {
            array[i][j] = 0;
        }
    }
    return array;
}

int **extendDoubleArray(int **array, int currentStringsNumber, int columnsNumber, int extendValue)
{
    if (array == NULL)
    {
        return NULL;
    }
    int newLength = currentStringsNumber + extendValue;
    array = realloc(array, newLength * sizeof(int *));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = currentStringsNumber; i < newLength; ++i)
    {
        array[i] = malloc(columnsNumber * sizeof(int));
        for (int j = 0; j < columnsNumber; ++j)
        {
            array[i][j] = 0;
        }
    }
    return array;
}

int **swapStrings(int **array, int firstStringIndex, int secondStringIndex, int columnsNumber)
{
    if (array == NULL)
    {
        return NULL;
    }
    int *temporary = createIntArray(columnsNumber);
    for (int i = 0; i < columnsNumber; ++i)
    {
        temporary[i] = array[firstStringIndex][i];
        array[firstStringIndex][i] = array[secondStringIndex][i];
        array[secondStringIndex][i] = temporary[i];
    }
    free(temporary);
    return array;
}

int **sortDoubleArray(int **array, int stringsNumber, int columnsNumber)
{
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < stringsNumber; ++i)
    {
        for (int j = i; j < stringsNumber; ++j)
        {
            if (array[j][0] < array[i][0])
            {
                array = swapStrings(array, i, j, columnsNumber);
            }
        }
    }
    return array;
}

void printDoubleArray(int **array, int stringsNumber, int columnsNumber)
{
    for (int i = 0; i < stringsNumber; ++i)
    {
        for (int j = 0; j < columnsNumber; ++j)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deleteDoubleArray(int **array, int stringsNumber)
{
    for (int i = 0; i < stringsNumber; ++i)
    {
        free(array[i]);
    }
    free(array);
}
