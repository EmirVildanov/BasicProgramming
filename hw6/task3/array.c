#include <stdlib.h>

int *createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    if (list == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

int *expandIntArray(int *array, int currentSize, int expandValue)
{
    if (array == NULL)
    {
        return NULL;
    }
    int newSize = currentSize + expandValue;
    array = realloc(array, newSize * sizeof(int));
    for (int i = currentSize; i < newSize; ++i)
    {
        array[i] = '\0';
    }
    return array;
}