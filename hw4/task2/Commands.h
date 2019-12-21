#pragma once
#include "PhoneBook.h"

char *getConsoleInput();
void executeCommand(PhoneBook* list, int input, int *rememberLastNumberIndex, FILE* file);
void usage();
