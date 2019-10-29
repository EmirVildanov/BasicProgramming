#ifndef INC_4_2_LIST_H
#define INC_4_2_LIST_H

#include <stdbool.h>
struct List;
struct ListElement;

typedef struct ListElement ListElement;
typedef struct List List;

List* createList();
bool isEmpty(List*);
bool addNew(List* list, int index, char symbol);
char getValue(ListElement* listElement);
int getIndex(ListElement* listElement);
void insert(List* list, int index, char symbol);
ListElement* findByIndex(List* list, int index);
void changeElementNext(ListElement* listElement, ListElement* newNext);
ListElement* getFirstListElement(List* list);
ListElement* getNextElement(ListElement* listElement);
void printTheList(List* list);
void deleteList(List* list);
#endif
