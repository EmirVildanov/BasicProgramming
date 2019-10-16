#ifndef INC_4_2_COMMANDS_H
#define INC_4_2_COMMANDS_H
#include "Commands.h"
#include "List.h"

void readCommand(List* list, int input, int* numberIndex, int rememberNumbersNumber, FILE* file, int maxBookSize, int maxNameSize);
void entrance();

#endif
