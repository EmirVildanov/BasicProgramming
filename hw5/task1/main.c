#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Array.h"
#include "stack.h"
#include "queue.h"

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
    deleteQueue(queue);
    deleteStack(stack);
    return newLine;
}

int main()
{
    char *line = createCharArray(maxInputSize);
    printf("Please, enter your line without spaces : ");
    fgets(line, maxInputSize, stdin);
    if (checkInput(line, strlen(line)))
    {
        char *postfixLine = makePostfix(line);
        printf("The postfix line is : %s", postfixLine);
        free(postfixLine);
    }
    else
    {
        printf("There are spaces in your line\n");
    }
    free(line);
    return 0;
}