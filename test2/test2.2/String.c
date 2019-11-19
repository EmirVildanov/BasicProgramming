#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "Array.h"

const int maxWordSize = 10;

struct String
{
    int length;
    int power; //for current task is a number of this word in the file
    char* array;
};

int getStringPower(String *string)//for current task
{
    return string->power;
}

void changePower(String* string, int power)//for current task
{
    string->power = power;
}

int findCharLength(const char* string)
{
    int length = 0;
    while (string[length] != '\0' && string[length] != '\n')
    {
        ++length;
    }
    return length;
}

bool isEmpty(String* string)
{
    if (string->length == 0)
    {
        return true;
    }
    return false;
}

String* createString(char* input)
{
    String *string = (String*) malloc(sizeof(String));
    string->length = findCharLength(input);
    string->power = 1;
    string->array = malloc((string->length + 1) * sizeof(char));
    for (int i = 0; i < string->length; ++i)
    {
        string->array[i] = input[i];
    }
    string->array[string->length] = '\0';
    return string;
}

void printString(String* string)
{
    for (int i = 0; i < string->length; ++i)
    {
        printf("%c", string->array[i]);
    }
    printf("\n");
}

int findLength(String* string)
{
    return string->length;
}

void deleteString(String* string)
{
    free(string);
}

void checkEmpty(String* string)
{
    if (isEmpty(string))
    {
        printf("The string is empty\n");
    }
    else
    {
        printf("The string is not empty\n");
    }
}

String* clone(String* string)
{
    String *newString = (String*) malloc(sizeof(String));
    int length = string->length;
    newString->length = string->length;
    newString->array = malloc(length * sizeof(char));
    for (int i = 0; i < length; ++i)
    {
        newString->array[i] = string->array[i];
    }
    return newString;
}

void addString(String* firstString, String* secondString)
{
    int totalLength = firstString->length + secondString->length;
    realloc(firstString->array, totalLength * sizeof(char));
    for (int i = firstString->length; i < totalLength; ++i)
    {
        firstString->array[i] = secondString->array[i - firstString->length];
    }
    firstString->length = totalLength;
}

bool compare(String* firstString, String* secondString)
{
    if (firstString == NULL || secondString == NULL)
    {
        return false;
    }
    if (firstString->length != secondString->length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < firstString->length; ++i)
        {
            if (firstString->array[i] != secondString->array[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool compareChar(char firstChar, char secondChar)
{
    if (firstChar == secondChar)
    {
        return true;
    }
    return false;
}

String* cutOut(String* string, int firstIndex, int secondIndex)
{
    String* cutString = (String*) malloc(sizeof(String));
    cutString->length = secondIndex - firstIndex + 1;
    cutString->array = malloc(cutString->length * sizeof(char));
    for (int i = firstIndex; i < secondIndex + 1; ++i)
    {
        cutString->array[i - firstIndex] = string->array[i];
    }
    return cutString;
}

char* makeChar(String* string)
{
    char* charString = malloc(string->length * sizeof(char));
    for (int i = 0; i < string->length; ++i)
    {
        charString[i] = string->array[i];
    }
    return charString;
}

char getChar(String* string, int index)
{
    return string->array[index];
}

String** split(String* string, char separator, int* wordsNumber)
{
    String **wordsArray = (String**) malloc((string->length / 2) * sizeof(String*));
    for (int i = 0; i < string->length / 2 ; ++i)
    {
        wordsArray[i] = NULL;
    }
    char *currentWord = createCharArray(maxWordSize);
    int newCharIndex = 0;
    int newElementIndex = 0;
    for (int i = 0; i < string->length; ++i)
    {
        if (compareChar(string->array[i], separator))
        {
            newCharIndex = 0;
            wordsArray[newElementIndex] = createString(currentWord);
            currentWord = createCharArray(maxWordSize);
            ++newElementIndex;
            while(string->array[i] == ' ' && i < string->length)
            {
                ++i;
            }
        }
        currentWord[newCharIndex] = string->array[i];
        ++newCharIndex;
    }
    wordsArray[newElementIndex] = createString(currentWord);
    //++newElementIndex;
    *wordsNumber = newElementIndex + 1;
    return wordsArray;
}