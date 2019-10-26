#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListElement* findAliveUnit(List* list, ListElement* currentUnit)
{
    while (!checkLifeStatus(currentUnit))
    {
        currentUnit = getNextElement(currentUnit);
    }
    return currentUnit;
}

ListElement* killUnit(List* list, int everyUnit, ListElement *currentUnit, int* numberOfAliveUnits)
{
    for (int i = 0; i < everyUnit - 1; ++i)
    {
        currentUnit = findAliveUnit(list, getNextElement(currentUnit));
    }
    if (checkLifeStatus(currentUnit))
    {
        changeLifeStatus(currentUnit, false);
        *numberOfAliveUnits -= 1;
    }
    else
    {
        currentUnit = findAliveUnit(list, currentUnit);
        changeLifeStatus(currentUnit, false);
        *numberOfAliveUnits -= 1;
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
    ListElement *currentUnit = getFirstListElement(list);
    while (aliveUnitsNumber != 1)
    {
        currentUnit = killUnit(list, everyUnit, currentUnit, &aliveUnitsNumber);
    }
    ListElement* winner = findAliveUnit(list, currentUnit);
    int answer = getValue(winner);
    deleteList(list);
    return answer;
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