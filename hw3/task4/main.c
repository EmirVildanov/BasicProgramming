#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAppropriatedUser(int numberOfActions, const int* actionsArray, int actionsAppropriateNumber, int timer)
{
    int numberOfAppropriateActions = 0;
    for (int i = 0; i < numberOfActions; i += 2)
    {
        if (actionsArray[i] <= timer)
        {
            ++numberOfAppropriateActions;
        }
    }

    return numberOfAppropriateActions == actionsAppropriateNumber;
}

int* getActions(int *numberOfActions)
{
    printf("Enter the number of actions : ");
    fflush(stdout);
    scanf("%d", numberOfActions);
    int *numbers = malloc(*numberOfActions * sizeof(int));
    printf("Enter actions time periods : ");
    fflush(stdout);
    for (int j = 0; j < *numberOfActions; ++j)
    {
        scanf("%d", &numbers[j]);
    }
    return numbers;
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
        int *actionsArray = getActions(&numberOfActions);
        if (isAppropriatedUser(numberOfActions, actionsArray, actions, timer))
        {
            ++answer;
        }
        free(actionsArray);
    }
    printf("The number of appropriate actions is : %d", answer);
    return 0;
}