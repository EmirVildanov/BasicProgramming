#include <stdio.h>
#include "List.h"

List *sortList(List *list)
{
    if (list == NULL)
    {
        return NULL;
    }
    ListElement *newElement = NULL;
    int newElementValue = 0;
    int location = 0;

    for (int i = 1; i < getListSize(list); i++)
    {
        newElement = getByIndex(list, i);
        newElementValue = getValue(newElement);
        location = i - 1;
        while(location >= 0 && getValue(getByIndex(list, location)) > newElementValue)
        {
            int newValue = getValue(getByIndex(list, location));
            changeElementValue(getByIndex(list, location + 1), newValue);
            location -= 1;
        }
        changeElementValue(getByIndex(list, location + 1), newElementValue);
    }
    return list;
}

int main()
{
    List *list = createList();
    if (list == NULL)
    {
        return 1;
    }
    addNew(list, 1);
    addNew(list, 5);
    addNew(list, 3);
    addNew(list, 9);
    addNew(list, 2);
    addNew(list, 15);
    printf("The first view of your list is : ");
    printListValues(list);
    list = sortList(list);
    printf("The second view of your list is : ");
    printListValues(list);
    deleteList(list);
    return 0;
}