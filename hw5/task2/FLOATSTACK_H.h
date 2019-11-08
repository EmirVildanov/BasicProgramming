#ifndef INTSTACK_H
#define INTSTACK_H
#include <stdbool.h>
struct Stack;
struct StackElement;

typedef struct Stack Stack;
typedef struct StackElement StackElement;

Stack* createStack();
bool isEmpty(Stack *stack);
bool push(float value, Stack *stack);
float pop(Stack *stack);
void deleteStack(Stack* stack);
#endif
