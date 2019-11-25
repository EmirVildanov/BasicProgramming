#include <stdio.h>
#include <stdlib.h>

int** createInputArray(int size)
{
    int** array = (int**) malloc(size * sizeof(int*));
    if (array == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < size; ++i)
    {
        array[i] = (int*) malloc(size * sizeof(int));
        if (array[i] == NULL)
        {
            exit(1);
        }
        printf("(New line) ");
        for (int j = 0; j < size; ++j)
        {
            printf("Enter new element of the array : ");
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

int* createIntArray(int size)
{
    int *array = (int*) malloc(size * sizeof(int));
    if (array == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < size; ++i)
    {
        array[i] = 0;
    }
    return array;
}

void printArray(int** array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}

void printSpiralArray(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void freeArray(int** array, int side)
{
    if (array == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < side; ++i)
    {
        if (array[i] == NULL)
        {
            exit(1);
        }
        free(array[i]);
    }
    free(array);
}

void addToSpiralArray(int** list, int currentElementIndex1, int currentElementIndex2, int* spiralArray, int* spiralArrayIndex)
{
    ++*spiralArrayIndex;
    spiralArray[*spiralArrayIndex] = list[currentElementIndex1][currentElementIndex2];
}

void moveNumber(int **list, int* spiralArray, int *currentElementIndex1, int *currentElementIndex2, int direction, int length, int side, int* spiralArrayIndex)
{
    for (int i = 0; i < length; ++i)//move horizontally
    {
        *currentElementIndex2 += direction;
        addToSpiralArray(list, *currentElementIndex1, *currentElementIndex2, spiralArray, spiralArrayIndex);
    }
    for (int i = 0; i < length; ++i)//move upright
    {
        *currentElementIndex1 -= direction;
        addToSpiralArray(list, *currentElementIndex1, *currentElementIndex2, spiralArray, spiralArrayIndex);
    }
    if (length == side - 1)//moves numbers of the last array column
    {
        for (int i = 0; i < length; ++i)
        {
            *currentElementIndex2 -= direction;
            addToSpiralArray(list, *currentElementIndex1, *currentElementIndex2, spiralArray, spiralArrayIndex);
        }
    }
}

int* getSpiral(int **list, int side)
{
    int rightUpDirection = 1;// if 1 it moves right/up, if -1  moves left/down
    int lineIndex = side / 2;
    int columnIndex = side / 2;
    int *spiralGettingArray = createIntArray(side * side);
    int spiralArrayIndex = 0;
    spiralGettingArray[spiralArrayIndex] = list[lineIndex][columnIndex];
    for (int i = 1; i < side; ++i)
    {
        moveNumber(list, spiralGettingArray, &lineIndex, &columnIndex, rightUpDirection, i, side, &spiralArrayIndex);
        rightUpDirection *= -1;
    }
    return spiralGettingArray;
}

int main()
{
    int side = 0;//side of the array
    printf("Enter the side power : ");
    scanf("%d", &side);
    int **numbers = createInputArray(side);
    int *spiralArray = getSpiral(numbers, side);
    printf("The first view of your array:\n");
    printArray(numbers, side);
    printf("The spiral view of your array is:\n");
    printSpiralArray(spiralArray, side * side);
    freeArray(numbers, side);
    free(spiralArray);
    return 0;
}