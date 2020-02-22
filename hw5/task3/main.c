#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"
#include "Calculation.h"

char* getInput(FILE *source)
{
    char currentChar = '\0';
    char *newLine = createCharArray(0);
    fscanf(source, "%c", &currentChar);
    int newCharIndex = 0;
    while (currentChar != '\n')
    {
        newLine = expandCharArray(newLine, newCharIndex, 1);
        newLine[newCharIndex] = currentChar;
        if (fscanf(source,"%c", &currentChar) == -1)
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

bool checkInput(const char *line, int length)
{
    bool operandWait = true;
    int openBracketsNumber = 0;
    int closeBracketsNumber = 0;
    for (int i = 0; i < length; ++i)
    {
        char currentChar = line[i];
        if (currentChar != ' ' && currentChar != '+' && currentChar != '-' && currentChar != '(' &&
            currentChar != ')' && currentChar != '*' && currentChar != '/' && !isdigit(currentChar))
        {
            return false;
        }
        if (currentChar == '(')
        {
            ++openBracketsNumber;
        }
        else if (currentChar == ')')
        {
            ++closeBracketsNumber;
        }
        else if (isdigit(currentChar))
        {
            if (operandWait)
            {
                operandWait = !operandWait;
            }
            else
            {
                return false;
            }
        }
        else if (currentChar != ' ')
        {
            if (!operandWait)
            {
                operandWait = !operandWait;
            }
            else
            {
                return false;
            }
        }
    }
    if (operandWait || openBracketsNumber != closeBracketsNumber)
    {
        return false;
    }
    return true;
}

float calculateNewLine(char* line)
{
    char *postfixLine = makePostfix(line);
    float result = calculateLine(postfixLine);
    free(postfixLine);
    return result;
}

int main()
{
    printf("Please, enter your line without spaces: ");
    char *line = getInput(stdin);
    while (!checkInput(line, strlen(line)))
    {
        printf("Wrong input. Please, enter your postfix line again: ");
        free(line);
        line = getInput(stdin);
    }
    printf("The answer is : %f", calculateNewLine(line));
    free(line);
    return 0;
}