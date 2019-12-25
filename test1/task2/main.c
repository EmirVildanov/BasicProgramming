#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array.h"

const int lettersArraySize = 26;

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

void analyseNewLine(int *symbolsArray, char *inputLine)
{
    int length = (int) strlen(inputLine);
    for (int i = 0; i < length; ++i)
    {
        int firstSymbolIndex = (int) (inputLine[i]) - 'a';
        if (firstSymbolIndex > lettersArraySize - 1)
        {
            continue;
        }
        symbolsArray[firstSymbolIndex] += 1;
    }
}

int *readFile(FILE* file)
{
    int *symbolsArray = createIntArray(lettersArraySize);
    while (!feof(file))
    {
        char *inputLine = getFileInput(file);
        analyseNewLine(symbolsArray, inputLine);
        free(inputLine);
    }
    return symbolsArray;
}

void writeData(int *lettersCountArray, FILE *fileToWrite)
{
    for (int i = 0; i < lettersArraySize; ++i)
    {
        if (lettersCountArray[i] == 0)
        {
            continue;
        }
        char currentLetter = (char) i + 'a';
        fprintf(fileToWrite, "%c -> %d\n", currentLetter, lettersCountArray[i]);
        fflush(fileToWrite);
    }
}

int main()
{
    FILE *fileToRead = fopen("read", "r");
    FILE *fileToWrite = fopen("write", "w");
    if (fileToRead == NULL || fileToWrite == NULL)
    {
        printf("File reading problem\n");
        return 1;
    }
    else
    {
        int *lettersCountArray = readFile(fileToRead);
        writeData(lettersCountArray, fileToWrite);
        free(lettersCountArray);
    }
    fclose(fileToRead);
    fclose(fileToWrite);
    return 0;
}