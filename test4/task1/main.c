#include <stdio.h>
#include <malloc.h>
#include "ComplexNumber.h"

int main() {
    ComplexNumber *first = createComplexNumber(-2, 1);
    ComplexNumber *second = createComplexNumber(1, -1);
    ComplexNumber *add = addComplexNumber(first, second);
    ComplexNumber *subtract = subtractComplexNumber(first, second);
    ComplexNumber *multiply = multiplyComplexNumber(first, second);
    ComplexNumber *divide = divideComplexNumber(first, second);
    printComplexNumber(add);
    printComplexNumber(subtract);
    printComplexNumber(multiply);
    printComplexNumber(divide);
    free(first);
    free(second);
    free(add);
    free(subtract);
    free(multiply);
    free(divide);
    return 0;
}
