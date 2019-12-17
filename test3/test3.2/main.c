#include <stdio.h>
#include <stdbool.h>
#include "array.h"

bool checkSaddlePoint(int stringsNumber, int columnsNumber, float **array, int stringIndex, int columnIndex)
{
    float min = 0;
    float max = 0;
    min = array[stringIndex][0];
    for (int j = 0; j < columnsNumber; j++)
    {
        if (array[stringIndex][j] < min)
        {
            min = array[stringIndex][j];
        }
    }
    max = array[0][columnIndex];
    for (int i = 0; i < stringsNumber; i++)
    {
        if (array[i][columnIndex] > max)
        {
            max = array[i][columnIndex];
        }
    }
    return (array[stringIndex][columnIndex] == min && array[stringIndex][columnIndex] == max ? true : false);
}

float **saddlePoints(int stringsNumber, int columnsNumber, float **array, int *pointsNumber)
{
    int counter = 0;
    for (int i = 0; i < stringsNumber; i++)
    {
        for (int j = 0; j < columnsNumber; j++)
        {
            if (checkSaddlePoint(stringsNumber, columnsNumber, array, i, j))
            {
                ++counter;
            }
        }
    }
    *pointsNumber = counter;
    if (counter == 0)
    {
        return NULL;
    }
    float **pointsArray = createDoubleArray(counter, 3);
    int newPointIndex = 0;
    for (int i = 0; i < stringsNumber; i++)
    {
        for (int j = 0; j < columnsNumber; j++)
        {
            if (checkSaddlePoint(stringsNumber, columnsNumber, array, i ,j))
            {
                pointsArray[newPointIndex][0] = array[i][j];
                pointsArray[newPointIndex][1] = (float) i;
                pointsArray[newPointIndex][2] = (float) j;
                newPointIndex += 1;
            }
        }
    }
    return pointsArray;
}

void printArray(float **array, int stringsNumber)
{
    for (int i = 0; i < stringsNumber; ++i)
    {
        printf("%f ", array[i][0]);
        printf("%d ", (int) array[i][1]);
        printf("%d\n", (int) array[i][2]);
    }
    printf("\n");
}

int main()
{
    int stringsNumber = 0;
    int columnsNumber = 0;
    int pointsNumber = 0;
    printf("Enter the number of strings : ");
    fflush(stdout);
    scanf("%d", &stringsNumber);
    printf("Enter the number of columns : ");
    fflush(stdout);
    scanf("%d", &columnsNumber);
    float **inputArray = createInputDoubleArray(stringsNumber, columnsNumber);
    float **pointsArray = saddlePoints(stringsNumber, columnsNumber, inputArray, &pointsNumber);
    printf("Your saddle points are: (value, stringIndex columnIndex)\n");
    fflush(stdout);
    printArray(pointsArray, pointsNumber);
    deleteDoubleArray(pointsArray, pointsNumber);
    deleteDoubleArray(inputArray, stringsNumber);
    return 0;
}