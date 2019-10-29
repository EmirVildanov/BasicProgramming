#include <stdlib.h>
#include "Array.h"

char* createCharArray(size)
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

int** createDoubleArray(int size)
{
    int** list = malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i)
    {
        list[i] = (int*) malloc(size * sizeof(int));
        printf("(New line) ");
        for (int j = 0; j < size; ++j)
        {
            printf("Enter new element of the array : ");
            scanf("%d", &list[i][j]);
        }
    }
    return list;
}

float* createFloatArray(size)
{
    float *list = malloc(size * sizeof(float));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

void printCharArray(char* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%c ", array[i]);
	}
	return;
}

void printIntArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	return;
}

void printFloatArray(float* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%f ", array[i]);
	}
	return;
}
