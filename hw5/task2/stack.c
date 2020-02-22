#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

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

void deleteStack(FloatStack* stack)
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
