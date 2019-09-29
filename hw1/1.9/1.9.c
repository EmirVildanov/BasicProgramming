#include <stdio.h>
#include <math.h>

int binaryPow(int number, int degree)
{
    int answer = 0;
    if (degree == 0)
    {
        return 1;
    }
    else if (degree % 2 != 0)
    {
        return binaryPow(number, degree - 1) * number;
    }
    else
    {
        int squaredNumber = binaryPow(number, degree / 2);
        return squaredNumber * squaredNumber;
    }
}

int main()
{
    int inputNumber = 0;
    int inputDegree = 0;
    float negativeDegreeAnswer = 0;
    printf("Enter the number:");
    scanf("%d", &inputNumber);
    printf("Enter the degree:");
    scanf("%d", &inputDegree);
    if (inputDegree >= 0)
    {
        printf("The answer is: %d", binaryPow(inputNumber, inputDegree));
    }
    else
    {
        inputDegree = abs(inputDegree);
        negativeDegreeAnswer = (float) 1 / binaryPow(inputNumber, inputDegree);
        printf("The answer is: %f", negativeDegreeAnswer);
    }
    return 0;
}
