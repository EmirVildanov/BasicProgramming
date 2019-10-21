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

int checkAppropriateUsers(int numberOfUsers, int actions, int timer)
{
    int answer = 0;
    for (int i = 0; i < numberOfUsers; ++i)
    {
        int numberOfActions = 0;
        int numberOfAppropriateActions = 0;
        printf("Enter the number of actions : ");
        scanf("%d", &numberOfActions);
        int *numbers = malloc(numberOfActions * sizeof(int));
        printf("Enter actions time periods : ");
        for(int i = 0; i < numberOfActions; ++i)
        {
            scanf("%d", &numbers[i]);
        }
        for (int i = 0; i < numberOfActions; i += 2)
        {
            if (numbers[i] <= timer)
            {
                ++numberOfAppropriateActions;
            }
        }
        if (numberOfAppropriateActions == actions)
        {
            ++answer;
        }
        free(numbers);
    }
    return answer;
}

int main() {
    int users = 0;
    int actions = 0;
    int timer = 0;
    printf("Enter the values : ");
    scanf("%d %d %d", &users, &actions, &timer);
    printf("The number of appropriate actions is : %d", checkAppropriateUsers(users, actions, timer));
    return 0;
}