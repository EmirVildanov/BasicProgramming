#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "Town.h"

struct Town
{
    int number;
    bool freeStatus;
    int **neighbors;
    int capitalNumber;
    int neighborsNumber;

    int distanceFromCapital;
    bool capitalConnectionStatus;
};

Town *createTown()
{
    Town *newTown = (Town *) malloc(sizeof(Town));
    if (newTown == NULL)
    {
        return NULL;
    }
    newTown->number = 0;
    newTown->freeStatus = true;
    newTown->neighbors = NULL; //first - town, second - roadLength
    newTown->neighborsNumber = 0;
    newTown->capitalNumber = 0;

    newTown->distanceFromCapital = -1; //instead of infinite value
    newTown->capitalConnectionStatus = false;//if it's false it wasn't processed

    return newTown;
}

Town **createTownsArray(int numberOfTowns)
{
    Town **townsArray = (Town **) malloc(numberOfTowns * sizeof(Town *));
    if (townsArray == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < numberOfTowns; ++i)
    {
        townsArray[i] = createTown();
        townsArray[i]->number = i + 1;
    }
    return townsArray;
}

void updateNeighbors(Town *firstTown, Town *secondTown, int roadLength)
{
    firstTown->neighbors = realloc(firstTown->neighbors, (firstTown->neighborsNumber + 1) * sizeof(int *));
    firstTown->neighbors[firstTown->neighborsNumber] = malloc(2 * sizeof(int));
    firstTown->neighbors[firstTown->neighborsNumber][0] = secondTown->number;
    firstTown->neighbors[firstTown->neighborsNumber][1] = roadLength;
    ++firstTown->neighborsNumber;

    secondTown->neighbors = realloc(secondTown->neighbors, (secondTown->neighborsNumber + 1) * sizeof(int *));
    secondTown->neighbors[secondTown->neighborsNumber] = malloc(2 * sizeof(int));
    secondTown->neighbors[secondTown->neighborsNumber][0] = firstTown->number;
    secondTown->neighbors[secondTown->neighborsNumber][1] = roadLength;
    ++secondTown->neighborsNumber;
}

Town **addNewTownsPair(Town **townsArray, int firstTownNumber, int secondTownNumber, int roadLength)
{
    if (townsArray == NULL)
    {
        return NULL;
    }
    Town *firstTown = townsArray[firstTownNumber - 1];
    Town *secondTown = townsArray[secondTownNumber - 1];
    updateNeighbors(firstTown, secondTown, roadLength);
    return townsArray;
}

Town **getNewTownPair(FILE *file, Town **townsArray)
{
    if (townsArray == NULL)
    {
        return NULL;
    }
    int firstTownNumber = 0;
    int secondTownNumber = 0;
    int lengthOfTheRoad = 0;
    fscanf(file, "%d %d %d", &firstTownNumber, &secondTownNumber, &lengthOfTheRoad);
    townsArray = addNewTownsPair(townsArray, firstTownNumber, secondTownNumber, lengthOfTheRoad);
    return townsArray;
}

int *getCapitals(FILE *file, int capitalsNumber, Town **townsArray)
{
    int *capitalsArray = createIntArray(capitalsNumber);
    int currentCapitalNumber = 0;
    for (int i = 0; i < capitalsNumber; ++i)
    {
        fscanf(file, "%d", &currentCapitalNumber);
        capitalsArray[i] = currentCapitalNumber;
        townsArray[currentCapitalNumber - 1]->freeStatus = false;
        townsArray[currentCapitalNumber - 1]->distanceFromCapital = 0;
        townsArray[currentCapitalNumber - 1]->capitalNumber = currentCapitalNumber;
    }
    return capitalsArray;
}

Town **redefineDijkstraValues(Town **townsArray, int townsNumber)
{
    for (int i = 0; i < townsNumber; ++i)
    {
        townsArray[i]->distanceFromCapital = -1;
        townsArray[i]->capitalConnectionStatus = false;
    }
    return townsArray;
}

bool checkNeighborsDijkstraStatus(Town **townsArray, Town *currentTown)
{
    for (int i = 0; i < currentTown->neighborsNumber; ++i)
    {
        Town *currentNeighbor = townsArray[currentTown->neighbors[i][0] - 1];
        if (!currentNeighbor->capitalConnectionStatus)
        {
            return true;
        }
    }
    return false;
}

int findDistanceToUnmarkedNeighbor(Town **townsArray, Town *currentTown, int currentCapitalNumber)
{
    for (int i = 0; i < currentTown->neighborsNumber; ++i)
    {
        Town *currentNeighbor = townsArray[currentTown->neighbors[i][0] - 1];
        if ((currentNeighbor->capitalNumber == 0 || currentNeighbor->capitalNumber == currentCapitalNumber) &&
            !currentNeighbor->capitalConnectionStatus)
        {
            return currentTown->neighbors[i][1];
        }
    }
    return 0;
}

void redefineTownToConquer(Town *currentTown, Town **townToConquer)
{
    if (currentTown->freeStatus && (*townToConquer) == NULL)//if the previous town was a capital
    {
        (*townToConquer) = currentTown;
    }
    else if (currentTown->freeStatus && currentTown->distanceFromCapital < (*townToConquer)->distanceFromCapital)
    {
        *townToConquer = currentTown;
    }
}

void changeDijkstraValue(Town *currentTown, int index, Town *currentNeighbor, int *bestDistance, Town **nearestTown)
{
    int currentDistance = currentTown->neighbors[index][1];
    if (currentNeighbor->distanceFromCapital == -1)
    {
        currentNeighbor->distanceFromCapital = currentTown->distanceFromCapital + currentDistance;
        if (currentDistance <= *bestDistance)
        {
            *nearestTown = currentNeighbor;
            *bestDistance = currentDistance;
        }
    }
    else if (currentTown->distanceFromCapital + currentDistance <= currentNeighbor->distanceFromCapital)
    {
        currentNeighbor->distanceFromCapital = currentTown->distanceFromCapital + currentDistance;
        if (currentDistance <= *bestDistance)
        {
            *nearestTown = currentNeighbor;
            *bestDistance = currentDistance;
        }
    }
    else
    {
        currentNeighbor->capitalConnectionStatus = true;
    }
}

void startDijkstraProcess(Town **townsArray, int townsNumber, Town *currentTown, Town **townToConquer, int currentCapitalNumber)
{
    if (currentTown == NULL)
    {
        return;
    }
    currentTown->capitalConnectionStatus = true;
    redefineTownToConquer(currentTown, townToConquer);
    while (checkNeighborsDijkstraStatus(townsArray, currentTown))
    {
        int bestDistance = findDistanceToUnmarkedNeighbor(townsArray, currentTown, currentCapitalNumber);
        Town *nearestTown = NULL;
        for (int i = 0; i < currentTown->neighborsNumber; ++i)
        {
            Town *currentNeighbor = townsArray[currentTown->neighbors[i][0] - 1];
            if (currentNeighbor->capitalConnectionStatus)
            {
                continue;
            }
            else if (currentNeighbor->capitalNumber != 0 && currentNeighbor->capitalNumber != currentCapitalNumber)//if it belongs to another capital
            {
                currentNeighbor->capitalConnectionStatus = true;
                continue;
            }
            changeDijkstraValue(currentTown, i, currentNeighbor, &bestDistance, &nearestTown);//also try to find nearest neighbor
        }
        startDijkstraProcess(townsArray, townsNumber, nearestTown, townToConquer, currentCapitalNumber);
    }
}

Town **redirectTowns(Town **townsArray, int townsNumber, const int *capitalsArray, int capitalsNumber)
{
    int numberOfFreeTowns = townsNumber - capitalsNumber;
    int currentCapitalIndex = 0;
    while (numberOfFreeTowns != 0)
    {
        Town *townToConquer = NULL;
        currentCapitalIndex = currentCapitalIndex % capitalsNumber;
        Town *currentCapital = townsArray[capitalsArray[currentCapitalIndex] - 1];
        startDijkstraProcess(townsArray, townsNumber, currentCapital, &townToConquer, currentCapital->number);
        townsArray = redefineDijkstraValues(townsArray, townsNumber);
        if (townToConquer == NULL)
        {
            ++currentCapitalIndex;
            continue;
        }
        townToConquer->freeStatus = false;
        townToConquer->capitalNumber = currentCapital->number;
        ++currentCapitalIndex;
        --numberOfFreeTowns;
    }
    return townsArray;
}

void printTownsMap(Town **townsArray, const int *capitalsArray, int townsNumber, int capitalsNumber)
{
    if (townsArray == NULL)
    {
        return;
    }
    for (int i = 0; i < capitalsNumber; ++i)
    {
        Town *currentCapital = townsArray[capitalsArray[i] - 1];
        printf("Country number %d consists of following towns : ", currentCapital->number);
        fflush(stdout);
        for (int j = 0; j < townsNumber; ++j)
        {
            if (townsArray[j]->capitalNumber == currentCapital->number)
            {
                printf("%d ", townsArray[j]->number);
            }
        }
        printf("\n");
    }
}

void deleteTownsArray(Town **townsArray, int townsNumber)
{
    for (int i = 0; i < townsNumber; ++i)
    {
        Town *currentTown = townsArray[i];
        for (int j = 0; j < currentTown->neighborsNumber; ++j)
        {
            free(currentTown->neighbors[j]);
        }
        free(currentTown->neighbors);
        free(currentTown);
    }
    free(townsArray);
}