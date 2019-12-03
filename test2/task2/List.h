#pragma once

#include <stdbool.h>

struct List;
struct ListElement;

typedef struct ListElement ListElement;
typedef struct List List;

List *createList();

bool addNew(List *list, int number);

int getListSize(List *list);

ListElement *getByIndex(List *list, int index);

int getValue(ListElement *listElement);

void changeElementValue(ListElement *listElement, int value);

void printListValues(List *list);

void deleteList(List *list);