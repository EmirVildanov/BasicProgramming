#include <stdio.h>

int findFibonacciNumber(int number)
{
    int firstNumber = 0;
    int secondNumber = 1;
    int temporary = 0;
    for (int i = 0; i < number - 1; ++i)
    {
        temporary = firstNumber;
        firstNumber = secondNumber;
        secondNumber += temporary;
    }
    return firstNumber;
}

int main() {
    int number = 0;
    printf("Enter the number : ");
    scanf("%d", &number);
    printf("Result : %d", findFibonacciNumber(number));
    return 0;
}