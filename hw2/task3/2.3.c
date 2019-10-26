#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

bool findInArray(int* list, int size, int value)
{
    bool answer = false;
    for(int i = 0; i < size; ++i)
    {
        if (list[i] == value)
        {
            answer = true;
            break;
        }
    }
    return answer;
}

bool findDigit(int* list, int digit)
{
    bool checking = false;
    for (int i = 0; i < 4; ++i)
    {
        if (list[i] == digit)
        {
            checking = true;
            break;
        }
    }
    return checking;
}

void startTheGame(int number, int *numberArray)
{
    printf("%d \n", number);
    int input = 0;
    int *inputArray = createIntArray(4);
    printf("Enter your number : ");
    scanf("%d", &input);
    for (int i = 0; i < 4; ++i)
    {
        inputArray[i] = (input / (int) pow(10, 3 - i)) % 10;
    }
    while (input != number)
    {
        int bullNumber = 0;
        int cowNumber = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (inputArray[i] == numberArray[i])
            {
                ++bullNumber;
            }
            else if (findDigit(numberArray, inputArray[i]))
            {
                ++cowNumber;
            }
        }
        printf("cows : %d bulls: %d \n", cowNumber, bullNumber);
        printf("Enter the next number : ");
        scanf("%d", &input);
        for (int i = 0; i < 4; ++i)
        {
            inputArray[i] = (input / (int) pow(10, 3 - i)) % 10;
        }
    }
    printf("My congradulations! You win!");
    free(inputArray);
}

int main()
{
    int *numberArray = createIntArray(4);
    int number = 0;
    srand(time(NULL));
    for (int i = 0; i < 4; i++) 
    {
        int digit = rand()%10;
        while (findInArray(numberArray, i, digit))
        {
            digit = rand()%10;
        }
        numberArray[i] = digit;
        number += numberArray[i] * pow(10, 3 - i);
    }
    printf("Let's start the game \n");
    startTheGame(number, numberArray);
    free(numberArray);
    return 0;
}
