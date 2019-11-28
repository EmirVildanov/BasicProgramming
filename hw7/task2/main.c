/*
 * (The length of your string is infinite)
 * createString();
 * deleteString(String* string);
 * clone(String* string);
 * addString(String* firstString, String* SecondString); // concatenation
 * compare(String* firstString, String* SecondString);
 * findLength(String* string);
 * checkEmpty(String* string);
 * cutOut(String* string, int firstIndex, int secondIndex);
 * makeChar(String* string); // conversion to char*
 */

#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "array.h"

char *getInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        exit(1);
    }
    else
    {
        int lastSymbolIndex = 0;
        int bufferIndex = 0;
        while (true)
        {
            while (bufferIndex < expandValue - 1)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[bufferIndex] == '\n')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[bufferIndex];
                ++lastSymbolIndex;
                ++bufferIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            bufferIndex = 0;
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

int main()
{
    printf("Enter your string (for better example please enter 'Check') : ");
    char *charString = getInput();
    String *string = createString(charString);
    //checking Length function
    printf("The length of your string is : %d \n", findLength(string));
    //checking isEmpty function
    String *emptyString = createString("");
    checkEmpty(emptyString);
    checkEmpty(string);
    //checking Clone function
    String *cloneString = clone(string);
    printString(string);
    //checking Adding function
    char *charAddingString = "er";
    String *addingString = createString(charAddingString);
    addString(string, addingString);
    printString(string);
    //checking Compare function
    char *charCheckString = "Checker";
    String *checkString = createString(charCheckString);
    if (compare(string, checkString))
    {
        printf("Equal strings\n");
    }
    else
    {
        printf("Unequal strings\n");
    }
    if (compare(string, cloneString))
    {
        printf("Equal strings\n");
    }
    else
    {
        printf("Unequal strings\n");
    }
    //checking Cutting out function
    String *cutString = cutOut(string, 1, 4);
    printString(cutString);
    //checking Char conversion
    char *checkCharConvert = toCharPtr(string);
    printf("The char string is : %s \n", checkCharConvert);

    free(charString);
    free(checkCharConvert);
    deleteString(string);
    deleteString(emptyString);
    deleteString(cloneString);
    deleteString(addingString);
    deleteString(checkString);
    deleteString(cutString);
    return 0;
}