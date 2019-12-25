gi#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "array.h"

const int machineSize = 18;
const int finalState = 10;

struct State
{
    unsigned int current;
    signed char symbol;
    unsigned int next;
};

struct State machine[] =
        {
                {0, 'd', 1},
                {0, 'z', 1},
                {0, 'u', 1},
                {1, 'd', 2},
                {1, 'u', 2},
                {1, 'z', 2},
                {2, 'B', 3},
                {2, 'S', 3},
                {2, 'M', 3},
                {3, 'u', 5},
                {3, 'd', 4},
                {4, '-', 7},
                {5, 'z', 6},
                {5, '-', 7},
                {6, '-', 7},
                {7, 'm', 8},
                {8, 'm', 9},
                {9, '\0', 10},
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
        if (currentChar == 'z' || currentChar == 'd' || currentChar == 'u')
        {
            return false;
        }
        if (currentChar == '0') //zero
        {
            currentChar = 'z';
        }
        else if (currentChar == '1')//unit
        {
            currentChar = 'u';
        }
        else if (isdigit(currentChar))//non-unit digit
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
        printf("Your input is appropriate\n");
    }
    else
    {
        printf("Your input is not appropriate\n");
    }
    free(input);
    return 0;
}
