#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxSize = 100;

int* createIntArray(int size)
{
    int *list = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        list[i] = 0;
    }
    return list;
}

char* createCharArray(int size)
{
    char *list = malloc(size * sizeof(char));
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

void checkStrings(char *firstString, char *secondString)
{
    int answer = 1;
    int *symbolsCount = createIntArray(256);
    int firstLength = strlen(firstString);
    int secondLength = strlen(secondString);
    if (firstLength == secondLength)
    {
        for (int i = 0; i < firstLength; ++i)
        {
            int firstSymbolIndex = (firstString[i]) - '0';
            int secondSymbolIndex = (int) (secondString[i]) - '0';
            symbolsCount[firstSymbolIndex] += 1;
            symbolsCount[secondSymbolIndex] -= 1;
        }
        for (int i = 0; i < 256; ++i)
        {
            if (symbolsCount[i] != 0)
            {
                answer = 0;
                break;
            }
        }
    }
    else
    {
        answer = 0;
    }
    if (answer == 1)
    {
        printf("I may make up first string from the second and backwards");
    }
    else
    {
        printf("Your strings consist of different letters");
    }
    free(symbolsCount);
}

int main()
{
    char *firstInput = createCharArray(maxSize);
    char *secondInput = createCharArray(maxSize);
    printf("Enter the first string : ");
    scanf("%s", firstInput);
    printf("Enter the second string : ");
    scanf("%s", secondInput);
    checkStrings(firstInput, secondInput);
    free(firstInput);
    free(secondInput);
    return 0;
}
