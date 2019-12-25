#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"
#include "Calculation.h"

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
    int openBracketsNumber = 0;
    int closeBracketsNumber = 0;
    for (int i = 0; i < length; ++i)
    {
        char currentChar = line[i];
        if (currentChar != ' ' && currentChar != '+' && currentChar != '-' && currentChar != '(' &&
            currentChar != ')' && currentChar != '*' && currentChar != '/' && !isdigit(currentChar))
        {
            return false;
        }
        if (currentChar == '(')
        {
            ++openBracketsNumber;
        }
        else if (currentChar == ')')
        {
            ++closeBracketsNumber;
        }
        else if (isdigit(currentChar))
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
    if (operandWait || openBracketsNumber != closeBracketsNumber)
    {
        return false;
    }
    return true;
}

float calculateNewLine(char* line)
{
    char *postfixLine = makePostfix(line);
    float result = calculateLine(postfixLine);
    free(postfixLine);
    return result;
}

int main()
{
    printf("Please, enter your line without spaces: ");
    char *line = getConsoleInput();
    while (!checkInput(line, strlen(line)))
    {
        printf("Wrong input. Please, enter your postfix line again: ");
        free(line);
        line = getConsoleInput();
    }
    printf("The answer is : %f", calculateNewLine(line));
    free(line);
    return 0;
}