#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct ListElement
{
    int number;
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
        return NULL;
    }
    newList->first = NULL;
    newList->lowestElement = NULL;
    return newList;
}

bool addNew(List* list, int number)
{
    if (list == NULL)
    {
        return false;
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
    return true;
}

int getValue(ListElement* listElement)
{
    if (listElement == NULL)
    {
        return -1;
    }
    return listElement->number;
}

ListElement* getFirstListElement(List* list)
{
    if (list == NULL)
    {
        return NULL;
    }
    return list->first;
}

ListElement* getNextElement(ListElement* listElement)
{
    if (listElement == NULL)
    {
        return NULL;
    }
    return listElement->next;
}

void deleteElement(List *list, ListElement *listElement)
{
    if (list == NULL || listElement == NULL)
    {
        return;
    }
    ListElement *currentElement = list->first;
    struct ListElement *rememberPrecursor = list->first;
    while (currentElement != listElement && currentElement != NULL)
    {
        rememberPrecursor = currentElement;
        currentElement = currentElement->next;
    }
    if (currentElement == NULL)
    {
        return;
    }
    if (currentElement == list->first)
    {
        rememberPrecursor = list->lowestElement;
        list->first = currentElement->next;
    }
    else if (currentElement == list->lowestElement)
    {
        list->lowestElement = rememberPrecursor;
    }
    rememberPrecursor->next = currentElement->next;
    free(currentElement);
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        return;
    }
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