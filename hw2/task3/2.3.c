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
    for (int i = 0; i < size; ++i)
    {
        if (list[i] == value)
        {
            return true;
        }
    }
    return false;
}

void startTheGame(int number, int *numberArray)
{
    int input = 0;
    int *inputArray = createIntArray(4);
    int bullNumber = 0;
    int cowNumber = 0;
    while (bullNumber != 4)
    {
        bullNumber = 0;
        cowNumber = 0;
        printf("Enter number : ");
        scanf("%d", &input);
        for (int i = 0; i < 4; ++i)
        {
            inputArray[i] = (input / (int) pow(10, 3 - i)) % 10;
        }
        for (int i = 0; i < 4; ++i)
        {
            if (inputArray[i] == numberArray[i])
            {
                ++bullNumber;
            }
            else if (findInArray(numberArray, 4, inputArray[i]))
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
    int *numberArray = createIntArray(4);
    int number = 0;
    printf("the number is : ");
    srand(time(NULL));
    for (int i = 0; i < 4; i++) 
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
