#include <stdio.h>
#include <stdlib.h>
#include "String.h"

struct String
{
    int length;
    char *array;
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

bool isEmpty(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    if (string->length == 0)
    {
        return true;
    }
    return false;
}

String *createString(char *input)
{
    String *string = (String *) malloc(sizeof(String));
    if (string == NULL)
    {
        exit(1);
    }
    string->length = findCharLength(input);
    string->array = malloc((string->length + 1) * sizeof(char));//length with '\0' symbol
    if (string->array == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < string->length; ++i)
    {
        string->array[i] = input[i];
    }
    string->array[string->length] = '\0';
    return string;
}

void printString(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < string->length; ++i)
    {
        printf("%c", string->array[i]);
    }
    printf("\n");
}

int findLength(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    return string->length;
}

void deleteString(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    free(string->array);
    free(string);
}

void checkEmpty(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    if (isEmpty(string))
    {
        printf("The string is empty\n");
    }
    else
    {
        printf("The string is not empty\n");
    }
}

String *clone(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    String *newString = (String *) malloc(sizeof(String));
    if (newString == NULL)
    {
        exit(1);
    }
    int length = string->length;
    newString->length = string->length;
    newString->array = malloc((length + 1) * sizeof(char));
    if (newString->array == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < length; ++i)
    {
        newString->array[i] = string->array[i];
    }
    newString->array[length] = '\0';
    return newString;
}

void addString(String *firstString, String *secondString)
{
    if (firstString == NULL || secondString == NULL)
    {
        exit(1);
    }
    int totalLength = firstString->length + secondString->length;
    firstString->array = realloc(firstString->array, (totalLength + 1) * sizeof(char));
    for (int i = firstString->length; i < totalLength; ++i)
    {
        firstString->array[i] = secondString->array[i - firstString->length];
    }
    firstString->array[totalLength] = '\0';
    firstString->length = totalLength;
}

bool compare(String *firstString, String *secondString)
{
    if (firstString == NULL || secondString == NULL)
    {
        exit(1);
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

String *cutOut(String *string, int firstIndex, int secondIndex)
{
    if (string == NULL)
    {
        exit(1);
    }
    String *cutString = (String *) malloc(sizeof(String));
    if (cutString == NULL)
    {
        exit(1);
    }
    cutString->length = secondIndex - firstIndex + 1;
    cutString->array = malloc((cutString->length + 1) * sizeof(char));
    if (cutString->array == NULL)
    {
        exit(1);
    }
    for (int i = firstIndex; i < secondIndex + 1; ++i)
    {
        cutString->array[i - firstIndex] = string->array[i];
    }
    cutString->array[secondIndex + 1 - firstIndex] = '\0';
    return cutString;
}

char *toCharPtr(String *string)
{
    if (string == NULL)
    {
        exit(1);
    }
    char *charString = malloc((string->length + 1) * sizeof(char));
    if (charString == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < string->length; ++i)
    {
        charString[i] = string->array[i];
    }
    charString[string->length] = '\0';
    return charString;
}