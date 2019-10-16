#include <stdio.h>
#include <stdlib.h>

const int maxLength = 1000;

int* createArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

void quickSort(int numbers[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mainstayElement = numbers[left];
    int rememberLeft = left;
    int rememberRight = right;
    while (left < right)
    {
        while (numbers[left] < mainstayElement)
        {
            left += 1;
        }
        while (numbers[right] > mainstayElement)
        {
            right -= 1;
        }
        int temporary = numbers[left];
        numbers[left] = numbers[right];
        numbers[right] = temporary;
        if (numbers[left] == numbers[right])
        {
            ++left;
        }
    }
    quickSort(numbers, rememberLeft, right - 1);
    quickSort(numbers, right + 1, rememberRight);
}

int main()
{
    int *numbers = createArray(maxLength);
    int length = 0;
    printf("Enter the length of your list : ");
    scanf("%d", &length);
    for (int i = 0; i < length; ++i)
    {
        printf("Enter the new element of the list : ");
        scanf("%d", &numbers[i]);
    }
    quickSort(numbers, 0, length - 1);
    printf("Your sorted array : ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }
    free(numbers);
    return 0;
}
