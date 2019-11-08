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

char* findNumber(List* list, char name[], int maxNumberSize)
{
    char *number = malloc(maxNumberSize * sizeof(char));
    number[0] = '*';
    ListElement *currentElement = list->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->name, name) == 0)
        {
            return currentElement->number;
        }
        currentElement = currentElement->next;
    }
    return number;
}

char* findName(List* list, char number[], int maxNameSize)
{
    char *answer = malloc(maxNameSize * sizeof(char));
    answer[0] = '*';
    ListElement *currentElement = list->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->number, number) == 0)
        {
            return currentElement->name;
        }
        currentElement = currentElement->next;
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



