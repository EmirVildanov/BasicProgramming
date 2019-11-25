#pragma once

#include <stdbool.h>

bool checkOperator(char digit);
int getPriority(char digit);
char* makePostfix(char* line);
float doOperation(char operator, float firstDigit, float secondDigit);
float calculateLine(char* line);