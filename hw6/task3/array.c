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