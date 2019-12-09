#pragma once

#include <stdbool.h>

typedef struct SetElement SetElement;
typedef struct Set Set;

Set *createSet();
int getSetSize(Set *set);
bool isSetEmpty(Set *set);
bool findElement(Set *set, int value);
void addToSet(Set *set, int value);
void checkElement(Set *set, int value);

//to capture set's elements in array
void getInIncreasingOrder(Set *set, int *array);
void getInDecreasingOrder(Set *set, int *array);

void deleteElement(Set *set, int value);
void deleteSet(Set *set);

void printSet(Set *set);