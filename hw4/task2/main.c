#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PhoneBook.h"
#include "Commands.h"
#include "Array.h"

const int maxInputSize = 15;

void readFile(FILE* file, PhoneBook* phoneBook)
{
    while (!feof(file))
    {
        char *number = createCharArray(maxInputSize);
        char *name = createCharArray(maxInputSize);
        fscanf(file,"%s %s", name, number);
        if (strcmp(name, "") == 0 || strcmp(number, "") == 0)
        {
            free(number);
            free(name);
            return;
        }
        addNew(phoneBook, number, name);
    }
}

int main()
{
    int input = 0;
    FILE* file = fopen("numbers", "a+");
    if (file == NULL)
    {
        return 1;
    }
    PhoneBook* phoneBook = createBook();
    if (phoneBook == NULL)
    {
        return 1;
    }
    readFile(file, phoneBook);
    usage();
    scanf("%d", &input);
    int lastNumberIndex = getBookSize(phoneBook);
    while (input != 0)
    {
        executeCommand(phoneBook, input, lastNumberIndex - 1, file, maxInputSize);
        printf("Enter new command: ");
        scanf("%d", &input);
    }
    fclose(file);
    deleteBook(phoneBook);
    printf("Goodbye!\n");
    return 0;
}