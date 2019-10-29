#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct ListElement
{
    char symbol;
    int index;
    ListElement* next;
};

struct List
{
    ListElement* first;
};

List* createList()
{
    List* newList = malloc(sizeof(List));
    newList->first = NULL;
    return newList;
}

bool isEmpty(List* list)
{
    return list->first == NULL;
}

bool addNew(List* list, int index, char symbol)
{
    ListElement *listElement = (ListElement*) malloc(sizeof(ListElement));
    listElement->symbol = symbol;
    listElement->index = index;
    listElement->next = list->first;
    list->first  = listElement;
    return true;
}

char getValue(ListElement* listElement)
{
    return listElement->symbol;
}

int getIndex(ListElement* listElement)
{
    return listElement->index;
}

ListElement* findByIndex(List* list, int index)
{
    ListElement *currentElement = list->first;
    while (currentElement->index != index)
    {
        currentElement = currentElement->next;
    }
    return currentElement;
}

void insert(List* list, int index, char symbol)
{
    ListElement* currentElement = list->first;
    ListElement* newElement = (ListElement*) malloc(sizeof(ListElement));
    newElement->symbol = symbol;
    newElement->index = index;
    ListElement* nextElement = currentElement->next;
    while (currentElement->index != index - 1)
    {
        currentElement = currentElement->next;
        nextElement = currentElement->next;
    }
    currentElement->next = newElement;
    newElement->next = nextElement;
    ListElement *nextAfterNew = newElement->next;
    while(nextAfterNew->next != NULL)
    {
        ++nextAfterNew->index;
        nextAfterNew = nextAfterNew->next;
    }
    ++nextAfterNew->index;
}

ListElement* getFirstListElement(List* list)
{
    return list->first;
}

ListElement* getNextElement(ListElement* listElement)
{
    return listElement->next;
}


void changeElementNext(ListElement* listElement, ListElement* newNext)
{
    listElement->next = newNext;
}

void printTheList(List* list) {
    ListElement *newElement = list->first;
    while (newElement->next != NULL)
    {
        printf("%c", newElement->symbol);
        newElement = newElement->next;
    }
    printf("%c", newElement->symbol);
}

void deleteList(List* list)
{
    while(list->first != 0)
    {
        ListElement* currentElement = list->first;
        if (currentElement->next != NULL)
        {
            list->first = currentElement->next;
        }
        if (currentElement = list->first)
        {
        	free(list->first);
        	break;
        }
        free(currentElement);
    }
}
