#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

//For stack with char elements

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
        return 0;
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
        return '\0';
    }
    return stack->first->value;
}

void deleteCharStack(Stack* stack)
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

//For stack with float elements

struct FloatStackElement
{
    float value;
    FloatStackElement* next;
};

struct FloatStack
{
    FloatStackElement* first;
};

FloatStack* createFloatStack()
{
    FloatStack* newFloatStack = malloc(sizeof(FloatStack));
    if (newFloatStack == NULL)
    {
        return NULL;
    }
    newFloatStack->first = NULL;
    return newFloatStack;
}

bool isEmptyFloatStack(FloatStack* floatStack)
{
    if (floatStack == NULL)
    {
        return true;
    }
    return floatStack->first == NULL;
}

bool pushFloatStack(float value, FloatStack* floatStack)
{
    if (floatStack == NULL)
    {
        return false;
    }
    FloatStackElement* floatStackElement = (FloatStackElement*) malloc(sizeof(FloatStackElement));
    floatStackElement->value = value;
    floatStackElement->next = floatStack->first;
    floatStack->first = floatStackElement;
    return true;
}

float popFloatStack(FloatStack* floatStack)
{
    if (floatStack == NULL)
    {
        return 0;
    }
    if (isEmptyFloatStack(floatStack))
    {
        return 0;
    }
    FloatStackElement* poppedElement = floatStack->first;
    floatStack->first = poppedElement->next;
    float value = poppedElement->value;
    free(poppedElement);
    return value;
}

void deleteFloatStack(FloatStack* stack)
{
    if (stack == NULL)
    {
        return;
    }
    while (stack->first != NULL)
    {
        FloatStackElement *currentElement = stack->first;
        stack->first = currentElement->next;
        free(currentElement);
    }
    free(stack);
}