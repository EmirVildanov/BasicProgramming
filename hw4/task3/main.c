#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** createArray(int size)
{
    int** list = malloc(size * sizeof(int*));
    for (int i = 0; i < size; ++i)
    {
        list[i] = (int*) malloc(size * sizeof(int));
        printf("(New line) ");
        for (int j = 0; j < size; ++j)
        {
            printf("Enter new element of the array : ");
            scanf("%d", &list[i][j]);
        }
    }
    return list;
}

void moveRight(int **list, int *currentElementIndex1, int *currentElementIndex2, bool direction, int length)
{
    for (int i = 0; i < length; ++i)
    {
        *currentElementIndex2 += 1;
        printf("%d ", list[*currentElementIndex1][*currentElementIndex2]);
    }
}

void moveUp(int **list, int *currentElementIndex1, int *currentElementIndex2, bool direction, int length)
{
    for (int i = 0; i < length; ++i)
    {
        *currentElementIndex1 -= 1;
        printf("%d ", list[*currentElementIndex1][*currentElementIndex2]);
    }
}

void moveLeft(int **list, int *currentElementIndex1, int *currentElementIndex2, bool direction, int length)
{
    for (int i = 0; i < length; ++i)
    {
        *currentElementIndex2 -= 1;
        printf("%d ", list[*currentElementIndex1][*currentElementIndex2]);
    }
}

void moveDown(int **list, int *currentElementIndex1, int *currentElementIndex2, bool direction, int length)
{
    for (int i = 0; i < length; ++i)
    {
        *currentElementIndex1 += 1;
        printf("%d ", list[*currentElementIndex1][*currentElementIndex2]);
    }
}

void moveNumber(int **list, int *currentElementIndex1, int *currentElementIndex2, bool direction, int length, int number)
{
    if (direction)
    {
        moveRight(list, currentElementIndex1, currentElementIndex2, direction, length);
        moveUp(list, currentElementIndex1, currentElementIndex2, direction, length);
    }
    else
    {
        moveLeft(list, currentElementIndex1, currentElementIndex2, direction, length);
        moveDown(list, currentElementIndex1, currentElementIndex2, direction, length);
    }
    if (length == number - 1)
    {
        moveRight(list, currentElementIndex1, currentElementIndex2, direction, length);
    }
}

void printSpiral(int **list, int length)
{
    printf("The first view of your array : \n");
    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
    printf("The spiral view of your array is : ");
    bool rightUpDirection = true;
    int lineIndex = length / 2;
    int columnIndex = length / 2;
    printf("%d ", list[lineIndex][columnIndex]);
    for (int i = 1; i < length; ++i)
    {
        moveNumber(list, &lineIndex, &columnIndex, rightUpDirection, i, length);
        rightUpDirection = !rightUpDirection;
    }
}

int main() {
    int number = 0;
    printf("Enter the number : ");
    scanf("%d", &number);
    int **numbers = createArray(number);
    printSpiral(numbers, number);
    for (int i = 0; i < number; ++i)
    {
        free(numbers[i]);
    }
    free(numbers);
    return 0;
}