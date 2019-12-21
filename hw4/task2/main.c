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

bool redirectInput(char* inputLine, char *name, char *number)
{
    int nameIndex = 0;
    int numberIndex = 0;
    while(inputLine[nameIndex] != ' ')
    {
        if (inputLine[nameIndex] == '\0')
        {
            free(inputLine);
            free(name);
            free(number);
            return false;
        }
        name = expandCharArray(name, nameIndex, 1);
        name[nameIndex] = inputLine[nameIndex];
        ++nameIndex;
    }
    ++nameIndex;
    while (inputLine[nameIndex] != '\0')
    {
        number = expandCharArray(number, numberIndex, 1);
        number[numberIndex] = inputLine[nameIndex];
        ++numberIndex;
        ++nameIndex;
    }
    return true;
}

bool readFile(FILE* file, PhoneBook* phoneBook)
{
    while (!feof(file))
    {
        char *inputLine = getFileInput(file);
        if (inputLine == NULL)
        {
            return true;
        }
        char *name = createCharArray(0);
        char *number = createCharArray(0);
        if (!redirectInput(inputLine, name, number))
        {
            free(number);
            free(name);
            free(inputLine);
            return false;
        }
        if (strcmp(name, "") == 0 || strcmp(number, "") == 0)
        {
            free(number);
            free(name);
            free(inputLine);
            return false;
        }
        addNew(phoneBook, number, name);
        free(inputLine);
    }
    return true;
}

int main()
{
    FILE* file = fopen("numbers", "a+");
    if (file == NULL)
    {
        return 1;
    }
    PhoneBook* phoneBook = createBook();
    bool readingCheck = readFile(file, phoneBook);
    if (!readingCheck)
    {
        printf("File reading problem\n");
        return 1;
    }
    usage();
    char *charInput = getConsoleInput();
    int input = (int) strtol(charInput, NULL, 10);
    int lastNumberIndex = getBookSize(phoneBook) - 1;
    while (input != 0)
    {
        executeCommand(phoneBook, input, &lastNumberIndex, file);
        printf("Enter new command: ");
        charInput = getConsoleInput();
        input = (int) strtol(charInput, NULL, 10);
        free(charInput);
    }
    fclose(file);
    deleteBook(phoneBook);
    printf("Goodbye!\n");
    return 0;
}