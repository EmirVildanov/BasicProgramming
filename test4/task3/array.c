#include <stdio.h>
#include <stdlib.h>

char* createCharArray(int size)
{
    char *list = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

float* createFloatArray(int size)
{
    float *list = malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

int **createDoubleDimensionalArray(int stringsNumber, int columnsNumber)
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

int *expandIntArray(int *array, int currentSize, int expandValue)
{
    int newSize = currentSize + expandValue;
    array = realloc(array, newSize * sizeof(int));
    for (int i = currentSize; i < newSize; ++i)
    {
        array[i] = '\0';
    }
    return array;
}

char *expandCharArray(char *array, int currentSize, int expandValue)
{
    int newSize = currentSize + expandValue;
    array = realloc(array, newSize * sizeof(char));
    for (int i = currentSize; i < newSize; ++i)
    {
        array[i] = '\0';
    }
    return array;
}

int **expandDoubleDimensionalArray(int **array, int currentStringsNumber, int columnsNumber, int extendValue)
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

void printCharArray(char* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%c ", array[i]);
	}
}

void printIntArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
}

void printFloatArray(float* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%f ", array[i]);
	}
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
