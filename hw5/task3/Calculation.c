#include "Calculation.h"
#include <stdio.h>
#include <string.h>
#include "array.h"
#include "queue.h"
#include "stack.h"

//For making into postfix

bool checkOperator(char digit)
{
    return digit == '+' || digit == '-' || digit == '*' ||  digit == '/';
}

int getPriority(char operator)
{
    if (operator == '+' || operator ==  '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int readLineElement(const char *line, Queue *queue, Stack *stack, int index)//returns 1/0 if operation is (un)successful
{
    char digit = line[index];
    if (digit == ' ')
    {
        return 0;
    }
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
        if (isEmpty(stack))
        {
            printf("The opening bracket is missed");
            return 1;
        }
        pop(stack);
    }
    else
    {
        while (!isEmpty(stack) && checkOperator(getValue(stack)) && getPriority(getValue(stack)) >= getPriority(digit))
        {
            pushToQueue(pop(stack), queue);
        }
        push(digit, stack);
    }
    return 0;
}

char* makePostfix(char* line)
{
    int lineLength = strlen(line);
    char *newLine = createCharArray(lineLength);
    Stack *stack = createStack();
    Queue *queue = createQueue();
    for (int i = 0; i < lineLength; ++i)
    {
        if (readLineElement(line, queue, stack, i) == 1)
        {
            return "The mistake";
        }
    }
    if (!isEmpty(stack))
    {
        char firstValue = pop(stack);
        if (firstValue == '(' || firstValue == ')')
        {
            return "The mistake";
        }
        pushToQueue(firstValue, queue);
    }
    while (!isEmpty(stack))
    {
        pushToQueue(pop(stack), queue);
    }
    int newlineIndex = 0;
    while(!isEmptyQueue(queue))
    {
        newLine[newlineIndex] = popFromQueue(queue);
        ++newlineIndex;
    }
    newLine[newlineIndex] = '\0';
    deleteQueue(queue);
    deleteStack(stack);
    return newLine;
}

//For calculating

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

float calculateLine(char* line)
{
    int lineLength = (int) strlen(line);
    FloatStack *floatStack = createFloatStack();
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
            pushFloatStack(numberDigit, floatStack);
        }
        else
        {
            float firstDigit = popFloatStack(floatStack);
            float secondDigit = popFloatStack(floatStack);
            float result = doOperation(digit, firstDigit, secondDigit);
            pushFloatStack(result, floatStack);
        }
    }
    float result = popFloatStack(floatStack);
    deleteFloatStack(floatStack);
    return result;
}