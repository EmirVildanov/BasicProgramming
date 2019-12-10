#pragma once

#include <stdbool.h>

typedef struct String String;

String *createString();

bool compareChar(char firstChar, char secondChar);
int getLength(String *string);
char getChar(String *string, int index);
void deleteString(String *string);
char *toCharPtr(String *string); // conversion to char*
String** split(String* string, char separator);