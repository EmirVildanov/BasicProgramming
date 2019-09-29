#include <stdio.h>

const int length = 100;

void reverse(int list[], int start, int end)
{
    int length = (end - start + 1) / 2;
    for (int i = 0; i < length; ++i)
    {
        int temporary = list[start + i];
        list[start + i] = list[end - i];
        list[end - i] = temporary;
    }
}

int main()
{
    int firstBoard = 0;
    int secondBoard = 0;
    printf("Enter the first board : ");
    scanf("%d", &firstBoard);
    printf("Enter the second board : ");
    scanf("%d", &secondBoard);
    int numbers[length];
    for (int i = 0; i < firstBoard + secondBoard; ++i)
    {
        printf("Enter the new element of the list : ");
        scanf("%d", &numbers[i]);
    }
    reverse(numbers, 0, firstBoard - 1);
    reverse(numbers, firstBoard, (firstBoard + secondBoard) - 1);
    reverse(numbers, 0, (firstBoard + secondBoard) - 1);
    printf("The answer is : ");
    for (int i = 0; i < firstBoard + secondBoard; ++i)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}