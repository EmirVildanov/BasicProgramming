#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Array.h"
#include "String.h"

const int maxLineSize = 100;
const int dateSize = 10;
const int dateParametersNumber = 3;
const int maxDatesNumber = 100;

bool checkDate(String* string)
{
    if (findLength(string) != dateSize)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < dateSize; ++i)
        {
            if ((i != 2 && i != 5) && ('0' > getChar(string, i) || getChar(string, i) > '9'))
            {
                printf("False1 \n");
                return false;
            }
            if ((i == 2 || i == 5) && getChar(string, i) != '.')
            {
                printf("False2 \n");
                return false;
            }
        }
    }
    return true;
}

int* findDatePower(String* date)
{
    int power = 0;
    int* powerArray = malloc(dateParametersNumber * sizeof(int));
    String* day = cutOut(date, 0, 2);
    String* month = cutOut(date, 3, 5);
    String* year = cutOut(date, 6, 10);
    int intDay = atoi(makeChar(day));
    int intMonth = atoi(makeChar(month));
    int intYear = atoi(makeChar(year));
    powerArray[0] = intDay;
    powerArray[1] = intMonth;
    powerArray[2] = intYear;
    return powerArray;
}

String* findGreaterDate(String* firstDate, String* secondDate)
{
    int *firstPower = findDatePower(firstDate);
    int *secondPower = findDatePower(secondDate);
    if (firstPower[2] > secondPower[2])
    {
        return firstDate;
    }
    else if (firstPower[2] < secondPower[2])
    {
        return secondDate;
    }
    else
    {
        if (firstPower[1] > secondPower[1])
        {
            return firstDate;
        }
        else if (firstPower[1] < secondPower[1])
        {
            return secondDate;
        }
        else
        {
            if (firstPower[0] > secondPower[0])
            {
                return firstDate;
            }
            else
            {
                return secondDate;
            }
        }
    }
}

String* findGreatestDate(String** datesArray, int datesNumber)
{
    printf("The dates number is : %d \n", datesNumber);
    String* result = createString("00.00.00");
    for (int i = 0; i < datesNumber; ++i)
    {
        result = findGreaterDate(result, datesArray[i]);
    }
    return result;
}

int main() {
    FILE *file = fopen("test", "rt");
    char *newline = createCharArray(maxLineSize); //for lines of the file
    int lineWordsNumber = 0;
    String **datesArray = malloc(maxDatesNumber * sizeof(String*));
    int datesNumber = 0;
    if (file == NULL)//Checking file was read correctly
    {
        printf("\nPlease put your file in the build-debug directory");
        exit(1);
    }
    else
    {
        while (!feof(file)) //while not empty
        {
            if (fgets(newline, maxLineSize, file) != NULL)//new line
            {
                String *currentLine = createString(newline);
                String **wordsArray = split(currentLine, ' ', &lineWordsNumber);
                for (int i = 0; i < lineWordsNumber; ++i)
                {
                    String *currentWord = wordsArray[i];
                    if (checkDate(currentWord))
                    {
                        datesArray[datesNumber] = currentWord;
                        ++datesNumber;
                    }
                }
            }
        }
    }
    fclose(file);
    String *maxDate = findGreatestDate(datesArray, datesNumber);
    printf("The greatest date is : ");
    printString(maxDate);
    return 0;
}