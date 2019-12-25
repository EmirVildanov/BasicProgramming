#include <stdlib.h>

char* createCharArray(int size)
{
    char *list = malloc(size * sizeof(char));
    if (list == NULL)
    {
        return NULL;
    }
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
    if (array == NULL)
    {
        return NULL;
    }
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