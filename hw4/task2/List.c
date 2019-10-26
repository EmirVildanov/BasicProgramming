#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

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

void addNew(List* list, char number[], char name[], int numberIndex, int maxValueSize)
{
    ListElement *newElement = (ListElement*) malloc(sizeof(ListElement));
    strncpy(newElement->number, number, maxValueSize);
    newElement->numberIndex = numberIndex;
    strncpy(newElement->name, name, maxValueSize);
    newElement->next = list->first;
    list->first  = newElement;
}

int findNameIndex(List* list, const char name[])
{
    int index = -1;
    ListElement* currentNumber = list->first;
    while (strcmp(currentNumber->number, "404") != 00)
    {
        if (strcmp(currentNumber->name, name) == 0)
        {
            return currentNumber->numberIndex;
        }
        currentNumber = currentNumber->next;
    }
    return index;
}

int findNumberIndex(List* list, const char number[])
{
    int index = -1;
    ListElement* currentNumber = list->first;
    while (strcmp(currentNumber->number, "404") != 00)
    {
        if (strcmp(currentNumber->number, number) == 0)
        {
            return currentNumber->numberIndex;
        }
        currentNumber = currentNumber->next;
    }
    return index;
}

char* findNumber(List* list, char name[], int maxNumberSize)
{
    char *number = malloc(maxNumberSize * sizeof(char));
    number[0] = '*';
    int nameIndex = findNameIndex(list, name);
    if (nameIndex != -1)
    {
        ListElement *currentNumber = list->first;
        while (currentNumber->numberIndex != nameIndex)
        {
            currentNumber = currentNumber->next;
        }
        return currentNumber->number;
    }
    return number;
}

char* findName(List* list, char number[], int maxNameSize)
{
    char *answer = malloc(maxNameSize * sizeof(char));
    answer[0] = '*';
    int numberIndex = findNumberIndex(list, number);
    if (numberIndex != -1)
    {
        ListElement *currentNumber = list->first;
        while (currentNumber->numberIndex != numberIndex)
        {
            currentNumber = currentNumber->next;
        }
        return currentNumber->name;
    }
    return answer;
}

int pop(List* list, int* numberIndex)
{
    if (isEmpty(list))
    {
        return 0;
    }
    ListElement* poppedElement = list->first;
    list->first = poppedElement->next;
    int value = poppedElement->number;
    *numberIndex -= 1;
    free(poppedElement);
    return value;
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
        if(currentElement == list->first)
        {
            free(list->first);
            break;
        }
        free(currentElement);
    }
}



