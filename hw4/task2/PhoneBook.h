#pragma once

#include <stdbool.h>

struct PhoneBook;
struct BookElement;

typedef struct BookElement BookElement;
typedef struct PhoneBook PhoneBook;

PhoneBook *createBook();
BookElement *createBookElement();
int getBookSize(PhoneBook *phoneBook);
BookElement *getBookFirst(PhoneBook *phoneBook);
void changeBookSize(PhoneBook *phoneBook, int value);
int getNumberIndex(BookElement *phoneBookElement);
char *getNumber(BookElement *phoneBookElement);
char *getName(BookElement *phoneBookElement);
BookElement *getNext(BookElement *phoneBookElement);
void addNew(PhoneBook *phoneBook, char *number, char *name);
char *findNumber(PhoneBook *phoneBook, char name[]);
char *findName(PhoneBook *phoneBook, char number[]);
void deleteBook(PhoneBook *phoneBook);