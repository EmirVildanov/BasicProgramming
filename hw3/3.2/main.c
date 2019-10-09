#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxSize = 1000;

char* createCharArray(int size)
{
    char *list = malloc(maxSize * sizeof(char));
    for (int i = 0; i < size; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

int main()
{
    FILE *file = fopen("text", "rt");
    int answer = 0;
    char *newline = createCharArray((maxSize));
    if (file == NULL)
    {
        printf("\nPlease put your file in the build-debug directory");
        exit(1);
    }
    else
    {
        while (!feof(file))
        {
            if (fgets(newline,100, file) != NULL)
            {
                for (int i = 0; i < strlen(newline); ++i)
                {
                    if (newline[i] != '\t' && newline[i] != '\n')
                    {
                        ++answer;
                        break;
                    }
                }
            }
        }
    }
    fclose(file);
    free(newline);
    printf("The number of non-empty lines in your file is : %d", answer);
    return 0;
}
