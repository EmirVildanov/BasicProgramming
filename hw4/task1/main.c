#include <stdio.h>
#include "List.h"

ListElement* findAliveUnit(ListElement* currentUnit)
{
    while (!checkLifeStatus(currentUnit))
    {
        currentUnit = getNextElement(currentUnit);
    }
    return currentUnit;
}

ListElement* killUnit(int everyUnit, ListElement *currentUnit)
{
    for (int i = 0; i < everyUnit - 1; ++i)
    {
        currentUnit = findAliveUnit(getNextElement(currentUnit));
    }
    changeLifeStatus(currentUnit, false);
    return findAliveUnit(getNextElement(currentUnit));
}

int findPosition(int unitsNumber, int everyUnit)
{
    List *list = createList();
    for (int i = unitsNumber; i > 0; --i)
    {
        addNew(list, i);
    }
    ListElement *currentUnit = getFirstListElement(list);
    for (int i = 0; i < unitsNumber - 1; ++i)
    {
        currentUnit = killUnit(everyUnit, currentUnit);
    }
    ListElement* winner = findAliveUnit(currentUnit);
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
    printf("The good position for you to survive is : %d", findPosition(numberOfUnits, everyUnit));
    return 0;
}