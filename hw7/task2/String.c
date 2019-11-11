#include <stdio.h>
#include <stdlib.h>
#include "String.h"

struct String
{
    int length;
    char* array;
};

int findCharLength(const char* string)
{
    int length = 0;
    while (string[length] != '\0')
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
    string->array = malloc(string->length * sizeof(char));
    for (int i = 0; i < string->length; ++i)
    {
        string->array[i] = input[i];
    }
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