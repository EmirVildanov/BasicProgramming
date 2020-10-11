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
