#pragma once

#include <stdbool.h>

typedef struct Set Set;

Set *createSet();

int getSetSize(Set *set);

bool isSetEmpty(Set *set);

void addToSet(Set *set, int value);

void getInIncreasingOrder(Set *set, int *array);

void getInDecreasingOrder(Set *set, int *array);

bool findElement(Set *set, int value);

void checkElement(Set *set, int value);

void printSet(Set *set);

void deleteElement(Set *set, int value);

void deleteSet(Set *set);