#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "String.h"
#include "Array.h"

const int maxLineSize = 100;
const int firstBucketsNumber = 20;
const int hashPrimeNumber = 3;

void initializeArray(String **array, int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex; ++i)
    {
        array[i] = createString("Empty");
    }
}

int hashFunction(String* string, int currentLength)
{
    int numberPower = 1;
    int hashNumber = 0;
    int stringLength = findLength(string);
    for (int i = 0; i < stringLength; ++i)
    {
        hashNumber += (getChar(string, i) - 'a' + 1) * numberPower;
        numberPower *= hashPrimeNumber;
    }
    return abs(hashNumber % currentLength); //abs because in case of big words it will return negative answer
}

bool newWordInsert(String** array, int length, int hashIndex, String* string, int* attemptsArray, int* attemptsArraySize, int* wordsInArrayNumber)
{
    int attemptsNumbers = 0;
    while (hashIndex + attemptsNumbers < length - 1)
    {
        if (compare(array[hashIndex + attemptsNumbers], string))
        {
            changePower(array[hashIndex + attemptsNumbers], getStringPower(array[hashIndex + attemptsNumbers]) + 1);
            attemptsArray[*attemptsArraySize] = attemptsNumbers;
            ++*attemptsArraySize;
            return true;
        }
        else if (compare(array[hashIndex + attemptsNumbers], createString("Empty")))
        {
            array[hashIndex + attemptsNumbers] = string;
            attemptsArray[*attemptsArraySize] = attemptsNumbers;
            ++*attemptsArraySize;
            ++*wordsInArrayNumber;
            return true;
        }
        ++attemptsNumbers;
        hashIndex = hashIndex + attemptsNumbers * attemptsNumbers;
    }
    return false;
}

//print function1
int findMaxAttemptsNumber(int* array, int length)
{
    int maxNumber = 0;
    for (int i = 0; i < length; ++i)
    {
        if (array[i] > maxNumber)
        {
            maxNumber = array[i];
        }
    }
    return maxNumber;
}
//print function2
float findAverageAttemptsNumber(int* array, int length)
{
    float averageNumber = 0;
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
    }
    averageNumber = (float) sum / (float) length;
    return averageNumber;
}

String** extendStringArray(String** array, int expansionPower, int* currentLength)
{
    int newLength = firstBucketsNumber * (expansionPower + 2);
    array = realloc(array, newLength * sizeof(String*));
    *currentLength = newLength;
    return array;
}

int* extendIntArray(int* array, int expansionPower)
{
    array = realloc(array, firstBucketsNumber * (expansionPower + 2) * sizeof(int));
    return array;
}

int main()
{
    FILE *file = fopen("Test", "rt");
    char *newline = createCharArray(maxLineSize); //for lines of the file
    String **array = (String**) malloc(firstBucketsNumber * sizeof(String*)); //for buckets
    initializeArray(array, 0, firstBucketsNumber);
    int *attemptsArray = malloc(firstBucketsNumber * sizeof(int));//for statistics
    int attemptsArrayLength = 0;
    int currentLength = firstBucketsNumber;
    float loadFactor = 0;
    int wordsInArrayNumber = 0;
    int expansionNumber = 0; //how many times we realloced our array
    int hashIndex = 0;
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
                String* string = createString(newline);
                int wordsNumber = 0;
                String **lineWords = split(string, ' ', &wordsNumber);//splitted for words
                for (int i = 0; i < wordsNumber; ++i)//adding new word into array
                {
                    String *currentWord = lineWords[i];
                    hashIndex = hashFunction(currentWord, currentLength);
                    if (!newWordInsert(array, currentLength, hashIndex, currentWord, attemptsArray, &attemptsArrayLength, &wordsInArrayNumber))//if can't insert
                    {
                        array = extendStringArray(array, expansionNumber, &currentLength);
                        attemptsArray = extendIntArray(attemptsArray, expansionNumber);
                        ++expansionNumber;
                        initializeArray(array, firstBucketsNumber * expansionNumber, currentLength);
                        newWordInsert(array, currentLength, hashIndex, currentWord, attemptsArray, &attemptsArrayLength, &wordsInArrayNumber);
                    }
                    loadFactor = (float) wordsInArrayNumber / currentLength;
                    if (loadFactor >= 0.7) //extension
                    {
                        array = extendStringArray(array, expansionNumber, &currentLength);
                        attemptsArray = extendIntArray(attemptsArray, expansionNumber);
                        ++expansionNumber;
                        initializeArray(array, firstBucketsNumber * expansionNumber, currentLength);
                    }
                }
            }
        }
    }
    printf("Load factor is : %f \n", loadFactor);
    printf("The number of extensions is : %d \n", expansionNumber);
    printf("The max number of searching attempts is : %d \n", findMaxAttemptsNumber(attemptsArray, currentLength));
    printf("The average number of searching attempts is : %f \n", findAverageAttemptsNumber(attemptsArray, currentLength));
    printf("The number of added words is : %d \n", wordsInArrayNumber);
    printf("The number of empty buckets is : %d \n", currentLength - wordsInArrayNumber);
    printIntArray(attemptsArray, attemptsArrayLength);
    printf("\n");
    for (int i = 0; i < currentLength; ++i)
    {
        if (!compare(array[i], createString("Empty")))
        {
            printf("%s -> %d \n", makeChar(array[i]), getStringPower(array[i]));
        }
    }
    free(newline);
    for (int i = 0; i < currentLength; ++i)
    {
        free(array[i]);
    }
    free(array);
    free(attemptsArray);
    fclose(file);
    return 0;
}