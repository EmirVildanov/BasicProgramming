#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int maxSize = 100;

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

char* createCharArray(int size)
{
    char *list = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

void quickSort(int* numbers, int left, int right)
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
 
int returnNewNumber(char* string)
{
    int length = 0;
    length = strlen(string);
    int number = atoi(string);
    int *digits = createIntArray(length);
    for (int i = 0; i < length; ++i)
    {
        int tenPower = (int) pow(10, length - i - 1);
        digits[i] = number / tenPower;
        number = number % tenPower;
    }
    quickSort(digits, 0, length - 1);
    for (int i = 0; i < length; ++i)
    {
        printf("%d", digits[i]);
    }
    free(digits);
}

int main()
{
    char *input = createCharArray(maxSize);
    printf("Enter the number : ");
    scanf("%s", input);
    printf("The smallest number is : ");
    returnNewNumber(input);
    free(input);
    return 0;
}
