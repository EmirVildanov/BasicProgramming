#include <stdio.h>
#include <stdlib.h>

int* createBooksStack(size)
{
    int *stack = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        int complexity = 0;
        printf("Enter the new lesson complexity : ");
        scanf("%d", &complexity);
        stack[i] = complexity;
    }
    return stack;
}

int* createEmptyStack(int size)
{
    int *stack = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
    {
        stack[i] = -1;
    }
    return stack;
}

int* createTheAppropriateStack(int* stack1, int* stack2, int size)
{
    int *stackIndexForBoth = createEmptyStack(size * 2);
    int IndexForFirstStack = 0;
    int IndexForSecondStack = 0;
    int IndexForBoth = 0;
    while (IndexForFirstStack < size && IndexForSecondStack < size)
    {
        if (stack1[IndexForFirstStack] > stack2[IndexForSecondStack])
        {
            stackIndexForBoth[IndexForBoth] = stack1[IndexForFirstStack];
            ++IndexForFirstStack;
        }
        else if (stack1[IndexForFirstStack] < stack2[IndexForSecondStack])
        {
            stackIndexForBoth[IndexForBoth] = stack2[IndexForSecondStack];
            ++IndexForSecondStack;
        }
        else
        {
            stackIndexForBoth[IndexForBoth] = stack2[IndexForSecondStack];
            ++IndexForSecondStack;
            ++IndexForFirstStack;
        }
        ++IndexForBoth;
    }
    while (IndexForFirstStack < size)
    {
        stackIndexForBoth[IndexForBoth] = stack1[IndexForFirstStack];
        ++IndexForFirstStack;
        ++IndexForBoth;
    }
    while (IndexForSecondStack < size)
    {
        stackIndexForBoth[IndexForBoth] = stack2[IndexForSecondStack];
        ++IndexForSecondStack;
        ++IndexForBoth;
    }
    return stackIndexForBoth;
}

int main() {
    int numberOfLessons = 0;
    printf("Enter the number of lessons : ");
    scanf("%d", &numberOfLessons);
    int *firstBookStack = createBooksStack(numberOfLessons);
    int *secondBookStack = createBooksStack(numberOfLessons);
    int *corporateStack = createTheAppropriateStack(firstBookStack, secondBookStack, numberOfLessons);
    printf("The new stack of books is : ");
    for (int i = 0; i < numberOfLessons * 2; ++i)
    {
        if (corporateStack[i] == -1)
        {
            break;
        }
        printf("%d ", corporateStack[i]);
    }
    free(firstBookStack);
    free(secondBookStack);
    free(corporateStack);
    return 0;
}