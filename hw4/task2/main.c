#include <stdio.h>
#include "List.h"
#include "Commands.h"
#include "Array.h"

const int maxInputSize = 15;

void readFile(FILE* file, List* numberList)
{
    while (!feof(file))
    {
        char *number = createCharArray(maxInputSize);
        char *name = createCharArray(maxInputSize);
        fscanf(file, "%s %s", name, number);
        addNew(numberList, number, name);
    }
    pop(numberList); //to delete last(empty) line in the list
}

int main()
{
    int input = 0;
    FILE* file = fopen("numbers", "a+");
    List* numberList = createList();
    readFile(file, numberList);
    entrance(); //print entrance lines
    scanf("%d", &input);
    int lastNumberIndex = getListSize(numberList);
    while (input != 0)
    {
        readCommand(numberList, input, lastNumberIndex - 1, file, maxInputSize);
        printf("Enter new command: ");
        scanf("%d", &input);
    }
    fclose(file);
    deleteList(numberList);
    printf("Goodbye!\n");
    return 1;
}