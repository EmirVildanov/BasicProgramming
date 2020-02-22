#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PhoneBook.h"
#include "Commands.h"
#include "Array.h"

char* getFileInput(FILE *file)
{
    char currentChar = '\0';
    char *newLine = createCharArray(0);
    fscanf(file, "%c", &currentChar);
    int newCharIndex = 0;
    while (currentChar != '\n')
    {
        newLine = expandCharArray(newLine, newCharIndex, 1);
        newLine[newCharIndex] = currentChar;
        if (fscanf(file,"%c", &currentChar) == -1)
        {
            ++newCharIndex;
            break;
        }
        ++newCharIndex;
    }
    newLine = expandCharArray(newLine, newCharIndex, 1);
    newLine[newCharIndex] = '\0';
    return newLine;
}

void redirectInput(const char* inputLine, char **name, char **number)
{
    int nameIndex = 0;
    int numberIndex = 0;
    while(inputLine[nameIndex] != ' ')
    {
        *name = expandCharArray(*name, nameIndex, 1);
        (*name)[nameIndex] = inputLine[nameIndex];
        ++nameIndex;
    }
    *name = expandCharArray(*name, nameIndex, 1);
    (*name)[nameIndex] = '\0';
    ++nameIndex;
    while (inputLine[nameIndex] != '\0')
    {
        *number = expandCharArray(*number, numberIndex, 1);
        (*number)[numberIndex] = inputLine[nameIndex];
        ++numberIndex;
        ++nameIndex;
    }
    *number = expandCharArray(*number, numberIndex, 1);
    (*number)[numberIndex] = '\0';
}

void readFile(FILE* file, PhoneBook* phoneBook)
{
    while (!feof(file))
    {
        char *inputLine = getFileInput(file);
        char *name = NULL;
        char *number = NULL;
        redirectInput(inputLine, &name, &number);
        if (name == NULL || number == NULL)
        {
            printf("ASDFSDFGSDFSDGSDG");
            exit(1);
        }
        addNew(phoneBook, number, name);
        free(inputLine);
    }
}

int main()
{
    FILE* file = fopen("numbers", "a+");
    if (file == NULL)
    {
        return 1;
    }
    PhoneBook* phoneBook = createBook();
    readFile(file, phoneBook);
    usage();
    char *charInput = getConsoleInput();
    int input = (int) strtol(charInput, NULL, 10);
    free(charInput);
    int lastNumberIndex = getBookSize(phoneBook) - 1;
    if (input == 0)
    {
        free(charInput);
    }
    while (input != 0)
    {
        executeCommand(phoneBook, input, &lastNumberIndex, file);
        printf("Enter new command: ");
        fflush(stdout);
        charInput = getConsoleInput();
        input = (int) strtol(charInput, NULL, 10);
        free(charInput);
    }
    fclose(file);
    deleteBook(phoneBook);
    printf("Goodbye!\n");
    fflush(stdout);
    return 0;
}