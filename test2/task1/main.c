#include <stdio.h>

long int findFactorial(long int number)
{
    long int factorial = 1;
    for (long int i = 1; i <= number; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

long int findCatalanNumber(long int input)
{
    long int answer = findFactorial(2 * input) / (findFactorial(input) * (findFactorial(input + 1)));
    return answer;
}

int main()
{
    long int input = 0;
    printf("Enter the Catalan number : ");
    scanf("%ld", &input);
    input = findCatalanNumber(input);
    printf("The answer is : %ld", input);
    return 0;
}