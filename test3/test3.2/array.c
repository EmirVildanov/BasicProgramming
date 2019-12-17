#include <stdlib.h>
#include <stdio.h>

float **createInputDoubleArray(int stringsNumber, int columnsNumber)
{
    float **array = malloc(stringsNumber * sizeof(float *));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < stringsNumber; ++i)
    {
        array[i] = (float *) malloc(columnsNumber * sizeof(float));
        if (array[i] == NULL)
        {
            return NULL;
        }
        printf("(new line) ");
        fflush(stdout);
        for (int j = 0; j < columnsNumber; ++j)
        {
            printf("Enter new number : ");
            fflush(stdout);
            scanf("%f", &array[i][j]);
        }
    }
    return array;
}

float **createDoubleArray(int stringsNumber, int columnsNumber)
{
    float **array = malloc(stringsNumber * sizeof(float *));
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < stringsNumber; ++i)
    {
        array[i] = (float *) malloc(columnsNumber * sizeof(float));
        if (array[i] == NULL)
        {
            return NULL;
        }
        for (int j = 0; j < columnsNumber; ++j)
        {
            array[i][j] = 0;
        }
    }
    return array;
}

void deleteDoubleArray(float **array, int stringsNumber)
{
    for (int i = 0; i < stringsNumber; ++i)
    {
        free(array[i]);
    }
    free(array);
}
