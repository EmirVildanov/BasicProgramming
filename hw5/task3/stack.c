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

void deleteCharStack(Stack* stack)
{
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
    	exit(1);
    }
    newFloatStack->first = NULL;
    return newFloatStack;
}

bool isEmptyFloatStack(FloatStack* floatStack)
{
    if (floatStack == NULL)
    {
    	exit(1);
    }
    return floatStack->first == NULL;
}

bool pushFloatStack(float value, FloatStack* floatStack)
{
    if (floatStack == NULL)
    {
    	exit(1);
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
    	exit(1);
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
    while (stack->first != NULL)
    {
        FloatStackElement *currentElement = stack->first;
        stack->first = currentElement->next;
        free(currentElement);
    }
    free(stack);
}