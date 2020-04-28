#pragma once

struct ComplexNumber;

typedef struct ComplexNumber ComplexNumber;

ComplexNumber *createComplexNumber(float real, float imaginary);
void printComplexNumber(ComplexNumber *number);

ComplexNumber *addComplexNumber(ComplexNumber *first, ComplexNumber *second);
ComplexNumber *multiplyComplexNumber(ComplexNumber *first, ComplexNumber *second);
ComplexNumber *subtractComplexNumber(ComplexNumber *first, ComplexNumber *second);
ComplexNumber *divideComplexNumber(ComplexNumber *first, ComplexNumber *second);