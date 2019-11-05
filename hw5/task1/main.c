#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Array.h"
#include "STACK_H.h"
#include "queue.h"

const int maxSize = 100;

bool checkOperator(char digit)
{
    if (digit == '+' || digit == '-' || digit == '*' ||  digit == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

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
    deleteQueue(queue);
    deleteStack(stack);
    return  newLine;
}

int main() {
    char *line = createCharArray(maxSize);
    printf("Please, enter your line without spaces : ");
    scanf("%s", line);
    char *postfixLine = makePostfix(line);
    printf("The postfix line is : %s", postfixLine);
    free(line);
    free(postfixLine);
    return 0;
}