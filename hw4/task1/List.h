#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
struct List;
struct ListElement;

typedef struct ListElement ListElement;
typedef struct List List;

List* createList();
bool isEmpty(List*);
bool addNew(List* list, int number);
bool checkLifeStatus(ListElement* listElement);
int getValue(ListElement* listElement);
void changeLifeStatus(ListElement* listElement, bool status);
void changeElementNext(ListElement* listElement, ListElement* newNext);
ListElement* getFirstListElement(List* list);
ListElement* getNextElement(ListElement* listElement);
void deleteList(List* list);

#endif