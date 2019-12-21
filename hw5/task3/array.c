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
