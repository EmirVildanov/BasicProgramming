#include <stdlib.h>

char* createCharArray(size)
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