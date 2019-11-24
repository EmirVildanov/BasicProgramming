#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAppropriatedUser(int numberOfActions, const int* numbers, int actionsAppropriateNumber, int timer)
{
    int numberOfAppropriateActions = 0;
    for (int i = 0; i < numberOfActions; i += 2)
    {
        if (numbers[i] <= timer)
        {
            ++numberOfAppropriateActions;
        }
    }

    return numberOfAppropriateActions == actionsAppropriateNumber;
}

int main()
{
    int users = 0;
    int actions = 0;
    int timer = 0;
    int answer = 0;
    int numberOfActions = 0;
    printf("Enter the values: ");
    fflush(stdout);
    scanf("%d %d %d", &users, &actions, &timer);
    for (int i = 0; i < users; ++i)
    {
        printf("Enter the number of actions : ");
        fflush(stdout);
        scanf("%d", &numberOfActions);
        int *numbers = malloc(numberOfActions * sizeof(int));
        printf("Enter actions time periods : ");
        fflush(stdout);
        for (int j = 0; j < numberOfActions; ++j)
        {
            scanf("%d", &numbers[j]);
        }
        if (isAppropriatedUser(numberOfActions, numbers, actions, timer))
        {
            ++answer;
        }
        free(numbers);
    }
    printf("The number of appropriate actions is : %d", answer);
    return 0;
}