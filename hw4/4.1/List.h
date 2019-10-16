#ifndef INC_4_2_LIST_H
#define INC_4_2_LIST_H

#include <stdbool.h>
struct List;
struct ListElement;

typedef struct ListElement ListElement;
struct ListElement{
    int number;
    bool lifeStatus;
    ListElement* next;
};

typedef struct List List;
struct List{
    ListElement* first;
};

List* createList();
bool isEmpty(List*);
bool addNew(List* list, int number);

#endif