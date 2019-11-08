#ifndef LIST_H
#define LIST_H
#define valueSize 15

#include <stdbool.h>

struct List;
struct ListElement;

typedef struct ListElement ListElement;
struct ListElement{
    int numberIndex;
    char number[valueSize];
    char name[valueSize];
    ListElement* next;
};

typedef struct List List;
struct List{
    ListElement* first;
};

List* createList();
bool isEmpty(List*);
void addNew(List* list, char number[], char name[], int numberIndex, int maxValueSize);
char* findNumber(List* list, char name[], int maxNumberSize);
char* findName(List* list, char number[], int maxNameSize);
int pop(List* list, int* numberIndex);
void deleteList(List* list);
#endif