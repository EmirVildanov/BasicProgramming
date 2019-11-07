#include <stdio.h>
#include <stdlib.h>

char* createArray(int length)
{
    char *list = malloc(length * sizeof(char));
    for (int i = 0; i < length; ++i)
    {
        list[i] = '\0';
    }
    return list;
}

void checkAppropriateUsers(int numberOfActions, int* numbers, int numberOfUsers, int actions, int timer, int* answer)
{
    int numberOfAppropriateActions = 0;
    for (int i = 0; i < numberOfActions; i += 2)
    {
        if (numbers[i] <= timer)
        {
            ++numberOfAppropriateActions;
        }
    }
    if (numberOfAppropriateActions == actions)
    {
        *answer += 1;
    }
}

int main() {
    int users = 0;
    int actions = 0;
    int timer = 0;
    int numberOfActions = 0;
    int *numbers = malloc(numberOfActions * sizeof(int));
    int answer = 0;
    printf("Enter the values : ");
    scanf("%d %d %d", &users, &actions, &timer);
    for (int i = 0; i < users; ++i)
    {
        printf("Enter the number of actions : ");
        scanf("%d", &numberOfActions);
        printf("Enter actions time periods : ");
        for(int i = 0; i < numberOfActions; ++i)
        {
            scanf("%d", &numbers[i]);
        }
        checkAppropriateUsers(numberOfActions, numbers, users, actions, timer, &answer);
    }
    printf("The number of appropriate actions is : %d", answer);
    free(numbers);
    return 0;
}