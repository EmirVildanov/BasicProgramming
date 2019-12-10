#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "array.h"

const int machineSize = 17;
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
                {1, 'd', 2},
                {2, 'd', 2},
                {2, '.', 3},
                {2, '\0', 8},
                {3, 'd', 4},
                {4, 'd', 4},
                {4, 'E', 5},
                {4, '\0', 8},
                {5, '+', 6},
                {5, '-', 6},
                {5, 'd', 7},
                {6, 'd', 7},
                {7, 'd', 7},
                {7, '\0', 8},
        };

char *getInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    if (input == NULL)
    {
        return NULL;
    }
    char *buffer = createCharArray(maxGettingSize);
    if (buffer == NULL)
    {
        return NULL;
    }
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        return NULL;
    }
    else
    {
        int lastSymbolIndex = 0;
        while (true)
        {
            for (int i = 0; i < expandValue - 1; ++i)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[i] == '\n')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[i];
                ++lastSymbolIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

unsigned int checkState(unsigned int currentState, char currentChar)
{
    for (int i = 0; i < machineSize; ++i)
    {
        if (machine[i].current == currentState && currentChar == machine[i].symbol)
        {
            return machine[i].next;
        }
    }
    return -1;
}

bool analyseInput(const char *input)
{
    int currentCharIndex = 0;
    unsigned int currentState = 0;
    while (true)
    {
        char currentChar = input[currentCharIndex];
        if (isdigit(currentChar))
        {
            currentChar = 'd';
        }
        currentState = checkState(currentState, currentChar);
        if (currentState == -1)
        {
            return false;
        }
        if (currentState == finalState)
        {
            return true;
        }
        ++currentCharIndex;
    }
}

int main()
{
    printf("Enter your line: ");
    char *input = getInput();
    if (input == NULL)
    {
        return 1;
    }
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