#include <stdio.h>
#include <stdbool.h>
#include "array.h"

const int columnsNumber = 2;

int **getInput(int *stringsNumber)
{
    int **inputArray = createDoubleArray(0, columnsNumber);
    int input = 0;
    bool findChecking = false;
    printf("Enter new number : ");
    scanf("%d", &input);
    while (input != 0)
    {
        for (int i = 0; i < *stringsNumber; ++i)
        {
            if (inputArray[i][0] == input)
            {
                inputArray[i][1] += 1;
                findChecking = true;
            }
        }
        if (!findChecking)
        {
            inputArray = extendDoubleArray(inputArray, *stringsNumber, columnsNumber, 1);
            inputArray[*stringsNumber][0] = input;
            inputArray[*stringsNumber][1] += 1;
            *stringsNumber += 1;
        }
        findChecking = false;
        printf("Enter new number : ");
        scanf("%d", &input);
    }
    return inputArray;
}

int main()
{
    int stringsNumber = 0;
    int **inputArray = getInput(&stringsNumber);
    inputArray = sortDoubleArray(inputArray, stringsNumber, columnsNumber);
    printf("Your array is (number frequency):\n");
    printDoubleArray(inputArray, stringsNumber, columnsNumber);
    deleteDoubleArray(inputArray, stringsNumber);
    return 0;
}