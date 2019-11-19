#ifndef ARRAY_H
#define ARRAY_H

char* createCharArray(int size);
int* createIntArray(int size);
int** createDoubleArray(int size);
float* createFloatArray(int size);
void printCharArray(char* array, int length);
void printIntArray(int* array, int length);
void printFloatArray(float* array, int length);

#endif
