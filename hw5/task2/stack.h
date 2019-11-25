#pragma once

#include <stdbool.h>

struct FloatStack;
struct FloatStackElement;

typedef struct FloatStack FloatStack;
typedef struct FloatStackElement FloatStackElement;

FloatStack* createFloatStack();
bool isEmptyFloatStack(FloatStack *floatStack);
bool pushFloatStack(float value, FloatStack *floatStack);
float popFloatStack(FloatStack *floatStack);
void deleteStack(FloatStack* stack);

