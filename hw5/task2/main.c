#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "array.h"

const int maxInputSize = 100;

bool checkInput(const char* line, int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (line[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

bool checkOperator(char digit)
{
    bool answer = false;
    if (digit == '+' || digit == '-' || digit == '*' ||  digit == '/')
    {
        answer = true;
    }
    return answer;
}

float doOperation(char operator, float firstDigit, float secondDigit)
{
    float answer = 0;
    if (operator == '+')
    {
        answer = firstDigit + secondDigit;
    }
    if (operator == '-')
    {
        answer = secondDigit - firstDigit;
    }
    if (operator == '*')
    {
        answer = firstDigit * secondDigit;
    }
    if (operator == '/')
    {
        answer = secondDigit / firstDigit;
    }
    return answer;
}

float calculateLine(char* line)
{
    int lineLength = (int) strlen(line) - 1;
    FloatStack *stack = createFloatStack();
    for (int i = 0; i < lineLength; ++i)
    {
        char digit = line[i];
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
    char *line = createCharArray(maxInputSize);
    printf("Please, enter your postfix line without spaces : ");
    fgets(line, maxInputSize, stdin);
    if (checkInput(line, strlen(line)))
    {
        printf("The answer is : %f", calculateLine(line));
    }
    else
    {
        printf("There are spaces in your line");
    }
    free(line);
    return 0;
}