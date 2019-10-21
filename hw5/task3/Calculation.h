#ifndef INC_5_3_CALCULATION_H
#define INC_5_3_CALCULATION_H

#include <stdbool.h>

bool checkOperator(char digit);
int checkPower(char digit);
char* makePostfix(char* line);
float doOperation(char operator, float firstDigit, float secondDigit);
float calculateLine(char* line);

#endif
