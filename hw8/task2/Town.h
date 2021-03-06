#pragma once

typedef struct Town Town;

Town *createTown();
Town **createTownsArray(int numberOfTowns);
Town **getNewTownPair(FILE* file, Town **townsArray);
int *getCapitals(FILE *file, int capitalsNumber, Town **townsArray);
Town **redirectTowns(Town **townsArray, int townsNumber, const int *capitalsArray, int capitalsNumber);
void printTownsMap(Town **townsArray, const int *capitalsArray, int townsNumber, int capitalsNumber);
void deleteTownsArray(Town **townsArray, int townsNumber);
