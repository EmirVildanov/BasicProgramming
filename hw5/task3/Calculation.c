#include "Calculation.h"
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

void readLineElement(const char* line, Queue* queue, Stack* stack, int index)
{
    char digit = line[index];
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
        while (!isEmpty(stack) && checkOperator(getValue(stack)) && getPriority(getValue(stack)) >= getPriority(digit))
        {
            pushToQueue(pop(stack), queue);
        }
        push(digit, stack);
    }
}

char* makePostfix(char* line)
{
    int lineLength = strlen(line) - 1;
    char *newLine = createCharArray(lineLength);
    Stack *stack = createStack();
    Queue *queue = createQueue();
    for (int i = 0; i < lineLength; ++i)
    {
        readLineElement(line, queue, stack, i);
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
            float result = doOperation(digit, firstDigit, secondDigit);
            pushFloatStack(result, floatStack);
        }
    }
    float result = popFloatStack(floatStack);
    deleteFloatStack(floatStack);
    return result;
}