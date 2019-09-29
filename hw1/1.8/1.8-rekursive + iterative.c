#include <stdio.h>

int recursiveFactorial(int number)
{
    if (number == 0)
    {
        return 1;
    }
    else
    {
        return recursiveFactorial(number - 1) * number;
    }
}

int iterativeFactorial(int number)
{
    int answer = 1;
    for (int i = 1; i < number + 1; ++i)
    {
        answer *= i;
    }
    return answer;
}

int main() 
{
    int input = 0;
    printf ("Enter the number: ");
    scanf("%d", &input);
    printf ("The recursive function answer is: %d \n", recursiveFactorial(input));
    printf ("The iterative function answer is: %d", iterativeFactorial(input));
    return 0;
}