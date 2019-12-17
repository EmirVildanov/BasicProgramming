#include <stdlib.h>
#include "array.h"

char* createCharArray(int size)
{
    char *array = malloc(size * sizeof(char));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
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

int* createIntArray(int size)
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

int** createDoubleArray(int size)
{
    int** array = malloc(size * sizeof(int*));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        array[i] = (int*) malloc(size * sizeof(int));
        if (array[i] == NULL)
        {
            return NULL;
        }
        printf("(New line) ");
        for (int j = 0; j < size; ++j)
        {
            printf("Enter new element of the array : ");
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

float* createFloatArray(int size)
{
    float *array = malloc(size * sizeof(float));
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

void printCharArray(char* array, int length)
{
    if (array == NULL)
    {
        return;
    }
	for (int i = 0; i < length; i++)
	{
		printf("%c ", array[i]);
	}
	return;
}

void printIntArray(int* array, int length)
{
    if (array == NULL)
    {
        return;
    }
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	return;
}

void printFloatArray(float* array, int length)
{
    if (array == NULL)
    {
        return;
    }
	for (int i = 0; i < length; i++)
	{
		printf("%f ", array[i]);
	}
	return;
}
