#include <stdio.h>
#include <malloc.h>
#include "array.h"

int **createDoubleDimensionalArray(int stringsNumber, int columnsNumber)
{
    int **array = malloc(stringsNumber * sizeof(int *));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < stringsNumber; ++i)
    {
        printf("New line: ");
        array[i] = (int *) malloc(columnsNumber * sizeof(int));
        if (array[i] == NULL)
        {
            return NULL;
        }
        for (int j = 0; j < columnsNumber; ++j)
        {
            int newValue;
            printf("Enter new value: ");
            scanf("%d", &newValue);
            array[i][j] = newValue;
        }
    }
    return array;
}

int **swapDoubleArrayStrings(int **array, int firstStringIndex, int secondStringIndex, int columnsNumber)
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

int **sortDoubleDimensionalArray(int **array, int stringsNumber, int columnsNumber)
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
                array = swapDoubleArrayStrings(array, i, j, columnsNumber);
            }
        }
    }
    return array;
}

void deleteDoubleDimensionalArray(int **array, int stringsNumber)
{
    for (int i = 0; i < stringsNumber; ++i)
    {
        free(array[i]);
    }
    free(array);
}

void printDoubleDimensionalArray(int **array, int stringsNumber, int columnsNumber)
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

int main() {
    int **array = createDoubleDimensionalArray(4, 3);
    printf("First array:\n");
    printDoubleDimensionalArray(array, 4, 3);
    int **newArray = sortDoubleDimensionalArray(array, 4, 3);
    printf("Second array:\n");
    printDoubleDimensionalArray(newArray, 4, 3);
    deleteDoubleDimensionalArray(array, 4);
    return 0;
}
