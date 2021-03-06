#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "array.h"

struct String
{
    int length;
    char *array;
    int power; //in case we need to calculate how many times it appeared in the hashtable
};

int findCharLength(const char *input)//length without '\0' symbol
{
    int length = 0;
    while (input[length] != '\0')
    {
        ++length;
    }
    return length;
}

String *createString(char *input)
{
    String *string = (String *) malloc(sizeof(String));
    if (string == NULL)
    {
        return NULL;
    }
    string->length = findCharLength(input);
    string->power = 1;
    string->array = malloc((string->length + 1) * sizeof(char));//length with '\0' symbol
    if (string->array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < string->length; ++i)
    {
        string->array[i] = input[i];
    }
    string->array[string->length] = '\0';
    return string;
}

String **createStringArray(int size)
{
    String **wordsArray = (String **) malloc(size * sizeof(String *));
    if (wordsArray == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; ++i)
    {
        wordsArray[i] = NULL;
    }
    return wordsArray;
}

int getStringPower(String *string)
{
    if (string == NULL)
    {
        return -1;
    }
    return string->power;
}

void changeStringPower(String *string, int value)
{
    if (string == NULL)
    {
        return;
    }
    string->power = value;
}

int findLength(String *string)
{
    if (string == NULL)
    {
        return -1;
    }
    return string->length;
}

void deleteString(String *string)
{
    if (string == NULL)
    {
        return;
    }
    free(string->array);
    free(string);
}

bool compare(String *firstString, String *secondString)
{
    if (firstString == NULL || secondString == NULL)
    {
        return false;
    }
    if (firstString->length != secondString->length)
    {
        return false;
    }
    for (int i = 0; i < firstString->length; ++i)
    {
        if (firstString->array[i] != secondString->array[i])
        {
            return false;
        }
    }
    return true;
}

bool compareChar(char firstChar, char secondChar)
{
    if (firstChar == secondChar)
    {
        return true;
    }
    return false;
}

char *toCharPtr(String *string)
{
    if (string == NULL)
    {
        return NULL;
    }
    char *charString = malloc((string->length + 1) * sizeof(char));
    if (charString == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < string->length; ++i)
    {
        charString[i] = string->array[i];
    }
    charString[string->length] = '\0';
    return charString;
}

char getChar(String *string, int index)
{
    return string->array[index];
}

String **addSplittedWord(String **wordsArray, char** currentWord, int *newCharIndex, int *newElementIndex)
{
    *currentWord = expandCharArray(*currentWord, *newCharIndex, 1);//we need it in the process of finding it's length
    (*currentWord)[*newCharIndex] = '\0';
    *newCharIndex = 0;
    wordsArray[*newElementIndex] = createString(*currentWord);
    free(*currentWord);
    *currentWord = NULL;
    ++(*newElementIndex);
    return wordsArray;
}

String** splitWords(String *string, char separator, String **wordsArray, int *newElementIndex)
{
    int newCharIndex = 0;
    char *currentWord = NULL;
    for (int i = 0; i < string->length; ++i)
    {
        if (compareChar(string->array[i], separator))
        {
            wordsArray = addSplittedWord(wordsArray, &currentWord, &newCharIndex, newElementIndex);
            while (string->array[i] == separator && i < string->length)
            {
                ++i;
            }
            if (i == string->length)
            {
                break;
            }
        }
        currentWord = expandCharArray(currentWord, newCharIndex, 1);
        currentWord[newCharIndex] = string->array[i];
        ++newCharIndex;
    }
    currentWord = expandCharArray(currentWord, newCharIndex, 1);
    currentWord[newCharIndex] = '\0';
    wordsArray[*newElementIndex] = createString(currentWord);
    free(currentWord);
    return wordsArray;
}

String **split(String *string, char separator)
{
    if (string == NULL)
    {
        return NULL;
    }
    int arrayMaxLength = (string->length + 3) / 2;// we need it to add an extra NULL element in array for future checking
    String **wordsArray = (String **) malloc( arrayMaxLength * sizeof(String *));
    if (wordsArray == NULL)
    {
        return NULL;
    }
    int newElementIndex = 0;
    wordsArray = splitWords(string, separator, wordsArray, &newElementIndex);
    for (int i = newElementIndex + 1; i < arrayMaxLength; ++i)
    {
        wordsArray[i] = NULL;
    }
    return wordsArray;
}

