#include <stdlib.h>

char *createCharArray(size)
{
    char *list = malloc(size * sizeof(char));
    if (list == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

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