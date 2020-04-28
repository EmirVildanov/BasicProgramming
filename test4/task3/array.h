#pragma once

char* createCharArray(int size);
int* createIntArray(int size);
float* createFloatArray(int size);
int **createDoubleDimensionalArray(int stringsNumber, int columnsNumber);

char *expandCharArray(char *array, int currentSize, int expandValue);
int *expandIntArray(int *array, int currentSize, int expandValue);
int **expandDoubleDimensionalArray(int **array, int currentStringsNumber, int columnsNumber, int extendValue);

void printCharArray(char* array, int length);
void printIntArray(int* array, int length);
void printFloatArray(float* array, int length);
void printDoubleDimensionalArray(int **array, int stringsNumber, int columnsNumber);

int *sortIntArray(int *array, int size);
int **sortDoubleDimensionalArray(int **array, int stringsNumber, int columnsNumber);
void deleteDoubleDimensionalArray(int **array, int stringsNumber);

