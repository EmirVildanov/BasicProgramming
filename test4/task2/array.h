#pragma once

char* createCharArray(int size);
int* createIntArray(int size);
float* createFloatArray(int size);
int **createDoubleDimensionalArray(int stringsNumber, int columnsNumber);

char *expandCharArray(char *array, int currentSize, int expandValue);
int *expandIntArray(int *array, int currentSize, int expandValue);

void printCharArray(char* array, int length);
void printIntArray(int* array, int length);
void printFloatArray(float* array, int length);

int *sortIntArray(int *array, int size);
