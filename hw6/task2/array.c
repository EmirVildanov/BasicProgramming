#include <stdlib.h>

char *createCharArray(size)
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
    if (array == NULL)
    {
        return NULL;
    }
    int newSize = currentSize + expandValue;
    array = realloc(array, newSize * sizeof(char));
    for (int i = currentSize; i < newSize; ++i)
    {
        array[i] = '\0';
    }
    return array;
}

int *createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    if (list == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}