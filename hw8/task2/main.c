#include <stdio.h>
#include <stdlib.h>
#include "Town.h"

Town **readInputData(FILE *file, int *townsNumber, int *capitalsNumber)
{
    int roadsNumber = 0;
    fscanf(file,"%d", townsNumber);
    Town **townsArray = createTownsArray(*townsNumber);
    fscanf(file,"%d", &roadsNumber);
    for (int i = 0; i < roadsNumber; ++i)
    {
        townsArray = getNewTownPair(file, townsArray);
    }
    fscanf(file,"%d", capitalsNumber);
    return townsArray;
}

int main()
{
    FILE *file = fopen("Towns", "r");
    if (file == NULL)
    {
        return 1;
    }
    int townsNumber = 0;
    int capitalsNumber = 0;
    Town **townsArray = readInputData(file, &townsNumber, &capitalsNumber);
    int *capitalsArray = getCapitals(file, capitalsNumber, townsArray);
    townsArray = redirectTowns(townsArray, townsNumber, capitalsArray, capitalsNumber);
    printTownsMap(townsArray, capitalsArray, townsNumber, capitalsNumber);
    free(capitalsArray);
    deleteTownsArray(townsArray, townsNumber);
    fclose(file);
    return 0;
}