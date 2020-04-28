#include <stdlib.h>
#include <stdio.h>
#include "ComplexNumber.h"

struct ComplexNumber{
    float realPart;
    float imaginaryPart;
};

ComplexNumber *createComplexNumber(float real, float imaginary)
{
    ComplexNumber *new = malloc(sizeof(ComplexNumber));
    new->realPart = real;
    new->imaginaryPart = imaginary;
    return new;
}

ComplexNumber *addComplexNumber(ComplexNumber *first, ComplexNumber *second)
{
    return createComplexNumber(first->realPart + second->realPart, first->imaginaryPart + second->imaginaryPart);
}

ComplexNumber *subtractComplexNumber(ComplexNumber *first, ComplexNumber *second)
{
    return createComplexNumber(first->realPart - second->realPart, first->imaginaryPart - second->imaginaryPart);
}

ComplexNumber *multiplyComplexNumber(ComplexNumber *first, ComplexNumber *second)
{
    return createComplexNumber(first->realPart * second->realPart - first->imaginaryPart * second->imaginaryPart,
                           first->realPart * second->imaginaryPart + first->imaginaryPart * second->realPart);
}

ComplexNumber *divideComplexNumber(ComplexNumber *first, ComplexNumber *second)
{
    float newRealPart = (first->realPart * second->realPart + first->imaginaryPart * second->imaginaryPart) /
                        (second->realPart * second->realPart + second->imaginaryPart * second->imaginaryPart);
    float newImaginaryPart = (second->realPart * first->imaginaryPart - first->realPart * second->imaginaryPart) /
                             (second->realPart * second->realPart + second->imaginaryPart * second->imaginaryPart);
    return createComplexNumber(newRealPart, newImaginaryPart);
}

void printComplexNumber(ComplexNumber *number)
{
    if (number->imaginaryPart < 0) {
        printf("%f %f * i\n", number->realPart, number->imaginaryPart);
        return;
    }
    printf("%f +%f * i\n", number->realPart, number->imaginaryPart);
}