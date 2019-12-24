#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool checkStrings(char *firstString, char *secondString)
{
    bool answer = true;
    int *symbolsCount = createIntArray(26);
    int firstLength = strlen(firstString);
    int secondLength = strlen(secondString);
    if (firstLength == secondLength)
    {
        for (int i = 0; i < firstLength; ++i)
        {
            int firstSymbolIndex = (int) (firstString[i]) - 'a';
            int secondSymbolIndex = (int) (secondString[i]) - 'a';
            symbolsCount[firstSymbolIndex] += 1;
            symbolsCount[secondSymbolIndex] -= 1;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (symbolsCount[i] != 0)
            {
                answer = false;
            }
        }
    }
    else
    {
        answer = false;
    }
    free(symbolsCount);
    return answer;
}

int main()
{
    char *firstInput = createCharArray(maxSize);
    char *secondInput = createCharArray(maxSize);
    printf("Enter the first string : ");
    scanf("%s", firstInput);
    printf("Enter the second string : ");
    scanf("%s", secondInput);
    bool answer = checkStrings(firstInput, secondInput);
    if (answer)
    {
        printf("I may make up first string from the second and backwards");
    }
    else
    {
        printf("Your strings consist of different letters");
    }
    free(firstInput);
    free(secondInput);
    return 0;
}
