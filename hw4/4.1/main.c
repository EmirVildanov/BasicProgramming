#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListElement* findAliveUnit(List* list, ListElement* currentUnit)
{
    while (!currentUnit ->lifeStatus)
    {
        currentUnit = currentUnit ->next;
    }
    return currentUnit;
}

ListElement* killUnit(List* list, int everyUnit, ListElement *currentUnit, int* numberOfAliveUnits)
{
    for (int i = 0; i < everyUnit - 1; ++i)
    {
        currentUnit = findAliveUnit(list, currentUnit ->next);
    }
    if (currentUnit -> lifeStatus)
    {
        currentUnit ->lifeStatus = false;
        *numberOfAliveUnits -= 1;
        currentUnit = findAliveUnit(list, currentUnit ->next);
    }
    else
    {
        currentUnit = findAliveUnit(list, currentUnit);
        currentUnit ->lifeStatus = false;
        *numberOfAliveUnits -= 1;
        currentUnit = findAliveUnit(list, currentUnit ->next);
    }
    return currentUnit;
}

int findPosition(int unitsNumber, int everyUnit)
{
    List *list = createList();
    int aliveUnitsNumber = unitsNumber;
    for (int i = unitsNumber; i > 0; --i)
    {
        addNew(list, i);
    }
    ListElement *nextUnit = list ->first;
    while (nextUnit ->next != NULL)
    {
        nextUnit = nextUnit ->next;
    }
    nextUnit ->next = list ->first;
    ListElement *currentUnit = list ->first;
    while (aliveUnitsNumber != 1)
    {
        currentUnit = killUnit(list, everyUnit, currentUnit, &aliveUnitsNumber);
    }
    ListElement* winner = findAliveUnit(list, currentUnit);
    return winner ->number;
}

int main() {
    int numberOfUnits = 0;
    int everyUnit = 0;
    printf("Enter the number of units : ");
    scanf("%d", &numberOfUnits);
    printf("Enter the number of every killing unit : ");
    scanf("%d", &everyUnit);
    printf("The good position for you to survive is : %d", findPosition(numberOfUnits, everyUnit));
    return 0;
}