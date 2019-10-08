#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxLength = 80;

char* createString(int size)
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
	char *firstInput = createString(maxLength);
	char *secondInput = createString(maxLength);
	int answer = 0;
	printf("Enter the first string: ");
	scanf("%s", firstInput);
	printf("Enter the second string: ");
	scanf("%s", secondInput);
	int firstInputLength = strlen(firstInput);
	int secondInputLength = strlen(secondInput);
	for (int i = 0; i < firstInputLength; ++i)
	{
		for (int j = 0; j < secondInputLength; ++j)
		{
			if (firstInput[i + j] != secondInput[j])
			{
				break;
			}
			if (j == secondInputLength - 1)
			{
				++answer;
			}
		}
	}
	free(firstInput);
	free(secondInput);
	printf("The answer is: %d", answer);
	return 0;
}

