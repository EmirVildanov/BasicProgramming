#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
struct Stack;
struct StackElement;

typedef struct StackElement StackElement;
typedef struct Stack Stack;

Stack* createStack();
bool isEmpty(Stack *stack);
bool push(char value, Stack *stack);
char pop(Stack *stack);
char getValue(Stack *stack);
void deleteStack(Stack* stack);
#endif
