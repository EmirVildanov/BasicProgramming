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
#include "String.h"


int main()
{
    String* string = createString("Check");
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
    String *addingString = createString("er");
    addString(string, addingString);
    printString(string);
    //checking Compare function
    String* checkString = createString("Checker");
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
    String* cutString = cutOut(string, 1, 4);
    printString(cutString);
    //checking Char conversion
    char* charString = makeChar(string);
    printf("The char string is : %s \n", charString);
    return 0;
}