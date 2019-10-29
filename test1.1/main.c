#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"
#include "List.h"

const int maxSize = 20;

int findFirstSpaceIndex(List* list)
{
    ListElement  *currentElement = getFirstListElement(list);
    while (getValue(currentElement) != ' ')
    {
        currentElement = getNextElement(currentElement);
    }
    return getIndex(currentElement);
}

int findAppropriateIndex(List* list, int* badIndex)
{
    ListElement *currentElement = getFirstListElement(list);
    while(getValue(currentElement) != ' ')
    {
        if (getNextElement(currentElement) == NULL)
        {
            return -1;
        }
        currentElement = getNextElement(currentElement);
        if (getValue(currentElement) == ' ' && getIndex(currentElement) <= *badIndex)
        {
            while (getValue(currentElement) == ' ')
            {
                currentElement = getNextElement(currentElement);
            }
        }
    }
    return getIndex(currentElement);
}

void makeLongerLine(List* list,  int firstSpaceIndex, int* newSpaceIndex, int lineLength)
{
    int indexToInsert = findAppropriateIndex(list, newSpaceIndex);
    if (indexToInsert == -1)
    {
        *newSpaceIndex = firstSpaceIndex;
        insert(list, firstSpaceIndex, ' ');
        return;
    }
    *newSpaceIndex = indexToInsert;
    insert(list, indexToInsert, ' ');
}

int main() {
    int userLength = 0;
    char *line = createCharArray(maxSize);
    List *list = createList();
    printf("Enter the line : ");
    gets(line);
    int lineLength = strlen(line);
    for (int i = lineLength - 1; i >= 0; --i)
    {
        addNew(list, i, line[i]);
    }
    printf("Enter the length you want to get : ");
    scanf("%d", &userLength);
    int firstSpaceIndex = findFirstSpaceIndex(list);
    int newSpaceIndex = -1;
    while (lineLength < userLength)
    {
        makeLongerLine(list, firstSpaceIndex, &newSpaceIndex, lineLength);
        ++lineLength;
    }
    printf("The new line is : ");
    printTheList(list);
    free(line);
    deleteList(list);
    return 0;
}