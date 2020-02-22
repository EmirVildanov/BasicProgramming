#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Array.h"
#include "stack.h"
#include "queue.h"

char* getInput(FILE *source)
{
    char currentChar = '\0';
    char *newLine = createCharArray(0);
    fscanf(source, "%c", &currentChar);
    int newCharIndex = 0;
    while (currentChar != '\n')
    {
        newLine = expandCharArray(newLine, newCharIndex, 1);
        newLine[newCharIndex] = currentChar;
        if (fscanf(source,"%c", &currentChar) == -1)
        {
            ++newCharIndex;
            break;
        }
        ++newCharIndex;
    }
    newLine = expandCharArray(newLine, newCharIndex, 1);
    newLine[newCharIndex] = '\0';
    return newLine;
}

bool checkOperator(char digit)
{
    return digit == '+' || digit == '-' || digit == '*' || digit == '/';
}

bool checkInput(const char *line, int length)
{
    bool operandWait = true;
    int openBracketsNumber = 0;
    int closeBracketsNumber = 0;
    for (int i = 0; i < length; ++i)
    {
        char currentChar = line[i];
        if (currentChar != ' ' && !checkOperator(currentChar) && currentChar != '(' &&
            currentChar != ')' && !isdigit(currentChar))
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

char *makePostfix(char *line)
{
    int lineLength = strlen(line);
    char *newLine = createCharArray(lineLength + 1);
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
    char *line = getInput(stdin);
    bool operandState = true;
    while (!checkInput(line, strlen(line)))
    {
        printf("Wrong input. Please, enter your line again: ");
        free(line);
        line = getInput(stdin);
    }
    char *postfixLine = makePostfix(line);
    printf("The postfix line is : %s", postfixLine);
    free(postfixLine);
    free(line);
    return 0;
}