#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxLength = 30;

char* createArray()
{
    char *list = malloc(maxLength * sizeof(char));
    for (int i = 0; i < maxLength; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

int main()
{
    char *brackets = createArray();
    int firstBracket = 0;
    int secondBracket = 0;
    int i = 0;
    printf("Enter the string:");
    scanf("%s", brackets);
    int length = strlen(brackets);
    for (i = 0; i <= length; ++i)
    {
        if (brackets[i] == '(')
        {
            ++firstBracket;
        }
        else if (brackets[i] == ')')
        {
            ++secondBracket;
        }
        if (secondBracket > firstBracket)
        {
            break;
        }
     }
     free(brackets);
     if (firstBracket == secondBracket)
     {
        printf("All is okay");
     }
     else
     {
        printf("Mistake");
     }
     return 0;
}
