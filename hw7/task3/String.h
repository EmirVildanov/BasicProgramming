#pragma once

#include <stdbool.h>

typedef struct String String;

String *createString();

String **createStringArray(int size);

int getStringPower(String *string);

void changeStringPower(String *string, int value);

int findLength(String *string);

void deleteString(String *string);

bool compare(String *firstString, String *secondString);

bool compareChar(char firstChar, char secondChar);

char *toCharPtr(String *string); // conversion to char*

char getChar(String *string, int index);

String **split(String *string, char separator);
