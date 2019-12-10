#include <stdio.h>
#include <stdlib.h>
#include "Town.h"

Town **readInputData(int *townsNumber, int *capitalsNumber)
{
    int roadsNumber = 0;
    printf("Enter the number of towns: ");
    scanf("%d", townsNumber);
    Town **townsArray = createTownsArray(*townsNumber);
    printf("Enter the number of roads: ");
    scanf("%d", &roadsNumber);
    for (int i = 0; i < roadsNumber; ++i)
    {
        townsArray = getNewTownPair(townsArray);
    }
    printf("Enter the number of capitals: ");
    scanf("%d", capitalsNumber);
    return townsArray;
}

int main()
{
    int townsNumber = 0;
    int capitalsNumber = 0;
    Town **townsArray = readInputData(&townsNumber, &capitalsNumber);
    int *capitalsArray = getCapitals(capitalsNumber, townsArray);
    townsArray = redirectTowns(townsArray, townsNumber, capitalsArray, capitalsNumber);
    printTownsMap(townsArray, capitalsArray, townsNumber, capitalsNumber);
    free(capitalsArray);
    deleteTownsArray(townsArray, townsNumber);
    return 0;
}