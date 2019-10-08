#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Fraction
{
   int numerator;
   int denominator;
   float power; 
};

int findNumberOfFractions(int maxDenominator)
{
    if (maxDenominator == 2)
    {
        return 1;
    }
    else
    {
        return findNumberOfFractions(maxDenominator - 1) + maxDenominator - 1;
    }
}

bool findFractionPower(struct Fraction list[], int length, float power)
{
    bool checking = false;
    for (int i = 0; i < length; ++i)
    {
        if (list[i].power == power)
        {
            checking = true;
            break;
        }
    }
    return checking;
}

void printAllFractions(int number, struct Fraction fractions[], int length)
{
    for (int i = 0; i < length; ++i)
    {
        int minFractionIndex = 0;
        float maxFraction = (float) (number - 1) / number;
        for (int j = 0; j < length; ++j)
        {
            if (fractions[j].power < fractions[minFractionIndex].power)
            {
                minFractionIndex = j;
            }
        }
        printf("%d%c%d \n", fractions[minFractionIndex].numerator, '/', fractions[minFractionIndex].denominator);
        fractions[minFractionIndex].power = 1;
    }
}

void writeAllFractions(int input)
{
    int length = findNumberOfFractions(input); 
    struct Fraction fractions[length];
    struct Fraction fraction;
    int newFrationCounter = 0;
    fraction.numerator = 1;
    fraction.denominator = 2;
    for (int i = 0; i < input - 1; ++i)
    {
        while (fraction.numerator < fraction.denominator)
        {
            fraction.power = (float) fraction.numerator / fraction.denominator;
            if (findFractionPower(fractions, length, fraction.power) == true)
            {
                fraction.numerator += 1;
                continue;
            }
            else
            {
                fractions[newFrationCounter].power = fraction.power;
                fractions[newFrationCounter].numerator = fraction.numerator;
                fractions[newFrationCounter].denominator = fraction.denominator;
                newFrationCounter += 1;
                fraction.numerator += 1;
            }
        }
        fraction.denominator += 1;
        fraction.numerator = 1;
    }
    printAllFractions(input, fractions, newFrationCounter);
}

int main ()
{
    int input = 0;
    printf("Enter the number greater than 1 : ");
    scanf("%d", &input);
    writeAllFractions(input);
    return 0;
}
