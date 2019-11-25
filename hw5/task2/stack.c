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

void deleteStack(FloatStack* stack)
{
    while (stack->first != NULL)
    {
        FloatStackElement *currentElement = stack->first;
        stack->first = currentElement->next;
        free(currentElement);
    }
    free(stack);
}
