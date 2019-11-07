#include <stdio.h>
#include <stdlib.h>

const int maxSize = 100;

int* createArray(int size)
{
    int* newList = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        newList[i] = 0;
    }
    return newList;
}

void swap(int list[], int first, int second)
{
    int temporary = list[first];
    list[first] = list[second];
    list[second] = temporary;
}

int findFartherNaturalIndex(int list[], int length, int zeroIndex)
{
    int index = length - 1;
    while (list[index] == 0 && index != zeroIndex)
    {
        index -= 1;
    }
    return index;
}

void moveZeros(int list[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (list[i] == 0)
        {
            int noZeroElementIndex = findFartherNaturalIndex(list, length, i);
            swap(list, i, noZeroElementIndex);
        }
    }
}

int main()
{
    int *numbers = createArray(maxSize);
    int length = 0;
    printf("Enter the length of your array : ");
    scanf("%d", &length);
    for (int i = 0; i < length; ++i)
    {
        printf("Enter new element of the array : ");
        scanf("%d", &numbers[i]);
    }
    moveZeros(numbers, length);
    printf("The new array is : ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}
