#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct ListElement
{
    int number;
    int index;
    ListElement *next;
};

struct List
{
    ListElement *first;
    int size;
};

List *createList()
{
    List *newList = malloc(sizeof(List));
    if (newList == NULL)
    {
        return NULL;
    }
    newList->first = NULL;
    newList->size = 0;
    return newList;
}

bool addNew(List *list, int number)
{
    if (list == NULL)
    {
        return false;
    }
    ListElement *listElement = (ListElement *) malloc(sizeof(ListElement));
    listElement->number = number;
    listElement->next = list->first;
    listElement->index = list->size;
    list->first = listElement;
    ++list->size;
    return true;
}

ListElement *getByIndex(List *list, int index)
{
    ListElement *currentElement = list->first;
    while (currentElement->index != index && currentElement != NULL)
    {
        currentElement = currentElement->next;
    }
    return currentElement;
}

void changeElementValue(ListElement *listElement, int value)
{
    if (listElement == NULL)
    {
        return;
    }
    listElement->number = value;
}

int getListSize(List *list)
{
    if (list == NULL)
    {
        return 0;
    }
    return list->size;
}

int getValue(ListElement *listElement)
{
    if (listElement == NULL)
    {
        return 0;
    }
    return listElement->number;
}

void deleteList(List *list)
{
    if (list == NULL)
    {
        return;
    }
    ListElement *currentElement = list->first;
    ListElement *nextElement = currentElement->next;
    while (nextElement != NULL)
    {
        free(currentElement);
        currentElement = nextElement;
        nextElement = nextElement->next;
    }
    free(currentElement);
    free(list);
}

void printListValues(List *list)
{
    if (list == NULL)
    {
        return;
    }
    for (int i = 0; i < list->size; ++i)
    {
        int currentValue = getValue(getByIndex(list, i));
        printf("%d ", currentValue);
    }
    printf("\n");
}
