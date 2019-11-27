#pragma once

#include <stdbool.h>

typedef struct SetElement SetElement;
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

//functions for Self Balancing tree

int findHeight(SetElement *setElement);

int findBalanceFactor(SetElement *setElement);

void updateHeight(SetElement *setElement);

SetElement *rotateRight(Set *set, SetElement *setElement);

SetElement *rotateLeft(Set *set, SetElement *setElement);

SetElement *balance(Set *, SetElement *setElement);
