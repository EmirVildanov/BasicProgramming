#ifndef H_CONST
#define H_CONST



#endif


#ifndef INC_4_2_LIST_H
#define INC_4_2_LIST_H

#include <stdbool.h>

struct List;
struct ListElement;

typedef struct ListElement ListElement;
struct ListElement{
    int numberIndex;
    char number[15];
    char name[15];
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
int findNameIndex(List* list, const char name[]);
int findNumberIndex(List* list, const char number[]);
int pop(List* list, int* numberIndex);
void deleteList(List* list);
#endif