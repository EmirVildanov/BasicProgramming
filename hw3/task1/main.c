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

void heapify(int list[], int length, int firstIndex, int secondIndex)
{
    for (int i = 0; i < length / 2; ++i) //first sort
    {
        for (int j = 2 * i + firstIndex; j < length; ++j)
        {
            if (list[i] < list[j])
            {
                swap(list, i, j);
            }
        }
    }
    
    for (int i = 0; i < length / 2; ++i) //second sort
    {
        for (int j = 2 * i + secondIndex; j < length; ++j)
        {
            if (list[i] < list[j])
            {
                swap(list, i, j);
            }
        }
    }
}

void heapSort(int list[], int length)
{
    heapify(list, length, 1, 2);
    for (int i = 1; i < length; ++i)
    {
        swap(list, 0, length - i);
        heapify(list, length - i, 1, 2);
    }
}

int main()
{
    int *numbers = createArray(maxSize);
    int length = 0;
    printf("Enter the size of your array : ");
    scanf("%d", &length);
    for (int i = 0; i < length; ++i)
    {
        printf("Enter new element of the array : ");
        scanf("%d", &numbers[i]);
    }
    heapSort(numbers, length);
    printf("Sorted array is : ");
    for (int i = 0 ; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}
