#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "Hashtable.h"
#include "String.h"

//every time you createString from char you have to free it then

const int firstBucketsNumber = 20;
const int hashPrimeNumber = 3;

struct Hashtable
{
    String **bucketsArray;
    float loadFactor;
    int size;
    int wordsNumber;
    int *attemptsArray; //for statistics
    int attemptsArraySize;
    int expansionNumber; //how many times we reallocated our array
};

String **initializeBucketsArray(Hashtable *hashtable, int startIndex, int endIndex)
{
    if (hashtable == NULL)
    {
        return NULL;
    }
    for (int i = startIndex; i < endIndex; ++i)
    {
        hashtable->bucketsArray[i] = createString("Empty");
    }
    return hashtable->bucketsArray;
}

Hashtable *createHashTable()
{
    Hashtable *hashtable = (Hashtable *) malloc(sizeof(Hashtable));
    if (hashtable == NULL)
    {
        return NULL;
    }
    hashtable->loadFactor = 0;
    hashtable->wordsNumber = 0;
    hashtable->size = firstBucketsNumber;
    hashtable->attemptsArraySize = 0;
    hashtable->expansionNumber = 0;
    hashtable->attemptsArray = NULL;
    hashtable->bucketsArray = malloc(firstBucketsNumber * sizeof(String *));;
    initializeBucketsArray(hashtable, 0, hashtable->size);
    return hashtable;
}

int hashFunction(Hashtable *hashtable, String *string)
{
    if (hashtable == NULL)
    {
        return -1;
    }
    int numberPower = 1;
    int hashNumber = 0;
    int stringLength = findLength(string);
    for (int i = 0; i < stringLength; ++i)
    {
        hashNumber += (getChar(string, i) - 'a' + 1) * numberPower;
        numberPower *= hashPrimeNumber;
    }
    return abs(hashNumber % hashtable->size); //abs because in case of big words it will return negative answer
}

bool isEmptyBucket(String *currentString)
{
    if (currentString == NULL)
    {
        return true;
    }
    String *check = createString("Empty");
    if (compare(currentString, check))
    {
        deleteString(check);
        return true;
    }
    deleteString(check);
    return false;
}

Hashtable *redefineHashValues(Hashtable *hashtable, int previousSize)
{
    if (hashtable == NULL)
    {
        return NULL;
    }
    String **wordsArray = createStringArray(hashtable->wordsNumber);
    int arrayIndex = 0;
    int hashValue = 0;
    for (int i = 0; i < previousSize; ++i)
    {
        String *currentString = hashtable->bucketsArray[i];
        if (!isEmptyBucket(currentString))
        {
            hashtable->bucketsArray[i] = createString("Empty");
            wordsArray[arrayIndex] = currentString;
            ++arrayIndex;
        }
    }
    for (int i = 0; i < hashtable->wordsNumber; ++i)
    {
        String *currentWord = wordsArray[i];
        hashValue = hashFunction(hashtable, currentWord);
        int attemptsNumber = 1;
        bool insertCheck = false;
        while (!insertCheck)
        {
            while (hashValue + attemptsNumber < hashtable->size)
            {
                if (isEmptyBucket(hashtable->bucketsArray[hashValue + attemptsNumber]))
                {
                    deleteString(hashtable->bucketsArray[hashValue + attemptsNumber]);
                    hashtable->bucketsArray[hashValue + attemptsNumber] = currentWord;
                    insertCheck = true;
                    break;
                }
                ++attemptsNumber;
                hashValue = hashValue + attemptsNumber * attemptsNumber;
            }
            hashValue = hashValue % hashtable->size;
            attemptsNumber = 0;
        }
    }
    free(wordsArray);
    return hashtable;
}

String **extendBucketsArray(Hashtable *hashtable)
{
    if (hashtable == NULL)
    {
        return NULL;
    }
    int newLength = firstBucketsNumber * (hashtable->expansionNumber + 2);
    hashtable->bucketsArray = realloc(hashtable->bucketsArray, newLength * sizeof(String *));
    int rememberSize = hashtable->size;
    hashtable->size = newLength;
    initializeBucketsArray(hashtable, rememberSize, hashtable->size);
    ++hashtable->expansionNumber;
    hashtable->loadFactor = (float) hashtable->wordsNumber / (float) hashtable->size;
    return hashtable->bucketsArray;
}

Hashtable *startInsertProcess(Hashtable *hashtable, String* currentWord)
{
    if (hashtable == NULL)
    {
        return NULL;
    }
    int hashIndex = hashFunction(hashtable, currentWord);
    int attemptsNumber = 1;
    int rememberAttemptsNumber = 1;
    bool insertCheck = false;
    while (!insertCheck)
    {
        while (hashIndex + attemptsNumber < hashtable->size)
        {
            if (compare(hashtable->bucketsArray[hashIndex + attemptsNumber], currentWord))
            {
                changeStringPower(hashtable->bucketsArray[hashIndex + attemptsNumber],
                                  getStringPower(hashtable->bucketsArray[hashIndex + attemptsNumber]) + 1);
                hashtable->attemptsArray[hashtable->attemptsArraySize - 1] = rememberAttemptsNumber;
                insertCheck = true;
                deleteString(currentWord);
                break;
            }
            else if (isEmptyBucket(hashtable->bucketsArray[hashIndex + attemptsNumber]))
            {
                deleteString(hashtable->bucketsArray[hashIndex + attemptsNumber]);
                hashtable->bucketsArray[hashIndex + attemptsNumber] = currentWord;
                hashtable->attemptsArray[hashtable->attemptsArraySize - 1] = rememberAttemptsNumber;
                ++hashtable->wordsNumber;
                insertCheck = true;
                break;
            }
            ++attemptsNumber;
            hashIndex = hashIndex + attemptsNumber * attemptsNumber;
        }
        hashIndex = hashIndex % hashtable->size;
        rememberAttemptsNumber += attemptsNumber;
        attemptsNumber = 0;
    }
    return hashtable;
}

void insertNewWord(Hashtable *hashtable, String *currentWord)
{
    if (hashtable == NULL)
    {
        return;
    }
    while (hashtable->loadFactor >= 0.7)
    {
        int rememberSize = hashtable->size;
        hashtable->bucketsArray = extendBucketsArray(hashtable);
        hashtable = redefineHashValues(hashtable, rememberSize);
    }
    hashtable->attemptsArray = realloc(hashtable->attemptsArray, (hashtable->attemptsArraySize + 1) * sizeof(int));
    hashtable->attemptsArray[hashtable->attemptsArraySize] = 0;
    ++hashtable->attemptsArraySize;
    hashtable = startInsertProcess(hashtable, currentWord);
    hashtable->loadFactor = (float) hashtable->wordsNumber / (float) hashtable->size;
}

void deleteHashtable(Hashtable *hashtable)
{
    if (hashtable == NULL)
    {
        return;
    }
    for (int i = 0; i < hashtable->size; ++i)
    {
        deleteString(hashtable->bucketsArray[i]);
    }
    free(hashtable->bucketsArray);
    free(hashtable->attemptsArray);
    free(hashtable);
}

//functions to print statistics

int findMaxAttemptsNumber(Hashtable *hashtable)
{
    if (hashtable == NULL)
    {
        return -1;
    }
    int maxNumber = 0;
    for (int i = 0; i < hashtable->attemptsArraySize; ++i)
    {
        if (hashtable->attemptsArray[i] > maxNumber)
        {
            maxNumber = hashtable->attemptsArray[i];
        }
    }
    return maxNumber;
}

float findAverageAttemptsNumber(Hashtable *hashtable)
{
    if (hashtable == NULL)
    {
        return -1;
    }
    float averageNumber = 0;
    int sum = 0;
    for (int i = 0; i < hashtable->attemptsArraySize; ++i)
    {
        sum += hashtable->attemptsArray[i];
    }
    averageNumber = (float) sum / (float) hashtable->attemptsArraySize;
    return averageNumber;
}

void printHashtableWords(Hashtable *hashtable)
{
    if (hashtable == NULL)
    {
        return;
    }
    for (int i = 0; i < hashtable->size; ++i)
    {
        if (!isEmptyBucket(hashtable->bucketsArray[i]))
        {
            char *charWord = toCharPtr(hashtable->bucketsArray[i]);
            printf("%s -> %d\n", charWord, getStringPower(hashtable->bucketsArray[i]));
            free(charWord);
        }
    }
}

void printStatistics(Hashtable *hashtable)
{
    printf("Load factor is : %f \n", hashtable->loadFactor);
    printf("The number of extensions is : %d \n", hashtable->expansionNumber);
    printf("The max number of searching attempts is : %d \n", findMaxAttemptsNumber(hashtable));
    printf("The average number of searching attempts is : %f \n", findAverageAttemptsNumber(hashtable));
    printIntArray(hashtable->attemptsArray, hashtable->attemptsArraySize);
    printf("The number of added words is : %d \n", hashtable->wordsNumber);
    printf("The number of empty buckets is : %d \n", hashtable->size - hashtable->wordsNumber);
    printHashtableWords(hashtable);
    printf("\n");
}

