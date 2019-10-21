#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const int maxLength = 100;

int compare(const void *a, const void *b) 
{
     return *(int*)a - *(int*)b;
} 

int findDoubleMaxElement(int list[], int start, int end)
{
    int maxElement = list[start];
    int answer = maxElement;
    for (int i = start + 1; i < end; ++i)
    {
        if (list[i] > maxElement)
        {
            maxElement = list[i];
        }
        else
        {
            answer = maxElement;
        }
    }
    return answer;
}

int main()
{
    int numbers[maxLength];
    for (int i = 0; i < maxLength; ++i)
    {
        numbers[i] = 0;
    }
    int length = 0;
    printf("Enter the number of elemrnts : ");
    scanf("%d", &length);
    for (int i = 0; i < length; ++i)
    {
        printf("ENter the new element : ");
        scanf("%d", &numbers[i]);
    }
    qsort(numbers, maxLength, sizeof(int), compare);
    printf("The answer is : %d ", findDoubleMaxElement(numbers, maxLength - length, maxLength));
}