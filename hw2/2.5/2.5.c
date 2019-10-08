#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkStrings(char firstString[], char secondString[])
{
    int answer = 1;
    int symbolsCount[256] = {0};
    int firstLength = strlen(firstString);
    int secondLength = strlen(secondString);
    if (firstLength == secondLength)
    {
        for (int i = 0; i < firstLength; ++i)
        {
            int firstSymbolIndex = (int)(firstString[i]);
            int secondSymbolIndex = (int)(secondString[i]);
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
}

int main()
{
    char firstInput[100];
    char secondInput[100];
    printf("Enter the first string : ");
    scanf("%s", firstInput);
    printf("Enter the second string : ");
    scanf("%s", secondInput);
    checkStrings(firstInput, secondInput);
    return 0;
}