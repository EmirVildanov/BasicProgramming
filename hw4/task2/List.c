#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "Array.h"

struct ListElement
{
    int numberIndex;
    char *number;
    char *name;
    ListElement* next;
};

struct List
{
    ListElement* first;
    int size;
};

List* createList()
{
    List* newList = malloc(sizeof(List));
    if (newList == NULL)
    {
        exit(1);
    }
    newList->first = NULL;
    newList->size = 0;
    return newList;
}

ListElement* createListElement()
{
    ListElement *newListElement = (ListElement*) malloc(sizeof(ListElement));
    if (newListElement == NULL)
    {
        exit(1);
    }
    return newListElement;
}

int getListSize(List *list)
{
    if (list == NULL)
    {
        exit(1);
    }
    return list->size;
}

ListElement *getListFirst(List *list)
{
    if (list == NULL)
    {
        exit(1);
    }
    return list->first;
}

void changeListSize(List *list, int value)
{
    if (list == NULL)
    {
        exit(1);
    }
    list->size = value;
}

int getNumberIndex(ListElement *listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->numberIndex;
}

char *getNumber(ListElement *listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->number;
}

char *getName(ListElement *listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->name;
}

ListElement *getNext(ListElement *listElement)
{
    if (listElement == NULL)
    {
        exit(1);
    }
    return listElement->next;
}

bool isEmpty(List* list)
{
    if (list == NULL)
    {
        exit(1);
    }
    return list->first == NULL;
}

void addNew(List* list, char* number, char* name)
{
    if (list == NULL)
    {
        exit(1);
    }
    ListElement *newElement = createListElement();
    newElement->number = number;
    newElement->name = name;
    newElement->numberIndex = list->size;
    newElement->next = list->first;
    list->first = newElement;
    ++list->size;
}

char* findNumber(List* list, char name[])
{
    if (list == NULL)
    {
        exit(1);
    }
    char *wrongSearching = createCharArray(1);
    wrongSearching[0] = '*';
    ListElement *currentElement = list->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->name, name) == 0)
        {
            return currentElement->number;
        }
        currentElement = currentElement->next;
    }
    return wrongSearching;
}

char* findName(List* list, char number[])
{
    if (list == NULL)
    {
        exit(1);
    }
    char *wrongSearching = createCharArray(1);
    wrongSearching[0] = '*';
    ListElement *currentElement = list->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->number, number) == 0)
        {
            return currentElement->name;
        }
        currentElement = currentElement->next;
    }
    return wrongSearching;
}

char* pop(List* list)
{
    if (list == NULL)
    {
        exit(1);
    }
    if (isEmpty(list))
    {
        return 0;
    }
    ListElement* poppedElement = list->first;
    list->first = poppedElement->next;
    char* value = poppedElement->number;
    list->size -= 1;
    free(poppedElement);
    return value;
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        exit(1);
    }
    while(list->first != 0)
    {
        ListElement* currentElement = list->first;
        if (currentElement->next != NULL)
        {
            list->first = currentElement->next;
        }
        if(currentElement == list->first)
        {
            free(list->first);
            break;
        }
        free(currentElement);
    }
}