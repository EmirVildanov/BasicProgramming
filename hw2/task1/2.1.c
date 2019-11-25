#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* createIntArray(int size)
{
    int* list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

void initializeArray(int* units, int number)
{
    for (int i = 0; i < number; ++i)
    {
        units[i] = 1;
    }
}

int findNaturalElement(const int *list, int length, int start)
{
    int index = start;
    while (list[index] == 0)
    {
        ++index;
    }
    return index;
}

void printTheSum(int *list, int length)
{
    int firstNaturalNumberIndex = findNaturalElement(list, length, 0);
    printf("%d ", list[firstNaturalNumberIndex]);
    if (length > 1)
    {
        for (int i = firstNaturalNumberIndex; i < length - 1; ++i)
        {
            if (list[i + 1] != 0)
            {
                printf("+ %d ", list[i + 1]);
            }
        }
    }
    printf("\n");
}

void moveMaxElement(int *list, int length, int *maxElement, int *maxElementIndex)
{
    list[*maxElementIndex] = 0;
    list[*maxElementIndex + 1] = *maxElement + 1;
    *maxElementIndex += 1;
    *maxElement += 1;
    for (int i = *maxElementIndex + 1; i < length; ++i)
    {
        list[i] = 1;
    }
}

int findSmallestElementIndex(const int *sortedArray, int length)
{
    int index = length - 1;
    while (sortedArray[index - 1] == sortedArray[index])
    {
        index -= 1;
    }
    return index;
}

bool increaseFirstElement(int* units, int maxElement, int number, int maxElementIndex)//returns false if can't increase first element
{
    int nextAfterMaxElementIndex = findNaturalElement(units, number, maxElementIndex + 1);
    if (units[nextAfterMaxElementIndex] + 1 > maxElement || nextAfterMaxElementIndex == number - 1)
    {
        return false;
    }
    int element = units[nextAfterMaxElementIndex];
    moveMaxElement(units, number, &element, &nextAfterMaxElementIndex);
    printTheSum(units, number);
    return true;
}

bool transformAfterMaxElement(int* smallestElement, int number, int* units, int maxElement, int maxElementIndex, int* smallestElementIndex)//returns false if can't transform elements after max element
{
    if (*smallestElementIndex == number - 1)
    {
        if (!increaseFirstElement(units, maxElement, number, maxElementIndex))
        {
            return false;
        }
    }
    else
    {
        moveMaxElement(units, number, smallestElement, smallestElementIndex);
        printTheSum(units, number);
    }
    return true;
}

void transformUnits(int number)
{
    int maxElement = 1;
    int maxElementIndex = 0;
    int *units = createIntArray(number);
    initializeArray(units, number);
    while (maxElement != number)
    {
        printTheSum(units, number);
        while (units[number - 1] + units[number - 2] <= maxElement)
        {
            int smallestElementIndex = findSmallestElementIndex(units, number);
            int smallestElement = units[smallestElementIndex];
            if (!transformAfterMaxElement(&smallestElement, number, units, maxElement, maxElementIndex, &smallestElementIndex))
            {
                break;
            }
        }
        moveMaxElement(units, number, &maxElement, &maxElementIndex);
    }
    printTheSum(units, number);
    free(units);
}

int main()
{
    int input = 0;
    printf("Enter the number : ");
    scanf("%d,", &input);
    printf("Number %d also may be represented as : \n", input);
    transformUnits(input);
    return 0;
}
;
