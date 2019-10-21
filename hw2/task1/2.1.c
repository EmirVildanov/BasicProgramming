#include <stdio.h>

int findNaturalElement(int list[], int length, int start)
{
    int index = start;
    while (list[index] == 0)
    {
        ++index;
    }
    return index;
}

void printTheSum(int list[], int length)
{
    int firstNaturalNumberIndex = 0;
    while (list[firstNaturalNumberIndex] == 0)
    {
        ++firstNaturalNumberIndex;
    }
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

void moveMaxElement(int list[], int length, int *maxElement, int *maxElementIndex)
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

int findSmallestElementIndex(int list[], int length, int maxElement, int maxElementIndex)
{
    int index = length - 1;
    while (list[index - 1] == list[index])
    {
        index -= 1;
    }
    return index;
}

void transformUnits(int number)
{
    int maxElement = 1;
    int maxElementIndex = 0;
    int units[number];
    for (int i = 0; i < number; ++i)
    {
        units[i] = 1;
    }
    while (maxElement != number)
    {
        printTheSum(units, number);
        while (units[number - 1] + units[number - 2] <= maxElement)
        {
            int smallestElementIndex = findSmallestElementIndex(units, number, maxElement, maxElementIndex);
            int smallestElement = units[smallestElementIndex];
            if (smallestElementIndex == number - 1)
            {
                int nextAfterMaxElementIndex = findNaturalElement(units, number, maxElementIndex + 1);
                if ((units[nextAfterMaxElementIndex] + 1) > maxElement || nextAfterMaxElementIndex == number - 1)
                {
                    break;
                }
                else
                {
                    int element = units[nextAfterMaxElementIndex];
                    moveMaxElement(units, number, &element, &nextAfterMaxElementIndex);
                    printTheSum(units, number);
                }
            }
            else
            {
                moveMaxElement(units, number, &smallestElement, &smallestElementIndex);
                printTheSum(units, number);
            }
        }
        moveMaxElement(units, number, &maxElement, &maxElementIndex);
    }
    printTheSum(units, number);
}

int main()
{
    int input = 0;
    printf("Enter the number : ");
    scanf("%d,", &input);
    transformUnits(input);
    return 0;
}