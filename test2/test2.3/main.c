#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "String.h"

const int maxLineSize = 100;
const int maxArraySize = 100;

void writeToFile(int firstNumber, int secondNumber, FILE* firstFile, FILE* secondFile)
{
    char *newline = createCharArray(maxLineSize); //for lines of the file
    int *firstArray = createIntArray(maxArraySize);
    int firstArrayIndex = 0;
    int *secondArray = createIntArray(maxArraySize);
    int secondArrayIndex = 0;
    int *thirdArray = createIntArray(maxArraySize);
    int thirdArrayIndex = 0;
    while (!feof(firstFile)) //while not empty
    {
        if (fgets(newline, maxLineSize, firstFile) != NULL)//new line
        {
            String *currentString = createString(newline);
            int wordsNumber = 0;
            String **numbersArray = split(currentString, ' ', &wordsNumber);
            for (int i = 0; i < wordsNumber; ++i)
            {
                if (atoi(makeChar(numbersArray[i])) < firstNumber)
                {
                    firstArray[firstArrayIndex] = atoi(makeChar(numbersArray[i]));
                    ++firstArrayIndex;
                }
                else if (atoi(makeChar(numbersArray[i])) >= firstNumber && atoi(makeChar(numbersArray[i]))  <= secondNumber)
                {
                    secondArray[secondArrayIndex] = atoi(makeChar(numbersArray[i]));
                    ++secondArrayIndex;
                }
                else {
                    thirdArray[thirdArrayIndex] = atoi(makeChar(numbersArray[i]));
                    ++thirdArrayIndex;
                }
            }
        }
    }
    for (int i = 0; i < firstArrayIndex; ++i)
    {
        fprintf(secondFile, "%d \n", firstArray[i]);
    }
    for (int i = 0; i < secondArrayIndex; ++i)
    {
        fprintf(secondFile, "%d \n", secondArray[i]);
    }
    for (int i = 0; i < thirdArrayIndex; ++i)
    {
        fprintf(secondFile, "%d \n", thirdArray[i]);
    }
}

int main() {
    FILE *firstFile = fopen("read", "rt");
    FILE *secondFile = fopen("write", "a+");
    int firstNumber = 0;
    int secondNumber = 0;
    printf("Enter first number : ");
    scanf("%d", &firstNumber);
    printf("Enter second number : ");
    scanf("%d", &secondNumber);
    writeToFile(firstNumber, secondNumber, firstFile, secondFile);
    fclose(firstFile);
    fclose(secondFile);
    return 0;
}