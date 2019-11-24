#include <stdio.h>
#include <stdlib.h>

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

void heapify(int list[], int length, int index)
{
    for (int i = 0; i < length / 2; ++i) //first sort
    {
        for (int j = 2 * i + index; j < length; ++j)
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
    heapify(list, length, 1);
    heapify(list, length, 2);
    for (int i = 1; i < length; ++i)
    {
        swap(list, 0, length - i);
        heapify(list, length - i, 1);
        heapify(list, length - i, 2);
    }
}

int main()
{
    int length = 0;
    printf("Enter the size of your array : ");
    scanf("%d", &length);
    int *numbers = createArray(length);
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
