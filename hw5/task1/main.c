#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Array.h"
#include "stack.h"
#include "queue.h"

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
    for (int i = 0; i < length; ++i)
    {
        char currentChar = line[i];
        if (currentChar != ' ' && currentChar != '+' && currentChar != '-' && currentChar != '(' &&
            currentChar != ')' && currentChar != '*' && currentChar != '/' && !isdigit(currentChar))
        {
            return false;
        }
    }
    return true;
}

bool checkOperator(char digit)
{
    return digit == '+' || digit == '-' || digit == '*' || digit == '/';
}

int getPriority(char operator)
{
    if (operator == '+' || operator == '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void readLineElement(const char *line, Queue *queue, Stack *stack, int index)
{
    char digit = line[index];
    if (digit == ' ')
    {
        return;
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

char *makePostfix(char *line)
{
    int lineLength = strlen(line) + 1;
    char *newLine = createCharArray(lineLength);
    Stack *stack = createStack();
    Queue *queue = createQueue();
    for (int i = 0; i < lineLength - 1; ++i)
    {
        readLineElement(line, queue, stack, i);
    }
    while (!isEmpty(stack))
    {
        pushToQueue(pop(stack), queue);
    }
    int newlineIndex = 0;
    while (!isEmptyQueue(queue))
    {
        newLine[newlineIndex] = popFromQueue(queue);
        ++newlineIndex;
    }
    newLine[newlineIndex] = '\0';
    deleteQueue(queue);
    deleteStack(stack);
    return newLine;
}

int main()
{
    printf("Please, enter your line : ");
    char *line = getConsoleInput();
    while (!checkInput(line, strlen(line)))
    {
        printf("Wrong input. Please, enter your line again: ");
        line = getConsoleInput();
    }
    char *postfixLine = makePostfix(line);
    printf("The postfix line is : %s", postfixLine);
    free(postfixLine);
    free(line);
    return 0;
}