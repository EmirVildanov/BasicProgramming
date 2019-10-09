#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp(const void *a, const void *b) 
{
     return *(int*)a - *(int*)b;
} 
 
int returnNewNumber(char string[])
{
    int length = 0;
    length = strlen(string);
    int number = atoi(string);
    int digits[length];
    for (int i = 0; i < length; ++i)
    {
        int tenPower = (int) pow(10, length - i - 1);
        digits[i] = number / tenPower;
        number = number % tenPower;
    }
    qsort(digits, length, sizeof(int), cmp);
    for (int i = 0; i < length; ++i)
    {
        printf("%d", digits[i]);
    }
}

int main()
{
    char input[30];
    printf("Enter the number : ");
    scanf("%s", &input);
    printf("The new number is : ");
    returnNewNumber(input);
    return 0;
}
