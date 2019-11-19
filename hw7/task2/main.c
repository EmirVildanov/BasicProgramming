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
#include "Array.h"

const int maxSize = 100;

int main()
{
    char* charString = createCharArray(maxSize);
    printf("Enter your string (for better example please enter 'Check') : ");
    scanf("%s", charString);
    String* string = createString(charString);
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
    char* charAddingString = "er";
    String *addingString = createString(charAddingString);
    addString(string, addingString);
    printString(string);
    //checking Compare function
    char * charCheckString = "Checker";
    String* checkString = createString(charCheckString);
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
    charString = makeChar(string);
    printf("The char string is : %s \n", charString);
    return 0;
}