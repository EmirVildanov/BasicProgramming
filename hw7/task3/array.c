#include <stdlib.h>
#include <stdio.h>

char *createCharArray(int size)
{
    char *list = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
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
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

void printIntArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
}
