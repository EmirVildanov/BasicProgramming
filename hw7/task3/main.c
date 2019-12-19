#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "String.h"
#include "Hashtable.h"
#include "array.h"

char *getFileInput(FILE *file)
{
    int maxGettingSize = 10;
    int expandValue = 10;
    char *input = createCharArray(maxGettingSize);
    char *buffer = createCharArray(maxGettingSize);
    if (fgets(buffer, maxGettingSize, file) == NULL)
    {
        return NULL;
    }
    else
    {
        int lastSymbolIndex = 0;
        while (true)
        {
            for (int i = 0; i < expandValue - 1; ++i)// -1 because we don't want to read '\0' symbol
            {
                if (buffer[i] == '\0' && feof(file))
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                else if (buffer[i] == '\0')
                {
                    break;
                }
                else if (buffer[i] == '\n')
                {
                    input[lastSymbolIndex] = '\0';
                    free(buffer);
                    return input;
                }
                input[lastSymbolIndex] = buffer[i];
                ++lastSymbolIndex;
            }
            input = expandCharArray(input, lastSymbolIndex, expandValue);
            fgets(buffer, maxGettingSize, file);
        }
    }
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
        char *newLine = getFileInput(file);
        readNewLine(hashtable, newLine);
        free(newLine);
    }
    printStatistics(hashtable);
    deleteHashtable(hashtable);
    fclose(file);
    return 0;
}