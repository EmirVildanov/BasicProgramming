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

void changePlaces(int list[], int first, int second)
{
    int temporary = list[first];
    list[first] = list[second];
    list[second] = temporary;
}

void firstSort(int list[], int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        for (int j = 2 * i + 1; j < length; ++j)
        {
            if (list[i] < list[j])
            {
                changePlaces(list, i, j);
            }
        }
    }
}

void secondSort(int list[], int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        for (int j = 2 * i + 2; j < length; ++j)
        {
            if (list[i] < list[j])
            {
                changePlaces(list, i, j);
            }
        }
    }
}

void heapify(int list[], int length)
{
    firstSort(list, length);
    secondSort(list, length);
}

void heapSort(int list[], int length)
{
    heapify(list, length);
    for (int i = 1; i < length; ++i)
    {
        changePlaces(list, 0, length - i);
        heapify(list, length - i);
    }
}

int main() {
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