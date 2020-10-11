#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"
#include "PhoneBook.h"

enum NameCheck
{
    EMPTY_INPUT,
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

char *getConsoleInput()
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
    if (fgets(buffer, maxGettingSize, stdin) == NULL)
    {
        free(input);
        free(buffer);
        return NULL;
    }
    else
    {
        int lastSymbolIndex = 0;
        while (true)
        {
            for (int i = 0; i < expandValue - 1; ++i)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[i] == '\0')
                {
                    break;
                }
                else if (buffer[i] == '\n')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[i];
                ++lastSymbolIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            fgets(buffer, maxGettingSize, stdin);
        }
    }
}

int checkInput(PhoneBook* book, char* name, char* number)
{
    if (book == NULL || strcmp(name, "") == 0 || strcmp(number, "") == 0)
    {
        return false;
    }
    char *nameInTheBook = findName(book, number);
    char *numberInTheBook = findNumber(book, name);
    if (nameInTheBook[0] != '*')
    {
        if (numberInTheBook[0] == '*')
        {
            free(numberInTheBook);
        }
        return WRONG_NUMBER;
    }
    else
    {
        free(nameInTheBook);
    }
    if (numberInTheBook[0] != '*')
    {
        return WRONG_NAME;
    }
    else
    {
        free(numberInTheBook);
    }
    return CORRECT;
}

void executeFirstCommand(PhoneBook *book)
{
    printf("Enter the name you want to add : ");
    fflush(stdout);
    fflush(stdin);
    char *name = getConsoleInput();
    printf("Enter the number you want to add :  ");
    char *number = getConsoleInput();
    int checkingAnswer = checkInput(book, name, number);
    while (checkingAnswer == EMPTY_INPUT)
    {
        printf("You entered empty name or number. Please, try again :");
        printf("Enter the name you want to add :  ");
        name = getConsoleInput();
        printf("Enter the number you want to add :  ");
        number = getConsoleInput();
        checkingAnswer = checkInput(book, name, number);
    }
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
    else if (checkingAnswer == WRONG_NAME)
    {
        free(name);
        free(number);
        printf("Name is already in the phone book.\n");
    }
}

void executeSecondCommand(PhoneBook *book)
{
    printf("Enter a name: ");
    char *name = getConsoleInput();
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

void executeThirdCommand(PhoneBook *book)
{
    printf("Enter a number: ");
    char *number = getConsoleInput();
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

void executeFourthCommand(PhoneBook *book, FILE *file, int *rememberLastNumberIndex)
{
    BookElement *currentElement = getBookFirst(book);
    int newNumbersQuantity = 0;
    while(getNumberIndex(currentElement) != *rememberLastNumberIndex)// - 1
    {
        fprintf(file, "\n%s %s", getName(currentElement), getNumber(currentElement));
        fflush(file);
        currentElement = getNext(currentElement);
        newNumbersQuantity += 1;
    }
    *rememberLastNumberIndex += newNumbersQuantity;
}

void executeCommand(PhoneBook* book, int input, int *rememberLastNumberIndex, FILE* file)
{
    switch (input)
    {
        case 1:
        {
            executeFirstCommand(book);
            break;
        }
        case 2:
        {
            executeSecondCommand(book);
            break;
        }
        case 3:
        {
            executeThirdCommand(book);
            break;
        }
        case 4:
        {
            executeFourthCommand(book, file, rememberLastNumberIndex);
            break;
        }
        default:
        {
            printf("You entered incorrect command\n");
            scanf("%*[^\n]");
            break;
        }
    }
}