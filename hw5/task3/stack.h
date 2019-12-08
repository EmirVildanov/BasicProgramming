#pragma once

#include <stdbool.h>

//For stack with char elements
struct Stack;
struct StackElement;

typedef struct StackElement StackElement;
typedef struct Stack Stack;

Stack* createStack();
bool isEmpty(Stack *stack);
bool push(char value, Stack *stack);
char pop(Stack *stack);
char getValue(Stack *stack);
void deleteCharStack(Stack* stack);

//For stack with float elements

struct FloatStack;
struct FloatStackElement;

typedef struct FloatStack FloatStack;
typedef struct FloatStackElement FloatStackElement;

FloatStack* createFloatStack();
bool isEmptyFloatStack(FloatStack *floatStack);
bool pushFloatStack(float value, FloatStack *floatStack);
float popFloatStack(FloatStack *floatStack);
void deleteFloatStack(FloatStack* stack);

