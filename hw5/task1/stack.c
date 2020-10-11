#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct StackElement
{
    char value;
    StackElement* next;
};

struct Stack
{
    StackElement* first;
};

Stack* createStack()
{
    Stack* newStack = malloc(sizeof(Stack));
    if (newStack == NULL)
    {
        return NULL;
    }
    newStack->first = NULL;
    return newStack;
}

bool isEmpty(Stack* stack)
{
    if (stack == NULL)
    {
        return true;
    }
    return stack->first == NULL;
}

bool push(char value, Stack* stack)
{
    if (stack == NULL)
    {
        return false;
    }
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = stack->first;
    stack->first = stackElement;
    return true;
}

char pop(Stack* stack)
{
    if (stack == NULL)
    {
        return '\0';
    }
    if (isEmpty(stack))
    {
        return '\0';
    }
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    char value = poppedElement->value;
    free(poppedElement);
    return value;
}

char getValue(Stack *stack)
{
    if (stack == NULL)
    {
        return '\0';
    }
    return stack->first->value;
}

void deleteStack(Stack* stack)
{
    if (stack == NULL)
    {
        return;
    }
    while (stack->first != NULL)
    {
        StackElement *currentElement = stack->first;
        stack->first = currentElement->next;
        free(currentElement);
    }
    free(stack);
}
