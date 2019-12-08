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

int findNonZeroIndex(int* digits, int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        if (digits[i] != 0)
        {
            return i;
        }
    }
}

void swap(int* digits, int firstIndex, int secondIndex)
{
    int temporary = digits[firstIndex];
    digits[firstIndex] = digits[secondIndex];
    digits[secondIndex] = temporary;
}

int returnNewNumber(char* inputNumber)
{
    int answer = 0;
    int length = 0;
    length = strlen(inputNumber);
    int *digits = createIntArray(length);
    for (int i = 0; i < length; ++i)
    {
        digits[i] = inputNumber[i] - '0';
    }
    quickSort(digits, 0, length - 1);
    if (digits[0] == 0)
    {
        swap(digits, 0, findNonZeroIndex(digits, length));
    }
    for (int i = 0; i < length; ++i)
    {
        answer = answer * 10 + digits[i];
    }
    free(digits);
    return answer;
}

int main()
{
    char *input = createCharArray(maxSize);
    printf("Enter the number : ");
    scanf("%s", input);
    int answer = returnNewNumber(input);
    printf("The smallest number is : %d", answer);
    free(input);
    return 0;
}
