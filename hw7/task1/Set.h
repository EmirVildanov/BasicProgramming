#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct SetElement SetElement;
typedef struct Set Set;

Set* createSet();
bool isSetEmpty(Set* set);
void addToSet(Set* set, int value);
void getInIncreasingOrder(Set* set, int* array, int* sizeOfArray);
void getInDecreasingOrder(Set* set, int* array, int* sizeOfArray);
bool findElement(Set* set, int value);
void checkElement(Set* set, int value);
void printSet(Set* set);
void deleteElement(Set* set, int value);

//functions for Self Balancing tree

int height(SetElement* setElement);
int balanceFactor(SetElement* setElement);
void updateHeight(SetElement* setElement);
SetElement* rotateRight(Set* set, SetElement* setElement);
SetElement* rotateLeft(Set* set, SetElement* setElement);
SetElement* balance(Set*, SetElement* setElement);

#endif
