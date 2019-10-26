#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct ListElement{
    int number;
    bool lifeStatus;
    ListElement* next;
};

struct List{
    ListElement* first;
    ListElement* lowestElement;
};

List* createList()
{
    List* newList = malloc(sizeof(List));
    newList->first = NULL;
    newList->lowestElement = NULL;
    return newList;
}

bool isEmpty(List* list)
{
    return list->first == NULL;
}

bool addNew(List* list, int number)
{
    ListElement *listElement = (ListElement*) malloc(sizeof(ListElement));
    if (list->first == NULL)
    {
        list->lowestElement = listElement;
        list->lowestElement->number = number;
        list->lowestElement->lifeStatus = true;
        list->first = listElement;
    }
    else
    {
        listElement->next = list->first;
        listElement->number = number;
        listElement->lifeStatus = true;
        list->first = listElement;
        list->lowestElement->next = listElement;
    }
    return true;
}

bool checkLifeStatus(ListElement* listElement)
{
    return listElement->lifeStatus;
}

int getValue(ListElement* listElement)
{
    return listElement->number;
}

ListElement* getFirstListElement(List* list)
{
    return list->first;
}

ListElement* getNextElement(ListElement* listElement)
{
    return listElement->next;
}

void changeLifeStatus(ListElement* listElement, bool status)
{
    listElement->lifeStatus = status;
}

void changeElementNext(ListElement* listElement, ListElement* newNext)
{
    listElement->next = newNext;
}

void deleteList(List* list)
{
    list->lowestElement->next = NULL;
    while(list->first != NULL)
    {
        ListElement* currentElement = list->first;
        if (currentElement->next != NULL)
        {
            list->first = currentElement->next;
        }
        if (currentElement == list->lowestElement)
        {
            free(list->lowestElement);
            break;
        }
        free(currentElement);
    }
}