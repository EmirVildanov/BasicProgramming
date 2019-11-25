#pragma once

#include <stdbool.h>

struct List;
struct ListElement;

typedef struct ListElement ListElement;
struct ListElement
{
    int numberIndex;
    char *number;
    char *name;
    ListElement* next;
};

typedef struct List List;
struct List
{
    ListElement* first;
    int size;
};

List* createList();
ListElement* createListElement();
bool isEmpty(List*);
void addNew(List* list, char* number, char* name);
char* findNumber(List* list, char name[]);
char* findName(List* list, char number[]);
char* pop(List* list);
void deleteList(List* list);
