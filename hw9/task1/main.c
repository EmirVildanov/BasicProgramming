#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"

const char digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

const int machineSize = 22;
const int finalState = 8;

struct state
{
    unsigned int current;
    signed char symbol;
    unsigned int next;
};

struct state machine[] =
        {
                {0, '+', 1},
                {0, '-', 1},
                {0, 'd', 2},
                {0, 'd', 8},
                {1, 'd', 2},
                {1, 'd', 8},
                {2, 'd', 2},
                {2, '.', 3},
                {2, 'd', 8},
                {3, 'd', 4},
                {3, 'd', 8},
                {4, 'd', 4},
                {4, 'E', 5},
                {4, 'd', 8},
                {5, '+', 6},
                {5, '-', 6},
                {5, 'd', 7},
                {5, 'd', 8},
                {6, 'd', 7},
                {7, 'd', 7},
                {7, 'd', 8},
                {8, '\0', 9}
        };

char *getInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        exit(1);
    }
    else
    {
        int lastSymbolIndex = 0;
        int bufferIndex = 0;
        while (true)
        {
            while (bufferIndex < expandValue - 1)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[bufferIndex] == '\n' || buffer[bufferIndex] == '\0')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[bufferIndex];
                ++lastSymbolIndex;
                ++bufferIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            bufferIndex = 0;
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

bool checkDigit(char currentChar)
{
    for (int i = 0; i < 10; ++i)
    {
        if (currentChar == digits[i])
        {
            return true;
        }
    }
    return false;
}

bool checkState(unsigned int *currentState, char currentChar, char nextChar)
{
    for (int i = 0; i < machineSize; ++i)
    {
        if (machine[i].current == *currentState && currentChar == machine[i].symbol)
        {
            for (int j = i + 1; j < machineSize; ++j)
            {
                if (machine[j].current == machine[i].next && nextChar == machine[j].symbol)
                {
                    *currentState = machine[j].current;
                    return true;
                }
            }
        }
    }
    return false;
}

bool analyseInput(const char *input)
{
    int currentCharIndex = 0;
    unsigned int currentState = 0;
    while (input[currentCharIndex] != '\0')
    {
        char currentChar = input[currentCharIndex];
        char nextChar = input[currentCharIndex + 1];
        if (checkDigit(currentChar))
        {
            currentChar = 'd';
        }
        if (checkDigit(nextChar))
        {
            nextChar = 'd';
        }
        if (!checkState(&currentState, currentChar, nextChar))
        {
            return false;
        }
        ++currentCharIndex;
    }
    if (currentState != finalState)
    {
        return false;
    }
    return true;
}

int main()
{
    printf("Enter your line: ");
    char *input = getInput();
    if (analyseInput(input))
    {
        printf("Your input is a real number!\n");
    }
    else
    {
        printf("Your input is not a real number\n");
    }
    return 0;
}