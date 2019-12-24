#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const float epsilon = 1e-7;

struct Fraction
{
    float power;
    int numerator;
    int denominator;
};

bool floatNumbersCompare(float firstNumber, float secondNumber)
{
    return fabs(firstNumber - secondNumber) < epsilon;
}

bool findFractionPower(struct Fraction list[], int length, float power)
{
    for (int i = 0; i < length; ++i)
    {
        if (floatNumbersCompare(list[i].power, power))
        {
            return true;
        }
    }
    return false;
}

void getAllFractions(int input, struct Fraction fractions[], int* newFrationCounter)
{
    int length = input / 2 * (input - 1);
    for (int denominator = 2; denominator < input + 1; ++denominator)
    {
        for (int numerator = 1; numerator < denominator; ++numerator)
        {
            float power = (float) numerator / (float) denominator;
            if (findFractionPower(fractions, length, power))
            {
                continue;
            }
            else
            {
                fractions[*newFrationCounter].power = power;
                fractions[*newFrationCounter].numerator = numerator;
                fractions[*newFrationCounter].denominator = denominator;
                *newFrationCounter += 1;
            }
        }
    }
}

void printAllFractions(struct Fraction fractions[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        for (int j = i + 1; j < length; ++j)
        {
            if (fractions[j].power < fractions[i].power)
            {
                struct Fraction temporary = fractions[i];
                fractions[i] = fractions[j];
                fractions[j] = temporary;
            }
        }
    }
    for (int i = 0; i < length; ++i)
    {
        printf("%d%c%d \n", fractions[i].numerator, '/', fractions[i].denominator);
    }
}

int main ()
{
    int input = 0;
    int fractionsCounter = 0;
    printf("Enter the number greater than 1 : ");
    while (scanf("%d", &input) == 0)
    {
        scanf("%*[^\n]");
        printf("Please enter the number other symbols : ");
    }
    struct Fraction fractions[input / 2 * (input - 1)];
    getAllFractions(input, fractions, &fractionsCounter);
    printAllFractions(fractions, fractionsCounter);
    return 0;
}
