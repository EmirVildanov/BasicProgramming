#include <stdlib.h>
#include <stdio.h>
#include "FLOATSTACK_H.h"

struct StackElement
{
    float value;
    StackElement* next;
};

struct Stack
{
    StackElement* first;
};

Stack* createStack()
{
    Stack* newStack = malloc(sizeof(Stack));
    newStack ->first = NULL;
    return newStack;
}

bool isEmpty(Stack* stack)
{
    return stack ->first == NULL;
}

bool push(float value, Stack* stack)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement ->value = value;
    stackElement ->next = stack ->first;
    stack->first = stackElement;
    return true;
}

float pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    StackElement* poppedElement = stack ->first;
    stack ->first = poppedElement ->next;
    float value = poppedElement ->value;
    return value;
}
