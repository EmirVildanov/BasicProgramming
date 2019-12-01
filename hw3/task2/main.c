#include <stdio.h>
#include <string.h>

void checkNewLine(FILE* file, int* newChar, int* numberOfLines)
{
    while((char) *newChar != '\n' && *newChar)
    {
        if ((char) *newChar != '\t' &&  (char) *newChar != ' ')
        {
            ++(*numberOfLines);
            *newChar = fgetc(file);
            while( (char) *newChar != '\n')
            {
                *newChar = fgetc(file);
            }
            break;
        }
        else
        {
            *newChar = fgetc(file);
        }
    }
}

int main()
{
    FILE *file = fopen("text", "r");
    int numberOfLines = 0;
    if (file == NULL)
    {
        printf("\nPlease put your file in the build-debug directory\n");
        return 1;
    }
    int newChar = fgetc(file);
    while (EOF != newChar)
    {
        checkNewLine(file, &newChar, &numberOfLines);
        newChar = fgetc(file);
    }
    fclose(file);
    printf("The number of non-empty lines in your file is : %d", numberOfLines);
    return 0;
}
