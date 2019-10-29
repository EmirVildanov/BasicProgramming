#ifndef INC_6_3_BAG_H
#define INC_6_3_BAG_H

#include <stdbool.h>

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

#endif
