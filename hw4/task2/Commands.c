#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "List.h"
#include "Commands.h"

void entrance() {
    printf("Hello! You opened phone book.\n");
    printf("You have such commands to use : \n");
    printf("0 - exit \n");
    printf("1 - add new number(format: name number)\n");
    printf("2 - find phone number\n");
    printf("3 - find name\n");
    printf("4 - save data(will appear in the book after closing the program)\n");
    printf("Enter the command : ");
}

void readCommand(List* list, int input, int* numberIndex, int rememberLastNumberIndex, FILE* file, int maxBookSize, int maxValueSize)
{
    if (input == 1)
    {
        ListElement *newNumber = malloc(sizeof(ListElement));
        printf("Enter a new name number : ");
        scanf("%s %s", newNumber->name, newNumber->number);
        newNumber->numberIndex = *numberIndex;
        printf("You added number : %s_%s\n", newNumber->name, newNumber->number);
        addNew(list, newNumber->number, newNumber->name, newNumber->numberIndex, maxValueSize);
        *numberIndex += 1;
    }
    else if (input == 2)
    {
        char *name = createCharArray(maxValueSize);
        printf("Enter a name : ");
        scanf("%s", name);
        char *answer = findNumber(list, name, maxValueSize);
        if (answer[0] != '*')
        {
            printf("The number is : %s\n", answer);
        }
        else
        {
            printf("There is no such name in the book\n");
        }
    }
    else if (input == 3)
    {
        char *number = createCharArray(maxValueSize);
        printf("Enter a number : ");
        scanf("%s", number);
        char *answer = findName(list, number, maxValueSize);
        if (answer[0] != '*')
        {
            printf("The name is : %s\n", answer);
        }
        else
        {
            printf("There is no such number in the book\n");
        }
    }
    else if (input == 4)
    {
        ListElement *currentElement = list->first;
        while(currentElement->numberIndex != rememberLastNumberIndex)
        {
            fprintf(file, "%s %s \n", currentElement->name, currentElement->number);
            currentElement = currentElement->next;
        }
    }
    else
    {
        printf("You entered incorrect command ");
    }
}