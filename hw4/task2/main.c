#include <stdio.h>
#include "List.h"
#include "Commands.h"
#include "Array.h"

const int maxBookSize = 1000;
const int maxValueSize = 15;

int main()
{
    int input = 0;
    FILE* file = fopen("numbers", "a+");
    List* numberList = createList();
    int numberIndex = 0;
    ++numberIndex;
    while (!feof(file))
    {
        char *number = createCharArray(maxValueSize);
        char *name = createCharArray(maxValueSize);
        fscanf(file, "%s %s", name, number);
        addNew(numberList, number, name, numberIndex, maxValueSize);
        ++numberIndex;
    }
    pop(numberList, &numberIndex);
    entrance();
    scanf("%d", &input);
    int lastNumberIndex = numberIndex;
    while (input != 0)
    {
        readCommand(numberList, input, &numberIndex, lastNumberIndex - 1, file, maxBookSize, maxValueSize);
        printf("Enter new command : ");
        scanf("%d", &input);
    }
    fclose(file);
    deleteList(numberList);
    printf("Goodbye!");
    return 0;
}