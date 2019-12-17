#pragma once

char* createCharArray(int size);
char *expandCharArray(char *array, int currentSize, int expandValue);
int* createIntArray(int size);
int *expandIntArray(int *array, int currentSize, int expandValue);
int** createDoubleArray(int size);
float* createFloatArray(int size);
void printCharArray(char* array, int length);
void printIntArray(int* array, int length);
void printFloatArray(float* array, int length);

