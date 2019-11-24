#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

const int numberSize = 4;

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

bool findInArray(const int* list, int size, int value)
{
    for(int i = 0; i < size; ++i)
    {
        if (list[i] == value)
        {
            return true;
        }
    }
    return false;
}

bool checkWrongInput(const int* inputArray)
{
    for (int i = 0; i < numberSize; ++i)
    {
        for (int j = i + 1; j < numberSize; ++j)
        {
            if (inputArray[i] == inputArray[j])
            {
                return true;
            }
        }
    }
    return false;
}

int power(int number, int power)
{
    int result = 1;
    for (int i = 0; i < power; ++i)
    {
        result *= number;
    }
    return result;
}

void newInput(int* inputArray, int input)
{
    scanf("%d", &input);
    for (int i = 0; i < numberSize; ++i)
    {
        inputArray[i] = (input / power(10, numberSize - 1 - i)) % 10;
    }
}

void startTheGame(int number, int *numberArray)
{
    int input = 0;
    int *inputArray = createIntArray(numberSize);
    int bullNumber = 0;
    while (bullNumber != numberSize)
    {
        bullNumber = 0;
        int cowNumber = 0;
        printf("Enter the number: ");
        newInput(inputArray, input);
        while(checkWrongInput(inputArray))
        {
            printf("Digits are repeated once. Enter the number again: ");
            newInput(inputArray, input);
        }
        for (int i = 0; i < numberSize; ++i)
        {
            if (inputArray[i] == numberArray[i])
            {
                ++bullNumber;
            }
            else if (findInArray(numberArray, numberSize, inputArray[i]))
            {
                ++cowNumber;
            }
        }
        printf("cows : %d bulls: %d \n", cowNumber, bullNumber);
    }
    printf("My congratulations! You win!");
    free(inputArray);
}

int main()
{
    int *numberArray = createIntArray(numberSize);
    int number = 0;
    printf("the number is : ");
    srand(time(NULL));
    for (int i = 0; i < numberSize; i++)
    {
        int digit = rand() % 10;
        while (findInArray(numberArray, i, digit))
        {
            digit = rand() % 10;
        }
        numberArray[i] = digit;
        printf("%d", digit);
        number = number * 10 + numberArray[i];
    }
    printf("\n");
    printf("Let's start the game \n");
    startTheGame(number, numberArray);
    free(numberArray);
    return 0;
}
