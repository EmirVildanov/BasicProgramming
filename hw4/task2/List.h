#pragma once

#include <stdbool.h>

struct List;
struct ListElement;

typedef struct ListElement ListElement;
typedef struct List List;

List *createList();

ListElement *createListElement();

int getListSize(List *list);

ListElement *getListFirst(List *list);

void changeListSize(List *list, int value);

int getNumberIndex(ListElement *listElement);

char *getNumber(ListElement *listElement);

char *getName(ListElement *listElement);

ListElement *getNext(ListElement *listElement);

bool isEmpty(List *);

void addNew(List *list, char *number, char *name);

char *findNumber(List *list, char name[]);

char *findName(List *list, char number[]);

char *pop(List *list);

void deleteList(List *list);
