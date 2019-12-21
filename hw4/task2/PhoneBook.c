#include <stdlib.h>
#include <string.h>
#include "PhoneBook.h"
#include "Array.h"

struct BookElement
{
    int numberIndex;
    char *number;
    char *name;
    BookElement* next;
};

struct PhoneBook
{
    BookElement* first;
    int size;
};

PhoneBook* createBook()
{
    PhoneBook* newBook = malloc(sizeof(PhoneBook));
    if (newBook == NULL)
    {
        return NULL;
    }
    newBook->first = NULL;
    newBook->size = 0;
    return newBook;
}

BookElement* createBookElement()
{
    BookElement *newBookElement = (BookElement*) malloc(sizeof(BookElement));
    if (newBookElement == NULL)
    {
        return NULL;
    }
    return newBookElement;
}

int getBookSize(PhoneBook *book)
{
    if (book == NULL)
    {
        return 0;
    }
    return book->size;
}

BookElement *getBookFirst(PhoneBook *book)
{
    if (book == NULL)
    {
        return NULL;
    }
    return book->first;
}

void changeBookSize(PhoneBook *book, int value)
{
    if (book == NULL)
    {
        return;
    }
    book->size = value;
}

int getNumberIndex(BookElement *bookElement)
{
    if (bookElement == NULL)
    {
        return -1;
    }
    return bookElement->numberIndex;
}

char *getNumber(BookElement *bookElement)
{
    if (bookElement == NULL)
    {
        return NULL;
    }
    return bookElement->number;
}

char *getName(BookElement *bookElement)
{
    if (bookElement == NULL)
    {
        return NULL;
    }
    return bookElement->name;
}

BookElement *getNext(BookElement *bookElement)
{
    if (bookElement == NULL)
    {
        return NULL;
    }
    return bookElement->next;
}

void addNew(PhoneBook* book, char* number, char* name)
{
    if (book == NULL)
    {
        return;
    }
    BookElement *newElement = createBookElement();
    if (newElement == NULL)
    {
        return;
    }
    newElement->number = number;
    newElement->name = name;
    newElement->numberIndex = book->size;
    newElement->next = book->first;
    book->first = newElement;
    ++book->size;
}

char* findNumber(PhoneBook* book, char name[])
{
    if (book == NULL)
    {
        return NULL;
    }
    char *wrongSearching = createCharArray(1);
    wrongSearching[0] = '*';
    BookElement *currentElement = book->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->name, name) == 0)
        {
            free(wrongSearching);
            return currentElement->number;
        }
        currentElement = currentElement->next;
    }
    return wrongSearching;
}

char* findName(PhoneBook* book, char number[])
{
    if (book == NULL)
    {
        return NULL;
    }
    char *wrongSearching = createCharArray(1);
    wrongSearching[0] = '*';
    BookElement *currentElement = book->first;
    while (currentElement != NULL)
    {
        if (strcmp(currentElement->number, number) == 0)
        {
            free(wrongSearching);
            return currentElement->name;
        }
        currentElement = currentElement->next;
    }
    return wrongSearching;
}

void deleteBook(PhoneBook* book)
{
    if (book == NULL)
    {
        return;
    }
    while(book->first != NULL)
    {
        BookElement* currentElement = book->first;
        if (currentElement->next != NULL)
        {
            book->first = currentElement->next;
        }
        if(currentElement == book->first)
        {
            free(currentElement->number);
            free(currentElement->name);
            free(book->first);
            break;
        }
        free(currentElement->number);
        free(currentElement->name);
        free(currentElement);
    }
    free(book);
}