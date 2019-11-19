#ifndef STRING_H
#define STRING_H

#include <stdbool.h>

typedef struct String String;

String* createString();
void printString(String* string);
int findLength(String* string);
void checkEmpty(String* string);
void deleteString(String* string);
String* clone(String* string);
void addString(String* firstString, String* SecondString); // concatenation
bool compare(String* firstString, String* secondString);
String* cutOut(String* string, int firstIndex, int secondIndex);
char* makeChar(String* string); // conversion to char*
char getChar(String* string, int index);
String** split(String* string, char separator, int* wordsNumber);

int getStringPower(String *string);
void changePower(String* string, int power);//for current task
bool compareChar(char firstChar, char secondChar);
#endif
