#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

List* createList()
{
    List* newList = malloc(sizeof(List));
    newList ->first = NULL;
    return newList;
}

bool isEmpty(List* list)
{
    return list ->first == NULL;
}

bool addNew(List* list, int number)
{
    ListElement *listElement = (ListElement*) malloc(sizeof(ListElement));
    listElement ->number = number;
    listElement ->lifeStatus = true;
    listElement ->next = list ->first;
    list ->first  = listElement;
    return true;
}


