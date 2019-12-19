#pragma once

#include "String.h"
#include "array.h"


typedef struct Hashtable Hashtable;

Hashtable *createHashTable();

void insertNewWord(Hashtable *hashtable, String *currentWord);
void printStatistics(Hashtable *hashtable);
void deleteHashtable(Hashtable *hashtable);


