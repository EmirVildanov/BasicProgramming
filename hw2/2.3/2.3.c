#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

bool findDigit(int list[], int digit)
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

void startTheGame(int number, int numberArray[])
{
    int input = 0;
    int inputArray[4] = {0};
    printf("Enter your number : ");
    scanf("%d", &input);
    for (int i = 0; i < 4; ++i)
    {
        inputArray[i] = (input / (int)pow(10, 3 - i)) % 10;
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
            else if (findDigit(numberArray, inputArray[i]) == true)
            {
                ++cowNumber;
            }
        }
        printf("cows : %d bulls: %d \n", cowNumber, bullNumber);
        printf("Enter the next number : ");
        scanf("%d", &input);
        for (int i = 0; i < 4; ++i)
        {
            inputArray[i] = (input / (int)pow(10, 3 - i)) % 10;
        }
    }
    printf("My congradulations! You win!");
}

int main()
{
    int numberArray[4] = {0};
    int number = 0;
    srand(time(NULL));
    for (int i = 0; i < 4; i++) 
    {
         numberArray[i] = rand()%10;
         number += numberArray[i] * pow(10, 3 - i);
    }
    printf("Let's start the game \n");
    startTheGame(number, numberArray);
}