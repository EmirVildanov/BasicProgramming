#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "Calculation.h"

const int maxInputSize = 100;

bool checkInput(const char* line, int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (line[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

float calculateNewLine(char* line)
{
    char *postfixLine = makePostfix(line);
    return calculateLine(postfixLine);
}

int main()
{
    char *newLine = createCharArray(maxInputSize);
    printf("Please, enter your line without spaces: ");
    fgets(newLine, maxInputSize, stdin);
    if (checkInput(newLine, strlen(newLine)))
    {
        printf("The answer is : %f\n", calculateNewLine(newLine));
    }
    else
    {
        printf("There are spaces in your line\n");
    }
    free(newLine);
    return 0;
}