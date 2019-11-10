/*
 *  Set* createSet();
 *  void addToSet(Set* set, int value);
 *  void deleteElement(Set* set, int value);
 *  void getInIncreasingOrder(Set* set, int* array, int* sizeOfArray); // collecting in the array and printing
 *  void getInDecreasingOrder(Set* set, int* array, int* sizeOfArray); // collecting in the array and printing
 *  void checkElement(Set* set, int value); // printing if your element in the set
 *  void printSet(Set* set);
 */

#include <stdio.h>
#include "Array.h"
#include "Set.h"

const int maxSize = 10;

int main() {
    Set *set = createSet();
    int *increasingArray = createIntArray(maxSize);
    int *decreasingArray = createIntArray(maxSize);
    int sizeOfArray = 0;
    addToSet(set, 2);
    addToSet(set, 3);
    addToSet(set, 9);
    addToSet(set, 5);
    addToSet(set, 8);
    addToSet(set, 4);
    //Checking deleting work properly
    checkElement(set, 8);
    deleteElement(set, 8);
    checkElement(set, 8);
    //Checking increasing output
    getInIncreasingOrder(set, increasingArray, &sizeOfArray); // collecting in the array
    //Checking decreasing output
    getInDecreasingOrder(set, decreasingArray, &sizeOfArray); // collecting in the array
    //Checking printing whole set
    printSet(set);
    return 0;
}