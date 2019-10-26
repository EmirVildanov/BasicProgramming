#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

void quickSort(int *numbers, int left, int right)
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

int findDoubleMaxElement(int *list, int length)
{
    int maxElement = list[0];
    int answer = -1;
    for (int i = 1; i < length; ++i)
    {
        if (list[i] > maxElement)
        {
            maxElement = list[i];
        }
        else
        {
            answer = maxElement;
        }
    }
    return answer;
}

int main()
{
    int length = 0;
    printf("Enter the number of elements : ");
    scanf("%d", &length);
    int *numbers = createIntArray(length);
    for (int i = 0; i < length; ++i)
    {
        printf("Enter the new element : ");
        scanf("%d", &numbers[i]);
    }
    printf("Your array is : ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    quickSort(numbers, 0, length - 1);
    int answer = findDoubleMaxElement(numbers, length);
    if (answer == -1)
    {
        printf("There is no double element in the array");
    }
    else
    {
        printf("The answer is : %d ", answer);
    }
    free(numbers);
    return 0;
}
