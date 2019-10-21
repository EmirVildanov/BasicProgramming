#ifndef UNTITLED_INTSTACK_H_H
#define UNTITLED_INTSTACK_H_H
#include <stdbool.h>
struct Stack;
struct StackElement;

typedef struct Stack Stack;
typedef struct StackElement StackElement;

Stack* createStack();
bool isEmpty(Stack *stack);
bool push(float value, Stack *stack);
float pop(Stack *stack);

#endif
