#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "PhoneBook.h"

enum NameCheck
{
    CORRECT,
    WRONG_NAME,
    WRONG_NUMBER
};

void usage()
{
    printf("Hello! You opened phone book.\n");
    printf("You have such commands to use: \n");
    printf("0 - exit \n");
    printf("1 - add new number(format: name number)\n");
    printf("2 - find phone number\n");
    printf("3 - find name\n");
    printf("4 - save data\n");
    printf("Enter the command: ");
}

int checkInput(PhoneBook* book, char* name, char* number)
{
    char *nameInTheBook = findName(book, number);
    char *numberInTheBook = findNumber(book, name);
    if (nameInTheBook[0] != '*')
    {
        if (numberInTheBook[0] == '*')
        {
            free(numberInTheBook);
        }
        return WRONG_NAME;
    }
    else
    {
        free(nameInTheBook);
    }
    if (numberInTheBook[0] != '*')
    {
        return WRONG_NUMBER;
    }
    else
    {
        free(numberInTheBook);
    }
    return CORRECT;
}

void executeFirstCommand(PhoneBook *book, int maxInputSize)
{
    char *name = createCharArray(maxInputSize);
    char *number = createCharArray(maxInputSize);
    printf("Enter a new pair (format: name number) :  ");
    scanf("%s %s", name, number);
    int checkingAnswer = checkInput(book, name, number);
    if (checkingAnswer == CORRECT)
    {
        printf("You added number: %s_%s \n", name, number);
        addNew(book, number, name);
        changeBookSize(book, getBookSize(book) + 1);
    }
    else if (checkingAnswer == WRONG_NUMBER)
    {
        free(name);
        free(number);
        printf("Number is already in the phone book.\n");
    }
    else
    {
        free(name);
        free(number);
        printf("Name is already in the phone book.\n");
    }
}

void executeSecondCommand(PhoneBook *book, int maxInputSize)
{
    char *name = createCharArray(maxInputSize);
    printf("Enter a name: ");
    scanf("%s", name);
    char *answer = findNumber(book, name);
    if (answer[0] != '*')
    {
        printf("The number is: %s\n", answer);
    }
    else
    {
        printf("There is no such name in the book\n");
        free(answer);
    }
    free(name);
}

void executeThirdCommand(PhoneBook *book, int maxInputSize)
{
    char *number = createCharArray(maxInputSize);
    printf("Enter a number: ");
    scanf("%s", number);
    char *answer = findName(book, number);
    if (answer[0] != '*')
    {
        printf("The name is: %s\n", answer);
    }
    else
    {
        printf("There is no such number in the book\n");
        free(answer);
    }
    free(number);
}

void executeFourthCommand(PhoneBook *book, FILE *file, int rememberLastNumberIndex)
{
    BookElement *currentElement = getBookFirst(book);
    while(getNumberIndex(currentElement) != rememberLastNumberIndex)
    {
        fprintf(file, "%s %s \n", getName(currentElement), getNumber(currentElement));
        fflush(file);
        currentElement = getNext(currentElement);
    }
}

void executeCommand(PhoneBook* book, int input, int rememberLastNumberIndex, FILE* file, int maxInputSize)
{
    switch (input)
    {
        case 1:
            executeFirstCommand(book, maxInputSize);
            break;
        case 2:
            executeSecondCommand(book, maxInputSize);
            break;
        case 3:
            executeThirdCommand(book, maxInputSize);
            break;
        case 4:
            executeFourthCommand(book, file, rememberLastNumberIndex);
            break;
        default:
            printf("You entered incorrect command\n");
            scanf("%*[^\n]");
            break;
    }
}