#include <stdlib.h>
#include <stdio.h>
#include "STACK_H.h"

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
    newStack ->first = NULL;
    return newStack;
}

bool isEmpty(Stack* stack)
{
    return stack ->first == NULL;
}

bool push(char value, Stack* stack)
{
    StackElement* stackElement = (StackElement*) malloc(sizeof(StackElement));
    stackElement ->value = value;
    stackElement ->next = stack ->first;
    stack->first = stackElement;
    return true;
}

char pop(Stack* stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    StackElement* poppedElement = stack ->first;
    stack ->first = poppedElement ->next;
    char value = poppedElement ->value;
    return value;
}

char getValue(Stack *stack)
{
    return stack->first->value;
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
    newFloatStack ->first = NULL;
    return newFloatStack;
}

bool isEmptyFloatStack(FloatStack* floatStack)
{
    return floatStack ->first == NULL;
}

bool pushFloatStack(float value, FloatStack* floatStack)
{
    FloatStackElement* floatStackElement = (FloatStackElement*) malloc(sizeof(FloatStackElement));
    floatStackElement ->value = value;
    floatStackElement ->next = floatStack ->first;
    floatStack->first = floatStackElement;
    return true;
}

float popFloatStack(FloatStack* floatStack)
{
    if (isEmptyFloatStack(floatStack))
    {
        return 0;
    }
    FloatStackElement* poppedElement = floatStack ->first;
    floatStack ->first = poppedElement ->next;
    float value = poppedElement ->value;
    return value;
}

float getFloatValue(FloatStack *floatStack)
{
    return floatStack->first->value;
}