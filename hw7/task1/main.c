#include <stdio.h>
#include <stdlib.h>
#include "Set.h"
#include "array.h"

void entrance()
{
    printf("Hello. You have such commands to play with the set : \n");
    printf("1 - add new element to the set\n");
    printf("2 - delete element from the set\n");
    printf("3 - check if the element in the set\n");
    printf("4 - print the set\n");
    printf("5 - print the in the increasing order\n");
    printf("6 - print the in the decreasing order\n");
    printf("0 - to exit from the program\n");
}

void runCommand(Set *set, int command, int **increasingArray, int **decreasingArray)
{
    int value = 0;
    switch (command)
    {
        case 1:
        {
            printf("Enter the value tou want to add : ");
            scanf("%d", &value);
            addToSet(set, value);
            *increasingArray = expandIntArray(*increasingArray, getSetSize(set), getSetSize(set) + 1);
            *decreasingArray = expandIntArray(*decreasingArray, getSetSize(set), getSetSize(set) + 1);
            return;
        }
        case 2:
        {
            printf("Enter the element you want to delete : ");
            scanf("%d", &value);
            deleteElement(set, value);
            return;
        }
        case 3:
        {
            printf("Enter the element you want to check : ");
            scanf("%d", &value);
            checkElement(set, value);
            return;
        }
        case 4:
        {
            printSet(set);
            return;
        }
        case 5:
        {
            getInIncreasingOrder(set, *increasingArray); // collecting in the array
            return;
        }
        case 6:
        {
            getInDecreasingOrder(set, *decreasingArray); // collecting in the array
            break;
        }
        default:
        {
            return;
        }
    }
}

int main()
{
    Set *set = createSet();
    int setSize = getSetSize(set);
    int *increasingArray = createIntArray(setSize);
    int *decreasingArray = createIntArray(setSize);
    entrance();
    int input = 1;
    while (input != 0)
    {
        printf("Please, enter new command : ");
        while (scanf("%d", &input) == 0)
        {
            scanf("%*[^\n]");
            printf("Wrong input. Please enter the command : ");
        }
        runCommand(set, input, &increasingArray, &decreasingArray);
        scanf("%*[^\n]");
    }
    deleteSet(set);
    free(increasingArray);
    free(decreasingArray);;
    return 0;
}