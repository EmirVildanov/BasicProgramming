#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "String.h"
#include "Hashtable.h"
#include "array.h"

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

void readNewLine(Hashtable *hashtable, char *newLine)
{
    if (newLine != NULL && hashtable != NULL)//new line
    {
        String *string = createString(newLine);
        String **lineWords = split(string, ' ');
        int currentWordIndex = 0;
        while (lineWords[currentWordIndex] != NULL)
        {
            String *currentWord = lineWords[currentWordIndex];
            insertNewWord(hashtable, currentWord);
            ++currentWordIndex;
        }
        free(lineWords);
        deleteString(string);
    }
}

int main()
{
    FILE *file = fopen("Test", "rt");
    Hashtable *hashtable = createHashTable();
    if (file == NULL)//Checking file was read correctly
    {
        printf("I can't find your file\n");
        return 1;
    }
    while (!feof(file))//while not empty
    {
        char *newLine = getInput(file);
        readNewLine(hashtable, newLine);
        free(newLine);
    }
    printStatistics(hashtable);
    deleteHashtable(hashtable);
    fclose(file);
    return 0;
}