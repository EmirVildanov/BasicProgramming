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
    	exit(1);
    }
    newStack->first = NULL;
    return newStack;
}

bool isEmpty(Stack* stack)
{
    if (stack == NULL)
    {
    	exit(1);
    }
    return stack->first == NULL;
}

bool push(char value, Stack* stack)
{
    if (stack == NULL)
    {
    	exit(1);
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
    	exit(1);
    }
    if (isEmpty(stack))
    {
        return 0;
    }
    StackElement* poppedElement = stack->first;
    stack->first = poppedElement->next;
    char value = poppedElement->value;
    return value;
}

char getValue(Stack *stack)
{
    if (stack == NULL)
    {
    	exit(1);
    }
    return stack->first->value;
}

void deleteStack(Stack* stack)
{
    while (stack->first != NULL)
    {
        StackElement *currentElement = stack->first;
        stack->first = currentElement->next;
        free(currentElement);
    }
    free(stack);
}
