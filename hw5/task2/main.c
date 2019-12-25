#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "array.h"

char *getConsoleInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
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
                if (buffer[i] == '\0')
                {
                    break;
                }
                else if (buffer[i] == '\n')
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

bool checkInput(const char *line, int length)
{
    bool operandWait = true;
    for (int i = 0; i < length; ++i)
    {
        char currentChar = line[i];
        if (currentChar != ' ' && currentChar != '+' && currentChar != '-' && currentChar != '*' && currentChar != '/' && !isdigit(currentChar))
        {
            return false;
        }
        if (i == 0 && !isdigit(currentChar))
        {
            return false;
        }
        else if (i == 0 && isdigit(currentChar))
        {
            continue;
        }
        if (isdigit(currentChar))
        {
            if (operandWait)
            {
                operandWait = !operandWait;
            }
            else
            {
                return false;
            }
        }
        else if (currentChar != ' ')
        {
            if (!operandWait)
            {
                operandWait = !operandWait;
            }
            else
            {
                return false;
            }
        }
    }
    if (!operandWait)
    {
        return false;
    }
    return true;
}

bool checkOperator(char digit)
{
    return digit == '+' || digit == '-' || digit == '*' || digit == '/';
}

float doOperation(char operator, float firstDigit, float secondDigit)
{
    float answer = 0;
    if (operator == '+')
    {
        answer = firstDigit + secondDigit;
    }
    else if (operator == '-')
    {
        answer = secondDigit - firstDigit;
    }
    else if (operator == '*')
    {
        answer = firstDigit * secondDigit;
    }
    else if (operator == '/')
    {
        answer = secondDigit / firstDigit;
    }
    return answer;
}

float calculateLine(char *line)
{
    int lineLength = (int) strlen(line);
    FloatStack *stack = createFloatStack();
    for (int i = 0; i < lineLength; ++i)
    {
        char digit = line[i];
        if (digit == ' ')
        {
            continue;
        }
        if (!checkOperator(digit))
        {
            float numberDigit = (float) digit - '0';
            pushFloatStack(numberDigit, stack);
        }
        else
        {
            float firstDigit = popFloatStack(stack);
            float secondDigit = popFloatStack(stack);
            float result = doOperation(digit, firstDigit, secondDigit);
            pushFloatStack(result, stack);
        }
    }
    float result = popFloatStack(stack);
    deleteStack(stack);
    return result;
}

int main()
{
    printf("Please, enter your postfix line : ");
    fflush(stdout);
    char *line = getConsoleInput();
    while (!checkInput(line, strlen(line)))
    {
        printf("Wrong input. Please, enter your postfix line again: ");
        fflush(stdout);
        free(line);
        line = getConsoleInput();
    }
    printf("The answer is : %f", calculateLine(line));
    fflush(stdout);
    free(line);
    return 0;
}