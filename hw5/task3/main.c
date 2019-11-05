#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Calculation.h"

const int maxSize = 100;

float calculateNewLine(char* line)
{
    char *postfixLine = makePostfix(line);
    return calculateLine(postfixLine);
}

int main() {
    char *newLine = createCharArray(maxSize);
    printf("Please, enter your line without spaces : ");
    scanf("%s", newLine);
    printf("The answer is : %f", calculateNewLine(newLine));
    free(newLine);
    return 0;
}