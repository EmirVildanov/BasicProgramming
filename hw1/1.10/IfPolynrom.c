#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int maxLength = 30; 

char* createArray(int size)
{
    char *list = malloc(size * sizeof(char));
	for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

int main()
{
    char *input = createArray(maxLength);
    bool identicalChecking = true;
    printf("Enter the string: ");
    scanf("%s", input);
    int stringlength = strlen(input);
    for (int i = 0; i < stringlength / 2; ++i)
    {
        if (input[i] != input[stringlength - i - 1])
        {
            identicalChecking = false;
            break;
        }
    }
    free(input);
    if (identicalChecking)
    {
        printf("Your string is polydrom");
    }
    else
    {
        printf("Your string is not polydrom");
    }
    return 0;
}
