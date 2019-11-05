#include "Calculation.h"
#include <string.h>
#include "Array.h"
#include "queue.h"
#include "STACK_H.h"

bool checkOperator(char digit)
{
    bool answer = false;
    if (digit == '+' || digit == '-' || digit == '*' ||  digit == '/')
    {
        answer = true;
    }
    return answer;
}

//For making into postfix

int checkPower(char digit)
{
    if (digit == '+' || digit ==  '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

char* makePostfix(char* line)
{
    int lineLength = strlen(line);
    char *newLine = createCharArray(lineLength);
    Stack *stack = createStack();
    Queue *queue = createQueue();
    for (int i = 0; i < lineLength; ++i)
    {
        char digit = line[i];
        if (!checkOperator(digit) && digit != '(' && digit != ')')
        {
            pushToQueue(digit, queue);
        }
        else if (digit == '(')
        {
            push(digit, stack);
        }
        else if (digit == ')')
        {
            while (!isEmpty(stack) && getValue(stack) != '(')
            {
                pushToQueue(pop(stack), queue);
            }
            pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && checkOperator(getValue(stack)) && checkPower(getValue(stack)) >= checkPower(digit))
            {
                pushToQueue(pop(stack), queue);
            }
            push(digit, stack);
        }
    }
    while(!isEmpty(stack))
    {
        pushToQueue(pop(stack), queue);
    }
    int newlineIndex = 0;
    while(!isEmptyQueue(queue))
    {
        newLine[newlineIndex] = popFromQueue(queue);
        ++newlineIndex;
    }
    deleteCharStack(stack);
    deleteQueue(queue);
    return  newLine;
}

//For calculating

float doOperation(char operator, float firstDigit, float secondDigit)
{
    float answer = 0;
    if (operator == '+')
    {
        answer = firstDigit + secondDigit;
    }
    if (operator == '-')
    {
        answer = firstDigit - secondDigit;
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
    FloatStack *floatStack = createFloatStack();
    for (int i = 0; i < lineLength; ++i)
    {
        char digit = line[i];
        if (!checkOperator(digit))
        {
            float numberDigit = (float) digit - '0';
            pushFloatStack(numberDigit, floatStack);
        }
        else
        {
            float firstDigit = popFloatStack(floatStack);
            float secondDigit = popFloatStack(floatStack);
            float result =  doOperation(digit, firstDigit, secondDigit);
            pushFloatStack(result, floatStack);
        }
    }
    float result = popFloatStack(floatStack);
    deleteFloatStack(floatStack);
    return result;
}


