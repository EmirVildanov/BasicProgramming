#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct ListElement
{
    int number;
    bool lifeStatus;
    ListElement* next;
};

struct List
{
    ListElement* first;
    ListElement* lowestElement;
};

List* createList()
{
    List* newList = malloc(sizeof(List));
    if (newList == NULL)
    {
        exit(1);
    }
    newList->first = NULL;
    newList->lowestElement = NULL;
    return newList;
}

bool addNew(List* list, int number)
{
    if (list == NULL)
    {
        exit(1);
    }
    ListElement *listElement = (ListElement*) malloc(sizeof(ListElement));
    if (list->first == NULL)
    {
        list->lowestElement = listElement;
    }
    else
    {
        listElement->next = list->first;
        list->lowestElement->next = listElement;
    }
    list->first = listElement;
    listElement->number = number;
    listElement->lifeStatus = true;
    return true;
}

bool checkLifeStatus(ListElement* listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->lifeStatus;
}

int getValue(ListElement* listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->number;
}

ListElement* getFirstListElement(List* list)
{
    if (list == NULL)
    {
        exit(1);
    }
    return list->first;
}

ListElement* getNextElement(ListElement* listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->next;
}

void changeLifeStatus(ListElement* listElement, bool status)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    listElement->lifeStatus = status;
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
    free(list);
}