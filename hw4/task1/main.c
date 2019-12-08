#include <stdio.h>
#include "List.h"

ListElement* killUnit(List *list, int everyUnit, ListElement *currentUnit)
{
    for (int i = 0; i < everyUnit - 1; ++i)
    {
        currentUnit = getNextElement(currentUnit);
    }
    ListElement *nextAliveUnit = getNextElement(currentUnit);
    deleteElement(list, currentUnit);
    return nextAliveUnit;
}

int findPosition(int unitsNumber, int everyUnit)
{
    List *list = createList();
    if (list == NULL)
    {
        return 0;
    }
    for (int i = unitsNumber; i > 0; --i)
    {
        addNew(list, i);
    }
    ListElement *currentUnit = getFirstListElement(list);
    for (int i = 0; i < unitsNumber - 1; ++i)
    {
        currentUnit = killUnit(list, everyUnit, currentUnit);
    }
    ListElement* winner = getFirstListElement(list);
    int goodPositionIndex = getValue(winner);
    deleteList(list);
    return goodPositionIndex;
}

int main()
{
    int numberOfUnits = 0;
    int everyUnit = 0;
    printf("Enter the number of units : ");
    scanf("%d", &numberOfUnits);
    printf("Enter the number of every killing unit : ");
    scanf("%d", &everyUnit);
    int goodPosition = findPosition(numberOfUnits, everyUnit);
    if (goodPosition == 0)
    {
        return 1;
    }
    printf("The good position for you to survive is : %d", goodPosition);
    return 0;
}