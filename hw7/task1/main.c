/*
 *  Set* createSet();
 *  void addToSet(Set* set, int value);
 *  void deleteElement(Set* set, int value);
 *  void getInIncreasingOrder(Set* set, int* array, int* sizeOfArray); // collecting in the array and printing
 *  void getInDecreasingOrder(Set* set, int* array, int* sizeOfArray); // collecting in the array and printing
 *  void checkElement(Set* set, int value); // printing if your element in the set
 *  void printSet(Set* set);
 */

#include <stdlib.h>
#include "array.h"
#include "Set.h"


int main()
{
    Set *set = createSet();
    addToSet(set, 2);
    addToSet(set, 3);
    addToSet(set, 9);
    addToSet(set, 5);
    addToSet(set, 8);
    addToSet(set, 4);
    addToSet(set, 10);
    addToSet(set, 11);
    addToSet(set, 15);

    //Checking printing whole set
    printSet(set);

    //Checking deleting work properly
    checkElement(set, 10);
    deleteElement(set, 10);
    deleteElement(set, 8);
    checkElement(set, 10);

    int setSize = getSetSize(set);
    //Checking increasing output
    int *increasingArray = createIntArray(setSize);
    getInIncreasingOrder(set, increasingArray); // collecting in the array

    //Checking decreasing output
    int *decreasingArray = createIntArray(setSize);
    getInDecreasingOrder(set, decreasingArray); // collecting in the array

    printSet(set);

    free(increasingArray);
    free(decreasingArray);
    deleteSet(set);
    return 0;
}