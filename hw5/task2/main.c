#include <stdio.h>
#include <string.h>
#include "FLOATSTACK_H.h"
#include "Array.h"

const int maxSize = 100;

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
    int lineLength = (int) strlen(line);
    Stack *stack = createStack();
    for (int i = 0; i < lineLength; ++i)
    {
        char digit = line[i];
        if (!checkOperator(digit))
        {
            float numberDigit = (float) digit - '0';
            push(numberDigit, stack);
        }
        else
        {
            float firstDigit = pop(stack);
            float secondDigit = pop(stack);
            float result =  doOperation(digit, firstDigit, secondDigit);
            push(result, stack);
        }
    }
    return pop(stack);
}

int main()
{
    char *line = createCharArray(maxSize);
    printf("Please, enter your postfix line without spaces : ");
    scanf("%s", line);
    printf("The answer is : %f", calculateLine(line));
    return 0;
}